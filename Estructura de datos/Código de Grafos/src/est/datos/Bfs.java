/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package est.datos;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;

/**
 *
 * @author Estudiante
 */
public class Bfs <V,A>{
    HashSet <V> visitados = new HashSet <>();
    LinkedList <V> cola=new LinkedList <>();
    public void limpiar(){
        visitados.clear(); 
    }
    public void anchura(Grafo<V,A> g, V vertice){
        cola.addLast(vertice);
        while(!cola.isEmpty()){
           V verticeP= cola.removeFirst();
           System.out.println(" "+verticeP.toString());  
           visitados.add(verticeP);
           ArrayList<V> sucesores = g.sucesores(posicion(g, verticeP));
            for (V sucesore : sucesores) {
                if(!visitados.contains(sucesore)){
                    cola.addLast(sucesore);
                }
            }
        }
        
        

    }
    
    
    private int posicion(Grafo<V, A> g, V vertice) {
        for (int i = 0; i < g.orden(); i++) {
            if(g.obtVertice((i)).equals(vertice)){
                return i;
            }
        }
        return -1;
    }
}
