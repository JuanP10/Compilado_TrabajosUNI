#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define N 4  // Número de hijos

// Función para verificar si un "1" tiene un "2" alrededor
int MirarVecinos(int **matrix, int rows, int cols, int i, int j) {
    for (int x = i - 1; x <= i + 1; x++) {
        for (int y = j - 1; y <= j + 1; y++) {
            if (x >= 0 && x < rows && y >= 0 && y < cols) {  //Si no está en la frontera
                if (matrix[x][y] == 2) {
                    return 1;  // Si hay un 2 en los vecinos, se confirma el nido
                }
            }
        }
    }
    return 0;  // Si no hay 2 alrededor, no se confirma el nido
}

// Función para procesar parte de la imagen (submatriz)
void subMatriz(int start, int end, int pipe_fd[2], int **matrix, int filas, int cols, int idHijo ) {

    close(pipe_fd[0]); // Cerrar el extremo de lectura de la tubería

    for (int i = start; i < end; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1) {
                // Verificar si hay un nido confirmado (un 2 alrededor)
                if (MirarVecinos(matrix, filas, cols, i, j)) {
                    // Escribir "nido confirmado" en la tubería
                    char msg[100];
                    sprintf(msg, "Hijo %d: Nido confirmado en [%d, %d]\n", idHijo, i, j);
                    write(pipe_fd[1], msg, sizeof(msg));
                } else {
                    // Escribir "posible nido" en la tubería
                    char msg[100];
                    sprintf(msg, "Hijo %d: Posible nido en [%d, %d]\n", idHijo, i, j);
                    write(pipe_fd[1], msg, sizeof(msg));
                }
            }
        }
    }
    close(pipe_fd[1]); // Cerrar el extremo de escritura de la tubería
}

// Función para leer la matriz desde un archivo
int **LeerMatriz(const char *filename, int *rows, int *cols) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d %d", rows, cols);

    // Asignar memoria para la matriz
    int **matrix = malloc((*rows) * sizeof(int *));
    for (int i = 0; i < *rows; i++) {
        matrix[i] = malloc((*cols) * sizeof(int));
    }

    // Leer los valores de la matriz
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }

    fclose(file);
    return matrix;
}

int main() {
    int filas, cols;

    
    int **matrix = LeerMatriz("matriz.txt", &filas, &cols);

    int pipes[N][2]; // Tuberías para cada hijo
    pid_t pids[N];
    
    int MatrizXHijo = filas / N;

    // Crear hijos y tuberías
    for (int i = 0; i < N; i++) {
        if (pipe(pipes[i]) == -1) { // Crear tubería
            perror("pipe");
            exit(EXIT_FAILURE);
        }
        if ((pids[i] = fork()) == -1) { // Crear proceso hijo
            perror("fork");
            exit(EXIT_FAILURE);
        }
        
        if (pids[i] == 0) { // Código de los hijos
            int start = i * MatrizXHijo;
            int end = (i + 1) * MatrizXHijo;
            if (i == N - 1) end = filas; // Último hijo procesa el resto

            subMatriz(start, end, pipes[i], matrix, filas, cols, i + 1);
            exit(EXIT_SUCCESS); // Termina el hijo
        }
    }

    // Código del padre
    for (int i = 0; i < N; i++) {
        close(pipes[i][1]); // Cerrar el extremo de escritura de las tuberías

        char buffer[100];
        while (read(pipes[i][0], buffer, sizeof(buffer)) > 0) {
            printf("%s", buffer); // Imprimir los resultados recibidos de los hijos
        }
        close(pipes[i][0]); // Cerrar el extremo de lectura de las tuberías

        wait(NULL); // Esperar a que el hijo termine
    }

    // Liberar la memoria de la matriz
    for (int i = 0; i < filas; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

