#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <wait.h>
#include <time.h>
#include <string.h>

/*
 el proceso padre recibe líneas de texto de dos archivos diferentes a través de tuberías y las imprime en la consola.
 Los hijos son responsables de leer los archivos y enviar las líneas al padre. 
 Una vez que ambos hijos han terminado de enviar todas las líneas, el padre finaliza su ejecución.

 Padre - Dos Hijos

*/

int main( int argc, char **argv ){
    //declarando los datos que utilizaremos para guardar los pids
    pid_t pidp = getpid();
    pid_t* pidsh = (pid_t*) malloc(sizeof(pid_t)*2);
    pidsh[0]= -1;
    pidsh[1]= -1;
    //declarando las tuberias
    int p1[2],p2[2], n;
    //creando las tuberias
    pipe( p1 );
    pipe( p2 );
    //declarando los bufers de lectura y escritura
   char Buffer1_out[100];
   char Buffer1_in[100];
   char Buffer2_out[100];
   char Buffer2_in [100];
    //creando los hijos 
    int i;
    for(i=0;i<2;i++){
        pidsh[i]=fork();
        if(pidsh[i] == 0 ){
            break;
        }
    }
    //creando la logica para cada proceso
    if(pidp == getpid() && i == 2){
        close(p1[1]);//cerramos el lado de escritura del pipe1
        close(p2[1]);//cerramos el lado de escritura del pipe2
        //logica del padre
        while(1){
            n = read(p1[0], Buffer1_in, sizeof(Buffer1_in));
            n = read(p2[0], Buffer2_in, sizeof(Buffer2_in));
            char var[1] = "@";
            if(Buffer1_in[0] == var[0] && Buffer2_in[0] == var[0]){
                break;
            }else{
                if(Buffer1_in[0] == var[0]){
                    printf("%s \n",Buffer2_in);
                }else{
                    if(Buffer2_in[0] == var[0]){
                        printf("%s \n",Buffer1_in);
                    }else{
                        printf("%s \n",Buffer1_in);
                        printf("%s \n",Buffer2_in);
                    }
                }
            }
        }
        //cerrando las pipes restantes
        close(p1[0]);//cerramos el lado de lectura del pipe1
        close(p2[0]);//cerramos el lado de lectura del pipe2
        //esperando los hijos
        for(i=0;i<2;i++){
            wait(NULL);
        }
        //terminando el programa
        printf("terminando el padre .... \n");
        
    }else{
        if(pidsh[0] == 0){
            //cerramos todas las entradas de la tuberia 1 y 2
            close(p2[1]);//cerramos el lado de escritura del pipe2
            close(p2[0]);//cerramos el lado de lectura del pipe2
            close(p1[0]);//cerramos el lado de lectura del pipe1

            //logica del primer hijo
            FILE *file1 = fopen("text1.txt", "r");
            if (file1 == NULL) {
                perror("Error al abrir el primer archivo");
                exit(EXIT_FAILURE);
            }
            while (fgets(Buffer1_out, 100, file1)){
                // Aquí, justo ahora, tenemos ya la línea. Le vamos a remover el salto
                strtok(Buffer1_out, "\n");
                // La imprimimos, pero realmente podríamos hacer cualquier otra cosa
                write(p1[1],Buffer1_out,sizeof(Buffer1_out));
            }
            strcpy(Buffer1_out, "@");
            write(p1[1],Buffer1_out,sizeof(Buffer1_out));
            //cerrando las pipes restantes
            close(p1[1]);//cerramos el lado de escritura del pipe1
            //terminando el programa
            exit(0);
        }
        else{
            if(pidsh[1] == 0){
                //cerramos todas las entradas de la tuberia 1 y 2
                close(p1[1]);//cerramos el lado de escritura del pipe1
                close(p1[0]);//cerramos el lado de lectura del pipe1
                close(p2[0]);//cerramos el lado de lectura del pipe2
                //logica del segundo hijo
                FILE *file2 = fopen("text2.txt", "r");
                if (file2 == NULL) {
                    perror("Error al abrir el primer archivo");
                    exit(EXIT_FAILURE);
                }
                while (fgets(Buffer2_out, 100, file2)){
                    // Aquí, justo ahora, tenemos ya la línea. Le vamos a remover el salto
                    strtok(Buffer2_out, "\n");
                    // La imprimimos, pero realmente podríamos hacer cualquier otra cosa
                    write(p2[1],Buffer2_out,sizeof(Buffer2_out));
                }
                strcpy(Buffer2_out, "@");
                write(p2[1],Buffer2_out,sizeof(Buffer2_out));
                //cerrando las pipes restantes
                close(p2[1]);//cerramos el lado de escritura del pipe2
                //terminando el programa
                exit(0);
            }
        }
    }
    return 0;
}