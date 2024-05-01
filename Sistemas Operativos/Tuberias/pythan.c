#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

#define TABLE_SIZE 10000

struct timespec start, end;

int *maximum(int *, int size);

int main(int argc, char *argv[]){
    FILE *file = NULL;
    clock_gettime(CLOCK_REALTIME, &start);
    file = fopen("archivo_entrada.txt", "r");
    if (file == NULL)
    {
        printf("Hubo un error");
        exit(-1);
    }
    int size;
    int n_proc = atoi(argv[2]);
    int i;

    int *table = calloc(TABLE_SIZE, sizeof(int));
    fscanf(file, "%d", &size);
    int *array = malloc(size * sizeof(int));

    for (int j = 0; j != size; ++j)
    {
        fscanf(file, "%d", &array[j]);
        table[array[j]] += 1;
    }

    fclose(file);

    if (array == NULL)
    {
        printf("Hubo un error");
        exit(-1);
    }

    // Create array bidimentional pipes
    int **pipes = (int **)malloc(n_proc * sizeof(int *));

    for (int j = 0; j != n_proc; j++){
        pipes[j] = (int *)malloc(2 * sizeof(int));
    }

    for (i = 0; i < n_proc; i++){
        pipe(pipes[i]); // create a pipe per child
        if (fork() == 0)
        {
            for (int j = 0; j <= i; ++j) // close the reading channel for each child
                close(pipes[j][0]);
            break;
        }
        close(pipes[i][1]);
    }

    long int sum = 0;

    if (i < n_proc)
    {
        int delta = size / n_proc;
        int inicio = delta * i;
        int fin = inicio + delta - 1;
        for (int j = inicio; j <= fin; j++)
        {
            sum += array[j];
        }

        write(pipes[i][1], &sum, sizeof(sum));
        free(array);
    }

    else
    {
        for (int j = 0; j != n_proc; j++)
            wait(NULL);

        for (int j = 0; j != n_proc; ++j)
        {
            long int received;
            read(pipes[j][0], &received, sizeof(received));
            sum += received;
        }

        printf("La suma es: %ld\n", sum);
        int *max = maximum(table, TABLE_SIZE);
        printf("(%d, %d)\n", max[1], max[0]);

        free(array);
        free(max);
        free(table);

        clock_gettime(CLOCK_REALTIME, &end);

        double elapsed =
            (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec);

        printf("EL tiempo es: %f seg\n", elapsed / 1e9);
    }

    return 0;
}

int *maximum(int *table, int size)
{
    int *values = malloc(2 * sizeof(int));
    values[0] = table[0];
    for (int i = 1; i != size; ++i)
    {
        if (table[i] > values[0])
        {
            values[0] = table[i];
            values[1] = i;
        }
    }

    return values;
}