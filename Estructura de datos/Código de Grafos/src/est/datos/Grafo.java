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
public interface Grafo<V,A> {
    void insVertice(V x);
    V obtVertice(int pos);
    void insArista(int vi, int vf, A costo);
    void modArista(int vi, int vf, A costo);
    A costoArista(int vi, int vf);
    int orden();
    String mostrar();
    ArrayList<V> sucesores(int v);
}
