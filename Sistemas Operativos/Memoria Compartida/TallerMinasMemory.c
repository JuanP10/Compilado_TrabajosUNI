#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define N 4  
#define BUFFER_HIJO 1024

int MirarVecinos(int **matrix, int rows, int cols, int i, int j) {
    for (int x = i - 1; x <= i + 1; x++) {
        for (int y = j - 1; y <= j + 1; y++) {
            if (x >= 0 && x < rows && y >= 0 && y < cols) {
                if (matrix[x][y] == 2) {
                    return 1; 
                }
            }
        }
    }
    return 0;  
}

void subMatriz(int inicio, int final, int **matrix, int filas, int cols, int idHijo, char *shared_mem) {
    for (int i = inicio; i < final; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1) {
                if (MirarVecinos(matrix, filas, cols, i, j)) {
                    char msg[100];
                    sprintf(msg, "Hijo %d: Mina en [%d, %d]\n", idHijo, i, j);
                    strcat(shared_mem, msg); 
                }
            }
        }
    }
}

int **LeerMatriz(const char *filename, int *rows, int *cols) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d", rows); 
    fscanf(file, "%d", cols);   
    int **matrix = malloc((*rows) * sizeof(int *));
    for (int i = 0; i < *rows; i++) {  
        matrix[i] = malloc((*cols) * sizeof(int));
    }

    for (int i = 0; i < *rows; i++) { 
        for (int j = 0; j < *cols; j++) { 
            fscanf(file, "%1d", &matrix[i][j]); 
        }
    }
    fclose(file);
    return matrix;
}


unsigned int sizeof_dm(int rows, int cols, size_t sizeElement){
    size_t size = rows * sizeof(void *);  
    size += (cols * rows * sizeElement);  
    return size;
}

void showtree(){
    char command [100];
    sprintf (command, "pstree -lp %d | awk '!/sh\\(/ && !/pstree\\(/' \n", getpid());
    system (command);
    printf("\n");
}

int main(int argc, char const *argv[]) {
    int filas, cols;

    int **matrix = LeerMatriz("matriz1.txt", &filas, &cols);
    
    size_t sizeMatrix = sizeof_dm(filas, cols, sizeof(int)); 
    int shmid = shmget(IPC_PRIVATE, sizeMatrix + N * BUFFER_HIJO, IPC_CREAT | 0666); 
    char *shared_mem = shmat(shmid, NULL, 0);

    pid_t pids[N];
    int MatrizXHijo = filas / N;

    for (int i = 0; i < N; i++) {
        if ((pids[i] = fork()) == -1) { 
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pids[i] == 0) { // Proceso hijo
            int inicio = i * MatrizXHijo;
            int final = (i + 1) * MatrizXHijo;
            if (i == N - 1) final = filas; // Último hijo procesa el resto

            char *child_shared_mem = shared_mem + sizeMatrix + (i * BUFFER_HIJO);

            subMatriz(inicio, final, matrix, filas, cols, i + 1, child_shared_mem);
            
            sleep(1);
            
            shmdt(shared_mem); 
            exit(EXIT_SUCCESS); 
        }
    }

    showtree();

    // Código del padre
    for (int i = 0; i < N; i++) {
        wait(NULL); 
    }

    for (int i = 0; i < N; i++) {
        char *child_result = shared_mem + sizeMatrix + (i * BUFFER_HIJO);
        printf("%s", child_result);
    }

    shmdt(shared_mem);
    shmctl(shmid, IPC_RMID, NULL);

    for (int i = 0; i < filas; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
