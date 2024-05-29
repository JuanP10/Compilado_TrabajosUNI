/*
Lectura de un archivo de texto que contiene una secuencia de ADN y estimar la secuencia complementaria de ADN. (A)
El programa debe dividir el archivo en N partes y cada hilo debe estimar la secuencia complementaria de ADN de una parte del archivo.
El hilo principal debe escribir la secuencia estimada en un archivo de texto llamado SecuenciaEstimada.txt.

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N 10 // Número de hilos
pthread_t hilos[N]; 

typedef struct {
    char *secuencia;    // Arreglo de caracteres
    size_t n;           // Número de elementos en el arreglo
} DatosArchivo;

typedef struct {              // Estructura para pasar argumentos a los hilos 
    DatosArchivo *datos;      // Puntero a la estructura de datos
    int id;                   // Identificador del hilo
} HiloArgs;

void leerArchivo(DatosArchivo *datos) {
    FILE *archivo;
    archivo = fopen("dna.dat", "r");   //"r" si es secuancial  y "rb" si es binario
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(EXIT_FAILURE);
    }

    // Calcular el tamaño del archivo  Es PARA ARCHIVOS BINARIOS
    fseek(archivo, 0, SEEK_END); // Mover el puntero al final del archivo
    datos->n = ftell(archivo); // Obtener la posición del puntero
    fseek(archivo, 0, SEEK_SET); // Mover el puntero al inicio del archivo

    /*
    ------------------------------------------------------------------------------
    // Contar Caracteres en un ARCHIVO SECUENCIAL de Texto

    datos->n = 0;
    int c;
    while ((c = fgetc(archivo)) != EOF) {
        datos->n++;
    }
    
    fseek(archivo, 0, SEEK_SET); // Mover el puntero al inicio del archivo

    -------------------------------------------------------------------------------------


    //Contar Líneas en un ARCHIVO SECUENCIAL de Texto

    datos->n = 0;
    int c;
    while ((c = fgetc(archivo)) != EOF) {
        if (c == '\n') {
            datos->n++;
        }
    }

    // Incrementar si el archivo no termina con una nueva línea
    fseek(archivo, -1, SEEK_END);
    if (fgetc(archivo) != '\n') {
        datos->n++;
    }
    ----------------------------------------------------------------------------------
    */
    


    datos->secuencia = (char *)malloc((datos->n + 1) * sizeof(char));  // Reservar memoria para el arreglo de caracteres
    if (datos->secuencia == NULL) {
        printf("Error al reservar memoria.\n");
        fclose(archivo);
        exit(EXIT_FAILURE);
    }

    size_t n = fread(datos->secuencia, sizeof(char), datos->n, archivo);  // Leer el archivo
    if (n != datos->n) {
        printf("Error al leer el archivo.\n");
        free(datos->secuencia);
        fclose(archivo);
        exit(EXIT_FAILURE);
    }

    datos->secuencia[datos->n] = '\0'; // Asegurarse de que la secuencia esté terminada en null
    fclose(archivo);
}

void EstimarSecuencia(DatosArchivo *datos) {
    for (size_t i = 0; i < datos->n; i++) {
        switch (datos->secuencia[i]) {
            case 'a':
                datos->secuencia[i] = 't';
                break;
            case 'c':
                datos->secuencia[i] = 'g';
                break;
            case 't':
                datos->secuencia[i] = 'a';
                break;
            case 'g':
                datos->secuencia[i] = 'c';
                break;
            default:
                break;
        }
    }
}

void *manejador(void *arg) {
    HiloArgs *args = (HiloArgs *)arg;
    DatosArchivo *datos = args->datos;

    leerArchivo(datos);
    EstimarSecuencia(datos);

    pthread_exit(NULL);
}

void CrearArchivo(DatosArchivo *datos, size_t n) {
    FILE *archivo = fopen("SecuenciaEstimada.txt", "w");
    if (archivo == NULL) {
        printf("Error al crear el archivo\n");
        exit(EXIT_FAILURE);
    }

    printf("Se ha creado el archivo SecuenciaEstimada.txt\n");
    for (size_t i = 0; i < n; i++) {
        fwrite(datos[i].secuencia, sizeof(char), datos[i].n, archivo);
    }
    fclose(archivo);
}

int main(int argc, char *argv[]) {
    DatosArchivo datos[N];
    HiloArgs args[N];

    for (int i = 0; i < N; i++) {
        datos[i].secuencia = NULL;
        datos[i].n = 0;
        args[i].datos = &datos[i];
        args[i].id = i;

        pthread_create(&hilos[i], NULL, manejador, (void *)&args[i]);
    }

    // Esperar a que todos los hilos terminen
    for (int i = 0; i < N; i++) {
        pthread_join(hilos[i], NULL);
    }

    // El hilo principal combina los resultados y escribe el archivo
    CrearArchivo(datos, N);

    // Liberar memoria asignada para el arreglo de caracteres
    for (int i = 0; i < N; i++) {
        if (datos[i].secuencia != NULL) {
            free(datos[i].secuencia);
        }
    }

    return 0;
}



