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
public class Alumno implements Comparable<Alumno>{
    private int codigo;
    private String nombre;
    private int edad;
    private float promedio;

    // Carrera 
    
    /**
     * @return the codigo
     */
    public int getCodigo() {
        return codigo;
    }

    /**
     * @param codigo the codigo to set
     */
    public void setCodigo(int codigo) {
        this.codigo = codigo;
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
     * @return the promedio
     */
    public float getPromedio() {
        return promedio;
    }

    /**
     * @param promedio the promedio to set
     */
    public void setPromedio(float promedio) {
        this.promedio = promedio;
    }

    public Alumno(int codigo, String nombre, int edad, float promedio) {
        this.codigo = codigo;
        this.nombre = nombre;
        this.edad = edad;
        this.promedio = promedio;
        
    }


    @Override
    public int compareTo(Alumno t) {
        return this.nombre.compareTo(t.nombre);
    }

    @Override
    public String toString() {
        return "Alumno{" + "codigo=" + codigo + ", nombre=" + nombre + ", edad=" + edad + ", promedio=" + promedio + '}';
    }
    
}
