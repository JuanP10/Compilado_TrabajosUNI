/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package est.datos;

import java.util.ArrayList;

/**
 *
 * @author Estudiante
 */
public class GrafoMat<V,A> implements Grafo<V, A> {
    //La fila representa lo que va saliendo
    //La columna representa lo que va entrando
    
    private ArrayList<V> vertices;
    private Object aristas[][]; //Object es la clase papá de todas las clases en java
    public static double inf = 99999999;//Infinito pq no tienen enlace directo, es decir, no hay arista
                                        //Para reemplazar el valor de costo mínimo
    public GrafoMat() {
        vertices=new ArrayList<>();
        aristas=new Object[100][100];
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                if(i!=j){
                    aristas[i][j]=inf;
                }else{
                    aristas[i][j]=0.0;
                }
            }
        }
    }

    @Override
    public void insVertice(V x) {
        vertices.add(x);
    }

    @Override
    public V obtVertice(int pos) {
        return vertices.get(pos);
    }

    @Override
    public void insArista(int vi, int vf, A costo) {
        aristas[vi][vf]=costo;
    }

    @Override
    public A costoArista(int vi, int vf) {
        return (A) aristas[vi][vf];//Se hace casting pq una matriz no puede ser generica y eso lo convierte en generica
    }

    @Override
    public int orden() {
        return vertices.size();//Cantidad de vertices
    }

    @Override
    public String mostrar() {
        String lis="";
        lis+=" "+vertices.toString()+"\n";
        for (int i = 0; i < orden(); i++) {
            for (int j = 0; j < orden(); j++) {
                lis+=" "+aristas[i][j];
            }
            lis+="\n";
        }
        return lis;
    }

    @Override
    public ArrayList<V> sucesores(int v) {
        ArrayList<V> suce=new ArrayList<>();
        for (int i = 0; i < orden(); i++) {
            if(v!=i && !aristas[v][i].equals(inf)){
                suce.add(obtVertice(i));
            }
        }
        return suce;
    }

    @Override
    public void modArista(int vi, int vf, A costo) {
        aristas[vi][vf]=costo;
    }
    
}
