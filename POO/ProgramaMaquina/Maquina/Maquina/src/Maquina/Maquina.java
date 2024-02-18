package tragaperras;

import java.util.Arrays;
import java.util.Random;

public class Maquina {
    private final int numeroCasillas;
    private double precioJugada;
    private int creditodisp;
    private final Premio premios;

    public Maquina(int numeroCasillas, double precioJugada, Premio creditodisp, Premio premios) {
        this.numeroCasillas = numeroCasillas;
        this.precioJugada = precioJugada;
        this.creditodisp = creditodisp.getCantidadDinero();
        this.premios = premios;
    }

    public void incrementarCredito(double cantidad){
        creditodisp += cantidad;
    }

    public Fruta[] jugar() {
        if (creditodisp >= precioJugada) {
            creditodisp -= precioJugada;

            Fruta[] combinacion = new Fruta[numeroCasillas];
            Random rnd = new Random();

            for (int i = 0; i < numeroCasillas; i++) {
                combinacion[i] = Fruta.values()[rnd.nextInt(Fruta.values().length)];
            }

            for (Premio premio : premios) {
                if (Arrays.equals(premio.getCombinacionGanadora(), combinacion)) {
                    creditodisp += premio.getCantidadDinero();
                    break;
                }
            }

            return combinacion;
        } else {
            return null;
        }
    }

    public int getCreditodisp() {
        return creditodisp;
    }

}
