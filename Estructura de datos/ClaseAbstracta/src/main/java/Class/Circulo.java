/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Class;

/**
 *
 * @author JUAN PABLO
 */
public class Circulo extends FIGURA {
    
    private double radio;

    public Circulo(double radio, double x, double y) {
        super(x, y);  //Esto llama el constructor de la clase padre, es decir de FIGURA
        this.radio = radio;
    }
    

    @Override
    public double calcularArea() {
        return 3.14*(radio*radio);
    }
    
}
