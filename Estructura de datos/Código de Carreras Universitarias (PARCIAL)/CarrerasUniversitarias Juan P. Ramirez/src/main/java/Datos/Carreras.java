/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Datos;

/**
 *
 * @author ESTUDIANTE
 */

/* 
Estudiantes: Juan Pablo Ramirez Gutierrez - Fila B - Prueba 1
Código: 2020214033
*/

public class Carreras implements Comparable<Carreras> {
    private int codigo;
    private String nombre;
    private String tecnica;
    private int semestre;
    
    
    public Carreras(int codigo, String nombre, String tecnica, int semestre) {
        this.codigo = codigo;
        this.nombre = nombre;
        this.tecnica = tecnica;
        this.semestre = semestre;
    }

    @Override
    public String toString() {
        return "Carreras{" + "codigo=" + codigo + ", nombre=" + nombre + ", tecnica=" + tecnica + ", semestre=" + semestre + '}';
    }

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
     * @return the tecnica
     */
    public String getTecnica() {
        return tecnica;
    }

    /**
     * @param tecnica the tecnica to set
     */
    public void setTecnica(String tecnica) {
        this.tecnica = tecnica;
    }

    @Override
    public int compareTo(Carreras o) {
        return this.getNombre().compareTo(o.getNombre());
    }

    /**
     * @return the semestre
     */
    public int getSemestre() {
        return semestre;
    }

    /**
     * @param semestre the semestre to set
     */
    public void setSemestre(int semestre) {
        this.semestre = semestre;
    }
}
