#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[]){
	
	//1: Leer el archivo
	
	FILE *file;
	file = fopen("test1.in", "rb");
	if(file == NULL){
    printf("Error al abrir el archivo\n");
    exit(1);
	} else{
		printf("Archivo abierto\n");
	}
	//2: crear array y asignarle la memoria necesaria dependiento del tamaño del archivo		
	
	int size;
	int *array = NULL;
	
	// Medir el tiempo de lectura del archivo
    struct timespec start_read, end_read;
    double elapsed_read;
    clock_gettime(CLOCK_MONOTONIC, &start_read);
    
    
	fscanf(file, "%d", &size);
	
	//size_t fread(void *ptr, size_t size, size_t n, FILE *stream);
	
	array = (int *)malloc(size * sizeof(int)); 
	if(array == NULL) {
        printf("Error al asignar memoria\n");
        exit(1);
    }
	
	//3: Recorrer y agregar en cada espacio del array los números del archivo
	long int suma = 0;
	int i;
	for(i=0 ; i< size ; i++){
		fscanf(file, "%d", &array[i]);
		suma += array[i];
	}
	
	clock_gettime(CLOCK_MONOTONIC, &end_read);
    elapsed_read = (end_read.tv_sec - start_read.tv_sec) + ((end_read.tv_nsec - start_read.tv_nsec) / 1e9);
	
	
	struct timespec start, end;
	double elapsed;
	
	int iteraciones = 10000;
	int j;
	for (j=0 ; j<100; j++){
		clock_gettime(CLOCK_MONOTONIC, &start);
		clock_gettime(CLOCK_MONOTONIC, &end);
		elapsed += (end.tv_sec - start.tv_sec) + ((end.tv_nsec - start.tv_nsec));
	}
	
	elapsed /= iteraciones; 

	
	
	printf("Tiempo de lectura del archivo: %.9f segundos\n", elapsed_read);
	printf("Suma: %li\n", suma);
    printf("Tiempo de suma: %f segundos\n", elapsed);
    
	
	fclose(file);
	free(array);
	
	
	return EXIT_SUCCESS;
}
