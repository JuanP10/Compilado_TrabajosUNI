#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <wait.h>


/*

                                ____________Padre____________
                                |             |             |
                               Hijo1        Hijo2         Hijo3
                                |             |             |
                               Nieto1       Nieto2        Nieto3
                                              |
                                            Bisnieto
                                              |
                                          Tataranieto


*/

pid_t* pidshijos;
pid_t* pidsnietos;

void sighandler(int sig) {
    printf("Proceso %d padre %d\n", getpid(), getppid());
    if (getpid() == pidshijos[0] || getpid() == pidsnietos[0] || getpid() == pidsnietos[2]) {
        kill(getppid(), SIGUSR1);
    }
}


void draw_tree(pid_t pid) { //muestra el árbol de procesos
    char command[50]; 
    sprintf(command, "pstree -Ulcp %d", pid);
    system(command);
}

int main(int argc, char *argv[]) {
    

    int i;
    pid_t pidpadre = getpid();

    //hijos.
    pid_t* pidshijos = (pid_t*) malloc(sizeof(pid_t)*3);

    //nietos.
    pid_t* pidsnietos = (pid_t*) malloc(sizeof(pid_t)*3);

    //Bisnieto
    pid_t* pidsBisnieto = (pid_t*) malloc(sizeof(pid_t));

    //Tataranieto
    pid_t* pidsTataranieto = (pid_t*) malloc(sizeof(pid_t));


    pidshijos[0]= -1;
    pidshijos[1]= -1;
    pidshijos[2]=-1;

    pidsnietos[0]= -1;
    pidsnietos[1]= -1;
    pidsnietos[2]= -1;

    pidsBisnieto[0]=-1;


    pidsTataranieto[0]=-1;

    signal(SIGUSR1, sighandler);

    //almacenar el manejador de señal anterior para SIGUSR1
    void * oldhandler1;

    oldhandler1 = signal( SIGUSR1, sighandler); 


    if(oldhandler1 == SIG_ERR){
        perror("signal:");exit(EXIT_FAILURE);  
    }


    for (i = 0; i < 3; i++) { 
    pidshijos[i] = fork();
    if (pidshijos[i] < 0) {
        // Error al crear el proceso hijo
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pidshijos[i] == 0) { // Proceso hijo
        if (i == 0) {
            pidsnietos[i] = fork();
            if (pidsnietos[i] < 0) {
                // Error al crear el proceso nieto
                perror("fork");
                exit(EXIT_FAILURE);
            } else if (pidsnietos[i] == 0) { // Proceso nieto
                printf("Nieto 1 [%d]\n", getpid());
                exit(EXIT_SUCCESS);
            }
        } else if (i == 1) {
            pidsnietos[i] = fork();
            if (pidsnietos[i] < 0) {
                // Error al crear el proceso nieto
                perror("fork");
                exit(EXIT_FAILURE);
            } else if (pidsnietos[i] == 0) { // Proceso nieto
                printf("Nieto 2 [%d]\n", getpid());
                pidsBisnieto[0] = fork();
                if (pidsBisnieto[0] < 0) {
                    // Error al crear el proceso bisnieto
                    perror("fork");
                    exit(EXIT_FAILURE);
                } else if (pidsBisnieto[0] == 0) { // Proceso bisnieto
                    printf("Bisnieto [%d]\n", getpid());
                    pidsTataranieto[0] = fork();
                    if (pidsTataranieto[0] < 0) {
                        // Error al crear el proceso tataranieto
                        perror("fork");
                        exit(EXIT_FAILURE);
                    } else if (pidsTataranieto[0] == 0) { // Proceso tataranieto
                        printf("Tataranieto [%d]\n", getpid());
                        exit(EXIT_SUCCESS);
                    }
                }
            }
        } else { // i == 2
            pidsnietos[i] = fork();
            if (pidsnietos[i] < 0) {
                // Error al crear el proceso nieto
                perror("fork");
                exit(EXIT_FAILURE);
            } else if (pidsnietos[i] == 0) { // Proceso nieto
                printf("Nieto 3 [%d]\n", getpid());
                exit(EXIT_SUCCESS);
            }
        }
    }
}



    if (pidpadre == getpid() && i == 3) {
        draw_tree(getpid());
        printf("-----------------------------------------------------------\n");
        usleep(100);
        printf("padre [%d]\n", getpid());

        // Esperar señales de los hijos
        for (int j = 0; j < 3; j++) {
            pause(); // Esperar señal del hijo
            printf("padre [%d]\n", getpid());
        }

        // Esperar a que los hijos terminen
        for (int l = 0; l < 3; l++) {
            wait(NULL);
        }

        printf("termino el programa padre.\n");
    }


    

    else{

        if(pidshijos[1] == 0 && getppid()==pidpadre && pidsnietos[1] != 0){  //SI Segundo Hijo,  SI ID padre es el original y SI nieto existe
            for(int j = 0;j<3;j++){
                pause();
                printf("nieto 2 [%d]\n",getpid());
                kill(pidsnietos[1],SIGUSR1);
                pause();
                printf("hijo 1 [%d]\n",getpid());
                kill(pidshijos[0],SIGUSR1);
            }
            wait(NULL);
        }
        
        
        
        
        else{




            if(pidshijos[0] == 0 && getppid()==pidpadre && pidsnietos[0] != 0){  //SI Primer Hijo, SI ID padre es el original y SI nieto existe
                for(int j = 0;j<3;j++){
                    pause();
                    printf("Nieto 1 [%d]\n",getpid());
                    kill(pidsnietos[0],SIGUSR1);
                    pause();
                    printf("padre [%d]\n",getpid());
                    kill(getppid(),SIGUSR1);
                }
                wait(NULL);
            }
            
            
            
            
            if(pidshijos[2] == 0 && getppid()==pidpadre && pidsnietos[0] != 0){  //SI Tercer Hijo, SI ID padre es el original y SI nieto existe
                for(int j = 0;j<3;j++){
                    pause();
                    printf("nieto 2 [%d]\n",getpid());
                    kill(pidsnietos[2],SIGUSR1);
                    pause();
                    printf("hijo 2 [%d]\n",getpid());
                    kill(pidshijos[1],SIGUSR1);
                }
                wait(NULL);
            }



            else{




               if(pidsnietos[2] == 0 && getppid()!= pidpadre && pidsnietos[0] != 0 ){  //Tercer Nieto
                        pause();
                        printf("hijo 3 [%d]\n",getpid());
                        kill(pidshijos[2],SIGUSR1);
                    }

                }
                if(pidsnietos[0] == 0 && getppid()!= pidpadre && pidsnietos[0] != 0 ){  //Primer nieto
                        pause();
                        printf("hijo 1 [%d]\n",getpid());
                        kill(pidshijos[0],SIGUSR1);
                }
                
                else{
                    if(pidsnietos[1] == 0 && getppid()!= pidpadre && pidsnietos[0] != 0 ){ //Segundo Nieto, ID Padre es diferente 
                        pause();
                        printf("bisnieto [%d]\n",getpid());
                        kill(pidsBisnieto[0],SIGUSR1);
                        pause();
                        printf("hijo 2 [%d]\n",getpid());
                        kill(pidshijos[1],SIGUSR1);

                    }
                        if(pidsBisnieto[0] == 0 && getppid()!= pidpadre){  //SI bisnieto
                            pause();
                            printf("tataranieto [%d]\n",getpid());
                            kill(pidsTataranieto[0],SIGUSR1);
                            pause();
                            printf("nieto 2 [%d]\n",getpid());
                            kill(pidsnietos[1],SIGUSR1);


                        }
                        else if(pidsTataranieto[0] == 0 && getppid()!= pidpadre){  //Si es Tataranieto
                            pause();
                            printf("Bisnieto [%d]\n",getpid());
                            kill(pidsBisnieto[0],SIGUSR1);
                        }
                            
                    
                    
                    
             }
                    
                
            
            
        }
        
    }

    if(signal(SIGUSR1, oldhandler1) == SIG_ERR){
        perror("signal:");
        exit(EXIT_FAILURE);
    }


    return EXIT_SUCCESS;
}