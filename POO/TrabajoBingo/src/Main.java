import java.io.PrintStream;
import java.util.Iterator;
import java.util.LinkedList;
public class Main {
    public static void main(String[] args) {
        Bingo bingo = new Bingo();
        Carton carton1 = new Carton();
        Carton carton2 = new Carton();
        Carton carton3 = new Carton();
        bingo.genrarCarton(carton1);
        bingo.genrarCarton(carton2);
        bingo.genrarCarton(carton3);
        PrintStream var10000 = System.out;
        LinkedList var10001 = carton1.getNumeros();
        var10000.println(" numeros del carton1" + var10001 + "\nnumeros del carton 2: " + carton2.getNumeros() + "\nnumeros del carton 3: " + carton3.getNumeros());
        if (bingo.isFinalizado() == true) {
            int bolaExtraida = bingo.extraerBola();
            System.out.println(" Bola Extraida: " + bolaExtraida);
        }

        if (bingo.getCartonesGanadores().size() > 0){
            Iterator var7 = bingo.getCartonesGanadores().iterator();
        while(bingo.getCartonesGanadores().iterator().hasNext()) {
            Carton cartn = bingo.getCartonesGanadores().iterator().next();
            System.out.println(" numeros de cartones ganadores: " + cartn.getNumeros());
            }
        }
    }
}