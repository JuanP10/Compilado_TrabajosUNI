import java.util.ArrayList;
import java.util.List;

public class ProyectoSoftware {
    private final String nombre;

    private ArrayList<Tarea> TodasLasTareas;
    private List<Tarea> TareasFinalizadas;

    private int duración;



    public ProyectoSoftware(String nombre, int duración) {
        this.nombre = nombre;
        this.duración = duración;
        TodasLasTareas = new ArrayList<>();
        TareasFinalizadas = new ArrayList<>();

    }



    public String getNombre() {
        return nombre;
    }

    public List<Tarea> getTodasLasTareas() {
        return TodasLasTareas;
    }

    public List<Tarea> getTareasFinalizadas() {
        return TareasFinalizadas;
    }

    public int getDuración() {
        return duración;
    }


}
