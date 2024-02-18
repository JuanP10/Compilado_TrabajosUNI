/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package CollectionsSET;

import java.util.Collections;
import java.util.LinkedHashSet;
import java.util.Set;

/**
 *
 * @author JUAN PABLO
 */
public class LINKEDHASHSET {

    public static void main(String[] args) {
        //LinkedHashSET:
        /*
       almacena los elementos en función del orden de inserción.
       Es, simplemente, un poco más costosa que HashSet
         */
        
        Set<Integer> conjunto3 = new LinkedHashSet<>();
        conjunto3.add(20);
        conjunto3.add(10);
        conjunto3.add(1);
        conjunto3.add(5);
        
        // El valor 20 no se inserta en el conjunto ya que se encuentra repetido
        conjunto3.add(20);
        
        
        // Los elementos se muestran en el orden que se insertaron
        
        for (int elemento : conjunto3) {
            System.out.print(elemento + " - ");
        }
        
        
        System.out.println(conjunto3);
        

    }

}
