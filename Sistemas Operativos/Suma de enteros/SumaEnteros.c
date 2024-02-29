/* NOTA: RECUERDA TERMINAR LA VARIACI�N ESTANDAR, VARIANZA Y MEDIANA */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HASH_SIZE 100000   //Aqu� puede estar el error de la suma del test.3  (BUSCAAA)

// Definici�n de un Nodo para la tabla hash

struct Nodo {
    int llave;
    int freq;
    struct Nodo* sig;
};

// Definici�n de la tabla hash

struct HashTable {
    struct Nodo* tabla[HASH_SIZE];
};

// Funci�n para crear un nuevo Nodo

struct Nodo* createNodo(int llave) {
    struct Nodo* newNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    newNodo->llave = llave;
    newNodo->freq = 1;
    newNodo->sig = NULL;
    return newNodo;
}

// Funci�n que obtiene el para obtener el �ndice  (RECUERDA!!!!)

int hashFunction(int llave) {
    return llave % HASH_SIZE;
}

// Funci�n para insertar un elemento en la tabla

void insert(struct HashTable* ht, int llave) {
    int index = hashFunction(llave);
    if (ht->tabla[index] == NULL) {
        ht->tabla[index] = createNodo(llave);
    } else {
        struct Nodo* curr = ht->tabla[index];
        while (curr->sig != NULL) {
            if (curr->llave == llave) {
                curr->freq++;
                return;
            }
            curr = curr->sig;
        }
        if (curr->llave == llave) 
            curr->freq++;
        else 
            curr->sig = createNodo(llave);
        
    }
}

int main(int argc, char *argv[]) {
	
    // Abre el archivo
    
    FILE *file;
    file = fopen("test2.in", "rb");  //El test 1 y 2 sirve, pero la suma de enteros en el 3 sale negativo (BUSCAAA!!)
    
    if (file == NULL) {
        printf("Error al abrir el archivo\n");
        exit(1);
    } else {
        printf("1. Archivo abierto\n");
    }

    // Medir el tiempo de lectura del archivo
    
    struct timespec start_read, end_read;
    double elapsed_read;
    clock_gettime(CLOCK_MONOTONIC, &start_read);  //Busca por qu� no se puede colocar CLOCK_MONOTONIC_RAW �es el contador m�s especifico?

    int size;
    fscanf(file, "%d", &size);

    // Crear la tabla hash
    struct HashTable ht;
    int i;
    for (i = 0; i < HASH_SIZE; i++) {
        ht.tabla[i] = NULL;
    }

    // Crear un array din�mico para almacenar los n�meros del archivo
    
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Error al asignar memoria para el array\n");
        exit(1);
    }else
    	printf("2. Memoria asignada\n");

    // Insertar los elementos del archivo en el array y en la tabla hash
    int numero;
    long suma = 0;
    for (i = 0; i < size; i++) {
        fscanf(file, "%d", &numero);
        array[i] = numero; 
        insert(&ht, numero); 
        suma += numero; 
    }

	fclose(file);  // OJO
	
    // Termina de medir el tiempo
    
    clock_gettime(CLOCK_MONOTONIC, &end_read);
    elapsed_read = (end_read.tv_sec - start_read.tv_sec) + ((end_read.tv_nsec - start_read.tv_nsec) / 1e9);

    // Encontrar el n�mero que m�s se repite y cu�ntas veces se repite
    
    int maxFreq = 0;
    int mostFrequent = -1;
    for (i = 0; i < HASH_SIZE; i++) {
        struct Nodo *curr = ht.tabla[i];
        while (curr != NULL) {
            if (curr->freq > maxFreq) {
                maxFreq = curr->freq;
                mostFrequent = curr->llave;
            }
            curr = curr->sig;
        }
    }

    // Liberar la memoria asignada para el array (OJO)
    
    free(array);

	printf("------------------------------------------------\n");
    printf("Tiempo de lectura del archivo: %.9f segundos\n", elapsed_read);
    printf("Suma de los enteros del archivo: %ld\n", suma);
    printf("El numero que mas se repite es: %d, y se repite %d veces\n", mostFrequent, maxFreq);

    return EXIT_SUCCESS;
}



