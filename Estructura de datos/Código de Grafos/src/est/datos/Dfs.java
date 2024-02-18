/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package est.datos;

import java.util.ArrayList;
import java.util.HashSet;

/**
 *
 * @author Estudiante
 */
public class Dfs <V,A>{
    HashSet <V> visitados = new HashSet <>();
    public void limpiar(){
        visitados.clear(); 
    }
    
    public void profundidad (Grafo<V,A> g, V vertice){
        System.out.println(" "+vertice.toString());
        visitados.add(vertice);
        int pos = posicion (g,vertice);
        ArrayList<V> sucesores =g.sucesores(pos);
        for (V sucesore : sucesores) {
            if(!visitados.contains(sucesore)){
                profundidad(g, sucesore);
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
