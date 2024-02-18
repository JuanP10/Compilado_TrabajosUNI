/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package datos;
/**
 *
 * @author JUAN PABLO
 */
public class Metodo {
    public static void main (String [] arg){   
        Metodo ordenar = new Metodo();
        int vectorA [] = {12,4,3,9,18,7,2,17,13,1};
        System.out.println("Arreglo Original");
        ordenar.MostrarArray(vectorA);
        ordenar.MetodoShell(vectorA);
    }
    public void MetodoShell (int [] array){
        int salto,i,j,k;
        salto=2;
        while(salto>0){
            for(i=salto; i<array.length; i++){
                j=i-salto;
                while(j>=0){
                    k=j+salto;
                    if(array [j] < array [k]){
                        j=-1;
                    }
                    else{
                       int t=array [j];
                      array [j] = array [k];
                      array [k] =t;
                      j=j-salto;
                    }
                }
            }
            salto=salto/2;
        }
       System.out.println("Arreglo Ordenado por Metodo Shell");
       MostrarArray(array);
    }
    public void MostrarArray (int [] array){
        int k;
        for(k=0; k < array.length ; k++){
            System.out.println("["+array[k]+"]");
        }
        System.out.println();
    }
}     