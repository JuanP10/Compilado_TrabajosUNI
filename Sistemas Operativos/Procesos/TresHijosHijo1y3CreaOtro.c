#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/*
                            (Padre)
                            /  |  \
                      (Hijo1)(Hijo2)(Hijo3)
                         |             |  
                    (Hijo1.1)      (Hijo3.1)     

*/

int main() {

    pid_t root = getpid();  //Identificar el padre

    for (int i = 0; i < 3; i++) {  //Tres Hijos
        if (fork() == 0) {
            if (i == 0 || i == 2) {  //Si es hijo 1 o 3 crea otro Hijo
                fork();
                for (int k = 0; k < 1; k++) {  //hace que el proceso espere a que alguno de sus hijos termine antes de continuar.
                    wait(NULL);
                }
            }
            break;
        }
    }

    if (root == getpid()) {    //Si es padre
        char b[50];
        sprintf(b,"pstree -lp %d",getpid());
        system(b);
        for (int j = 0; j < 3; j++) 
            wait(NULL);   //padre espera a que todos sus hijos terminen usando wait(NULL) tres veces 
                          //(una vez por cada nivel de procesos hijos creados).
        printf("Finalizando padre %d\n", getpid());
        
    }
    else{
        sleep(1); 
         printf("Finalizando hijo%d\n", getpid());

    }
        
    return EXIT_SUCCESS;
}