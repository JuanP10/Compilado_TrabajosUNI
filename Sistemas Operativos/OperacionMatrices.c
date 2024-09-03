#include <stdio.h>  
#include <stdlib.h> 

void SumaMatrices(int **matriz1, int **matriz2, int m, int n, int **resultado){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

void RestaMatrices(int **matriz1, int **matriz2, int m, int n, int **resultado){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            resultado[i][j] = matriz1[i][j] - matriz2[i][j];
        }
    }
}

void MultiplicaMatrices(int **matriz1, int **matriz2, int m, int n, int **resultado){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            resultado[i][j] = 0;
            for (int k = 0; k < n; k++){
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}




int main(int argc, char *argv[]){    

    FILE *file1 = fopen(argv[1], "r");
    if (file1 == NULL){
        printf("Error al abrir el archivo de entrada.\n");
        return EXIT_FAILURE;
    }

    FILE *file2 = fopen(argv[2], "r");
    if (file2 == NULL){
        printf("Error al abrir el archivo de entrada.\n");
        fclose(file1);
        return EXIT_FAILURE;
    }

    int m, n;
    fscanf(file1, "%d %d", &m, &n);
    fscanf(file2, "%d %d", &m, &n);

    int **matriz1 = (int **)malloc(m * sizeof(int *));
    if (matriz1 == NULL) {
        printf("Error al asignar memoria para la matriz.\n");
        fclose(file1);
        fclose(file2);
        return EXIT_FAILURE;
    }

    int **matriz2 = (int **)malloc(m * sizeof(int *));
    if (matriz2 == NULL) {
        printf("Error al asignar memoria para la matriz.\n");
        fclose(file1);
        fclose(file2);
        return EXIT_FAILURE;
    }

    for(int i = 0; i < m; i++){
        matriz1[i] = (int *)malloc(n * sizeof(int));
        if (matriz1[i] == NULL) {
            printf("Error al asignar memoria para la fila %d.\n", i);
            for (int j = 0; j < i; j++) {
                free(matriz1[j]);
            }
            free(matriz1);
            fclose(file1);
            fclose(file2);
            return EXIT_FAILURE;
        }
        for(int j = 0; j < n; j++){
            fscanf(file1, "%d", &matriz1[i][j]);
        }
    }

    for(int i = 0; i < m; i++){
        matriz2[i] = (int *)malloc(n * sizeof(int));
        if (matriz2[i] == NULL) {
            printf("Error al asignar memoria para la fila %d.\n", i);
            for (int j = 0; j < i; j++) {
                free(matriz2[j]);
            }
            free(matriz2);
            fclose(file1);
            fclose(file2);
            return EXIT_FAILURE;
        }
        for(int j = 0; j < n; j++){
            fscanf(file2, "%d", &matriz2[i][j]);
        }
    }

    fclose(file1);
    fclose(file2);

    int **resultado = (int **)malloc(m * sizeof(int *));
    if (resultado == NULL) {
        printf("Error al asignar memoria para la matriz resultado.\n");
        for (int i = 0; i < m; i++) {
            free(matriz1[i]);
        }
        free(matriz1);
        for (int i = 0; i < m; i++) {
            free(matriz2[i]);
        }
        free(matriz2);
        return EXIT_FAILURE;
    }

    for(int i = 0; i < m; i++){
        resultado[i] = (int *)malloc(n * sizeof(int));
        if (resultado[i] == NULL) {
            printf("Error al asignar memoria para la fila %d de resultado.\n", i);
            for (int j = 0; j < i; j++) {
                free(resultado[j]);
            }
            free(resultado);
            for (int j = 0; j < m; j++) {
                free(matriz1[j]);
            }
            free(matriz1);
            for (int j = 0; j < m; j++) {
                free(matriz2[j]);
            }
            free(matriz2);
            return EXIT_FAILURE;
        }
    }

    MultiplicaMatrices(matriz1, matriz2, m, n, resultado);  // Cambiar por la función que se desee

    FILE *outfile = fopen(argv[3], "w");
    if (outfile == NULL){
        printf("Error al abrir el archivo de salida.\n");
        for (int i = 0; i < m; i++) {
            free(matriz1[i]);
        }
        free(matriz1);
        for (int i = 0; i < m; i++) {
            free(matriz2[i]);
        }
        free(matriz2);
        for (int i = 0; i < m; i++) {
            free(resultado[i]);
        }
        free(resultado);
        return EXIT_FAILURE;
    }

    fprintf(outfile, "%d %d\n", m, n);
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            fprintf(outfile, "%d ", resultado[i][j]);
        }
        fprintf(outfile, "\n");
    }

    fclose(outfile);

    for (int i = 0; i < m; i++) {
        free(matriz1[i]);
    }
    free(matriz1);
    for (int i = 0; i < m; i++) {
        free(matriz2[i]);
    }
    free(matriz2);
    for (int i = 0; i < m; i++) {
        free(resultado[i]);
    }
    free(resultado);

    printf("Proceso completado con éxito.\n");

    return EXIT_SUCCESS;

}
