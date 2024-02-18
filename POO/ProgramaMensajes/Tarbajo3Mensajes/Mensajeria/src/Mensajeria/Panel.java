package Mensajeria;

import java.util.ArrayList;

public class Panel {
    private String propietario;
    private ArrayList<Mensaje> mensajes;

    public Panel(String propietario){
        this.propietario = propietario;
        this.mensajes = new ArrayList<>();
    }

    public ArrayList<Mensaje> getMensajes() {
        return mensajes;
    }

    public ArrayList<Mensaje> consultarRespuestasMensaje(Mensaje mens){

        ArrayList<Mensaje> mensajesQueSonRespuesta = new ArrayList<>();
        for (Mensaje mensaje:mensajes) {
            if(mensaje.getmensajeAlqueResponde() == mens){
                mensajesQueSonRespuesta.add(mensaje);
            }
        }
        return mensajesQueSonRespuesta;
    }

    public boolean borrarmensaje(Mensaje mensaje){
        if(consultarRespuestasMensaje(mensaje).isEmpty()){
            mensajes.remove(mensaje);
            return true;
        }
        return false;
    }

    public Mensaje publicarMensaje(String texto, String autor, Mensaje mensaje){
        if(mensaje == null && !propietario.equals(autor))
            return null;
        else if(mensaje != null && !mensajes.contains(mensaje))
            return null;

        Mensaje nuevoMensaje = new Mensaje(autor, texto, mensaje);

        mensajes.add(nuevoMensaje);
        return nuevoMensaje;

    }
    public Mensaje publicarMensaje(String texto){
        Mensaje nuevoMensaje = new Mensaje(propietario, texto, null);
        mensajes.add(nuevoMensaje);
        return nuevoMensaje;
    }

}
