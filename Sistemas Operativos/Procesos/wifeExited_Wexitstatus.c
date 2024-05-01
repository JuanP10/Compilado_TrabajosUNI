#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main (void) {
    int estado;
    pid_t pidchild, pidwait;
    /*
    estado de salida del hijo (estado), 
    el ID del proceso hijo (pidchild) y
    el ID del proceso esperado (pidwait).
    */
    pidchild = fork();

    switch (pidchild) {
        case -1:
            perror("Error fork");
            exit(EXIT_FAILURE);

        case 0:  //Hijo
            sleep(1);
            exit(15);

        default:  //Padre
        char b[50];
        sprintf(b,"pstree -lp %d",getpid());
        system(b);

        pidwait = wait(&estado); 
        //espera a que cualquier proceso hijo termine su ejecución utilizando la función wait().
        //y almacenar el estado de salida del proceso hijo, o sea 15.

        if (pidwait != -1) {  //Verificación del wait
            if (WIFEXITED(estado)) { 
                // WIFEXITED es una macro que comprueba el estado de salida del procesos
                // y devuelve un valor distinto de cero si el proceso ha terminado
                // correctamente. Si el proceso no ha salido correctamente, entonces la macro
                // WIFEEXITED devuelve cero.
            printf("Hijo estado: %d\n", WEXITSTATUS(estado));
            }
        }
    }
    return EXIT_SUCCESS;
}