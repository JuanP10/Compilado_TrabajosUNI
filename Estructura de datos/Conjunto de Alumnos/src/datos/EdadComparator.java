/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package datos;

import java.util.Comparator;

/**
 *
 * @author ESTUDIANTE
 */
public class EdadComparator implements Comparator<Alumno>{

    @Override
    public int compare(Alumno t, Alumno t1) {
        return t.getEdad()-t1.getEdad();
    }

    @Override
    public Comparator<Alumno> reversed() {
        return Comparator.super.reversed(); //To change body of generated methods, choose Tools | Templates.
    }
    
}
