import geometria.Punto;

public class PruebaPunto {
    public static void main(String[] args) {
        /*
         * Declara la variable local punto1 y asigna un objeto Punto 
         * en las coordenadas (1, 3). 
         * Muestra el valor de las propiedades x e y por la consola.
         */
        Punto punto1= new Punto(1, 3);
        punto1.imprimir();

        /*
         * Declara la variable punto2 y asigna un objeto Punto 
         * construido a partir del constructor sin parámetros. 
         * Muestra por la consola el valor de sus propiedades.
         */
        Punto punto2 = new Punto();
        punto2.imprimir(); 
        
        /*
         * Declara la variable punto3 y asigna un objeto Punto 
         * construido a partir del punto1 (constructor de copia). 
         * Muestra sus propiedades por la consola.
         */
        Punto punto3 = new Punto(punto1);
        punto3.imprimir();

        /*
         * Declara la variable punto4 y asígnale la variable punto2
         */
        Punto punto4 = punto2;
        punto4.imprimir();

        /*
         * Modifica las coordenadas de punto2 y 
         * muestra el valor de las propiedades por la consola. 
         * Muestra también el valor de las propiedades del punto4. 
         * Observa que tienen los mismos valores porque son referencias al mismo objeto.
         */
        punto2.setX(13);
        punto2.setY(10);

        punto2.imprimir();
        punto4.imprimir();

        punto1.distancia(punto2);

        Punto.mayorDistancia(punto1, punto2, punto3);
        Punto.mayorDistancia(punto1);
        Punto.mayorDistancia(punto2,punto3);
        Punto.mayorDistancia(punto1, punto2, punto3, punto4);
        Punto.mayorDistancia();
    }


}
