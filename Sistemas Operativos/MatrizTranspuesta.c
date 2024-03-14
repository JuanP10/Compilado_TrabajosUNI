/* Estudiantes: Juan Pablo Ramirez, Santiago Andrés Candanoza y Carlos Enrique Aroca

Crear un programa en C que lea una matriz de un archivo, calcule su transpuesta y 
guarde el resultado en otro archivo. 
Dada una matriz almacenada en un archivo de texto con dimensiones NxM, 
el programa debe calcular la matriz transpuesta 
(donde las filas se convierten en columnas y viceversa) 
y escribir el resultado en un nuevo archivo de texto.

*/


#include <stdio.h>  
#include <stdlib.h> 

void MatrizTranspuesta (int **matriz, int m, int n, int **resultado){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            resultado[i][j] = matriz[j][i];
        }
    }
}

int main(int argc, char *argv[]){

    FILE *file;
    FILE *outfile;

    file = fopen("matriz1.txt","r");

    if(file == NULL){
        printf("Error al abrir el archivo");
        return EXIT_SUCCESS;
    }

    int m, n;
    int **matriz = NULL;
    int **resultado = NULL;
    fscanf(file, "%d %d", &m, &n);

    //Asigno y leo memoria 
    matriz = (int **)malloc(m * sizeof(int *));
    for(int i = 0; i < m; i++){
        matriz[i] = (int *)malloc(n * sizeof(int));
        for(int j = 0; j < n; j++){
            fscanf(file, "%d", &matriz[i][j]);
        }
    }


    //Cierro archivo
    fclose(file);

    //Creo y asigno matriz resultado
    resultado = (int **)malloc(m * sizeof(int *));
    for(int i = 0; i < m; i++){
        resultado[i] = (int *)malloc(n * sizeof(int));
        for(int j = 0; j < n; j++){
            fscanf(file, "%d", &resultado[i][j]);
        }
    }

    //Doy valores a resultado
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            resultado [i][j] == matriz[j][i];
        }
    }

    MatrizTranspuesta (matriz,  m,  n, resultado);


    outfile = fopen("salida.txt", "w");
    if (outfile == NULL) {
        printf("Error creando archivo .\n");
        return EXIT_SUCCESS;;
    }

    // Escritura de los resultados
    for (int i = 0; i < m; i++) {
        for(int j = 0; j < n ; j++){
         fprintf(outfile, "%d ", resultado[i][j]);
    }
    fprintf(outfile, "\n");
}


    fclose(outfile);

    // Liberar memoria
    for (int i = 0; i < m; i++) {
        free(matriz[i]); //libera memoria de cada fila. puntero de un array de punturos 
    }
    free(matriz);
    free(resultado);

    printf("YAAAA SALIOOO HP!! \n");



    return EXIT_SUCCESS;
}