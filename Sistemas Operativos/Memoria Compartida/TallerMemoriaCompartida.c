#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <wait.h>
#include <signal.h>
#include <unistd.h>

void create_index(int **matrix, int rows, int cols, size_t sizeElement){
    size_t sizeRow = cols * sizeElement;
    matrix[0] = (int *)(matrix + rows);
    for (int i = 1; i < rows; i++){
        matrix[i] = (matrix[i - 1] + sizeRow);
    }
}

unsigned int sizeof_dm(int rows, int cols, size_t sizeElement){
    size_t size = rows * sizeof(void *); // indexSize
    size += (cols * rows * sizeElement); // datasize
    return size;
}

void sighandler(int sig){
}

int main(int argc, char const *argv[]){

    int Rows = atoi(argv[1]);
    int Cols = atoi(argv[2]);

    if (Rows <= 0 || Cols <= 0) {
        fprintf(stderr, "Las dimensiones de la matriz deben ser mayores que 0.\n");
        exit(EXIT_FAILURE);
    }
   
    double **matrix = NULL;
    size_t sizeMatrix = sizeof_dm(Rows, Cols, sizeof(double));
    
    int shmid = shmget(IPC_PRIVATE, sizeMatrix, IPC_CREAT|0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }
    
    matrix = shmat(shmid, NULL, 0);
    if (matrix == (void *)-1) {
        perror("shmat");
        shmctl(shmid, IPC_RMID, NULL);
        exit(1);
    }

    create_index((void*)matrix, Rows, Cols, sizeof(double));

    pid_t pidhijo = fork();

    switch (pidhijo){  //Verificar Error
    case -1:
        perror("fork");
        shmdt(matrix); 
        shmctl(shmid, IPC_RMID, NULL); 
        exit(EXIT_FAILURE);

    case 0: // hijo
        signal(SIGUSR1, sighandler); // Establecer el manejador de señales

        pause(); // Esperar la señal del padre

        printf("Hijo PID[%d] \n", getpid());


        for(int i=0 ; i<Rows ; i++){
            for(int j=0; j<Cols; j++){
                printf("%f ", matrix[i][j]);
            }
            printf("\n");
        }
        shmdt(matrix);

        break;

    default: // padre

        printf("Comienza Padre: PID[%d] \n", getpid());

        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < Cols; j++) {
                matrix[i][j] = i * Cols + j;
            }
        }

        kill(pidhijo, SIGUSR1); // Enviar señal al hijo para indicar que está listo para imprimir

        wait(NULL); // Esperar a que el hijo termine

        shmdt(matrix);
        shmctl(shmid, IPC_RMID, NULL);
        break;
    }

    return EXIT_SUCCESS;

}

