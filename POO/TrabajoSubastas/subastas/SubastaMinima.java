import java.util.LinkedList;

public class SubastaMinima extends Subasta{

    private double CantidadMin;

    public double getCantidadMin() {
        return CantidadMin;
    }

    public void setCantidadMin(double cantidadMin) {
        CantidadMin = cantidadMin;
    }

    public SubastaMinima(String nombreProducto, Usuario usuarioSubasta, boolean EstadoPuja, LinkedList<Puja> listaPujas, Puja pujaMayor) {
        super(nombreProducto, usuarioSubasta, EstadoPuja, listaPujas, pujaMayor);
        CantidadMin = CantidadMin;
    }

}
