#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>  


int main(int argc, char *argv[]) {

    pid_t root = getpid();

    FILE *file, *outputFile;

    // Leer el archivo .in
    file = fopen(argv[1], "rb");

    if (file == NULL) {
        printf("Error al abrir el archivo .in\n");
        exit(1);
    } else {
        printf("1. Archivo abierto\n");
    }

    int size;
    fscanf(file, "%d", &size);

    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Error al asignar memoria para el array\n");
        exit(1);
    } else {
        printf("2. Memoria asignada\n");
    }

    for (int i = 0; i < size; i++) {
        fscanf(file, "%d", &array[i]);
    }

    fclose(file);

    // Crear dos procesos hijos
    for (int i = 0; i < 2; i++) {

        pid_t pid = fork();

        if (pid == 0) {   // Proceso hijo

            outputFile = fopen("output.txt", "a");  // Modo 'a' para agregar
            if (outputFile == NULL) {
                printf("Error al abrir el archivo en el hijo\n");
                exit(1);
            } else {
                printf("3. Archivo abierto en el hijo %d\n", i+1);
            }

            long int suma = 0;

            if (i == 0) {
                // Proceso hijo 1
                for (int j = 0; j < size / 2; j++) {
                    suma += array[j];
                }
            } else {
                // Proceso hijo 2
                for (int j = size / 2; j < size; j++) {
                    suma += array[j];
                }
            }

            // Escribir suma en el archivo
            fprintf(outputFile, "%ld\n", suma);

            fclose(outputFile);
            free(array);
            
            exit(0);  // Terminar proceso hijo
        }
    }

    printf("------------------------------------------------\n");

    if (root == getpid()) {
        char b[50];
        sprintf(b,"pstree -lp %d",getpid());
        system(b);
    } else {
        sleep(2);
    }

    printf("------------------------------------------------\n");

    // Proceso padre
    for (int i = 0; i < 2; i++) {
        wait(NULL);  // Esperar a que terminen ambos hijos
    }

    outputFile = fopen("output.txt", "r");  // Abrir en modo lectura
    if (outputFile == NULL) {
        printf("Error al abrir el archivo en el padre\n");
        exit(1);
    } else {
        printf("4. Archivo abierto en el padre\n");
    }

    long int sumaTotal = 0;
    long int suma;
    while (fscanf(outputFile, "%ld", &suma) != EOF) {
        sumaTotal += suma;
    }

    fclose(outputFile);
    free(array);

    printf("------------------------------------------------\n");
    printf("Suma total: %ld\n", sumaTotal);

    return EXIT_SUCCESS;
}
