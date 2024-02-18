/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Class;

/**
 *
 * @author JUAN PABLO
 */
public class Cuadrado extends FIGURA{
    
    private double lado;

    public Cuadrado(double lado, double x, double y) {
        super(x, y);
        this.lado = lado;
    }
    
    //Cada clase que heradará FIGURA tiene que usar los metodos abstractos

    @Override
    public double calcularArea() {
        return lado*lado;    
    }
    
    
}
