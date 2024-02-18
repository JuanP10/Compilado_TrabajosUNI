/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Poli;

/**
 *
 * @author JUAN PABLO
 */

/* Primera subclase, el cual heredará los tres atributos  y el metodo de la SUPERCLASE
   Esta subclase tendrá otro atributo que el NUMdePuertas, por ello, el metodo MostrarDatos
   Tiene que mostrar estos 4 atributos, es decir, el objeto cambiará

Para heredar, solo se usa extends y luego el nombre de la super clase

RECUERDA: - Solo se puede HEREDAR de una superclase y ya, su necesito más, se hace interface y es con implements
          - Los atributos y metodos de la SUPERCLASE que esten en privado no se heredarán 

*/
public class VehTurismo extends Vehiculos {
     int NumPuertas;
     int tiempo;
    
    //El Override es porque se va a sobreescribir el metodo de la SUPERCLASE
    @Override
    public String MostrarDatos(){
        //Mostrará los atributos herados y además, el numero de puertas y el tiempo 
        
        return "Modelo: "+Modelo +"\nMarca:" +Marca + "\nPlaca" +Placa +"\nNumero de Puertas" +NumPuertas +"\nTiempo" +tiempo ;
    }

    /**
     * @return the NumPuertas
     */
    public int getNumPuertas() {
        return NumPuertas;
    }

    /**
     * @param NumPuertas the NumPuertas to set
     */
    public void setNumPuertas(int NumPuertas) {
        this.NumPuertas = NumPuertas;
    }

    /**
     * @return the tiempo
     */
    public int getTiempo() {
        return tiempo;
    }

    /**
     * @param tiempo the tiempo to set
     */
    public void setTiempo(int tiempo) {
        this.tiempo = tiempo;
    }

    public VehTurismo(int NumPuertas, int tiempo, String Modelo, String Marca, String Placa) {
        super(Modelo, Marca, Placa);
        this.NumPuertas = NumPuertas;
        this.tiempo = tiempo;
    }
    
    
    
}
