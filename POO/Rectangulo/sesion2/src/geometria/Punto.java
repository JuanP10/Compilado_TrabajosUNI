package geometria;

public class Punto {
    private int x;
    private int y;
    
    //Constructor con dos argumentos
    public Punto(int x, int y) {
        this.x = x;
        this.y = y;
    }
    //Constructor sin argumentos o constructor por defecto
    public Punto() {
       this(0,0);  
    }
    //Constructor de copia
    public Punto(Punto p){
        this(p.x, p.y);
    }

    //propiedades se pueden consultar
    public int getX() {
        return x;
    }
    public int getY() {
        return y;
    }

    //propiedades se pueden modifcar
    public void setX(int x) {
        this.x = x;
    }
    public void setY(int y) {
        this.y = y;
    }
    //Desplazar un incremento en x y un incremento en y
    public void desplazar(int incX, int incY){
        this.x += incX; //this.x = this.x + incX;
        this.y += incY;
    }
    /*
     * desplazar (versión sobrecargada): esta operación desplaza 
     * el punto una unidad según la dirección establecida como parámetro.
     */
    public void desplazar(Direccion direccion){
        switch(direccion){
            case ARRIBA:
                this.y++;
                break;
            case ABAJO:
                this.y--;
                break;
            case DERECHA:
                this.x++;
                break;
            case IZQUIERDA:
                this.x--;
                break;
        }
    }
   /*
    * recibe como parámetro una colección de puntos (argumento variable) 
    y devuelve aquel que esté más alejado del origen de coordenadas.
    */
    public static Punto mayorDistancia(Punto... puntos){
        Punto origen = new Punto();
        Punto masAlejado = origen;
        double mDistancia = 0.0;
        double distancia;
        for (Punto punto : puntos) {
            distancia = origen.distancia(punto);
            if( distancia > mDistancia){
                mDistancia = distancia;
                masAlejado = punto;
            }
        }

        return masAlejado;
    }
    public void imprimir() {
        System.out.println("(" + x + "," + y + ")");
    }
    /*
     * calcula la distancia euclídea entre un punto y otro 
     * que es establecido como parámetro
     */
    public double distancia(Punto punto){
        double xsAlCuadrado = Math.pow((this.x - punto.x), 2);
        double ysAlCuadrado = Math.pow(this.y - punto.y, 2);         
        return Math.sqrt(xsAlCuadrado + ysAlCuadrado );
    }
    
}
