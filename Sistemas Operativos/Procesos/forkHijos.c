/* cree un proceso principal y varios procesos hijos utilizando la función fork(). 
El proceso principal deberá dividir un conjunto de números en dos arreglos separados:
uno para números pares y otro para números impares. Cada proceso hijo deberá calcular
la suma de los números pares o impares en su propio arreglo asignado y enviar el resultado al proceso principal.

El proceso principal deberá esperar a que todos los procesos hijos terminen y luego imprimir
la suma total de los números pares y la suma total de los números impares.*/

#include <stdio.h>  
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h> //Para el fork()
#include <signal.h> //Para el 

#define ARRAY_SIZE 10

int main(int argc, char *argv[]) {

    int numbers[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int sumaPares = 0, sumaImpares = 0;

    // Dividir el conjunto de números en dos arreglos separados para números pares e impares

    // Crear procesos hijos para calcular la suma de los números pares e impares

    for (int i = 0; i < 2; i++) { // Crear dos procesos hijos
        pid_t pid = fork(); // Crear un proceso hijo

        // Imprime el PID del proceso actual y el PPID del proceso padre.
        printf("pid:%d ppid:%d\n", getpid(), getppid());

        

        if (pid < 0) {
            fprintf(stderr, "Error al crear el proceso hijo\n");  //stderr es el archivo de salida de errores, stdin es el archivo de entrada y stdout es el archivo de salida
            return 1; // Terminar el programa con un código de error

        } else if (pid == 0) { // El proceso hijo se crea correctamente

            // Código ejecutado por el proceso hijo
            int sum = 0;
            if (i == 0) {
                // Suma de números pares
                for (int j = 0; j < ARRAY_SIZE; j++) {
                    if (numbers[j] % 2 == 0) {
                        sum += numbers[j];
                        printf("sum par: %d\n", sum);
                    }
                }

                // Enviar la suma al proceso padre
                exit(sum);

            } else {
                // Suma de números impares
                for (int j = 0; j < ARRAY_SIZE; j++) {
                    if (numbers[j] % 2 != 0) {
                        sum += numbers[j];
                        printf("sum impar: %d\n", sum);
                    }
                }
                // Enviar la suma al proceso padre
                exit(sum);
            }
        }
    }

    // Proceso padre: esperar a que todos los procesos hijos terminen
    for (int i = 0; i < 2; i++) {
        int status;
        wait(&status); // Esperar a que un proceso hijo termine

        if (WIFEXITED(status)) { // Verificar si el proceso hijo terminó correctamente como el wait() y el waitpid()
            int child_sum = WEXITSTATUS(status); // Obtener el valor de retorno del proceso hijo
            if (i == 0) {
                sumaPares += child_sum; // Suma de los números pares
            } else {
                sumaImpares += child_sum; // Suma de los números impares
            }
        }
    }

    // Imprimir resultados
    printf("Suma de números pares: %d\n", sumaPares);
    printf("Suma de números impares: %d\n", sumaImpares);
    
    return 0;
}
