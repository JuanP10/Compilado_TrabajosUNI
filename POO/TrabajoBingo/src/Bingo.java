import java.util.Collections;
import java.util.Iterator;
import java.util.Objects;
import java.util.stream.IntStream;

import java.util.LinkedList;

public class Bingo {
    private LinkedList<Integer> bombo = new LinkedList();
    private LinkedList<Integer> bolasExtraidas;
    private LinkedList<Carton> cartones;
    private LinkedList<Carton> cartonesGanadores;

    public LinkedList<Carton> getCartonesGanadores() {
        return cartonesGanadores;
    }

    private boolean finalizado;

    public boolean isFinalizado() {
        return finalizado;
    }

    public Bingo() {
        IntStream var10000 = IntStream.rangeClosed(1, 30);
        LinkedList var10001 = this.bombo;
        Objects.requireNonNull(var10001);
        var10000.forEach(var10001::add);
        this.bolasExtraidas = new LinkedList();
        this.cartones = new LinkedList();
        this.cartonesGanadores = new LinkedList();
        this.finalizado = false;
    }
    public boolean comprobarCarton(Carton carton) {
        boolean comprobado = false;
        Iterator var3 = this.cartones.iterator();
        if (var3.hasNext()) {
            Carton carton1 = (Carton)var3.next();
            if (carton.getNumeros().contains(carton1)) {
                comprobado = true;
            }
        }

        return comprobado;
    }

    public Carton genrarCarton(Carton carton) {
        LinkedList<Integer> todosLosNumeros = new LinkedList();
        IntStream var10000 = IntStream.rangeClosed(1, 30);
        Objects.requireNonNull(todosLosNumeros);
        var10000.forEach(todosLosNumeros::add);
        Collections.shuffle(todosLosNumeros);
        LinkedList<Integer> numerosDelCarton = new LinkedList();
        for(int i = 0; i < 9; ++i) {
            numerosDelCarton.add(todosLosNumeros.get(i));
        }
        carton.agregarNumerosAlCarton(numerosDelCarton);
        this.cartones.add(carton);
        return carton;
    }

    public int extraerBola() {
        Collections.shuffle(this.bombo);
        this.bolasExtraidas.add(bombo.get(0));
        this.bombo.remove(0);
        Iterator var2 = this.cartones.iterator();

        while(var2.hasNext()) {
            Carton cart = (Carton)var2.next();
            if (this.comprobarCarton(cart)) {
                this.cartonesGanadores.add(cart);
            }
        }
        return bombo.get(0);
    }
}
