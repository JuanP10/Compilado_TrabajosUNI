#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


/*
                            (Padre)
                            /  |  \
                      (Hijo1)(Hijo2)(Hijo3)
                               |             
                           (Hijo2.1)
                               |
                          (Hijo2.1.1)     

*/

int main() {

    pid_t padre = getpid();  // Guardamos el PID del proceso padre original

    for (int i = 0; i < 3; i++) {
        if (fork() == 0) { 
            if (i == 1) {  // Si es el hijo del medio
                if (fork() == 0) {  // Crea un hijo (nieto del proceso original)
                    if (fork() == 0) {  // El nieto crea otro hijo (bisnieto del proceso original)
                        break;  // El bisnieto no crea más procesos
                    }
                    break;  // El nieto no crea más procesos
                }
                break;  // El hijo del medio no crea más procesos
            }
            break;  // Los demás hijos (primer y tercer hijo) no crean más procesos
        }
    }

    if (padre == getpid()) {  
        char b[50];
        sprintf(b,"pstree -lp %d",getpid());  
        system(b);
    } else {
        sleep(2);  
    }

    return 0;
}
