#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

char *helicePrimaria;
char *heliceComplementaria;

struct nodo {
    int inicio;
    int final;
};


void *recorrerHelice(void *arg) {
    struct nodo* helice = (struct nodo*) arg;

    for (int i = helice->inicio; i < helice->final; i++) {
        switch (helicePrimaria[i]) {
            case 'a':
                heliceComplementaria[i] = 't';
                break;
            case 'c':
                heliceComplementaria[i] = 'g';
                break;
            case 't':
                heliceComplementaria[i] = 'a';
                break;
            case 'g':
                heliceComplementaria[i] = 'c';
                break;
            default:
                break;
        }
    }
    free(helice);
    pthread_exit(0);
}

int main(int argc, char *argv[]) {

    int nHilos = atoi(argv[2]);
    if (nHilos <= 0) {
        printf("debe ser mayo que 0.\n");
        return 1;
    }

    pthread_t tids[nHilos];
    int size;
    int rangoXHilo;
    
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error al abrir el archivo de entrada");
        return 1;
    }

    fscanf(file, "%d", &size);

    helicePrimaria = (char *) malloc((size + 1) * sizeof(char));
    heliceComplementaria = (char *) malloc((size + 1) * sizeof(char));

    for (int i = 0; i < size; i++) {
        fscanf(file, " %c", &helicePrimaria[i]);
    }

    fclose(file);

    rangoXHilo = size / nHilos;
    struct nodo *dato;

    for (int i = 0; i < nHilos; i++) {
        dato = (struct nodo *) malloc(sizeof(struct nodo));
        if (dato == NULL) {
            perror("Error en malloc");
            exit(EXIT_FAILURE);
        }
        dato->inicio = i * rangoXHilo;  
        dato->final = (i == nHilos - 1) ? size : (i + 1) * rangoXHilo;

        pthread_create(&tids[i], NULL, recorrerHelice, (void *)dato);
        usleep (100);
    }

    printf("Hilo principal[%lu]\n", pthread_self());

    for (int i = 0; i < nHilos; i++) {
        pthread_join(tids[i], NULL);
    }

    FILE *output = fopen("SecuenciaEstimada.txt", "w");
    if (!output) {
        perror("Error al abrir el archivo de salida");
        exit(EXIT_FAILURE);
    }

    fprintf(output, "%d\n", size);

    for (int i = 0; i < size; i++) {
        fprintf(output, "%c", helicePrimaria[i]);
        if ((i + 1) % 60 == 0) {
            fprintf(output, "\n");
        }
    }

    fprintf(output, "\n\n\n");

    for (int i = 0; i < size; i++) {
        fprintf(output, "%c", heliceComplementaria[i]);
        if ((i + 1) % 60 == 0) {
            fprintf(output, "\n");
        }
    }


    printf("Se ha creado el archivo SecuenciaEstimada.txt\n");

    fclose(output);
    free(helicePrimaria);
    free(heliceComplementaria);

    return EXIT_SUCCESS;
}
