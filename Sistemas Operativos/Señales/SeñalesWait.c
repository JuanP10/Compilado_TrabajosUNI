#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h>


/*
                     Padre
                     / | \
                hijo1 hijo2 hijo3  
                       |
                     nieto

Señales:
Padre, Hijo 3, Hijo 2, Nieto, Hijo 2, Hijo 1, Padre
*/

void showtree() {
  char command[100];
  sprintf(command, "pstree -lp %d | awk '!/sh\\(/ && !/pstree\\(/' \n", getpid());
  system(command);
  printf("\n");
}


void handler (int s){}

void Kill(pid_t pid, int s){ 
  usleep(100); kill(pid, s);
}

int main(int argc, char **argv){

  pid_t pids[3], child, root=getpid();
  int idx;

  int n; //Numero de repeticiones de la señal

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <n>\n", argv[0]);
    return EXIT_FAILURE;
  }

  n = atoi(argv[1]);



  signal(SIGUSR1, handler); //Manejador de señal

  for(idx=0; idx<3; idx++){  //Crear 3 hijos
    pids[idx] = fork(); 
    if(pids[idx] == 0){
      if(idx==1) child = fork();  //Crear nieto por hijo 2
      break;
    }
  }

  while (n--){
    if(root == getpid()){ //Proceso padre
      usleep(100);
      printf("proceso Padre: %d\n", getpid());

      kill(pids[2], SIGUSR1); //Enviar señal a hijo 3
      pause(); //Esperar señal de retorno
      printf("proceso Padre: %d\n", getpid());
      printf("\n");

    }else{  //Procesos hijos
      
      pause(); //Esperar señal

      printf("proceso: %d\n", getpid()); //Imprimir proceso

      if(idx == 1){ //Hijo 2
        if(child){  //Hijo 2 (padre del nieto)

          Kill(child, SIGUSR1);  //Enviar señal al nieto
          pause(); //Esperar señal de retorno del nieto
          printf("proceso: %d\n", getpid()); 

          Kill(pids[idx-1], SIGUSR1); //Enviar señal al hijo 1

        }else Kill(getppid(), SIGUSR1);  //Señal de retorno al padre desde el nieto
      }
      else{
        if(idx==0) Kill(getppid(), SIGUSR1); //Hijo 1 envía señal al padre
        else Kill(pids[idx-1], SIGUSR1);  //Hijo 3 envía señal al hijo 2
      }
    }
    
  }
  
  

  if(root == getpid()){ //Proceso padre
    showtree();
  }else{
    sleep(1);
  }
  
  

  return EXIT_SUCCESS;
}




