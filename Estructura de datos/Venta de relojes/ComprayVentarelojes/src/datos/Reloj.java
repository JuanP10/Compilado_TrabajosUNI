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

    public Reloj(String reloj, float costo, int modelo) {
        this.ref = reloj;
        this.costo = costo;
        this.modelo = modelo;
    }

    @Override
    public String toString() {
        return "Ref{" + "Ref=" + ref + ", Costo=" + costo + ", Modelo=" + modelo + '}';
    }
    
    

    /**
     * @return the reloj
     */
    public String getRef() {
        return ref;
    }

    /**
     * @param reloj the reloj to set
     */
    public void setReloj(String reloj) {
        this.ref = reloj;
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
