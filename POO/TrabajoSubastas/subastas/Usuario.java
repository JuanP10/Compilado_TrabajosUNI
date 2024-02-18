public class Usuario {
    private final String nombre;
    private double credito;

    public String getNombre() {
        return nombre;
    }

    public double getCredito() {
        return credito;
    }

    public Usuario(String nombre, double credito) {
        this.nombre = nombre;
        this.credito = credito;
    }

    public void DecrementarCredito (double credito){
        if(this.credito<=credito)
            this.credito -= credito;
    }

    public void IncrementaCredito (double credito){
        this.credito += credito;

    }


}
