#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int count = 0;  //contar el número de veces que se recibe la señal SIGINT.

void *oldhandler; //puntero para almacenar el manejador de señales anterior.

void sighandler(int sig){ // incrementa el valor de count cada vez que se llama
    count++;
}

int main(){
    /*
    Establece el manejador de señales para SIGINT usando la función signal(). 
    El manejador de señales será la función sighandler. 
    El valor de retorno de signal() (el manejador de señales anterior) se almacena en oldhandler
    */
    oldhandler = signal(SIGINT, sighandler);

    if (oldhandler == SIG_ERR){ //Verifica si hubo un error al establecer el manejador de señales.
        perror("signal:");
        exit(EXIT_FAILURE);
    }

    printf("[%d]\n", getpid()); //Imprime el PID (identificador de proceso) del proceso actual.

    /*
     Imprime el número de veces que se ha recibido la señal SIGINT (Ctrl+C). 
     Hace que el programa espere 1 segundo antes de continuar con la siguiente iteración del bucle.
     */
    do{
        printf("\n %d veces SIGINT recibida\n", count);
        sleep(3);
    } while (1);


    //Verificar error
    if (signal(SIGUSR1, oldhandler) == SIG_ERR){
        perror("signal:");
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}