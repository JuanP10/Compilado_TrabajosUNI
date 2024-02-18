/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package datos;

/**
 *
 * @author Estudiante
 */
public class Colegios {
    private String Nombre;
    private String Paises;

    @Override
    public String toString() {
        return "Colegios{" + "Nombre=" + getNombre() + ", Paises=" + getPaises() + '}';
    }

    public Colegios(String Nombre, String Paises) {
        this.Nombre = Nombre;
        this.Paises = Paises;
    }

    /**
     * @return the Nombre
     */
    public String getNombre() {
        return Nombre;
    }

    /**
     * @param Nombre the Nombre to set
     */
    public void setNombre(String Nombre) {
        this.Nombre = Nombre;
    }

    /**
     * @return the Paises
     */
    public String getPaises() {
        return Paises;
    }

    /**
     * @param Paises the Paises to set
     */
    public void setPaises(String Paises) {
        this.Paises = Paises;
    }
}
