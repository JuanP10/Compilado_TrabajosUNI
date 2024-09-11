#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
                            (Padre)
                 --------------|--------------------
                 |             |                    |  
              (Hijo1)       (Hijo2)              (Hijo3)
                 |            /  \                /  |  \  
          (Hijo1.1)    (hijo2.1) (Hijo2.2)  (Hijo3.1)(Hijo3.2)(Hijo3.3)
               
*/


int main() {

    pid_t padre = getpid();

    for (int i=0; i<3; i++){
        if(fork()==0){
            if(i==0){
                fork();
                break;
            }
            if(i==1){
                for(int j=0; j<2; j++){
                    if(fork()==0){
                        break;
                    }
                }
                break;
                
            }
            if(i==2){
                for(int j=0; j<3; j++){
                    if(fork()==0){
                        break;
                    }
                }
                break;

            }
            break;
        }
    }

    if(padre==getpid()){
        char b[50];
        sprintf(b,"pstree -lp %d",getpid());
        system(b);
    } else {
        sleep(2);
    }




    return 0;
}