package geometria;

public class Rectangulo {
    private int ladoX;
    private int ladoY;
    public Punto verticeII;
    public Punto verticeSI;
    public Punto verticeSD;
    public Punto verticeID;
    public Punto perimetro;


    public Rectangulo(int ladoX, int ladoY, Punto verticeSI) {
        this.ladoX = ladoX;
        this.ladoY = ladoY;
        this.verticeII = verticeSI;
    }

    //Getters and Setters

    public int getLadoX() {
        return ladoX;
    }

    public void setLadoX(int ladoX) {
        this.ladoX = ladoX;
    }

    public int getLadoY() {
        return ladoY;
    }

    public void setLadoY(int ladoY) {
        this.ladoY = ladoY;
    }

    public Punto getVerticeSI() {
        return verticeII;
    }

    public void setVerticeSI(Punto verticeSI) {
        this.verticeII = verticeSI;
    }

    public Punto verticeSD(){
        Punto SD = new Punto(verticeII.getX()+ladoX, verticeII.getY()+ladoY);
        return SD;
    }

    public Punto verticeID(){
        Punto ID = new Punto(verticeII.getX()+ladoX, verticeII.getY());
        return  ID;
    }

    public Punto verticeSI(){
        Punto SI = new Punto(verticeII.getX(), verticeII.getY()+ladoY);
        return SI;
    }

    public int perimetro(){
        return ((2*ladoX)+(2*ladoY));
    }

    public void desplazar(Direccion direccion,int Cantidad){
        switch(direccion){
            case ARRIBA:   
                verticeII.setY(verticeII.getY()+Cantidad);
                break;
            case ABAJO:
                verticeII.setY(verticeII.getY()-Cantidad);
                break;
            case IZQUIERDA:
                verticeII.setX(verticeII.getX()-Cantidad);
                break;
            case DERECHA:
                verticeII.setX(verticeII.getX()+Cantidad);
                break;
            
        }
    }

    public void escalar(int Porcentaje){
        this.ladoX *= (Porcentaje/100);
        this.ladoY *= (Porcentaje/100);
    }

}
