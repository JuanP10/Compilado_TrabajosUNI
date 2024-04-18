#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>


/*
El programa implementa la creación de procesos utilizando la llamada al sistema fork() y
la gestión de señales utilizando la función signal(). Además, muestra el árbol de procesos 
utilizando el comando pstree
*/


void send_signal(pid_t pid, int sig) {  //envía una señal a un proceso dado

#ifdef DEBUG
    printf("(%d) snd (%d) to %d\n", getpid(), sig, pid);
#endif
    usleep(10000);
    kill(pid, sig);
}

void handle_sigusrl(int sig) {  //maneja la señal SIGUSR1
#ifdef DEBUG
    pid_t pid = getpid();
    printf("Proceso %d recibió SIGUSR1\n", pid);
#endif
}

void draw_tree(pid_t pid) { //muestra el árbol de procesos
    char command[50]; 
    sprintf(command, "pstree -Ulcp %d", pid);
    system(command);
}

int main(int argc, char **argv) {
    int NUM_CHILDREN, i;
    pid_t *pids, pidpadre;

    if (argc != 2) {
        printf("Uso: %s <numprocess>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    NUM_CHILDREN = atoi(argv[1]);
    pids = (pid_t *)malloc(sizeof(pid_t) * (NUM_CHILDREN * 2));
    pidpadre = getpid();

    signal(SIGUSR1, handle_sigusrl);
    for (i = 0; i < NUM_CHILDREN; i++) {
        pids[i] = fork();
        if (pids[i] == 0) {
            pids[NUM_CHILDREN + i] = fork();
            printf("Proceso hijo %d (PID = %d) iniciado.\n", i, getpid());
            break;
        }
    }

    if (getpid() == pidpadre) {
        draw_tree(getpid());
        printf("Padre %d\n", getpid());
        send_signal(pids[NUM_CHILDREN - 1], SIGUSR1);
        pause();
        printf("Padre %d\n", getpid());
        for (int i = 0; i < NUM_CHILDREN; i++) {
            wait(NULL);
        }
    } else {
        pause();
        printf("Proceso %d\n", getpid());
        bool isParent = getppid() == pidpadre;
        send_signal(isParent ? pids[NUM_CHILDREN + i] : getppid(), SIGUSR1);
        if (isParent) {
            pause();
            printf("Proceso %d\n", getpid());
            send_signal(i > 0 ? pids[i - 1] : getppid(), SIGUSR1);
        }

        return EXIT_SUCCESS;
    }
}
