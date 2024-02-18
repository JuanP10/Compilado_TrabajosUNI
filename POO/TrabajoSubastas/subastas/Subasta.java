import java.util.LinkedList;

public class Subasta {
    private String nombreProducto;
    private Usuario usuarioSubasta;
    private boolean EstadoPuja;

    LinkedList <Puja> listaPujas = new LinkedList<>();

    protected double pujaMayor;

    public Subasta(String nombreProducto, Usuario usuarioSubasta, boolean EstadoPuja, LinkedList<Puja> listaPujas, int pujaMayor) {
        this.nombreProducto = nombreProducto;
        this.usuarioSubasta = usuarioSubasta;
        this.EstadoPuja = EstadoPuja;
        this.listaPujas = listaPujas;
        this.pujaMayor = pujaMayor;
    }

    public String getNombreProducto() {
        return nombreProducto;
    }

    public Usuario getUsuarioSubasta() {
        return usuarioSubasta;
    }

    public boolean isEstadoPuja() {
        return EstadoPuja;
    }

    public LinkedList<Puja> getListaPujas() {
        return listaPujas;
    }

    public double getPujaMayor() {
        return pujaMayor;
    }

    public boolean pujar ( double cant, Usuario usuarioSubasta){
        if(EstadoPuja == true && this.usuarioSubasta.getCredito()>= cant &&  this.usuarioSubasta != usuarioSubasta){
            if(listaPujas.isEmpty()){
                Puja puja = new Puja(cant, usuarioSubasta);
                listaPujas.add(puja);
                return true;
            }
        }
        return false;
    }
    public void pujar (Usuario usuarioSubasta){
        if(listaPujas.isEmpty()){
            pujar(1,usuarioSubasta);
        }
      pujar(listaPujas.getLast().getCantidad()+1,usuarioSubasta);
    }

}
