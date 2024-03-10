#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Definición de un Nodo para la tabla hash
struct Nodo {
    int llave;
    int freq;
    struct Nodo* sig;
};

// Definición de la tabla hash
struct HashTable {
	int tamano;
    struct Nodo** tabla;
};

// Función para crear nueva tabla
struct HashTable* crearHashTable(int tamano) {
    struct HashTable* tabla = (struct HashTable*)malloc(sizeof(struct HashTable));
    tabla->tamano = tamano;
    tabla->tabla = (struct Nodo**)malloc(tamano * sizeof(struct Nodo*));
    int i;
    for (i = 0; i < tamano; i++) {
        tabla->tabla[i] = NULL;
    }
    return tabla;
}

// Función para liberar la memoria de la tabla hash
void liberarHashTable(struct HashTable* tabla) {
	int i;
    for ( i = 0; i < tabla->tamano; i++) {
        struct Nodo* actual = tabla->tabla[i];
        while (actual != NULL) {
            struct Nodo* siguiente = actual->sig;
            free(actual);
            actual = siguiente;
        }
    }
    free(tabla->tabla);
    free(tabla);
}

// Función que obtiene el para obtener el índice  (RECUERDA!!!!)
int hashFunction(int llave, int tamano) {
    return llave % tamano;
}

// Función para insertar un elemento en la tabla
void insert(struct HashTable* ht, int llave) {
    int index = hashFunction(llave, ht->tamano);
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->llave = llave;
    nuevoNodo->freq = 1;
    nuevoNodo->sig = NULL;

    if (ht->tabla[index] == NULL) {
        ht->tabla[index] = nuevoNodo;
    } else {
        struct Nodo* curr = ht->tabla[index];
        while (curr->sig != NULL) {
            if (curr->llave == llave) {
                curr->freq++;
                free(nuevoNodo); // Liberar el nodo ya que no se necesita
                return;
            }
            curr = curr->sig;
        }
        if (curr->llave == llave) {
            curr->freq++;
            free(nuevoNodo); // Liberar el nodo ya que no se necesita
        } else {
            curr->sig = nuevoNodo;
        }
    }
}

int main(int argc, char *argv[]) {
    // Abre el archivo
    FILE *file;
    file = fopen("test3.in", "rb");  
    
    if (file == NULL) {
        printf("Error al abrir el archivo\n");
        exit(1);
    } else {
        printf("1. Archivo abierto\n");
    }

    // Medir el tiempo de lectura del archivo
    struct timespec start_read, end_read;
    double elapsed_read;
    clock_gettime(CLOCK_MONOTONIC, &start_read);  //Busca por qué no se puede colocar CLOCK_MONOTONIC_RAW ¿es el contador más especifico?

    int size;
    fscanf(file, "%d", &size);

    // Crear la tabla hash
    struct HashTable* ht = crearHashTable(size);

    // Crear un array dinámico para almacenar los números del archivo
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Error al asignar memoria para el array\n");
        exit(1);
    } else {
    	printf("2. Memoria asignada\n");
	}

    // Insertar los elementos del archivo en el array y en la tabla hash
    int numero, i;
    double suma = 0;
    for (i = 0; i < size; i++) {
        fscanf(file, "%d", &numero);
        array[i] = numero; 
        insert(ht, numero); 
        suma += numero; 
    }

    fclose(file);  // OJO

    // Termina de medir el tiempo
    clock_gettime(CLOCK_MONOTONIC, &end_read);
    elapsed_read = (end_read.tv_sec - start_read.tv_sec) + ((end_read.tv_nsec - start_read.tv_nsec) / 1e9);

    // Encontrar el número que más se repite y cuántas veces se repite
    int maxFreq = 0;
    int mostFrequent = -1;
    for (i = 0; i < ht->tamano; i++) {
        struct Nodo *curr = ht->tabla[i];
        while (curr != NULL) {
            if (curr->freq > maxFreq) {
                maxFreq = curr->freq;
                mostFrequent = curr->llave;
            }
            curr = curr->sig;
        }
    }
    
    //VARIANZA ESTANDAR
    double media = (double)suma / size;
    double suma_cuadrados_diff = 0;
    
    for (i = 0; i < size; i++) {
        suma_cuadrados_diff += pow(array[i] - media, 2);  //POW: potencia
    }
    
    double varianza_estandar = sqrt(suma_cuadrados_diff / (size - 1));
    
    //MEDIANA
    int comparar(const void *a, const void *b) {
        return (*(int *)a - *(int *)b);
    }
    
    // Función de comparación para qsort
    qsort(array, size, sizeof(int), comparar);
    
    double mediana;
    
    if (size % 2 == 0) {
        mediana = (array[size/2 - 1] + array[size/2]) / 2.0;
    } else {
        mediana = array[size/2];
    }

    // Liberar la memoria asignada para el array (OJO)
    free(array);

	printf("------------------------------------------------\n");
    printf("Tiempo de lectura del archivo: %.9f segundos\n", elapsed_read);
    printf("Suma de los enteros del archivo: %ld\n", suma);
    printf("El numero que mas se repite es: %d, y se repite %d veces\n", mostFrequent, maxFreq);
    printf("Varianza estandar: %.2f\n", varianza_estandar);
    printf("La mediana es: %.2f\n", mediana);

    return EXIT_SUCCESS;
}



