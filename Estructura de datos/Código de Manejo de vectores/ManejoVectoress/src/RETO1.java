/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author JUAN PABLO
 */
public class RETO1 {
    
    //int compra = [3240, 9048, 2310, 4680, 3968, 6000, 13120, 5980, 7240, 29900, 193600];
    
     public static int [] reporte(int [] compra){
        //EN ESTE ESPACIO PONER SU LÓGICA
        //Costo total de la compra
        int salida[]=null;
        int suma=0;
        for(int i=0; i<compra.length;i++){
            suma+=compra[i];
        }
        
        int mayor, menor;
        mayor = menor = compra [0];
        
        //Producto mas barato
       
        for(int k=0; k<compra.length;k++){
            if(compra[k]<menor){
                menor=compra[k];
            }
        }
        
        //Producto mas caro
        for(int k=0; k<compra.length;k++){
            if(compra[k]>mayor){
                mayor=compra[k];
            }
        }
        
        for(int j=0; j<salida.length;j++){
            suma=salida[0];
        }
        

        
        
        
        return salida;
    }
      public static void main(String[] args) {
        
        
    }
}

   
