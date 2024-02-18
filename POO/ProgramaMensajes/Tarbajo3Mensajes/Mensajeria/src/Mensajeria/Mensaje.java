package Mensajeria;

public class Mensaje {
    private final String texto;
    private final String autor;
    private Mensaje mensajeAlqueResponde;

    private boolean independiente;


    public Mensaje(String texto, String autor) {
        this.texto = texto;
        this.autor = autor;

    }
    public Mensaje(String autor, String texto, Mensaje mensajeAlqueResponde) {
        this(texto, autor);
        mensajeAlqueResponde = mensajeAlqueResponde;
    }

    public String getTexto() {
        return texto;
    }

    public String getAutor() {
        return autor;
    }

    public Mensaje getmensajeAlqueResponde() {
        return mensajeAlqueResponde;
    }

    public boolean isIndependiente() {

        if(mensajeAlqueResponde == null){
            independiente = true;
        }
        return independiente;
    }
}
