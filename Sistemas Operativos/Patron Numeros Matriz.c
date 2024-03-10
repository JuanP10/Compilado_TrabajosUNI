/*
Imprime un patrón de números del 1 al n (1<=n<=80)
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char* argv[]) {
    int n;
    printf("Ingrese el valor de n (1 < n < 81): ");
    scanf("%d", &n);

    if (n <= 0 || n >= 81) {
        printf("El valor de n debe estar entre 1 y 80.\n");
        return  EXIT_SUCCESS;
    }
	int x=(2*n)- 1;
    int matriz[x][x];
    int i, j, min, max, valor;

    

    min = 0;
    max = x - 1;
    valor = n;

    while (min <= max) {
        for (i = min; i <= max; i++) {
            for (j = min; j <= max; j++) {
                if (i == min || i == max || j == min || j == max) {
                    matriz[i][j] = valor;
                } else {
                    if (valor - 1 < min) {
                        matriz[i][j] = min + 1;
                    } else {
                        matriz[i][j] = valor - 1;
                    }
                }
            }
        }
        min++;
        max--;
        valor--;
    }
	 

    // Imprimir la matriz
    for (i = 0; i < x; i++) {
        for (j = 0; j < x; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    
    
    // OTRA MANERA 
	 
	 printf("--------------------\n");
	 
	 // int n = atoi(argv[1]);   convierte el primer argumento pasado en la linea de comandos a un entero
	 
	 for(i=0 ; i<x; i++){
	 	
	 	int dx = i<n ? n-i: abs((x-i-1)-n);  //operador condicional ternario --> condición ? expresión_verdadera : expresión_falsa
	 	                                     //si i es menor que c, se evaluará n-i. De lo contrario, se evaluará abs((x-i-1)-n).
	 	for(j=0; j<x; j++){
	 		
	 		int dy = j<n ? n-j: abs((x-j-1)-n);
	 		int max= dx>dy ? dx: dy;
	 		printf("%d ",max);
		 }
		 
		printf("\n");
	 }
	 
	 printf("--------------------\n");
	
	 
	 //
    


    return EXIT_SUCCESS;
}

