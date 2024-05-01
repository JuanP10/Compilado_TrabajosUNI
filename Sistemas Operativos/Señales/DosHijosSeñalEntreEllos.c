#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h>

void *oldhandler;

void sighandler(int sig) {}

int main(){

    pid_t pidhijo[2], root;
    int i, j;

    oldhandler = signal(SIGUSR1, sighandler);

    if (oldhandler == SIG_ERR){  //Verificar Error
        perror("signal:");
        exit(EXIT_FAILURE);
    }

    root = getpid();  //ID padre
    for (i = 0; i < 2; i++){  //Dos Hijos
        pidhijo[i] = fork();
        if (!pidhijo[i])  //Salimos de cada hijo
            break; 
    }



    if (root == getpid()){ //Padre
        printf("Padre: PID[%d]\n", getpid());
        usleep(10);
        kill(pidhijo[1], SIGUSR1);  
        pause(); //El proceso padre se pausa hasta que recibe una señal.
        for (j = 0; j < 2; j++)
            wait(NULL);   //Se espera a que ambos procesos hijos terminen utilizando wait().
        printf("Padre: PID[%d]\n", getpid());
    }
    else
    {
        pause(); //Hijo se pausa hasta que recibe una señal.
        if (i == 1){
            printf("hijo 2: PID[%d]\n", getpid());
            kill(pidhijo[0], SIGUSR1);        //envía una señal al primer hijo   
        }
        else{
            printf("hijo 1: PID[%d]\n", getpid());
            kill(getppid(), SIGUSR1);  //envía una señal al proceso padre 
            
        }
           
    }

    return EXIT_SUCCESS;
}
