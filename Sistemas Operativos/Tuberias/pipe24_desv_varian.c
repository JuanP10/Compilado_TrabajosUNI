#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <math.h>

#define MAX_BUF_SIZE 50
#define MAX_VEC_SIZE 30

typedef struct Data {
    int n;
    double array[MAX_VEC_SIZE];
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
            double num = 0.0;
            fscanf(file, "%lf", &num);
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

double calc_variance(const Data *data, double avg) {
    double total = 0.0;
    int i;
    for (i = 0; i < data->n; ++i) {
        double x = data->array[i];
        total += (x - avg)*(x - avg);
    }

    return total/data->n;
}

int main(int argc, char* arcv[]) {

    int fd01[2];
    int fd12[2];
    char buffer[MAX_BUF_SIZE];

    pipe(fd01);
    pipe(fd12);

    if (fork()) {
        int fd23[2];
        pipe(fd23);

        if (fork()) {

            int fd30[2];
            pipe(fd30);

            if (fork()) {
                close(fd01[0]);
                close(fd12[0]);
                close(fd12[1]);
                close(fd23[0]);
                close(fd23[1]);
                close(fd30[1]);

                printf("[%d] Soy el padre.\n", getpid());

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

                    double std_dev = read_double(fd30);
                    printf("[%d] La desviacion estandar es %.4f.\n", getpid(), std_dev);
                }

                wait(NULL);
            } else {
                close(fd01[0]);
                close(fd01[1]);
                close(fd12[0]);
                close(fd12[1]);
                close(fd23[1]);
                close(fd30[0]);

                printf("[%d] Soy el hijo #3 de [%d].\n", getpid(), getppid());

                double variance = read_double(fd23);

                double std_dev = sqrt(variance);

                write_double(fd30, std_dev);
            }

        } else {
            close(fd01[0]);
            close(fd01[1]);
            close(fd12[1]);
            close(fd23[0]);

            printf("[%d] Soy el hijo #2 de [%d].\n", getpid(), getppid());

            Data data;
            read_data(fd12, &data);
            double avg = read_double(fd12);

            double variance = calc_variance(&data, avg);

            write_double(fd23, variance);
        }
    } else {
        close(fd01[1]);
        close(fd12[0]);

        printf("[%d] Soy el hijo #1 de [%d].\n", getpid(), getppid());

        Data data;
        read_data(fd01, &data);

        double avg = calc_average(&data);

        write_data(fd12, &data);
        write_double(fd12, avg);
    }

    return 0;
}

/*
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <math.h>

#define MAX_BUF_SIZE 50
#define MAX_VEC_SIZE 30

typedef struct Data {
    int n;
    double array[MAX_VEC_SIZE];
} Data;

void write_data(int *fd, const Data *data) {
    if (write(fd[1], data, sizeof(Data)) == -1) {
        perror("Error al escribir en la tubería");
        exit(EXIT_FAILURE);
    }
}

void read_data(int *fd, Data *data) {
    if (read(fd[0], data, sizeof(Data)) == -1) {
        perror("Error al leer desde la tubería");
        exit(EXIT_FAILURE);
    }
}

void write_double(int *fd, double data) {
    if (write(fd[1], &data, sizeof(double)) == -1) {
        perror("Error al escribir en la tubería");
        exit(EXIT_FAILURE);
    }
}

double read_double(int *fd) {
    double data;
    if (read(fd[0], &data, sizeof(double)) == -1) {
        perror("Error al leer desde la tubería");
        exit(EXIT_FAILURE);
    }

    return data;
}

int read_file(const char *filename, double array[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    int n = 0;
    while (fscanf(file, "%lf", &array[n]) == 1) {
        n++;
        if (n >= MAX_VEC_SIZE) {
            fprintf(stderr, "El archivo tiene demasiados elementos\n");
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    return n;
}

double calc_average(const Data *data) {
    double total = 0.0;
    for (int i = 0; i < data->n; ++i) {
        total += data->array[i];
    }

    return total / data->n;
}

double calc_variance(const Data *data, double avg) {
    double total = 0.0;
    for (int i = 0; i < data->n; ++i) {
        double x = data->array[i];
        total += (x - avg) * (x - avg);
    }

    return total / data->n;
}

int main() {
    int fd01[2];
    int fd12[2];

    pipe(fd01);
    pipe(fd12);

    pid_t pid1 = fork();
    if (pid1 == -1) {
        perror("Error al crear el proceso hijo 1");
        exit(EXIT_FAILURE);
    } else if (pid1 == 0) {
        close(fd01[1]);
        close(fd12[0]);

        Data data;
        read_data(fd01, &data);

        double avg = calc_average(&data);

        write_data(fd12, &data);
        write_double(fd12, avg);

        close(fd01[0]);
        close(fd12[1]);
        _exit(EXIT_SUCCESS);
    }

    pid_t pid2 = fork();
    if (pid2 == -1) {
        perror("Error al crear el proceso hijo 2");
        exit(EXIT_FAILURE);
    } else if (pid2 == 0) {
        close(fd01[0]);
        close(fd01[1]);
        close(fd12[1]);

        Data data;
        double avg;
        read_data(fd12, &data);
        avg = read_double(fd12);

        double variance = calc_variance(&data, avg);

        int fd23[2];
        pipe(fd23);

        pid_t pid3 = fork();
        if (pid3 == -1) {
            perror("Error al crear el proceso hijo 3");
            exit(EXIT_FAILURE);
        } else if (pid3 == 0) {
            close(fd23[0]);

            double std_dev = sqrt(variance);

            write_double(fd23, std_dev);

            close(fd23[1]);
            _exit(EXIT_SUCCESS);
        } else {
            close(fd23[1]);

            wait(NULL);

            double std_dev = read_double(fd23);
            printf("La desviacion estandar es %.4f.\n", std_dev);

            close(fd23[0]);
            _exit(EXIT_SUCCESS);
        }
    }

    close(fd01[0]);
    close(fd12[0]);
    close(fd12[1]);

    Data data;
    int n = read_file("data.txt", data.array);
    data.n = n;

    write_data(fd01, &data);

    close(fd01[1]);
    close(fd12[0]);

    wait(NULL);
    wait(NULL);

    return 0;
}



*/