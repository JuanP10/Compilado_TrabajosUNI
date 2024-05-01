#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <math.h>
/*
Ver(6552)─┬─Ver(6553)
          ├─Ver(6554)
          ├─Ver(6555)

Padre lee data y exribe resultados
Hijo1 Media
Hijo2 Más grande
Hijo3 Más repetido


*/
#define MAX_BUF_SIZE 50
#define MAX_VEC_SIZE 30

typedef struct Data {
    int n;
    int array[MAX_VEC_SIZE];
} Data;

void write_data(int *fd, const Data *data) {
    write(fd[1], data, sizeof(Data));
}

void read_data(int *fd, Data *data) {
    read(fd[0], data, sizeof(Data));
}

void write_double(int *fd, double data) {
    write(fd[1], &data, sizeof(double));
}

double read_double(int *fd) {
    double data;
    read(fd[0], &data, sizeof(double));

    return data;
}

int read_file(const char *filename, double array[]) {
    FILE *file = fopen(filename, "r");

    if (file) {
        int n = 0;
        while(!feof(file)) {
            int num = 0.0;
            fscanf(file, "%d", &num);
            array[n++] = num;
        }

        fclose(file);

        return n - 1;
    }

    return 0;
}

double calc_average(const Data *data) {
    double total = 0.0;
    int i;
    for (i = 0; i < data->n; ++i) {
        total += data->array[i];
    }

    return total/data->n;
}

int calc_greater(const Data *data) {
    int greater = data->array[0];
    int i = 1;
    for (; i < data->n; ++i) {
        if (data->array[i] > greater) {
            greater = data->array[i];
        }
    }

    return greater;
}

int calc_repeated(const Data *data) {
    int n = data->n;
    const int *array = data->array; // Array de enteros constantes
    int vector[n]; // Nuevo arreglo de enteros
    memcpy(vector, array, sizeof(int) * n); // Copiar el contenido del arreglo constante al nuevo arreglo

    int aux[n][2];

    int c = 0;

    int i = 0;
    for (; i < n; ++i) {
        int j = 0;
        for (; j < c; ++j) {
            if (aux[j][0] == vector[i]) {
                aux[j][1]++;
                break;
            }
        }

        if (j == c) {
            aux[c][0] = vector[i];
            aux[c][1] = 1;
            c++;
        }
    }

    int max_repeats = aux[0][1];
    int most_repeated = aux[0][0];

    for (i = 1; i < c; ++i) {
        if (aux[i][1] > max_repeats) {
            max_repeats = aux[i][1];
            most_repeated = aux[i][0];
        }
    }

    return most_repeated;
}



int main(int argc, char* arcv[]) {

    int fd01[2];
    int fd10[2];

    pipe(fd01);
    pipe(fd10);

    if (fork()) {
        int fd02[2];
        int fd20[2];
        pipe(fd02);
        pipe(fd20);

        if (fork()) {

            int fd03[2];
            int fd30[2];
            pipe(fd03);
            pipe(fd30);

            if (fork()) {
                close(fd01[0]);
                close(fd10[1]);
                close(fd02[0]);
                close(fd20[1]);
                close(fd03[0]);
                close(fd30[1]);

                printf("[%d] Soy el padre.\n", getpid());

                char b[50];
                sprintf(b,"pstree -lp %d",getpid());
                system(b);
                
                    
                
                double array[MAX_VEC_SIZE];
                int n = read_file("data.txt", array);
                if (n == 0) {
                    printf("No se pudo leer el archivo\n");
                } else {
                    printf("El archivo fue leido\n");
                    Data data;
                    data.n = n;

                    int i;
                    for (i = 0; i < n; ++i) {
                        data.array[i] = array[i];
                    }

                    write_data(fd01, &data);
                    write_data(fd02, &data);
                    write_data(fd03, &data);

                    double avg = read_double(fd10);
                    double greater = read_double(fd20);
                    double repeated = read_double(fd30);

                    printf("[%d] La media es %.4f.\n", getpid(), avg);
                    printf("[%d] El numero mayor es %.4f.\n", getpid(), greater);
                    printf("[%d] El numero mas repetido es %.4f.\n", getpid(), repeated);

                    
                }

                wait(NULL);
            } else {
                close(fd01[0]);
                close(fd01[1]);
                close(fd10[0]);
                close(fd10[1]);
                close(fd02[0]);
                close(fd02[1]);
                close(fd20[0]);
                close(fd20[1]);
                close(fd03[1]);
                close(fd30[0]);

                printf("[%d] Soy el hijo #3 de [%d].\n", getpid(), getppid());

                sleep(1); 

                Data data;
                read_data(fd03, &data);

                double repeated = calc_repeated(&data);

                write_double(fd30, repeated);
            }

        } else {
            close(fd01[0]);
            close(fd01[1]);
            close(fd10[0]);
            close(fd10[1]);
            close(fd02[1]);
            close(fd20[0]);

            printf("[%d] Soy el hijo #2 de [%d].\n", getpid(), getppid());

            sleep(1); 

            Data data;
            read_data(fd02, &data);

            double greater = calc_greater(&data);

            write_double(fd20, greater);
        }
    } else {
        close(fd01[1]);
        close(fd10[0]);

        printf("[%d] Soy el hijo #1 de [%d].\n", getpid(), getppid());

        sleep(1); 

        Data data;
        read_data(fd01, &data);

        double avg = calc_average(&data);

        write_double(fd10, avg);
    }

    return 0;
}