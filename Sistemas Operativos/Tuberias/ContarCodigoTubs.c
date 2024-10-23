#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

const char* keywords[] = {"int", "float", "return", "if", "else", "for", "while", "printf"};

int isKeyword(const char* str) {
    int num_keywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int contar_lineas_codigo(const char *contenido) {
    int lineas_codigo = 0;
    char *linea = strtok((char *)contenido, "\n"); 

    while (linea != NULL) {
        if (strlen(linea) > 0) { // Solo contar líneas no vacías
            lineas_codigo++;
        }
        linea = strtok(NULL, "\n");
    }
    return lineas_codigo;
}

int contar_palabras_clave(const char *contenido) {
    int count = 0;
    char *palabra = strtok((char*)contenido, " \n\t();"); 

    while (palabra != NULL) {
        if (isKeyword(palabra)) {
            count++;
        }
        palabra = strtok(NULL, " \n\t();"); 
    }
    return count;
}

int contar_comentarios(const char *contenido) {
    int comentarios = 0;
    char *linea = strtok((char*)contenido, "\n");

    while (linea != NULL) {
        if (strstr(linea, "//") != NULL) {
            comentarios++;
        }
        linea = strtok(NULL, "\n");
    }
    return comentarios;
}

void showtree() {
    char command[100];
    sprintf(command, "pstree -lp %d | awk '!/sh\\(/ && !/pstree\\(/'", getpid());
    system(command);
    printf("\n");
}

int main(int argc, char* argv[]) {

    FILE* archivo = fopen(argv[1], "r");
    if (!archivo) {
        perror("Error al abrir archivo");
        exit(EXIT_FAILURE);
    }

    char size;
    fscanf(archivo, "%s", &size); 

    printf("Tamaño del archivo: %s\n", size);

    char *contenido = (char*)malloc(size + 1);
    
    if (!contenido) {
        perror("Error de asignación de memoria");
        fclose(archivo);
        exit(EXIT_FAILURE);
    }
    fclose(archivo);

    printf("Contenido del archivo: \n%s\n", contenido);

    int pipes[3][2];
    for (int i = 0; i < 3; i++) {
        if (pipe(pipes[i]) == -1) {
            perror("Error al crear tubería");
            exit(EXIT_FAILURE);
        }
    }

    pid_t pids[3]; 

    for (int i = 0; i < 3; i++) {
        pids[i] = fork();
        if (pids[i] == 0) {
            // Cada hijo cierra lectura
            close(pipes[i][0]);

            // Crear una copia del contenido para procesar
            char *contenido_copia = strdup(contenido);
            
            if (!contenido_copia) {
                perror("Error de duplicación de cadena");
                exit(EXIT_FAILURE);
            }

            // Los hijos procesan el contenido recibido
            int resultado = 0;

            if (i == 0) { // Hijo 1
                resultado = contar_lineas_codigo(contenido_copia);
            } else if (i == 1) { // Hijo 2
                resultado = contar_palabras_clave(contenido_copia);
            } else if (i == 2) { // Hijo 3
                resultado = contar_comentarios(contenido_copia);
            }

            // Escribir el resultado en la tubería
            write(pipes[i][1], &resultado, sizeof(int));
            close(pipes[i][1]);
            free(contenido_copia);
            exit(EXIT_SUCCESS);

        } else if (pids[i] < 0) {
            perror("Error al crear el proceso hijo");
            exit(EXIT_FAILURE);
        }
    }

    // El padre imprime el árbol de procesos
    showtree();

    // El padre cierra escritura de los hijos
    for (int i = 0; i < 3; i++) {
        close(pipes[i][1]);
    }

    int resultados[3];
    for (int i = 0; i < 3; i++) {
        read(pipes[i][0], &resultados[i], sizeof(int));
        close(pipes[i][0]);
    }

    // Esperar a que todos los hijos terminen
    for (int i = 0; i < 3; i++) {
        waitpid(pids[i], NULL, 0);
    }

    printf("Resumen del análisis:\n");
    printf("Líneas de código no vacías: %d\n", resultados[0]);
    printf("Palabras clave encontradas: %d\n", resultados[1]);
    printf("Comentarios de una línea: %d\n", resultados[2]);

    free(contenido);

    return 0;
}
