#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <wait.h>

void show_tree() {
    char command[100];
    snprintf(command, sizeof(command), "pstree -lp %d | awk '!/sh\\(/ && !/pstree\\(/'", getpid());
    system(command);
    printf("\n");
}

int main() {
    int N, i;
    pid_t pid, padre;
    
    printf("Ingrese el número de hijos: ");
    scanf("%d", &N);

    int pipes[N + 1][2];  // Necesitamos N + 1 pipes (uno entre cada proceso)

    // Inicializar los pipes
    for (i = 0; i <= N; i++) {
        if (pipe(pipes[i]) == -1) {
            perror("Error creando el pipe");
            exit(EXIT_FAILURE);
        }
    }

    padre = getpid();  // Almacenar el PID del proceso padre

    // Crear hijos
    for (i = 0; i < N; i++) {
        pid = fork();
        if (pid == -1) {
            perror("Error en fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {  // Proceso hijo
            close(pipes[i][1]);      // Cerrar el extremo de escritura del pipe anterior
            close(pipes[i + 1][0]);  // Cerrar el extremo de lectura del siguiente pipe
            break;
        }
    }

    if (getpid() == padre) {

        // Leer el mensaje del usuario
        char mensaje[100];
        printf("Ingrese el mensaje (sin espacios): ");
        scanf("%s", mensaje);

        int message_len = strlen(mensaje);

        // Cerrar extremos no utilizados por el padre
        close(pipes[0][0]);         // Cerrar extremo de lectura del primer pipe
        close(pipes[N][1]);         // Cerrar extremo de escritura del último pipe

        // Enviar mensaje al primer hijo
        write(pipes[0][1], &message_len, sizeof(int));  // Enviar el tamaño del mensaje
        write(pipes[0][1], mensaje, message_len);       // Enviar el mensaje

        // Recibir el mensaje de vuelta del último hijo
        int message_size;
        read(pipes[N][0], &message_size, sizeof(int));  // Leer el tamaño del mensaje
        read(pipes[N][0], mensaje, message_size);       // Leer el mensaje

        // Imprimir el mensaje recibido en el padre
        printf("Padre (PID: %d) recibió el mensaje: %s\n", getpid(), mensaje);

        // Esperar a todos los hijos
        for (i = 0; i < N; i++) {
            wait(NULL);
        }
    } else { // Hijo

        // Leer el mensaje del proceso anterior
        int message_size;
        char mensaje[100];
        read(pipes[i][0], &message_size, sizeof(int));  // Leer el tamaño del mensaje
        read(pipes[i][0], mensaje, message_size);       // Leer el mensaje

        // Imprimir el PID y el mensaje
        printf("Hijo %d (PID: %d) recibió el mensaje: %s\n", i + 1, getpid(), mensaje);

        // Enviar el mensaje al siguiente proceso (si no es el último hijo)
        write(pipes[i + 1][1], &message_size, sizeof(int));  // Enviar el tamaño del mensaje
        write(pipes[i + 1][1], mensaje, message_size);       // Enviar el mensaje

        sleep(1);  // Esperar para que se vea el árbol de procesos en orden
    }

    if(padre==getpid()){  
        showtree();;
    }else{
        sleep(1);  
    }


    // Cerrar los pipes restantes
    close(pipes[i][0]);
    close(pipes[i][1]);

    return 0;
}
