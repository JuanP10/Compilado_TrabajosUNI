/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Class;

/**
 *
 * @author JUAN PABLO
 */

//Esta clase es como cualquer otra, puede poseer metodos, atributos, constructores etc. 
//Pero tiene que contener como minimo UN METODO ABSTRACTO

public abstract class FIGURA {
    
    
    
    protected double x; //Pos en X
    protected double y; //Pos en Y
    
    

    public FIGURA(double x, double y) {
        this.x = x;
        this.y = y;
    }
    
    
    public abstract double calcularArea(); //METODO ABSTRACTO
    //El metodo abstracto define el QUÉ hará, pero no el CÓMO, eso lo hara cada clase
}
