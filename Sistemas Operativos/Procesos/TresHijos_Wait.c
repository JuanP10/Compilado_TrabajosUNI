#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
/*
                             (Padre)
                            /   |    \
                      (Hijo1) (Hijo2) (Hijo3)
*/


int main(void) {
    pid_t root = getpid();  //ID del padre

    for (int i = 0; i < 3; i++) {  
        if (fork() == 0)   //3 hijos
            break;
    }
    if (root == getpid()) {    //Si es padre

        char b[50];
        sprintf(b,"pstree -lp %d",getpid());
        system(b);

        for (int j = 0; j < 3; j++)   //Espera que los hijos terminen e imprime el padre
            wait(NULL); 
            // Con la condicion NULL especifica que no necesita informacion
            // sobre el estado de los procesos hijos.
        printf("Finalizando padre %d\n", getpid());
        
    }
    else  //Hijos
        sleep(1);
        printf("Finalizando hijo%d\n", getpid());
    return EXIT_SUCCESS;
}