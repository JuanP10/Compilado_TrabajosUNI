#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*

El proceso padre deberá:
1. Leer en un vector los datos del archivo de entrada input.txt
2. Estimar los ı́ndices (principio y fin) del vector sobre el cual cada proceso hijo trabajará
3. Crear los procesos hijos
4. Esperar la terminación de los hijos
5. Imprimir el resultado final


Los procesos hijos deberán:
1. Recorrer el vector en las posiciones indicadas por el padre
2. Estimar la suma de las posiciones recorridas
3. Escribir el resultado en el archivo de salida out.txt

*/


/* Función para manejar errores */
void error(char *msg) {
    printf("%s\n", msg);
    exit(1);
}

int LeerNumeros(char *filename, int **vec) {
    long int c, numero, totalNumeros;

    FILE *infile = fopen(filename, "r");
    if(!infile ){ 
        error("Error fopen\n");
    }

    fscanf(infile, "%ld", &totalNumeros);

    *vec = (int *)calloc(totalNumeros, sizeof(int));
    if (!*vec) {
       error("error calloc");
    }

    for (c = 0; c < totalNumeros; c++) {
        fscanf(infile, "%ld", &numero);
        (*vec)[c] = numero;
        //printf("%d\n", numero);
    }

    fclose(infile);
    return c;
}

long int LeerTotal() {

    long int sumap1 = 0, sumap2 = 0, total = 0;
    FILE *infile = fopen("out.txt", "r");
    if (!infile) {
         error("Error padre archivo resultados");
    }

    fscanf(infile, "%ld", &sumap1);
    fscanf(infile, "%ld", &sumap2);
    
    total = sumap1 + sumap2;

    return total;
}

int main(int argc, char *argv[]) {

    pid_t root = getpid();

    int *vec;
    int cantidadNumeros = LeerNumeros(argv[1], &vec);

    
    int delta = cantidadNumeros / 2;
    int limites[2][2]; 

    limites[0][0] = 0;                       // Inicio del primer hijo
    limites[0][1] = delta;                   // Fin del primer hijo
    limites[1][0] = delta;                   // Inicio del segundo hijo
    limites[1][1] = cantidadNumeros;         // Fin del segundo hijo

    for (int i = 0; i < 2; i++) {
        if (fork() == 0) { // Proceso hijo

            FILE *outputFile = fopen("out.txt", "a");  // "a" para agregar al archivo
            if (outputFile == NULL) {
                error("Error al abrir el archivo en el hijo");
            }

            long int suma = 0;

            // Cada hijo recorre sus respectivos límites
            for (int j = limites[i][0]; j < limites[i][1]; j++) {
                suma += vec[j];
            }

            fprintf(outputFile, "%ld\n", suma);
            fclose(outputFile);
            //free(vec);
            exit(0); // Termina el proceso hijo
        }
    }

    // Proceso padre espera a los hijos
    for (int i = 0; i < 2; i++) {
        wait(NULL);  // Esperar que terminen los hijos
    }

    // Leer y mostrar la suma total
    printf("Suma total: %ld\n", LeerTotal());

    //remove("out.txt");
    free(vec);

    return EXIT_SUCCESS;
}
