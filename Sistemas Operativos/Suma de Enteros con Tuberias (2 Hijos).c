#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>

void error(char *msg) {
    perror(msg);
    exit(-1);
}

int LeerNumeros(char *filename, int **vec) {
    int c, numero, totalNum;
    FILE *infile;
    infile = fopen(filename, "r");
    if (!infile) {
        error("Error Fopen\n");
    }
    fscanf(infile, "%d", &totalNum);
    *vec = (int *)calloc(totalNum, sizeof(int));

    if (!*vec) {
        error("error Calloc");
    }

    for (c = 0; c < totalNum; c++) {
        fscanf(infile, "%d", &numero);
        (*vec)[c] = numero;
    }

    fclose(infile);
    return c;
}

int main() {
    int *vector;
    char *archivo = "./input.txt";

    int cantidadNum = LeerNumeros(archivo, &vector);
    printf("%d\n", cantidadNum);

    int limites[2][2];

    int delta = cantidadNum / 2;

    limites[0][0] = 0;
    limites[0][1] = delta;
    limites[1][0] = limites[0][1];
    limites[1][1] = cantidadNum;

    int tub1[2], tub2[2];
    pipe(tub1);
    pipe(tub2);

    for (int i = 0; i < 2; i++) {
        if (!fork()) {
            if (i == 0) {
                close(tub2[0]);
                close(tub2[1]);
                close(tub1[0]);

                int suma = 0; 
                for (int i = 0; i < limites[0][1]; i++) {
                    suma += vector[i];
                }

                printf("La suma en el hijo 1 es: %d\n", suma);
                write(tub1[1], &suma, sizeof(suma));

            } else {
                close(tub1[0]);
                close(tub1[1]);
                close(tub2[0]);

                int suma2 = 0; 
                for (int i = delta; i < cantidadNum; i++) {
                    suma2 += vector[i];
                }

                printf("La suma en el Hijo 2 es: %d\n", suma2);
                write(tub2[1], &suma2, sizeof(suma2));
            }
            exit(0);
        }
    }

    close(tub1[1]);
    close(tub2[1]);

    for (int i = 0; i < 2; i++) {
        wait(NULL);
    }

    int SumaTotalHijo1;
    int SumaTotalHijo2;

    read(tub1[0], &SumaTotalHijo1, sizeof(SumaTotalHijo1));
    read(tub2[0], &SumaTotalHijo2, sizeof(SumaTotalHijo2));

    int sumaTotal = SumaTotalHijo1 + SumaTotalHijo2;

    printf("La suma total es: %d \n", sumaTotal);

    free(vector); // RECUERDAAAA Liberar memoria asignada al vector
    return 0;
}
