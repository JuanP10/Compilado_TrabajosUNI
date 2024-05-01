#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

/*
                    ________(Padre)_________
                    |                       |
                 (Hijo1)                  (Hijo2)
                   / \                      / \
           (Hijo1.1) (Hijo1.2)      (Hijo2.1) (Hijo2.2) 
                       /                         / \
                (Hijo1.2.1)            (Hijo2.2.1) (Hijo2.2.2)           
                    / \                                \
         (Hijo1.2.1.1) (Hijo1.2.2.2)                 (Hijo2.2.2.1)  

*/

int main() {
  pid_t root = getpid();  //ID del padre
  for (int i = 0; i < 2; i++){ //2 hijos  (Hijo 1 y Hijo2)
    if (fork() == 0){
      if (i == 0){ //Hijo1
        for (int i = 0; i < 2; i++){  //Hijo 1 crea dos hijos  (Hijo1.1) (Hijo1.2) 
          if (fork() == 0){  //Hijo1.1
            if (i == 0) {  //Si es Hijo 1.1
              printf("Soy Hijo (Hijo1.1) - Pid:%d - Mi Padre:%d\n", getpid(), getppid());
            }
            else{  //Hijo 1.2
              if (fork() == 0){
                for (int i = 0; i < 2; i++){  //Crea dos Hijos  
                  if (fork() == 0) {
                    if (i == 0){
                      printf("Soy Hijo (Hijo1.2.1.1) - Pid:%d - Mi Padre:%d\n", getpid(), getppid());
                    }
                    else{
                      printf("Soy Hijo (Hijo1.2.2.2) - Pid:%d - Mi Padre:%d\n", getpid(), getppid());
                    }
                    break;
                  }
                  else{
                    wait(NULL);
                    printf("Soy Hijo (Hijo1.2.1) - Pid:%d - Mi Padre:%d\n", getpid(), getppid());
                  }
                }
                break;
              }
              
              wait(NULL);
              printf("Soy Hijo (Hijo1.2) - Pid:%d - Mi Padre:%d\n", getpid(), getppid());
            }
            break;
          }
          else{
            wait(NULL);
            printf("Soy Hijo (Hijo1)  - Mi PID:%d - Mi padre:%d\n", getpid(), getppid());
          }
        }
      }
      // Hijo2
      if (i == 1){
        for (int i = 0; i < 2; i++){
          if (fork() == 0){
            if (i == 0){
              printf("Soy Hijo (Hijo2.1) - Mi PID:%d - Mi padre:%d\n", getpid(), getppid());
            }
            else{
              for (int i = 0; i < 2; i++){
                if (fork() == 0){
                  if (i == 0){
                    printf("Soy Hijo (Hijo2.2.1) - Mi PID:%d - Mi padre:%d\n", getpid(), getppid());
                  }
                  else{
                    if (fork() == 0){
                      printf("Soy Hijo (Hijo2.2.2.1)  - Mi PID:%d - Mi padre:%d\n", getpid(), getppid());
                      break;
                    }
                    else{
                      wait(NULL);
                      printf("Soy Hijo (Hijo2.2.2) - Mi PID:%d - Mi padre:%d\n", getpid(), getppid());
                    }
                  }
                  break;
                }
                else{
                  wait(NULL);
                  printf("Soy Hijo (Hijo2.2)  - Mi PID:%d - Mi padre:%d\n", getpid(), getppid());
                }
              }
            }
            break;
          }
          else{
            wait(NULL);
            printf("Soy Hijo (Hijo2) - Mi PID:%d - Mi padre:%d\n", getpid(), getppid());
          }
        }
      }
      break;
    }
    else{  //Padre
      wait(NULL);
      printf("Soy Padre - Mi PID:%d - Mi padre:%d\n", getpid(), getppid());  
    }
    
  }
  return EXIT_SUCCESS;
}