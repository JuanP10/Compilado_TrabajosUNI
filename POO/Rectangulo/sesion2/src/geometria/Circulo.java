package geometria;

public class Circulo {
    private Punto centro;
    private int radio;
    public static final int RADIO_POR_DEFECTO = 5;   //Investigar esto!!!
    /**
     * 
- 
- Utilizando un constructor de copia!!!
     */

     /*Estableciendo el punto que representa el centro y el radio. */
     public Circulo(Punto centro, int radio) {
        this.centro = new Punto(centro);
        this.radio = radio;
    } 

    /*Tomando como valores por defecto el origen de coordenadas, para el centro, y 5
para el radio. Los valores por defecto deben definirse como constantes. */
    public Circulo(){
       this(new Punto(), RADIO_POR_DEFECTO);
    }
    public Punto getCentro() {
        return new Punto(centro);
    }
  
    public int getRadio() {
        return radio;
    }

    public double getPerimetro(){
        return 2 * Math.PI * radio * radio;
    }

    public void desplazar(int cantidadX, int cantidadY){
        this.centro.desplazar(cantidadX, cantidadY);
    }

    public void desplazar(Punto nuevoCentro){
        this.centro = new Punto(nuevoCentro);
    }

    public void escalar(int porcentaje){
        this.radio *=  porcentaje/100;
    }
}
