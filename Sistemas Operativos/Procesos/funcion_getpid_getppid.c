#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(void) {
    pid_t pidchild = fork();  //Id del Hijo

    switch (pidchild) {  //para manejar los diferentes valores devueltos por fork()

        case -1:  //error en la creación del proceso hijo.
            perror("Error fork");
            exit(EXIT_FAILURE);
            break;

        case 0:  //Hijo 
            sleep(1);  
            printf("Proceso hijo: pid=%d y ppid=%d\n", getpid(), getppid()); 
            //imprime el ID del proceso hijo y el ID del proceso padre
            break;

        default:
            char b[50];
            sprintf(b,"pstree -lp %d",getpid());
            system(b);
            printf("Proceso padre: pid=%d y ppid=%d\n", getpid(), getppid());
            //imprime el ID del proceso padre y el ID del proceso abuelo (el padre del proceso padre) 
    }
    return EXIT_SUCCESS;
}