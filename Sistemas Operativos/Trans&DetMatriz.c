/* Estudiantes: Juan Pablo Ramirez, Santiago Andrés Candanoza y Carlos Enrique Aroca

Crear un programa en C que lea una matriz de un archivo "matriz1.txt", calcule su transpuesta y 
guarde el resultado en otro archivo "matriztras.txt". 
Dada una matriz almacenada en un archivo de texto con dimensiones NxM, 
el programa debe calcular la matriz transpuesta 
(donde las filas se convierten en columnas y viceversa) 
y escribir el resultado en un nuevo archivo de texto.

*/

#include <stdio.h>  
#include <stdlib.h> 

void MatrizTranspuesta(int **matriz, int m, int n, int **resultado){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            resultado[j][i] = matriz[i][j];
        }
    }
}

int Determinante(int **matriz, int n) {
    if (n == 1) {
        return matriz[0][0];
    } else if (n == 2) {
        return (matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]);
    } else {
        int det = 0;
        for (int p = 0; p < n; p++) {
            int **submatriz = (int **)malloc((n - 1) * sizeof(int *));
            for (int i = 0; i < n - 1; i++) {
                submatriz[i] = (int *)malloc((n - 1) * sizeof(int));
            }
            for (int i = 1; i < n; i++) {
                int col = 0;
                for (int j = 0; j < n; j++) {
                    if (j != p) {
                        submatriz[i - 1][col] = matriz[i][j];
                        col++;
                    }
                }
            }
            det += matriz[0][p] * Determinante(submatriz, n - 1) * (p % 2 == 0 ? 1 : -1);
            for (int i = 0; i < n - 1; i++) {
                free(submatriz[i]);
            }
            free(submatriz);
        }
        return det;
    }
}




int main(int argc, char *argv[]){    

    FILE *file = fopen(argv[1], "r");
    if (file == NULL){
        printf("Error al abrir el archivo de entrada.\n");
        return EXIT_FAILURE;
    }

    int m, n;
    fscanf(file, "%d %d", &m, &n);

    int **matriz = (int **)malloc(m * sizeof(int *));
    if (matriz == NULL) {
        printf("Error al asignar memoria para la matriz.\n");
        fclose(file);
        return EXIT_FAILURE;
    }

    for(int i = 0; i < m; i++){
        matriz[i] = (int *)malloc(n * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Error al asignar memoria para la fila %d.\n", i);
            for (int j = 0; j < i; j++) {
                free(matriz[j]);
            }
            free(matriz);
            fclose(file);
            return EXIT_FAILURE;
        }
        for(int j = 0; j < n; j++){
            fscanf(file, "%d", &matriz[i][j]);
        }
    }

    fclose(file);

    int **resultado = (int **)malloc(n * sizeof(int *));
    if (resultado == NULL) {
        printf("Error al asignar memoria para la matriz resultado.\n");
        for (int i = 0; i < m; i++) {
            free(matriz[i]);
        }
        free(matriz);
        return EXIT_FAILURE;
    }

    for(int i = 0; i < n; i++){
        resultado[i] = (int *)malloc(m * sizeof(int));
        if (resultado[i] == NULL) {
            printf("Error al asignar memoria para la fila %d de resultado.\n", i);
            for (int j = 0; j < i; j++) {
                free(resultado[j]);
            }
            free(resultado);
            for (int j = 0; j < m; j++) {
                free(matriz[j]);
            }
            free(matriz);
            return EXIT_FAILURE;
        }
    }

    MatrizTranspuesta(matriz, m, n, resultado); 

    printf("Determinante de la matriz: %d\n", Determinante(matriz, n));


    FILE *outfile = fopen(argv[2], "w");
    if (outfile == NULL) {
        printf("Error creando archivo de salida.\n");
        for (int i = 0; i < m; i++) {
            free(matriz[i]);
        }
        free(matriz);
        for (int i = 0; i < n; i++) {
            free(resultado[i]);
        }
        free(resultado);
        return EXIT_FAILURE;
    }

    fprintf(outfile, "%d %d\n", n, m);

    // Escritura de los resultados
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            fprintf(outfile, "%d ", resultado[i][j]);
        }
        fprintf(outfile, "\n");
    }

    fclose(outfile);

    // Liberar memoria
    for (int i = 0; i < m; i++) {
        free(matriz[i]);
    }
    free(matriz);
    for (int i = 0; i < n; i++) {
        free(resultado[i]);
    }
    free(resultado);

    printf("Proceso completado correctamente.\n");

    return EXIT_SUCCESS;
}
