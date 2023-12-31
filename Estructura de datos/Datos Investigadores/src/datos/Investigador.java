/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package datos;

/**
 *
 * @author ESTUDIANTE
 */
public class Investigador {
 private String nombre;
 private int edad;
 private int cedula;
 private String locacacionCiudad;
 private String locacionPais;

    public Investigador(String nombre, int edad, int cedula, String locacacionCiudad, String locacionPais) {
        this.nombre = nombre;
        this.edad = edad;
        this.cedula = cedula;
        this.locacacionCiudad = locacacionCiudad;
        this.locacionPais = locacionPais;
    }

    @Override
    public String toString() {
        return "Investigador{" + "nombre=" + nombre + ", edad=" + edad + ", cedula=" + cedula + ", locacacionCiudad=" + locacacionCiudad + ", locacionPais=" + locacionPais + '}';
    }

    /**
     * @return the nombre
     */
    public String getNombre() {
        return nombre;
    }

    /**
     * @param nombre the nombre to set
     */
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    /**
     * @return the edad
     */
    public int getEdad() {
        return edad;
    }

    /**
     * @param edad the edad to set
     */
    public void setEdad(int edad) {
        this.edad = edad;
    }

    /**
     * @return the cedula
     */
    public int getCedula() {
        return cedula;
    }

    /**
     * @param cedula the cedula to set
     */
    public void setCedula(int cedula) {
        this.cedula = cedula;
    }

    /**
     * @return the locacacionCiudad
     */
    public String getLocacacionCiudad() {
        return locacacionCiudad;
    }

    /**
     * @param locacacionCiudad the locacacionCiudad to set
     */
    public void setLocacacionCiudad(String locacacionCiudad) {
        this.locacacionCiudad = locacacionCiudad;
    }

    /**
     * @return the locacionPais
     */
    public String getLocacionPais() {
        return locacionPais;
    }

    /**
     * @param locacionPais the locacionPais to set
     */
    public void setLocacionPais(String locacionPais) {
        this.locacionPais = locacionPais;
    } 
   /* public int compareTo(Investigador t){
        return this.cedula.compareTo(t.getCedula());
    }*/
 /* e.	Buscar por nombre(binaria)  */
/*f. ordenar por nombre (algoritmo propio)  */
/*g.	buscar por cedula(secuencial)*/

  
}
