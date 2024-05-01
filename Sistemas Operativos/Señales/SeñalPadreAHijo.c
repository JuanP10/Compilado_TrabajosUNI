#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h>

void *oldhandler;
void sighandler(int sig){
    printf("[PID %d] : sig %d capturada\n", getpid(), sig);
}

int main(){
    pid_t pidhijo;

    pidhijo = fork();

    switch (pidhijo){  //Verificar Error
    case -1:
        perror("fork");
        exit(EXIT_FAILURE);

    case 0: // hijo
        oldhandler = signal(SIGUSR1, sighandler);

        if (oldhandler == SIG_ERR){ //Verificar Error
            perror("signal:");
            exit(EXIT_FAILURE);
        }

        pause();
        printf("Hijo [PID %d] : Terminando\n", getpid());

        if (signal(SIGUSR1, oldhandler) == SIG_ERR){ //Verificar Error
            perror("signal:");
            exit(EXIT_FAILURE);
        }
        break;

    default: // padre
        usleep(200);
        kill(pidhijo, SIGUSR1);
        printf("Padre [PID %d] : Señal enviada\n", getpid());
        wait(NULL);
    }

    return EXIT_SUCCESS;
}