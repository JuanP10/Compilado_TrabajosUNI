#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>
#include <wait.h>


/*
                        ______ Padre  ______
                        |      |           |       
                       Hijo1   Hijo2     Hijo3   
                                           |
                                         Hijo3.1
                                           |    
                                         Hijo3.1.2

Tub1 = Hijo1 - Padre
Tub2 = Hijo1 - Hijo2 
Tub3 = Hijo2 - Hijo3
Tub4 = Hijo3 - Hijo3.1
Tub5 = Hijo3.1  - Hijo3.1.2
Tub6 = Hujo3.1.2 - Padre


De un archivo.txt contar numero de letras mayusculas, minusculas, espacios, puntos y comas
Hijo 1 = Sume Mayusculas
Hijo 2 = Sume Minusculas
Hijo 3 = Espacios
Hijo 3.1 = Puntos
Hijo 2.1.2 = Comas

*/


int main(int argc, char const *argv){

    pid_t childs[5],  //array de 5 elementos de tipo pid_t, que se utilizan para almacenar los identificadores de los procesos hijos
    padre=getpid();   //ID padre

    int **fd;         //almacenar punteros a los extremos de las tuberías
    int flag;         //tipo de proceso que es cada hijo
    int sizeBuffer;   //almacenar el tamaño del archivo 

    int cMayus=0,cMinus=0,cSpace=0,cDot=0,cCommas=0; //Contat numero de Mayusculas y demás
    char *buffer;  //Contenido del archivo 
    char caracter;  //Leer los caracteres
    FILE *file;


    fd = (int**) malloc(6*sizeof(int*)); //Array de 6 punteros

    for(int i=0;i<6;i++){  //Damos memoria
        fd[i] = (int*) malloc(2*sizeof(int));
        pipe(fd[i]);  
    }

    for(int i=0;i<3;i++){  //3 hijos
        if(!(childs[i]=fork())){   //Si es hijo
            flag=(i++);  //Hijo 1 es flag 1, Hijo 2 es flag 2 , Hijo 3 es flag 3

            if(i==2){  //Tercer Hijo
                if(!(childs[3]=fork())){ 
                    flag=3.1;    
                    if(!(childs[4]=fork())){  //El otro Hijo
                        flag=3.12;  
                    }
                }
            }
            break;
        }
    }

    //Mostrar diagrama

    if(padre==getpid()){
        char b[50];
        sprintf(b,"pstree -lp %d",getpid());
        system(b);
    }else{
        sleep(1);
    }

    if(padre==getpid()){  //Si es padre
        close(fd[0][0]);  //Cierro lectura del tub1
        close(fd[5][1]);   //Cierro Escritura del tub 6

        for(int i=1;i<5;i++){   //Cierro todos los otros tubos
            close(fd[i][0]);
            close(fd[i][1]);
        }


        int k=0;
        file = fopen("archivo.txt","r");//Abre el archivo en modo lectura "r" y devuelve un puntero a la estructura file
        
        //Coloca el puntero al final del archivo utilizando el valor de desplazamiento 0 y la constante SEEK_END, permite obtener la posicion actual del puntero en bytes, que es el tama�o del archivo
        fseek(file,0,SEEK_END);
        
        //Guarda el tamaño del archivo en la variable sizeBuffer
        sizeBuffer = ftell(file);
        
        //Coloca el puntero al inicio del archivo utilizando el valor de desplazamiento 0 y la constante SEEK_SET para leer el archivo del principio
        fseek(file,0,SEEK_SET);

        //Reserva memoria para el buffer
        buffer = (char*) malloc(sizeBuffer*sizeof(char));

        //Lee el archivo caracter por caracter y lo guarda en el buffer
        while((caracter = fgetc(file)) != EOF){
            buffer[k] = caracter;
            k++;
        }
        
        write(fd[0][1],&sizeBuffer,sizeof(int));  //Escribe Tamaño del archivo

        //Escribe el contenido del archivo en la tubería
        for(int i=0;i<sizeBuffer;i++){
            write(fd[0][1],&buffer[i],sizeof(char));   
        }

        //Lecturas
        read(fd[5][0],&cMayus,sizeof(int));
        read(fd[5][0],&cMinus,sizeof(int));
        read(fd[5][0],&cSpace,sizeof(int));
        read(fd[5][0],&cDot,sizeof(int));
        read(fd[5][0],&cCommas,sizeof(int));


        printf("En el archivo hay \n %d Mayusculas \n %d Minusculas \n %d Espacios \n %d Puntos \n %d Comas \n\n",cMayus,cMinus,cSpace,cDot,cCommas);
        
        while(wait(NULL)>0); //Espera que hijos finalicen

    }else if(flag==1){  //Hijo  1  Suma Mayusculas

        
        close(fd[flag-2][1]);  //Cerramos Escritura tub 2
        close(fd[flag-1][0]);  //Cerramos Lectura tub 1

        //Cerramos todos los demás
        for(int i=0;i<6;i++){
            if((i!=flag-2) && (i!=flag-1)){
                close(fd[i][0]);
                close(fd[i][1]);
            }
        }     


        
        read(fd[flag-2][0],&sizeBuffer,sizeof(int));  //Leer tamaño y guardar en sizeBuffer

        buffer = (char*) malloc(sizeBuffer*sizeof(char)); //Reserva de memora

        
        for(int i=0;i<sizeBuffer;i++){

            //Lee un caracter del pipe del proceso hermano anterior y lo guarda en la posición i del buffer
            read(fd[flag-2][0],&buffer[i],sizeof(char));

            if(isupper(buffer[i])){ //Si Es mayuscula
                cMayus++;
            }
        }

        // Escribe el tamaño del buffer en el tubo del proceso hermano siguiente
        write(fd[flag-1][1],&sizeBuffer,sizeof(int)); 

        //se escribe cada caracter del buffer en el tubo
        for(int i=0;i<sizeBuffer;i++){
            write(fd[flag-1][1],&buffer[i],sizeof(char));
        }

        //Escribe la cantida de Mayusculas
        write(fd[flag-1][1],&cMayus,sizeof(int));
        
    }else if(flag==2){   //Hijo 2  Suma Minusculas

        //Cerramos tubos que no sean necesarios
        close(fd[flag-2][1]);
        close(fd[flag-1][0]);
        for(int i=0;i<6;i++){
            if((i!=flag-2) && (i!=flag-1)){
                close(fd[i][0]);
                close(fd[i][1]);
            }
        }        

        read(fd[flag-2][0],&sizeBuffer,sizeof(int));
        buffer = (char*) malloc(sizeBuffer*sizeof(char));
        for(int i=0;i<sizeBuffer;i++){
            read(fd[flag-2][0],&buffer[i],sizeof(char));
            if(islower(buffer[i])){
                cMinus++;
            }
        }
        read(fd[flag-2][0],&cMayus,sizeof(int));



        write(fd[flag-1][1],&sizeBuffer,sizeof(int));
        for(int i=0;i<sizeBuffer;i++){
            write(fd[flag-1][1],&buffer[i],sizeof(char));
        }
        write(fd[flag-1][1],&cMayus,sizeof(int));
        write(fd[flag-1][1],&cMinus,sizeof(int));

    }else if(flag==3){  //Hijo 3 suma Espacios
        close(fd[flag-2][1]);
        close(fd[flag-1][0]);
        for(int i=0;i<6;i++){
            if((i!=flag-2) && (i!=flag-1)){
                close(fd[i][0]);
                close(fd[i][1]);
            }
        }        

        read(fd[flag-2][0],&sizeBuffer,sizeof(int));
        buffer = (char*) malloc(sizeBuffer*sizeof(char));
        for(int i=0;i<sizeBuffer;i++){
            read(fd[flag-2][0],&buffer[i],sizeof(char));
            //isspace es un caracter en blanco
            if(isspace(buffer[i])){
                cSpace++;
            }
        }
        
        read(fd[flag-2][0],&cMayus,sizeof(int));
        read(fd[flag-2][0],&cMinus,sizeof(int));

        

        write(fd[flag-1][1],&sizeBuffer,sizeof(int));
    
        for(int i=0;i<sizeBuffer;i++){
            write(fd[flag-1][1],&buffer[i],sizeof(char));
        }
        
        write(fd[flag-1][1],&cMayus,sizeof(int));
        write(fd[flag-1][1],&cMinus,sizeof(int));
        write(fd[flag-1][1],&cSpace,sizeof(int));

        while(wait(NULL)>0);
    }else if(flag==3.1){  //Suma puntos  (Hijo del 3 / Nieto)
        close(fd[flag-2][1]);
        close(fd[flag-1][0]);
        for(int i=0;i<6;i++){
            if((i!=flag-2) && (i!=flag-1)){
                close(fd[i][0]);
                close(fd[i][1]);
            }
        }        

        read(fd[flag-2][0],&sizeBuffer,sizeof(int));
        buffer = (char*) malloc(sizeBuffer*sizeof(char));
        for(int i=0;i<sizeBuffer;i++){
            read(fd[flag-2][0],&buffer[i],sizeof(char));
            if(buffer[i] == '.'){
                cDot++;
            }
        }
        
        read(fd[flag-2][0],&cMayus,sizeof(int));
        read(fd[flag-2][0],&cMinus,sizeof(int));
        read(fd[flag-2][0],&cSpace,sizeof(int));

        write(fd[flag-1][1],&sizeBuffer,sizeof(int));
        
        for(int i=0;i<sizeBuffer;i++){
            write(fd[flag-1][1],&buffer[i],sizeof(char));
        }
        
        write(fd[flag-1][1],&cMayus,sizeof(int));
        write(fd[flag-1][1],&cMinus,sizeof(int));
        write(fd[flag-1][1],&cSpace,sizeof(int));
        write(fd[flag-1][1],&cDot,sizeof(int));
        
        
       while(wait(NULL)>0);

    }else if(flag==3.12){  //Hijo 3.1.2 suma Comas  (Hijo del 3.1 / BisNieto)
        close(fd[flag-2][1]);
        close(fd[flag-1][0]);
        for(int i=0;i<6;i++){
            if((i!=flag-2) && (i!=flag-1)){
                close(fd[i][0]);
                close(fd[i][1]);
            }
        }        

        read(fd[flag-2][0],&sizeBuffer,sizeof(int));
        buffer = (char*) malloc(sizeBuffer*sizeof(char));
        for(int i=0;i<sizeBuffer;i++){
            read(fd[flag-2][0],&buffer[i],sizeof(char));
            if(buffer[i] == ','){
                cCommas++;
            }
        }

        
        read(fd[flag-2][0],&cMayus,sizeof(int));
        

        read(fd[flag-2][0],&cMinus,sizeof(int));
        read(fd[flag-2][0],&cSpace,sizeof(int));
        read(fd[flag-2][0],&cDot,sizeof(int));


        write(fd[flag-1][1],&cMayus,sizeof(int));
        write(fd[flag-1][1],&cMinus,sizeof(int));
        write(fd[flag-1][1],&cSpace,sizeof(int));
        write(fd[flag-1][1],&cDot,sizeof(int));
        write(fd[flag-1][1],&cCommas,sizeof(int));

    }
    


    return EXIT_SUCCESS;
}