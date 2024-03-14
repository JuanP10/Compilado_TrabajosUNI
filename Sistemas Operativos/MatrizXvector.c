/* 
Se tiene una matriz de dimensiones MxN y un vector de dimensión N, ambos almacenados
en un archivo de texto. El objetivo es realizar la multiplicación
de la matriz por el vector y guardar el vector resultante en un nuevo archivo

*/
#include <stdio.h>
#include <stdlib.h>

void multiplicaciónMatrizxVector(int **matrix, int *vector, int m, int n, int *result) {
    for (int i = 0; i < m; i++) {
        result[i] = 0.0;
        for (int j = 0; j < n; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }
}

int main() {
    FILE *inputFile, *outputFile;
    int **matrix;
    int *vector;
    int *result;
    int m, n;

    // Abrir archivo de entrada para lectura
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Leer dimensiones de la matriz
    fscanf(inputFile, "%d %d", &m, &n); 

    // Asignar memoria para la matriz
    matrix = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    // leer elementos de la matriz
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(inputFile, "%d", &matrix[i][j]);
        }
    }

    // Asignar memoria para el vector
    vector = (int *)malloc(n * sizeof(int));

    // Leer elementos del vector
    for (int i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &vector[i]);
    }

    // Cerrar archivo 
    fclose(inputFile);

    // Asignar memoria para el resultado
    result = (int *)malloc(m * sizeof(int));

    // Llamar la función de multiplicación
    multiplicaciónMatrizxVector(matrix, vector, m, n, result);

    // Abrir archivo de salida para escritura
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Escritura de los resultados
    for (int i = 0; i < m; i++) {
        fprintf(outputFile, "%d ", result[i]);
    }

    // Cerramos el archivo
    fclose(outputFile);

    // Liberar memoria
    for (int i = 0; i < m; i++) {
        free(matrix[i]); //libera memoria de cada fila. puntero de un array de punturos 
    }
    free(matrix);
    free(vector);
    free(result);

    printf("Yaaaaa.\n");

    return 0;
}
