#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define N 4 

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

void subMatriz(int inicio, int final, int pipe_fd[2], int **matrix, int filas, int cols, int idHijo ) {

    close(pipe_fd[0]); 

    for (int i = inicio; i < final; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1) {
                if (MirarVecinos(matrix, filas, cols, i, j)) {
                    char msg[100];
                    sprintf(msg, "Padre dice que: Hijo %d: Mina en [%d, %d]\n", idHijo, i, j);
                    //printf("Hijo %d dice: Mina en [%d, %d]\n", idHijo, i, j);
                    write(pipe_fd[1], msg, sizeof(msg));
                }
            }
        }
    }
    close(pipe_fd[1]); 
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
        char line[100]; 
        fscanf(file, "%s", line); 

        for (int j = 0; j < *cols; j++) {
            matrix[i][j] = line[j] - '0'; 
        }
    }
    fclose(file);
    return matrix;
}


void showtree(){
    char command [100];
    sprintf (command, "pstree -lp %d | awk '!/sh\\(/ && !/pstree\\(/' \n", getpid());
    system (command);
    printf("\n");
}

int main(int argc, char const *argv) {

    int filas, cols;

    int **matrix = LeerMatriz("matriz1.txt", &filas, &cols);

    int pipes[N][2]; // Tuberías para cada hijo
    pid_t pids[N] , padre = getpid();
    
    int MatrizXHijo = filas / N;

    for (int i = 0; i < N; i++) {
        if (pipe(pipes[i]) == -1) { 
            perror("pipe");
            exit(EXIT_FAILURE);
        }
        if ((pids[i] = fork()) == -1) { 
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pids[i] == 0) { //hijos
            sleep(1);
            int inicio = i * MatrizXHijo;
            int final = (i + 1) * MatrizXHijo;
            if (i == N - 1) final = filas; // Último hijo procesa el resto

            subMatriz(inicio, final, pipes[i], matrix, filas, cols, i + 1);
            
            exit(EXIT_SUCCESS); 
        }
    }
    
    showtree();


    // Código del padre
    for (int i = 0; i < N; i++) {
        close(pipes[i][1]); // Cerrar escritura
        char buffer[100];

        while(read(pipes[i][0], buffer, sizeof(buffer))>0){
            printf("%s", buffer);
        }
        
        close(pipes[i][0]); // Cerrar lectura 
        
        wait(NULL); // Esperar a que el hijo termine
    }


    for (int i = 0; i < filas; i++) {
        free(matrix[i]);
    }

    free(matrix);

    return 0;
}


