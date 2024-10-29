#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <sys/shm.h>
#include <sys/types.h>


unsigned int calculate_matrix_size(int rows, int cols, size_t sizeElement) {
    size_t size = rows * sizeof (void *); 
    size += (cols * rows * sizeElement); 
    return size;}

void create_index(void **m, int rows, int cols, size_t sizeElement){
    size_t sizeRow = cols * sizeElement;
    m[0] = m + rows;
    for (int i=1; i<rows; i++){
        m[i] = (m[i-1] + sizeRow);
    }
}

void print_matrix(int **matrix, int size, const char *name) {
    printf("================= Matrix %s =====================\n", name);
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            printf("%d\t", matrix[r][c]);
        }
        printf("\n");
    }
}

int multiplicar_matriz(int **A, int **B, int size, int row, int col) {
    int resultado = 0;
    for (int i = 0; i < size; i++) {
        resultado += A[row][i] * B[i][col];
    }
    return resultado;
}

void showtree(){
    char command [100];
    sprintf (command, "pstree -lp %d | awk '!/sh\\(/ && !/pstree\\(/' \n", getpid());
    system (command);
    printf("\n");
}

int main() {

    int MatrizTam = 6;

    int shmid_A, shmid_B, shmid_C;
    int **A, **B, **C;
    size_t matrix_size = calculate_matrix_size(MatrizTam, MatrizTam, sizeof(int));

    shmid_A = shmget(IPC_PRIVATE, matrix_size, IPC_CREAT | 0600);
    A = shmat(shmid_A, NULL, 0);
    create_index((void *)A, MatrizTam, MatrizTam, sizeof(int));


    shmid_B = shmget(IPC_PRIVATE, matrix_size, IPC_CREAT | 0600);
    B = shmat(shmid_B, NULL, 0);
    create_index((void *)B, MatrizTam, MatrizTam, sizeof(int));


    shmid_C = shmget(IPC_PRIVATE, matrix_size, IPC_CREAT | 0600);
    C = shmat(shmid_C, NULL, 0);
    create_index((void *)C, MatrizTam, MatrizTam, sizeof(int));

    int NumHijos = MatrizTam / 2 + (MatrizTam % 2 != 0);

    int LlenarA = 1, LlenarB = MatrizTam * MatrizTam;
    for (int i = 0; i < MatrizTam; i++) {
        for (int j = 0; j < MatrizTam; j++) {
            A[i][j] = LlenarA++;
            B[i][j] = LlenarB--;
        }
    }

    printf("[%d] Padre: Matrices Iniciales\n", getpid());
    print_matrix(A, MatrizTam, "A");
    print_matrix(B, MatrizTam, "B");

    for (int i = 0; i < NumHijos; i++) {
        if (fork() == 0) {

            printf("[%d] Hijo %d: Calculando filas y columnas...\n", getpid(), i+1);
            for (int col = i; col < MatrizTam - i; col++) {
                C[i][col] = multiplicar_matriz(A, B, MatrizTam, i, col);
                C[MatrizTam - i - 1][col] = multiplicar_matriz(A, B, MatrizTam, MatrizTam - i - 1, col);
                printf("[%d] Hijo %d: Calculando C[%d][%d] y C[%d][%d]\n", getpid(), i, i+1, col, MatrizTam - i - 1, col);
            }
            for (int row = i + 1; row < MatrizTam - i - 1; row++) {
                C[row][i] = multiplicar_matriz(A, B, MatrizTam, row, i);
                C[row][MatrizTam - i - 1] = multiplicar_matriz(A, B, MatrizTam, row, MatrizTam - i - 1);
                printf("[%d] Hijo %d: Calculando C[%d][%d] y C[%d][%d]\n", getpid(), i+1, row, i, row, MatrizTam - i - 1);
            }

            shmdt(A);
            shmdt(B);
            shmdt(C);
            exit(0); 
        }
    }

    showtree();

    while (wait(NULL) > 0);

    printf("\n[%d] Padre: Matriz Resultado C\n", getpid());
    print_matrix(C, MatrizTam, "C");


    shmdt(A); shmctl(shmid_A, IPC_RMID, 0);
    shmdt(B); shmctl(shmid_B, IPC_RMID, 0);
    shmdt(C); shmctl(shmid_C, IPC_RMID, 0);

    return 0;
}
