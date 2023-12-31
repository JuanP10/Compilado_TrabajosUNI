/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package datos;

import java.util.Arrays;

public class Vector {
    public static void llenarVector(int v[]){
        for (int i = 0; i < v.length; i++) {
            v[i]= (int) (Math.random()*10000);
            
        }
    }
    
    public static int busquedalineal (int v[], int datos){
        for (int i = 0; i < v.length; i++) {
            if (v[i]==datos) {
                return i;
            }
            
        }
        return -1;
    }
    
    public static void burbuja(int v[]){
        for (int i = 0; i < v.length; i++) {
            for (int j = 0; j < v.length-1; j++) {
                if(v[j]>v[j+1]){
                    int t=v[j];
                    v[j]=v[j+1];
                    v[j+1]=t;
                }
                
            }
            
        }
    }
    public static void main(String[] args) {
        int v[]=new int[100];
        llenarVector(v);
        System.out.println(""+Arrays.toString(v));
        burbuja(v);
       System.out.println("ordenado"+Arrays.toString(v));
        System.out.println("Busqueda "+ busquedalineal(v, 500));
        
    }
}

