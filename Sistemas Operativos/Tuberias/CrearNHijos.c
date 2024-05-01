#include <stdlib.h>
#include <stdio.h>
#include <wait.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    pid_t *pr1hjs, padre = getpid(), destinatario;
    int **tubs, num_children, i, flag;
    int size;
    char mensaje[256];

    printf("Ingrese la cantidad de hijos: ");
    scanf("%d", &num_children);

    pr1hjs = (pid_t*) malloc(num_children*sizeof(pid_t));
    tubs = (int**) malloc((num_children+1)*sizeof(int*));

    for (i = 0; i <= num_children; i++) {
        tubs[i] = (int *) malloc (2 * sizeof(int));
        if (pipe(tubs[i]) == -1) {
            perror("Error al crear la tubería");
            exit(EXIT_FAILURE);
        }
    }

    for(i = 0; i < num_children; i++) {
        pr1hjs[i] = fork();
        if(pr1hjs[i]==-1){
            perror("Error al crear el proceso hijo");
            exit(EXIT_FAILURE);
        }
        if(pr1hjs[i] == 0) {
            flag = i+2;
            break;
        }
    }

    if(padre == getpid()) {
        printf("Ingrese el mensaje que desea mandar: ");
        scanf("%s", mensaje);
        printf("El mensaje en el padre  es [%s] y mi id es %d\n", mensaje, getpid());

        close(tubs[0][0]);
        close(tubs[num_children][1]);

        for(int i = 1; i < num_children; i++) {
            close(tubs[i][0]);
            close(tubs[i][1]);
        }

        int size2 = strlen(mensaje);
        int size3;
        int idEnviar = padre;

        write(tubs[0][1], &size2, sizeof(int));
        write(tubs[0][1], &mensaje, size2);
        write(tubs[0][1], &idEnviar, sizeof(int));

        read(tubs[num_children][0], &size3, sizeof(int));
        read(tubs[num_children][0], &mensaje, size3);
        read(tubs[num_children][0], &destinatario, sizeof(int));

        printf("El mensaje en el padre  es [%s] y mi id es %d y el que lo envio fue %d\n", mensaje, getpid(), destinatario);
    }
    else {
        close(tubs[flag-2][1]);
        close(tubs[flag-1][0]);

        for(int i = 0; i < (num_children+1); i++) {
                if(i != flag-2 && i != flag-1){
                    close(tubs[i][0]);
                    close(tubs[i][1]);
                }
        }

        int idEnviar = (int) getpid();

        read(tubs[flag-2][0], &size, sizeof(int));
        read(tubs[flag-2][0], &mensaje, size);
        read(tubs[flag-2][0], &destinatario, sizeof(int));

        printf("El mensaje en el hijo %d es [%s] y mi id es %d y el que lo envio fue %d\n", flag-1, mensaje, getpid(), destinatario);

        write(tubs[flag-1][1], &size, sizeof(int));
        write(tubs[flag-1][1], &mensaje, size);
        write(tubs[flag-1][1], &idEnviar, sizeof(int));
    }

    if(padre==getpid()){
        char b[50];
        sprintf(b,"pstree -lp %d",getpid());
        system(b);
    }else{
        sleep(1);
    }

    free(pr1hjs);
    for(i=0; i<=num_children; i++)
        free(tubs[i]);
    free(tubs);
    return 0;
}
