import geometria.Direccion;
import geometria.Punto;
import geometria.Rectangulo;

public class PruebaRectangulo {
    public static void main(String[] args) {
        Punto VII = new Punto(3,1);
        Rectangulo Rec = new Rectangulo(2,5,VII);

        System.out.println("Primera coordenada (Color azul)");
        System.out.println("VII ("+Rec.verticeII.getX()+", "+Rec.verticeII.getY()+")");
        System.out.println("VSD ("+Rec.verticeSD().getX()+", "+Rec.verticeSD().getY()+")");
        System.out.println("VSI ("+Rec.verticeSI().getX()+", "+Rec.verticeSI().getY()+")");
        System.out.println("VID ("+Rec.verticeID().getX()+", "+Rec.verticeID().getY()+")");
        System.out.println("");

        System.out.println("Segunda coordenada (Color rojo)");
        Rec.desplazar(Direccion.ABAJO,7);
        System.out.println("VII ("+Rec.verticeII.getX()+", "+Rec.verticeII.getY()+")");
        System.out.println("VSD ("+Rec.verticeSD().getX()+", "+Rec.verticeSD().getY()+")");
        System.out.println("VSI ("+Rec.verticeSI().getX()+", "+Rec.verticeSI().getY()+")");
        System.out.println("VID ("+Rec.verticeID().getX()+", "+Rec.verticeID().getY()+")");

    }
}
