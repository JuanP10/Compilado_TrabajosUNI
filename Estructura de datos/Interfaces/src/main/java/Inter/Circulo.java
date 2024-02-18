/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Inter;

/**
 *
 * @author JUAN PABLO
 */

//Acá podemos impementear cuantas interfaces querramos

public class Circulo implements AreaFiguras {
    
    private double lado;
    
    
    //En la interfaz no se necesita el SUPER que es para llamar el constructor de la SUPERCLASE
    public Circulo(double lado) {
        this.lado = lado;
    }
    
    

    @Override
    public double CalcularArea() {
        return lado*lado;
    }
    
}
