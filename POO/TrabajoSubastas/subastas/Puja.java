public class Puja {

    private double cantidad;
    private Usuario usuario;

    public Puja(double cantidad, Usuario usuario) {
        this.cantidad = cantidad;
        this.usuario = usuario;
    }

    public double getCantidad() {
        return cantidad;
    }

    public Usuario getUsuario() {
        return usuario;
    }
}
