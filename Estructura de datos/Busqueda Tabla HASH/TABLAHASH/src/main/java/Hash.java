import java.util.Arrays;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author JUAN PABLO
 */
public class Hash {
    String arreglo [];
    int tamanio, contador;
    
    //constructor
    public Hash (int tam){
        tamanio=tam;
        arreglo= new String [tam];
        Arrays.fill(arreglo, "null");   //Rellena el arreglo de puros "null"
    }
    
    public void funcionHash (String cadenaArreglo [], String arreglo[]){
        for (int i = 0; i < cadenaArreglo.length; i++) {
            String elemento = cadenaArreglo[i];
            int indiceArreglo = Integer.parseInt(elemento)%6;
            System.out.println("El indice es " + indiceArreglo + "Para el elemento " + elemento);
        //Colisiones
            while(!"null".equals(arreglo[indiceArreglo])){
                  indiceArreglo++;
                  System.out.println("Ocurrio una colision con el inidice " + (indiceArreglo-1) + "Cambiar al indicie" + indiceArreglo);
                  indiceArreglo%=tamanio;
            }
            arreglo[indiceArreglo]=elemento;
        }
    }
    
    //Metodo para mostrar la tabla
    public void mostrar() {
        int incremento=0,i,j;
	for(i=0;i<1;i++) {
            incremento+=7;
        }	
        for(j=0;j<61;j++) {
	    System.out.print("-");
	}
	System.out.println();
	for(j=incremento -7;j<incremento;j++) {
	    System.out.format("|%3s"+"",j);	
	}
	System.out.println("|");
	for(int n=0;n<71;n++) {
	    System.out.print("-");	
	}
	System.out.println();
	for(j=incremento -8;j<incremento;j++) {
            if(arreglo[j].equals("-1")) {
		System.out.print("|");
		}else {
                    System.out.print(String.format("|%3s"+"", arreglo[j]));
		}
   	}
	System.out.println("|");
	for(j=0;j<71;j++) {
	    System.out.print("-");
	}
    }
    
    public String buscarClave (String elemento){
        int indiceArreglo=Integer.parseInt(elemento)%6;
        int cont=0;
        while(!"null".equals(arreglo[indiceArreglo])){
            if(arreglo[indiceArreglo].equals(elemento)){
                System.out.println("El elemento " + elemento + "Fue encontrado en el indicie " + indiceArreglo );
                return arreglo[indiceArreglo];
            }
            indiceArreglo++;
            indiceArreglo&=tamanio;
            cont++;
            if(cont >6){
                break;
            }
        }
        return null;
        
    }
    
    
    public static void main (String [] arg){
        Hash HASH = new Hash (6);
        String [] elementos={"Juan", "Santiago", "Geral", "Luz", "Julian","Gatis", "Saske"};
        HASH.funcionHash(elementos, HASH.arreglo);
        HASH.mostrar();
    }


    
}
