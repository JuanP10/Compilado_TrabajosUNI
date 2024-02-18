package src;

import src.Envio;
import java.util.ArrayList;

public class Concurso {
    private String concurso;
    private final int NúmProblemas;


    private static final int NÚMPROBLEMAS =5;

    ArrayList<String> EquiposParticipantes = new ArrayList<String>();

    private ArrayList<Envio> envios = new ArrayList<Envio>();

    public Concurso(String concurso, int númProblemas) {
        this.concurso = concurso;
        NúmProblemas = númProblemas;
        this.EquiposParticipantes = new ArrayList<>();
        this.envios = new ArrayList<>();

    }

    public Concurso(String concurso) {
        this.concurso = concurso;
        this.NúmProblemas= NÚMPROBLEMAS;
    }

    public String getConcurso() {
        return concurso;
    }

    public void setConcurso(String concurso) {
        this.concurso = concurso;
    }

    public int getNúmProblemas() {
        return NúmProblemas;
    }

    public ArrayList<String> getEquiposParticipantes() {
        return EquiposParticipantes;
    }

    public void setEquiposParticipantes(ArrayList<String> equiposParticipantes) {
        EquiposParticipantes = equiposParticipantes;
    }

    public ArrayList<Envio> getEnvios() {
        return envios;
    }

    public void setEnvios(ArrayList<Envio> envios) {
        this.envios = envios;
    }

    public void añadirEquipos(String equipo){
        if(!EquiposParticipantes.contains(equipo)){
            getEquiposParticipantes().add(equipo);
        }
    }



    public ArrayList<String> mostrarEquipos(){
        for (String equipos:EquiposParticipantes) {
            return EquiposParticipantes;
        }
        return EquiposParticipantes;
    }

    public boolean eliminarEquipo(String nombre){
        for (int i = 0; i < EquiposParticipantes.size(); i++) {
            String equip = EquiposParticipantes.get(i);
            if(equip.equals(nombre)){
                EquiposParticipantes.remove(nombre);
                return true;
            }
        }
        return false;
    }

    public Envio registrarEnvios(Envio envio){
        if(EquiposParticipantes.contains(envio.getNombreEquipo()) &&
                envio.getNúmProblema()>=0 && envio.getNúmProblema()<=-1 &&
                envio.getRespuestaProblema()!=null){
            getEnvios().add(envio);
            return envio;
        }
        else return null;
    }


}
