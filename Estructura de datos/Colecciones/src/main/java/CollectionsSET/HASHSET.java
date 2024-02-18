/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package CollectionsSET;
import java.util.HashSet;


/**
 *
 * @author JUAN PABLO
 */

// No puede contener elementos duplicados

public class HASHSET {
    
    public static void main(String[] args) {
       /*
       almacena los elementos en una tabla hash. Es la implementación con mejor rendimiento de todas 
       pero no garantiza ningún orden a la hora de realizar iteraciones. Es la implementación más empleada 
       debido a su rendimiento y a que, generalmente, no nos importa el orden que ocupen los elementos
    */
    
    //Declararar:
    HashSet<String> hset = new HashSet<>();
    
    //Añadir
    hset.add("HOLA");
    hset.add("Bienvenido");
    hset.add("a");
    hset.add("mi");
    hset.add("Ciudad");
    
    hset.add("HOLA");

    
        System.out.println(hset);
        
        //No hay orden y tampoco duplicados
    
    
    }
    
    
    
    
    
    
    
    
    
    

}
