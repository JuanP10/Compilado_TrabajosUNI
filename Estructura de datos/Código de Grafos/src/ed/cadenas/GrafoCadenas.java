/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ed.cadenas;

import est.datos.Bfs;
import est.datos.Dfs;
import est.datos.Grafo;
import est.datos.GrafoMat;
import java.util.Arrays;

/**
 *
 * @author Estudiante
 */
public class GrafoCadenas {

    private static float porOcupacion(Grafo<String, Double> grafo) {
        int c=0;
        int n=grafo.orden()*(grafo.orden()-1);
        for (int i = 0; i < grafo.orden(); i++) {
            for (int j = 0; j < grafo.orden(); j++) {
                Double numero = grafo.costoArista(i, j);
                if(numero!=GrafoMat.inf && numero!=0){
                    c++;
                }
            }
        }
        return (float) c/n*100;
    }
    
    public Grafo<String, Double> crearGrafo(){
        Grafo<String, Double> grafo=new GrafoMat<>();
        grafo.insVertice("C1");
        grafo.insVertice("C2");
        grafo.insVertice("C3");
        grafo.insVertice("C4");
        grafo.insVertice("C5");
        grafo.insVertice("C6");
        grafo.insVertice("C7");
        grafo.insVertice("C8");
        grafo.insVertice("C9");
        grafo.insVertice("C10");
        
        grafo.insArista(0, 1, 3.0);
        grafo.insArista(0, 2, 7.0);
        
        grafo.insArista(1, 4, 3.0);
        grafo.insArista(1, 6, 3.0);
        grafo.insArista(1, 3, 15.0);
        
        grafo.insArista(2, 3, 2.0);
        grafo.insArista(2, 5, 12.0);
        
        grafo.insArista(3, 2, 6.0);
        grafo.insArista(3, 6, 10.0);
        
        grafo.insArista(4, 8, 1.0);
        grafo.insArista(4, 3, 7.0);
        
        grafo.insArista(5, 9, 4.0);
        
        grafo.insArista(6, 7, 5.0);
        grafo.insArista(6, 4, 3.0);
        grafo.insArista(6, 5, 3.0);
        grafo.insArista(6, 10, 1.0);
        
        grafo.insArista(7, 6, 1.0);
        grafo.insArista(7, 8, 2.0);
        
        grafo.insArista(8, 7, 3.0);
        grafo.insArista(8, 6, 3.0);
        
        grafo.insArista(9, 8, 2.0);
        grafo.insArista(9, 2, 4.0);
        
        return grafo;
    }
    
    //GRAFO ALEATORIO
    public Grafo<String, Double> generarGrafo(int n){
        Grafo<String, Double> grafo= new GrafoMat<>();//Que el grafo tenga una matriz de aristas
        for (int i = 0; i < n; i++) {
            grafo.insVertice("Vert: "+i);
        }
        int naristas= n*(n-1);
        for (int i = 0; i <naristas ; i++) {
            int vi= (int)(Math.random()*n);
            int vf= (int)(Math.random()*n);
            if(vi!=vf){//Porque la diagonal principal no puede estar llena
                double costo= (int) (Math.random()*1000);
                grafo.insArista(vi, vf, costo);
            }
        }
        return grafo;
    }
    
    //HALLAR VÉRTICE CON MENOS SALIDAS
    public String menosSalidas(Grafo<String, Double> g){
        int men=9999;
        String vertmen="";
        for (int i = 0; i < g.orden(); i++) {
            if(g.sucesores(i).size()<men){
                men=g.sucesores(i).size();
                vertmen=g.obtVertice(i);
            }
        }
        return vertmen;
    }
    
    //HALLAR ARISTA MÁS COSTOSA
    public double aristaMasCostosa(Grafo<String, Double> g){
        double mayor=0;
        for (int i = 0; i < g.orden(); i++) {
            for (int j = 0; j < g.orden(); j++) {
                double aristas=g.costoArista(i, j);
                if(aristas!=GrafoMat.inf){//No puede ser infinito porque el infinito es mayor que todos los números
                    if(aristas>mayor){
                        mayor=aristas;
                        //Para devolver los vértices se guardan en una lista o vector
                    }
                }
            }
        }
        return mayor;
    }
    
    //DECIR SI UN VÉRTICE ESTÁ COMPLETO
    public boolean estaCompletoVertice(Grafo<String, Double> g, String v){
        int pos= buscarVertice(g,v);
        if(pos!=-1){//Porque no hay esa posición
            for (int i = 0; i < g.orden(); i++) {
                if(g.costoArista(pos, i)==GrafoMat.inf){
                    return false;
                }
            }
            return true;
        }
        return false;
    }
    
    
    private int buscarVertice(Grafo<String, Double> g, String v) {
        for (int i = 0; i < g.orden(); i++) {
            if(g.obtVertice(i).equals(v)){
                return i;
            }
        }
        return -1;
    }
    
    //INVERTIR UN GRAFO
    //AISLAR UN VERTICE
    public void aislarVertice(Grafo<String, Double> g, String v){
        int pos=buscarVertice(g, v);
        if(pos!=-1){
            for (int i = 0; i < g.orden(); i++) {
                g.modArista(pos, i, GrafoMat.inf);
                g.modArista(i, pos, GrafoMat.inf);
            } 
        }
    }
    
    //RECORRER UN GRAFO PROFUNDIDAD Y ANCHURA
    
    public static void main(String[] args) {
        //HACER MÉTODO ANTESCESORES
        GrafoCadenas gra=new GrafoCadenas();
        Grafo<String, Double> grafo =gra.crearGrafo();
        int n=20;
        for (int i = 0; i < grafo.orden(); i++) {
            ed.cadenas.Dijsktra d = new ed.cadenas.Dijsktra(grafo,i);
            System.out.println("Resultado: "+Arrays.toString(d.d));    
        }
        
        System.out.println("\n");
        
        ed.cadenas.Floyd floy= new ed.cadenas.Floyd(grafo);
        System.out.println(""+floy.mostrar());
        System.out.println("Ruta ... ");
        floy.ruta(0, 4);
        
        //Grafo<String, Double> grafo = gra.generarGrafo(20);
        System.out.println(" "+grafo.mostrar());
        Dfs<String,Double> rec=new Dfs<>();
        rec.profundidad(grafo, "A");
        
        
        float por=porOcupacion(grafo);
        System.out.println("Ocupación "+por);
        System.out.println("Menos salida: "+gra.menosSalidas(grafo));
        System.out.println("Arista más costosa: "+gra.aristaMasCostosa(grafo));
        
    }
}
