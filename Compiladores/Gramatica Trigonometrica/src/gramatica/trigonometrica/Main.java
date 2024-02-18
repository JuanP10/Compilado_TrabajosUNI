

package gramatica.trigonometrica;

import java.util.Scanner;

public class Main {
    public static void main(String args[])
    {
        Scanner leer = new Scanner(System.in);
        System.out.println("Introduzca su secuencia: ");
        String secuencia = leer.next();

        Tokens token = new Tokens(secuencia, false);
        Pila parser = new Pila(token);
        boolean truth = parser.parse();
        
        if(truth)
        {
            System.out.println("Iniciando proceso de evaluación semántica...");
            token.setIndex();
            Evaluador evaluador = new Evaluador(token);
            System.out.println("Convirtiendo...");
            evaluador.conversión();
            System.out.println("Evaluando...");
            evaluador.evaluacion();
        }
        else
        {
            System.out.println("Corregir secuencia...");
        }
    } 
}





