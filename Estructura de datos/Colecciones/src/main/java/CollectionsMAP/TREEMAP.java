/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package CollectionsMAP;

import java.util.Map;
import java.util.TreeMap;

/**
 *
 * @author JUAN PABLO
 */
public class TREEMAP {

    public static void main(String[] args) {
        Map<Integer, String> treeMap = new TreeMap<>();
        
        treeMap.put(1, "Casillas");
        treeMap.put(15, "Ramos");
        treeMap.put(3, "Pique");
        treeMap.put(5, "Puyol");
        treeMap.put(11, "Capdevila");
        treeMap.put(14, "Xabi Alonso");
        treeMap.put(16, "Busquets");
        treeMap.put(8, "Xavi Hernandez");
        treeMap.put(18, "Pedrito");
        treeMap.put(6, "Iniesta");
        treeMap.put(7, "Villa");
        
        
        System.out.println("Clave: " + treeMap.keySet() + " -> Valor: " + treeMap);
    }
}
