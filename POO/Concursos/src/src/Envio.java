package src;

public class Envio {
    private final String NombreEquipo;
    private final int NúmProblema;
    private final String RespuestaProblema;

    public Envio(String nombreEquipo, int númProblema, String respuestaProblema) {
        NombreEquipo = nombreEquipo;
        NúmProblema = númProblema;
        RespuestaProblema = respuestaProblema;
    }


    public String getNombreEquipo() {
        return NombreEquipo;
    }

    public int getNúmProblema() {
        return NúmProblema;
    }

    public String getRespuestaProblema() {
        return RespuestaProblema;
    }
}
