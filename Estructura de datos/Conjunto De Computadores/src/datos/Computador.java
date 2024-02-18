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
public class Computador implements Comparable<Computador>{
    private String referencia;
    private String marca;
    private float precio;

    @Override
    public String toString() {
        return "Computador{" + "referencia=" + referencia + ", marca=" + marca + ", precio=" + precio + '}';
    }

    public Computador(String referencia, String marca, float precio) {
        this.referencia = referencia;
        this.marca = marca;
        this.precio = precio;
    }

    /**
     * @return the referencia
     */
    public String getReferencia() {
        return referencia;
    }

    /**
     * @param referencia the referencia to set
     */
    public void setReferencia(String referencia) {
        this.referencia = referencia;
    }

    /**
     * @return the marca
     */
    public String getMarca() {
        return marca;
    }

    /**
     * @param marca the marca to set
     */
    public void setMarca(String marca) {
        this.marca = marca;
    }

    /**
     * @return the precio
     */
    public float getPrecio() {
        return precio;
    }

    /**
     * @param precio the precio to set
     */
    public void setPrecio(float precio) {
        this.precio = precio;
    }

    @Override
    public int compareTo(Computador t) {
        return this.marca.compareTo(t.getMarca());
    }
}
