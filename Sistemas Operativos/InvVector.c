#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[]){

    int n; //Tamano del vector
    int *vector; //Vector de enteros
    
    printf("Ingrese el tamano del vector: ");
    scanf("%d", &n);

    vector = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++){
        printf("Ingrese el valor de la posicion %d: ", i+1);
        scanf("%d", &vector[i]);
    }

    printf("El vector ingresado es: ");
    for (int i = 0; i < n; i++){
        printf("%d ", vector[i]);
    }

    printf("\n");

    printf("El vector invertido es: ");
    for (int i = n-1; i >= 0; i--){
        printf("%d ", vector[i]);
    }

    
    free(vector);


    return EXIT_SUCCESS;
}