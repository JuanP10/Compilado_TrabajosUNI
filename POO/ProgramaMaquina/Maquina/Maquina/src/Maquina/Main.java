package tragaperras;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Fruta[] combinacion1 = {Fruta.FRESA, Fruta.FRESA, Fruta.FRESA};
        Premio premio1 = new Premio(combinacion1, 20);
        Fruta[] combinacion2 = {Fruta.SANDIA, Fruta.FRESA,Fruta.SANDIA};
        Premio premio2 = new Premio(combinacion2, 10);

        Maquina maquina = new Maquina(3, 0.5, premio1, premio2);

        System.out.println("Introduzca el crédito: ");
        Scanner teclado = new Scanner(System.in);
        double credito = teclado.nextDouble();
        teclado.nextLine();
        maquina.incrementarCredito(credito);

        while (maquina.getCreditodisp() > 0){
            Fruta[] combinacion = maquina.jugar();
            System.out.println(Arrays.toString(combinacion) + " --- " + maquina.getCreditodisp());
        }
    }
}

