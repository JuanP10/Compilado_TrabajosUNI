package Mensajeria;
import java.util.ArrayList;
public class Main {
    public static void main(String[] args) {

        Panel panel = new Panel("Ernesto");

        Mensaje mensaje1 = panel.publicarMensaje("Busco programador/a Java");
        Mensaje mensaje2 = panel.publicarMensaje("tengo la certificacion en Java SE programmer I","Antonio", mensaje1);
        Mensaje mensaje3 = panel.publicarMensaje("Tengo cinco años de experiencia","Marta", mensaje1);

        ArrayList<Mensaje> respuestas = panel.consultarRespuestasMensaje(mensaje1);

        for (Mensaje mensajes : respuestas) {
            System.out.println("respuestas del mensaje 1: "+mensajes.getTexto());
        }

        if(panel.borrarmensaje(mensaje1))
            System.out.println("El mensaje ha sido eliminado");
        else
            System.out.println(" El mensaje no ha sido eliminado porque tiene respuestas");

        System.out.println(" mensaje 2 eliminado? :"+panel.borrarmensaje(mensaje2));

        ArrayList<Mensaje> mensajesDelPanel = panel.getMensajes();

        for (Mensaje mensajes: mensajesDelPanel) {
            System.out.println(" texto de mensajes del panel: "+mensajes.getTexto());
        }

    }
}
