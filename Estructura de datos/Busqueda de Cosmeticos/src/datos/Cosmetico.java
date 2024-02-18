/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package datos;

import java.io.Serializable;

/**
 *
 * @author -Valentina, Juan, ELiseo y Santiago-
 */
public class Cosmetico implements Serializable {
    private String Tipo;
    private int Codigo;
    private float precio;
    private int cantidad;
    private String Variacion;


    public Cosmetico(String Tipo, int Codigo, float precio, int cantidad, String Variacion) {
        this.Tipo = Tipo;
        this.Codigo = Codigo;
        this.precio = precio;
        this.cantidad = cantidad;
        this.Variacion = Variacion;
    }
    
    @Override
    public String toString() {
        return "Cosmetico{" + "Tipo: " + Tipo + ", Codigo: " + Codigo + ", Precio: " + precio + ", Cantidad: " + cantidad + ", Variacion: " + Variacion + '}';
    }

    /**
     * @return the Tipo
     */
    public String getTipo() {
        return Tipo;
    }

    /**
     * @param Tipo the Tipo to set
     */
    public void setTipo(String Tipo) {
        this.Tipo = Tipo;
    }

    /**
     * @return the Codigo
     */
    public int getCodigo() {
        return Codigo;
    }

    /**
     * @param Codigo the Codigo to set
     */
    public void setCodigo(int Codigo) {
        this.Codigo = Codigo;
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

    /**
     * @return the cantidad
     */
    public int getCantidad() {
        return cantidad;
    }

    /**
     * @param cantidad the cantidad to set
     */
    public void setCantidad(int cantidad) {
        this.cantidad = cantidad;
    }

    /**
     * @return the Variacion
     */
    public String getVariacion() {
        return Variacion;
    }

    /**
     * @param Variacion the Variacion to set
     */
    public void setVariacion(String Variacion) {
        this.Variacion = Variacion;
    }
}
