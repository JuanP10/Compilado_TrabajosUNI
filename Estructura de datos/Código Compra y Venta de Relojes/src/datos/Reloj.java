/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package datos;

import java.io.Serializable;

/**
 *
 * @author ESTUDIANTE
 */
public class Reloj implements Serializable{
    private String ref;
    private float costo;
    private int modelo;

    public Reloj(String ref, float costo, int modelo) {
        this.ref = ref;
        this.costo = costo;
        this.modelo = modelo;
    }

    @Override
    public String toString() {
        return "Reloj{" + "Referencia: " + ref + ", Costo: " + costo + ", Modelo: " + modelo + '}';
    }
    

    /**
     * @return the ref
     */
    public String getRef() {
        return ref;
    }

    /**
     * @param ref the ref to set
     */
    public void setRef(String ref) {
        this.ref = ref;
    }

    /**
     * @return the costo
     */
    public float getCosto() {
        return costo;
    }

    /**
     * @param costo the costo to set
     */
    public void setCosto(float costo) {
        this.costo = costo;
    }

    /**
     * @return the modelo
     */
    public int getModelo() {
        return modelo;
    }

    /**
     * @param modelo the modelo to set
     */
    public void setModelo(int modelo) {
        this.modelo = modelo;
    }
    
    
    
}
