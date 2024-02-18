/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Poli;

/**
 *
 * @author JUAN PABLO
 */
//Segunda subclase el cual también heredará los atributos y metodos de la SUPERCLASE 

/*
  Si por ejemplo queremos heredar de otra clase y no de Vehiculos, por ejemplo de los de turimos,
  Tendremos los tres atributos de Modelo, Marca y Placa, además también el numero de puertas, pero NO
  el de tiempo, porque esta privado

*/

public class VehDeportivos extends VehTurismo{
    private int cilindrada; 
    
    @Override
    public String MostrarDatos(){
        return "Modelo: "+Modelo +"\nMarca:" +Marca + "\nPlaca" +Placa +"\nNumero de Puertas" +NumPuertas +"\nCilindrada"+cilindrada + "\nTiempo"+tiempo;
    }

    /**
     * @return the cilindrada
     */
    public int getCilindrada() {
        return cilindrada;
    }

    /**
     * @param cilindrada the cilindrada to set
     */
    public void setCilindrada(int cilindrada) {
        this.cilindrada = cilindrada;
    }

    public VehDeportivos(int cilindrada, int NumPuertas, int tiempo, String Modelo, String Marca, String Placa) {
        super(NumPuertas, tiempo, Modelo, Marca, Placa);
        this.cilindrada = cilindrada;
    }

    

    
}
