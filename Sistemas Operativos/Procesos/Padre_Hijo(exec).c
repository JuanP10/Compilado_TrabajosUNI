#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <wait.h>

int main() {

    if (!fork()) {  //Hijo
        printf("Control1\n");
        execlp("/usr/bin/ls", "ls", "-a", "-l", NULL);
        /*
        "execlp" reemplaza el proceso hijo actual con un nuevo proceso que ejecuta el programa especificado (`/usr/bin/ls` en este caso, que es el comando `ls`).
            - "-a": Esta opción le dice a `ls` que liste todos los archivos, incluidos los ocultos.
            - "-l": Esta opción le dice a `ls` que use un formato de lista larga, proporcionando detalles sobre los archivos.
        */
        printf("Control2");
        /*
        Esta línea **no se ejecutará** porque la llamada "execlp" reemplaza el proceso hijo con el programa "ls".
        */
        return EXIT_SUCCESS;
    }
    else {  //Padre
        printf("Soy padre");
        wait(NULL);
    }

}