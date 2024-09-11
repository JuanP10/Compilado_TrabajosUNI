#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
                            (Padre)
                               |
                            (hijo1)
                     __________|__________
                     |         |          | 
                (hijo1.1)  (hijo1.2)  (hijo1.3)
                               |
                          (hijo1.2.1)
                       ________|_________
                       |                |
                (hijo1.2.1.1)    (hijo1.2.1.2)
*/

int main() {
    pid_t padre = getpid();

    // El primer fork crea a hijo1
    if (fork() == 0) {
        // Estamos en hijo1
        for (int i = 0; i < 3; i++) {
            if (fork() == 0) { // Creamos a hijo1.1, hijo1.2 y hijo1.3
                if (i == 1) {   //Estamos en hijo1.2
                    if (fork() == 0) {  //Creamos a hijo1.2.1
                        for (int j = 0; j < 2; j++) {  
                            if (fork() == 0) {  //Creamos a hijo1.2.1.1 y hijo1.2.1.2
                                break;  
                            }
                        }
                    }
                }
                break;  // Hijos de hijo1 no crean más procesos
            }
        }
    }

    // El proceso padre original muestra el árbol de procesos
    if (padre == getpid()) {
        char b[50];
        sprintf(b, "pstree -lp %d", getpid());
        system(b);
    } else {
        sleep(2);  // Los procesos hijos esperan un poco antes de terminar
    }

    return 0;
}
