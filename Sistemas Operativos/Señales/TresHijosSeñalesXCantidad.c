#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h>

void *oldhandler;
void sighandler(int sig){
    printf("[%d]sig %d capturada\n", getpid(), sig);
}

#define n_hijos 3

int main(){
    pid_t pidhijo[n_hijos]; 
    int i, j, n, k;

    printf("Numero de Mensajes:?");
    scanf("%d", &n);

    oldhandler = signal(SIGUSR1, sighandler);
    if (oldhandler == SIG_ERR){
        perror("signal:");
        exit(EXIT_FAILURE);
    }

    int root = getpid();

    for (i = 0; i < n_hijos; i++){ //3 Hijos
        pidhijo[i] = fork(); 
        if (!pidhijo[i])
            break;
    }

    if (root == getpid()){  //Padre

        for (k = 0; k < n; k++){ //numero de mensajes
            usleep(10000);
            printf("Padre PID:[%d]\n", getpid());
            kill(pidhijo[n_hijos - 1], SIGUSR1); //Señal a cada Hijo
            pause();
            printf("Padre PID:[%d] finaliza\n", getpid());
        }
        for (j = 0; j < n_hijos; j++)  //espera a que todos los hijos terminen 
            wait(NULL);
    }

    else{ //Hijos

        for (k = 0; k < n; k++){  //Bucle por numero de mensajes
            pause();
            printf("hijo %d PID:[%d]\n",i+1, getpid());
            if (i != 0)
                kill(pidhijo[i - 1], SIGUSR1);  //Llama a su "hermano", Hijo3 al 2, 2 al 1
            else
                kill(getppid(), SIGUSR1); //El primer hijo llama al padre
        }
    }

    signal(SIGUSR1, oldhandler);

    return EXIT_SUCCESS;
}