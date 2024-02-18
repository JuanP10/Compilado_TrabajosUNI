/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package CollectionsSET;


import java.util.TreeSet;

/**
 *
 * @author JUAN PABLO
 */
public class TREESET {
    
    public static void main(String[] args) {
    //TREESET:
    /*
       almacena los elementos ordenándolos en función de sus valores. Es bastante más lento que HashSet.
       Los elementos almacenados deben implementar la interfaz Comparable. Esta implementación tiene un 
       rendimiento de log(N) en las operaciones básicas, debido a la estructura de árbol empleada para almacenar los elementos.
    */
    
    //Declarar:
    TreeSet<String> trs = new TreeSet<>();
    
    //Añadir:
    trs.add("HOLA");
    trs.add("A");
    trs.add("E");
    
    
    //eliminar:
    trs.remove("a");
    
    //Pregunta si contene el elemento
    System.out.println("Contiene HOLA: " + trs.contains("HOLA"));
    
    //ts.addAll(ts);
    
    System.out.println(trs);
    
    
    ///////////Otras cosas
    TreeSet<Integer> ts = new TreeSet<>();
    ts.add(50);
    ts.add(10);
    ts.add(80);
    ts.add(30);
    ts.add(20);
    
    //HEADSET devuelve todos los datos desde el inicio hasta el elemento especificado 
    System.out.println("Elements in a TreeSet: " + ts.toString());
    System.out.println("HeadSet:");
    System.out.println(ts.headSet(30));
    System.out.println(ts.headSet(30, true));
    System.out.println(ts.headSet(30, false));
    
    //TAILSET: devuelve todos los datos del elemento especificado hasta el final
    System.out.println("TailSet:");
    System.out.println(ts.tailSet(30));
    System.out.println(ts.tailSet(30, true));
    System.out.println(ts.tailSet(30, false));
    
    //SUBSET: recuperar un rango de valores basados ​​en los elementos especificados
    System.out.println("SubSet:");
    System.out.println(ts.subSet(20, 50));
    System.out.println(ts.subSet(20, true, 50, true));
    System.out.println(ts.subSet(20, true, 50, false));
    System.out.println(ts.subSet(20, false, 50, true));
    System.out.println(ts.subSet(20, false, 50, false));

     
    }
    
}
