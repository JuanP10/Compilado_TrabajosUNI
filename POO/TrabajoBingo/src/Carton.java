
import java.util.LinkedList;
public class Carton {
    private final LinkedList<LinkedList<Integer>> numeros = new LinkedList();
    private final int tamaño;

    public Carton() {
        this.tamaño = this.numeros.size();
    }

    public LinkedList<LinkedList<Integer>> getNumeros() {
        return numeros;
    }

    public void agregarNumerosAlCarton(LinkedList<Integer> numero) {
        this.numeros.add(numero);
    }

}
