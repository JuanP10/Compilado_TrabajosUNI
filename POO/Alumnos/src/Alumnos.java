public class Alumnos {
    private String nombre;
    private String dni;
    private double credito;
    private static final double CREDITO_POR_DEFECTO  = 100;

    public String getNombre() {
        return nombre;
    }

    public String getDni() {
        return dni;
    }

    public double getCredito() {
        return credito;
    }

    public Alumnos(String nombre, String dni, double credito) {
        this.nombre = nombre;
        this.dni = dni;
        this.credito = credito;
    }

    public Alumnos(String nombre, String dni) {
        this(nombre, dni,CREDITO_POR_DEFECTO);
    }

    public void Incrementar (double credito){
        this.credito += credito;
    }

    public void Decrementar (double credito){
        if(credito <= this.credito)
            this.credito -= credito;
    }
}
