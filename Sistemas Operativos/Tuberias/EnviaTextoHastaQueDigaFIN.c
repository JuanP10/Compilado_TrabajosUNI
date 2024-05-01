#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>
#include <string.h>

/*
                            Padre
               _______________|______________
       (tub1) Hijo 1 (tub2)         (tub3) Hijo2  (tub4)
                |                           |
     (tub5) Hijo 1.1 (tub6)        (tub7) Hijo2.1  (tub8)
*/
int main(int argc, char const *argv[]){
    pid_t childs[4], padre = getpid();
    char buff[1000];
    int flag, i = 0, n;
    int fd1[2], fd2[2], fd3[2], fd4[2], fd5[2], fd6[2], fd7[2];
    int fd8[2];

    pipe(fd1);
    pipe(fd2);
    pipe(fd3);
    pipe(fd4);
    pipe(fd5);
    pipe(fd6);
    pipe(fd7);
    pipe(fd8);

    for (i = 0; i < 2; i++){
        if (!(childs[i] = fork())){
            flag = (i + 2);
            if (i == 0){
                if (!(childs[2] = fork())){
                    flag = 4;
                }
            }
            else if (i == 1){
                if (!(childs[3] = fork())){
                    flag = 5;
                }
            }
            break;
        }
    }

    if (getpid() == padre){
        char b[50];
        sprintf(b, "pstree -lp %d", getpid());
        system(b);
    }
    else
        sleep(1);
    

    if (padre == getpid()){

        printf("Proceso padre %d\n", getpid());
        close(fd1[0]);
        close(fd8[1]);
        close(fd4[1]);
        close(fd5[0]);

        do{
            fgets(buff, 1000, stdin);
            if (strlen(buff) > 1){
                buff[strlen(buff) - 1] = '\0';
                printf("[%d]write (Padre)-->:%s\n", getpid(), buff);
                write(fd1[1], buff, strlen(buff));

                read(fd4[0], &buff, 1000);
                printf("[%d]read  (Padre)<--:%s\n", getpid(), buff);

                write(fd5[1], &buff, 1000);
                printf("[%d]write (Padre)-->:%s\n", getpid(), buff);

                read(fd8[0], &buff, 1000);
                printf("[%d]read (Padre) <--:%s\n", getpid(), buff);
            }
        } while (strcmp(buff, "fin") != 0);
        //Toca cerrar las que utiliza cuando acabe, padre e hijo.
        close(fd1[1]);
        close(fd5[1]);

        while(wait(NULL) > 0);
    }
    else{
        if (flag == 3){ //Hijo 2
            close(fd1[1]);
            close(fd2[0]);
            close(fd3[1]);
            close(fd4[0]);

            while( (n=read(fd1[0], &buff, 1000)) >0 ){
                buff[n] = '\0';
                printf("[%d]read (Hijo2)<--:%s\n",getpid(),buff);   
                write(fd2[1], &buff, 1000);
                printf("[%d]write (Hijo2)-->:%s\n", getpid(), buff);    
                if((n=read(fd3[0], &buff, 1000)) >0)
                {
                    buff[n] = '\0';
                    printf("[%d]read (Hijo2)<--:%s\n",getpid(),buff);
                    write(fd4[1], &buff, 1000);
                    printf("[%d]write (Hijo2)-->:%s\n", getpid(), buff);
                }                
            }
            while (wait(NULL) > 0);
        }
        else if (flag == 5){  // hijo 2.1
            close(fd2[1]);
            close(fd3[0]);

            while( (n=read(fd2[0], &buff, 1000)) >0 ){
                buff[n] = '\0';
                printf("[%d]read (Hijo 2.1)<--:%s\n",getpid(),buff);   
                write(fd3[1], &buff, 1000);             
            }

        }
        else if (flag == 2){ //Hijo 1
            close(fd5[1]);
            close(fd6[0]);
            close(fd7[1]);
            close(fd8[0]);

            while( (n=read(fd5[0], &buff, 1000)) >0 ){
                buff[n] = '\0';
                printf("[%d]read (hijo1)<--:%s\n",getpid(),buff);   
                write(fd6[1], &buff, 1000);
                printf("[%d]write (hijo1)-->:%s\n", getpid(), buff);    
                if((n=read(fd7[0], &buff, 1000)) >0){
                    buff[n] = '\0';
                    printf("[%d]read (hijo1)<--:%s\n",getpid(),buff);
                    write(fd8[1], &buff, 1000);
                    printf("[%d]write (hijo1)-->:%s\n", getpid(), buff);
                }                
            }

            while (wait(NULL) > 0);
        }
        else if (flag == 4){ //Hijo 1.1
            close(fd6[1]);
            close(fd7[0]);

            while( (n=read(fd6[0], &buff, 1000)) >0 ){
                buff[n] = '\0';
                printf("[%d]read (hijo 1.1)<--:%s\n",getpid(),buff);
                write(fd7[1], &buff, 1000);                       
            }
        }
    }
    return 0;
}