#include <stdlib.h>
#include <stdio.h>
#include <wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

/*
                         _______Padre________
                        |                   |
                      Hijo1                HijoN
                        |                   |
                        |________Hijo2______|



*/

int main(int argc, char const *argv[]) {
    //Anillo de tubos
    pid_t *pr1hjs  , padre = getpid(), destinatario; //ID  procesos Hijos, padre Mensaje
    int **pd, nHijos, i,        flag;  // posición de los procesos en el anillo de tuberías
    int size;
    char mensaje[100];
    

    printf("Cuantos Hijos: ");
    scanf("%d", &nHijos);

    pr1hjs = (pid_t*) malloc(nHijos*sizeof(pid_t));  //casting de puntero a pid_t
    pd = (int**) malloc((nHijos+1)*sizeof(int*));

    for (i = 0; i <= nHijos; i++) //Creamos memoria a cada descriptor de archivo (Eso de 0 y 1) para leer y escribir
        pd[i] = (int *) malloc (2*sizeof(int)); 

    for(int i = 0; i < (nHijos+1); i++)  //Creamos los tubos
        pipe(pd[i]);

    for(i = 0; i < nHijos; i++) {  //Creamos los procesos
        pr1hjs[i] = fork();
        if(pr1hjs[i] == 0) {   //hijo recién creado
            flag = i+2;
            break;
        }
    }

    if(padre == getpid()) {
        
        printf("Ingrese el mensaje que desea mandar: ");
        scanf("%s", &mensaje);
        printf("El mensaje en el padre es %s y mi id es %d\n", mensaje, getpid());

        close(pd[0][0]);        //Cierra el extremo de lectura de la primera tubería
        close(pd[nHijos][1]);   //Cierra el extremo de Escritura de la ultima tubería

        for(int i = 1; i < nHijos; i++) {  //Cierra todos los otros tubos
            close(pd[i][0]);
            close(pd[i][1]);
        }



        int size2 = strlen(mensaje);  //Devuelve la longitud de una cadena de texto
        int size3;
        int idEnviar = padre;  //Guarda el ID del padre
 
        write(pd[0][1], &size2, sizeof(int));  //escribe en la tubería el tamaño del mensaje.
        write(pd[0][1], &mensaje, size2);    //escribe en la tubería el contenido del mensaje
        write(pd[0][1], &idEnviar, sizeof(int));  // escribe en la tubería el identificador de proceso del remitente

        read(pd[nHijos][0], &size3, sizeof(int));         //tamaño del mensaje que ha sido modificado por el último hijo
        read(pd[nHijos][0], &mensaje, size3);             //lee desde la tubería elmensaje 
        read(pd[nHijos][0], &destinatario, sizeof(int));  //Lee el PID 

        printf("El mensaje en el padre es %s y mi id es %d y el que lo envio fue %d\n", mensaje, getpid(), destinatario);

    }
    else {

        close(pd[flag-2][1]);    //Cierra el extremo de escritura de la tubería anterior al proceso actual en el anillo
        close(pd[flag-1][0]);   //Cierra el extremo de lectura de la tubería siguiente al proceso actual en el anillo

        for(int i = 0; i < (nHijos+1); i++) {  //Cierra todos los demás tubos
                if(i != flag-2 && i != flag-1){
                    close(pd[i][0]);
                    close(pd[i][1]);
                }
        }

        

        //identificador del proceso hijo actual a idEnviar. 
        int idEnviar = (int) getpid();
 
        read(pd[flag-2][0], &size, sizeof(int));          // Lee el tamaño del mensaje de la tubería anterior.
        read(pd[flag-2][0], &mensaje, size);              // Lee el mensaje
        read(pd[flag-2][0], &destinatario, sizeof(int));  // Lee el ID

        printf("El mensaje en el hijo es %s y mi id es %d y el que lo envio fue %d\n", mensaje, getpid(), destinatario);

        write(pd[flag-1][1], &size, sizeof(int));  //Tamaño del mensaje
        write(pd[flag-1][1], &mensaje, size);      //Escribe el mensaje
        write(pd[flag-1][1], &idEnviar, sizeof(int));  //Escribe el ID
    }

    if(padre==getpid()){  //Si es padre
    //Creamos el arbol 
    char b[50];
    sprintf(b,"pstree -lp %d",getpid());
    system(b);
    }else{
        sleep(1);  //Tener tiempo que el padre imprima el arbol
    }

    free(pr1hjs);
    free(pd);
    
    return 0;
}