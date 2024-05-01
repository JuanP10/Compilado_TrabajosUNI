#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*

                             (Padre)
                                |
                             (Hijo1) 

*/

int main(){
    
    pid_t child; //almacenar el ID del proceso hijo
    int estado;  //almacenar el estado de salida del proceso hijo
 
    child = fork(); //Crea hijo y El ID del proceso hijo se almacenará en la variable child

    if (child == 0) {  //Si es hijo
        sleep(1);
        printf("hijo: %d\n", getpid());  //Imprime PID su ID y retorna 15
        return 15;
    }
    else {  //Si es padre
        char b[50];
        sprintf(b,"pstree -lp %d",getpid());
        system(b);
        wait(&estado);  //Espera a que el proceso hijo termine su ejecución usando wait(&estado);

        if (WIFEXITED(estado))  //Verifica si el proceso hijo terminó normalmente. 

        //WIFEXITED es una macro que devuelve verdadero si el proceso hijo terminó normalmente,
        //es decir, si no fue interrumpido por una señal.

        printf("Padre: hijo pid %d cod.t: %d\n", child, WEXITSTATUS(estado));
        //Si el proceso hijo terminó normalmente, imprime el ID del proceso hijo y el código de salida del proceso hijo utilizando WEXITSTATUS(estado). 
        //El código de salida del proceso hijo se especificó mediante return en el paso 6.
    }
    return 0;

}