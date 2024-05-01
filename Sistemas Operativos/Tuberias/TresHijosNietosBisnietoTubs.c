#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>
/*
Ver(16625)─┬─Ver(16626)───Ver(16628)───Ver(16631)
           ├─Ver(16627)───Ver(16630)
           ├─Ver(16629)───Ver(16632)───Ver(16633)

Proceso padre 
Proceso Hijo 3 
Proceso Hijo 3.1 
Proceso Hijo 3.1.1 
Proceso Hijo 3.1 
Proceso Hijo 3
Proceso Hijo 2 
Proceso 2.1
Proceso Hijo 2 
Proceso Hijo 1 
Proceso Hijo 1.1 
Proceso Hijo 1.1.1 
Proceso Hijo 1.1
Proceso Hijo 1 
Proceso padre

*/
int main(int argc, char const *argv[]){

    pid_t childs[9], padre = getpid();
    char buffer[100];
    int flag, i = 0;
    int fd1[2], fd2[2], fd3[2], fd4[2], fd5[2], fd6[2], fd7[2];
    int fd8[2], fd9[2], fd10[2], fd11[2], fd12[2], fd13[2], fd14[2];

    pipe(fd1);
    pipe(fd2);
    pipe(fd3);
    pipe(fd4);
    pipe(fd5);
    pipe(fd6);
    pipe(fd7);
    pipe(fd8);
    pipe(fd9);
    pipe(fd10);
    pipe(fd11);
    pipe(fd12);
    pipe(fd13);
    pipe(fd14);
    // Cierra lo necesario en las directas a el, anterior y siguientes, y luego las cercanas de la vuelta
    // Especificando el primer elseif, por ahi entra

    for (i = 0; i < 3; i++)
    {
        if (!(childs[i] = fork()))
        {
            flag = (i + 2);
            if (i == 0)
            {
                if (!(childs[3] = fork()))
                {
                    flag = 5;
                    if (!(childs[6] = fork()))
                    {
                        flag = 8;
                    }
                }
            }
            else if (i == 1)
            {
                if (!(childs[4] = fork()))
                {
                    flag = 6;
                }
            }
            else if (i == 2)
            {
                if (!(childs[5] = fork()))
                {
                    flag = 7;
                    if (!(childs[7] = fork()))
                    {
                        flag = 9;
                    }
                }
            }
            break;
        }
    }

    if (getpid() == padre)
    {
        char b[50];
        sprintf(b, "pstree -lp %d", getpid());
        system(b);
    }
    else
    {
        sleep(1);
    }

    if (padre == getpid())
    {
        printf("Proceso padre %d\n", getpid());
        close(fd1[0]);
        close(fd14[1]);

        write(fd1[1], "Turno", 5);

        read(fd14[0], &buffer, 5);
        printf("Proceso padre %d\n", getpid());
        while (wait(NULL) > 0)
            ;
    }
    else if (flag == 4)
    {

        close(fd1[1]);
        close(fd2[0]);
        read(fd1[0], &buffer, 5);
        printf("Proceso Hijo 3 PID[%d] PPID[%d]\n", getpid(), getppid());
        write(fd2[1], &buffer, 5);

        close(fd5[1]);
        close(fd6[0]);
        read(fd5[0], &buffer, 5);
        printf("Proceso Hijo 3 PID[%d] PPID[%d]\n", getpid(), getppid());
        write(fd6[1], &buffer, 5);
        while (wait(NULL) > 0)
            ;
    }
    else if (flag == 7)
    {
        close(fd2[1]);
        close(fd3[0]);
        read(fd2[0], &buffer, 5);
        printf("Proceso Hijo 3.1 PID[%d] PPID[%d]\n", getpid(), getppid());
        write(fd3[1], &buffer, 5);

        close(fd4[1]);
        close(fd5[0]);
        read(fd4[0], &buffer, 5);
        printf("Proceso Hijo 3.1 PID[%d] PPID[%d]\n", getpid(), getppid());
        write(fd5[1], &buffer, 5);
        while (wait(NULL) > 0)
            ;
    }
    else if (flag == 9)
    {
        close(fd3[1]);
        close(fd4[0]);
        read(fd3[0], &buffer, 5);
        printf("Proceso Hijo 3.1.1 PID[%d] PPID[%d]\n", getpid(), getppid());
        write(fd4[1], &buffer, 5);
        while (wait(NULL) > 0)
            ;
    }
    else if (flag == 3)
    {
        close(fd6[1]);
        close(fd7[0]);
        read(fd6[0], &buffer, 5);
        printf("Proceso Hijo 2 PID[%d] PPID[%d]\n", getpid(), getppid());
        write(fd7[1], &buffer, 5);

        close(fd8[1]);
        close(fd9[0]);
        read(fd8[0], &buffer, 5);
        printf("Proceso Hijo 2 PID[%d] PPID[%d]\n", getpid(), getppid());
        write(fd9[1], &buffer, 5);
        while (wait(NULL) > 0)
            ;
    }
    else if (flag == 6)
    {
        close(fd7[1]);
        close(fd8[0]);
        read(fd7[0], &buffer, 5);
        printf("Proceso 2.1 PID[%d] PPID[%d]\n", getpid(), getppid());
        write(fd8[1], &buffer, 5);
        while (wait(NULL) > 0)
            ;
    }
    else if (flag == 2) //Hijo 1
    {
        close(fd9[1]);
        close(fd10[0]);
        read(fd9[0], &buffer, 5);
        printf("Proceso Hijo 1 PID[%d] PPID[%d]\n", getpid(), getppid());
        write(fd10[1], &buffer, 5);

        close(fd13[1]);
        close(fd14[0]);
        read(fd13[0], &buffer, 5);
        printf("Proceso Hijo 1 PID[%d] PPID[%d]\n", getpid(), getppid());
        write(fd14[1], &buffer, 5);
        while (wait(NULL) > 0)
            ;
    }
    else if (flag == 5)
    {
        close(fd10[1]);
        close(fd11[0]);
        read(fd10[0], &buffer, 5);
        printf("Proceso Hijo 1.1 PID[%d] PPID[%d]\n", getpid(), getppid());
        write(fd11[1], &buffer, 5);

        close(fd12[1]);
        close(fd13[0]);
        read(fd12[0], &buffer, 5);
        printf("Proceso Hijo 1.1 PID[%d] PPID[%d]\n", getpid(), getppid());
        write(fd13[1], &buffer, 5);
        while (wait(NULL) > 0)
            ;
    }
    else if (flag == 8)
    {
        close(fd11[1]);
        close(fd12[0]);
        read(fd11[0], &buffer, 5);
        printf("Proceso Hijo 1.1.1 PID[%d] PPID[%d]\n", getpid(), getppid());
        write(fd12[1], &buffer, 5);
        while (wait(NULL) > 0)
            ;
    }

    return 0;
}