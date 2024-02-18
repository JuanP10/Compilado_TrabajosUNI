import java.util.LinkedList;

public class SubastaLimitada extends Subasta{
    public final int MaxPujas;


    public SubastaLimitada(String nombreProducto, Usuario usuarioSubasta, boolean EstadoPuja, LinkedList<Puja> listaPujas, int pujaMayor, int maxPujas) {
        super(nombreProducto, usuarioSubasta, EstadoPuja, listaPujas, pujaMayor);
        MaxPujas = maxPujas;
    }
}
