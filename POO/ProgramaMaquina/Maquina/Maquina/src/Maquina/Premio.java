package tragaperras;

import java.util.Arrays;

public class Premio {
    private final Fruta combinacionGanadora;
    private int cantidadDinero;

    public Fruta getCombinacionGanadora() {
        return combinacionGanadora;
    }

    public int getCantidadDinero() {
        return cantidadDinero;
    }

    public Premio(Fruta combinacionGanadora, int cantidadDinero) {
        this.combinacionGanadora = Arrays.copyOf(combinacionGanadora, combinacionGanadora);
        this.cantidadDinero = cantidadDinero;
    }

}
