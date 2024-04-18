#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include<wait.h>

/*manejadores de señales para SIGUSR1 y SIGUSR2*/

    void sighandler1(int sig){
    
    }
    void sighandler2( int sig ){
    
    }
    
    void draw_tree(pid_t pid) { //muestra el árbol de procesos
    char command[50]; 
    sprintf(command, "pstree -Ulcp %d", pid);
    system(command);
}

    
int main(int argc, char *argv[]){

    pid_t pidp = getpid();

    //reserva memoria dinámica para un arreglo de dos elementos de tipo pid_t. 
    //Este arreglo pidsh se utilizará para almacenar los IDs de los procesos hijos.
    pid_t* pidsh = (pid_t*) malloc(sizeof(pid_t)*2);

    //almacenar los IDs de los procesos nietos.
    pid_t* pidsn = (pid_t*) malloc(sizeof(pid_t)*2);

    /*indicar que estos elementos aún no tienen un valor válido asignado.
    Se asignará el ID del proceso a cada elemento después de que se creen los procesos hijos y nietos.*/
    pidsh[0]= -1;
    pidsh[1]= -1;
    pidsn[0]= -1;
    pidsn[1]= -1;

    //almacenar el manejador de señal anterior para SIGUSR1
    void * oldhandler1;
    int n;
    
    printf("cuantas veces desea recorrer el ciclo?: ");
    scanf("%d",&n);

    
    /* manejador de señales para SIGUSR1. 
    el primer argumento es el número de la señal y el segundo argumento es el manejador de señal.
    La función signal() devuelve el manejador de señales anterior para la señal especificada.*/
    oldhandler1 = signal( SIGUSR1, sighandler1); 


    if(oldhandler1 == SIG_ERR){
        perror("signal:");exit(EXIT_FAILURE);  
    }

    int i;
    for(i=0; i<2;i++){  //Dos Hijos
        pidsh[i]=fork();
        if(pidsh[i]== 0 ){  //Nietos
            pidsn[i] = fork();
            break;
        }
    }


    if(pidp == getpid() && i ==2){  //Si es padre y creado los dos hijos
        draw_tree(getpid());  //Dibujar arbol
        printf("-----------------------------------------------------------\n");
        usleep(100);  //Padre Duerme
        printf("padre [%d]\n",getpid());  //ID padre

        for(int j = 0;j<n;j++){
            printf("-----------------------------------------------------------\n");
            kill(pidsh[1],SIGUSR1);  //Envía una señal SIGUSR1 al segundo proceso hijo
            pause();  //esperar hasta que reciba una señal.
            printf("padre [%d]\n",getpid());
        }
        for(int l = 0;l<2;l++){  //suspende la ejecución del proceso padre hasta que un hijo termine
            wait(NULL);
        }
        printf("termino el programa padre. \n");
    }
    else{
        if(pidsh[1] == 0 && getppid()==pidp && pidsn[1] != 0){  //SI Segundo Hijo,  SI ID padre es el original y SI nieto existe
            for(int j = 0;j<n;j++){
                pause();
                printf("hijo [%d]\n",getpid());
                kill(pidsn[1],SIGUSR1);
                pause();
                printf("hijo [%d]\n",getpid());
                kill(pidsh[0],SIGUSR1);
            }
            wait(NULL);
        }else{
            if(pidsh[0] == 0 && getppid()==pidp && pidsn[0] != 0){  //SI Primer Hijo, SI ID padre es el original y SI nieto existe
                for(int j = 0;j<n;j++){
                    pause();
                    printf("hijo [%d]\n",getpid());
                    kill(pidsn[0],SIGUSR1);
                    pause();
                    printf("hijo [%d]\n",getpid());
                    kill(getppid(),SIGUSR1);
                }
                wait(NULL);
            }else{
                if(pidsn[1] == 0 && getppid()!= pidp && pidsn[0] != 0 ){ //SI segundo Nieto, ID Padre es diferente 
                    for(int j = 0;j<n;j++){
                        pause();
                        printf("nieto [%d]\n",getpid());
                        kill(getppid(),SIGUSR1);
                    }
                }else{
                    if(pidsn[0] == 0 && getppid()!= pidp){  //SI primer Nieto, ID Padre es diferente 
                        for(int j = 0;j<n;j++){
                            pause();
                            printf("nieto [%d]\n",getpid());
                            kill(getppid(),SIGUSR1);
                        }
                    }
                    
                }
                
            }
            
        }
        
    }

    if(signal(SIGUSR1, oldhandler1) == SIG_ERR){
        perror("signal:");
        exit(EXIT_FAILURE);
    }

    
    return 0;
}