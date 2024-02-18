/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package datos;
import java.util.Comparator;
/**
 *
 * @author Estudiante
 */
public class ComparatorPorNombre implements Comparator <Colegios>{

    @Override
    public int compare(Colegios o1, Colegios o2) {
        return o1.getNombre().compareTo(o2.getNombre());
    }
    
}
