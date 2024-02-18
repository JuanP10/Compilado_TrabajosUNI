/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Poli;

/**
 *
 * @author JUAN PABLO
 */

// SuperCLASE - Esta va a heredar los atributos y el metodo MOSTRARDATOS a las subclases

public class Vehiculos {
    
    /*Este encapsulamiento es un tipo de visibilidad de los atributos y metodos como  public y private
      Este lo hace accesible desde la clase actual, sus descendentes o el paquete que hace parte.
    
      Si el atributo o Metodo no posee ninguna palabra, significa que es accesible desde cualquier paquete
      Por ejemplo el siguiente atributo;
    */
    String nada;
    
    ///
    protected String Modelo;
    protected String Marca;
    protected String Placa;
    
    
    public String MostrarDatos(){
        //Muestra acá solo los datos de la super clase, ya que son los unicos
        return "Modelo: "+Modelo +"\nMarca:" +Marca + "\nPlaca" +Placa;
    }

    public Vehiculos(String Modelo, String Marca, String Placa) {
        this.Modelo = Modelo;
        this.Marca = Marca;
        this.Placa = Placa;
    }

    /**
     * @return the Modelo
     */
    public String getModelo() {
        return Modelo;
    }

    /**
     * @param Modelo the Modelo to set
     */
    public void setModelo(String Modelo) {
        this.Modelo = Modelo;
    }

    /**
     * @return the Marca
     */
    public String getMarca() {
        return Marca;
    }

    /**
     * @param Marca the Marca to set
     */
    public void setMarca(String Marca) {
        this.Marca = Marca;
    }

    /**
     * @return the Placa
     */
    public String getPlaca() {
        return Placa;
    }

    /**
     * @param Placa the Placa to set
     */
    public void setPlaca(String Placa) {
        this.Placa = Placa;
    }
}
