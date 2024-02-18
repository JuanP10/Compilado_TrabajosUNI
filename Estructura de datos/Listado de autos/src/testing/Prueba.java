/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testing;

import datos.Auto;
import datos.Conjuntodeautos;

/**
 *
 * @author Estudiante
 */
public class Prueba {
    public static void main(String[] args) {
        Conjuntodeautos con = new Conjuntodeautos();
        con.addAuto(new Auto("xxx123", "Mazda", 1970, 500));
        con.addAuto(new Auto("xax153", "Renault", 2005, 550));
        con.addAuto(new Auto("xtx173", "Tesla", 2007, 600));
        con.addAuto(new Auto("mxx124", "Chevrolet", 2014, 700));
        con.addAuto(new Auto("jxx923", "Ford", 2018, 800));
        String listar = con.listar();
        System.out.println(" "+listar);
        float promedio = con.promedio();
        System.out.println("Promedio es "+promedio);
        
        con.listar();
        con.burbuja();
        System.out.println("Ordenado \n");
        con.listar();
    }
}
