import java.util.Date;
import java.util.LinkedList;


public class SubastaTemporal extends SubastaLimitada{

    private Date Periodo;



    public SubastaTemporal(String nombreProducto, Usuario usuarioSubasta, boolean EstadoPuja, LinkedList<Puja> listaPujas, Puja pujaMayor, int maxPujas) {
        super(nombreProducto, usuarioSubasta, EstadoPuja, listaPujas, pujaMayor, maxPujas);
    }
}
