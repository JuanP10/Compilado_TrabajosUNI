import geometria.Circulo;
import geometria.Direccion;
import geometria.Punto;

public class PruebasSesion2 {
public static void main(String[] args) {
   

    Punto punto1 = new Punto(2,3);
    punto1.desplazar(Direccion.ARRIBA);
    System.out.println("Imprimir punto 1");
    punto1.imprimir();

    Punto punto2 = new Punto(4,2);
    double distancia = punto1.distancia(punto2);
    System.out.println("la distancia del punto1 al punto2 es : " + distancia );

    Punto puntoMasAlejado = Punto.mayorDistancia(punto1, punto2);
    System.out.println("El punto  mas alejado del origen es :");
    puntoMasAlejado.imprimir();

    Circulo circulo1 = new Circulo(punto1, 3);
    Circulo circulo2 = new Circulo(punto1, 5);
    
    circulo1.desplazar(3, 2);
    
    Punto centroCirculo1 = circulo1.getCentro();
    System.out.println("Imprimir centro del circulo1");
    centroCirculo1.imprimir();
    System.out.println("Imprimir centro del circulo2");
    circulo2.getCentro().imprimir();

    
    Punto centro = circulo2.getCentro();
  
    centro.desplazar(Direccion.ABAJO);
  
    System.out.println("Imprimir el centro del circulo2 desplazado");
    centro.imprimir();
   
    System.out.println("Imprimir el centro del circulo2");
    circulo2.getCentro().imprimir();

    circulo2.escalar(150);
    System.out.println("Propiedades del c'irculo2: centro ("
                        + circulo2.getCentro().getX() + "," + circulo2.getCentro().getY() 
                        + " y radio " + circulo2.getRadio());


}

    
}
