#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <wait.h>
#include <time.h>
#include <string.h>

/*
    Creamos N hijos y un mensaje, ese mensaje lo transmite el padre y cada hijo

*/

void descpipe(int x, int n, int pps[][2]) {
    for(int i = 0; i < n; i++) {
        if(i != x) {
            close(pps[i][0]);
        }
        if(x + 1 != i && x != n - 1) {
            close(pps[i][1]);
        }
    }
}

int main(){
    int n;
    printf("ingrese el numero de hijos: ");
    scanf("%d", &n);
    pid_t pidp = getpid();
    pid_t* pidsh = (pid_t*) malloc(sizeof(pid_t)*n);
    char Buffer_in[20],Buffer_out[20]; 
    
    for(int i = 0; i<n;i++){
        pidsh[i]=-1;
    }
    int pps[n][2];
    for(int i = 0;i<n;i++){
        pipe(pps[i]); 
    }
    int id;
    for(id=0; id<n; id++){
        pidsh[id] = fork();
        if(pidsh[id]!=0 ){
            break;
        }
    }

    if(pidp == getpid()){
        char palabra[20]="hola";
        printf("escriba la palabra: ");
        scanf("%s",palabra);
        sleep(.5);
        printf("entrando a padre \n");
        strcpy(Buffer_out,palabra);
        printf("padre[%d] mensaje [%s]\n",getpid(),Buffer_out);
        write(pps[0][1],Buffer_out,sizeof(Buffer_out));
        wait(NULL);
        printf("terminando el padre... \n");
    }else{
        sleep(1.2);
        descpipe(id-1, n , pps);
            read(pps[id-1][0], Buffer_in, sizeof(Buffer_in));
            printf("hijo[%d][%d] mensaje [%s]\n",id,getpid(),Buffer_in);
        if(id<n){
            strcpy(Buffer_out,Buffer_in);
            write(pps[id][1],Buffer_out,sizeof(Buffer_out));
            wait(NULL);
        }
        exit(0);
    }
    return 0;
}