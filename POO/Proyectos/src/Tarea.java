import java.util.ArrayList;

  public class Tarea {
    private String descripción;
    private int duración;
    private static final int DURACION_POR_DEFECTO  = 10;
    private int fases;

     public Tarea(String descripción, int duración, int fases) {
        this.descripción = descripción;
        this.duración = duración;
        this.fases = fases;
    }

    public Tarea(String descripción, int fases) {
        this(descripción,DURACION_POR_DEFECTO, fases);
    }

    public Tarea() {

    }
      @Override public String toString() {
          return "\nTarea: \n[ descripcion: " + descripción +
                  ", \nduracion: " + duración +
                  ", \nfase: " + fases + " ]";
      }

    public String getDescripción() {
        return descripción;
    }

    public int getDuración() {
        return duración;
    }

    public int getFases() {
        return fases;
    }

    ArrayList<Tarea> tareas = new ArrayList<Tarea>();

    public ArrayList CosultarListaTareas(int fase){
        if(getFases()==fase)
            return tareas;
        return null;
    }

    public Tarea AñadirTareaProyecto (String descripcion, int duracion, int fase){
        Tarea AñadirTarea = new Tarea(descripcion, duracion, fase);
        tareas.add(AñadirTarea);
        return AñadirTarea;
    }

    public boolean BorrarProyecto (Tarea tarea){
        if(getDescripción().equals(tarea.getDescripción())){
            tareas.remove(tarea);
            return true;
        }
        return false;
    }
    ArrayList<Tarea> FinalizarTarea = new ArrayList<Tarea>();

    public boolean FinalizarTarea(Tarea TareaTerminada) {
        if (getDescripción()==TareaTerminada.getDescripción()) {
            FinalizarTarea.add(TareaTerminada);
            return true;
        }
        return false;
    }

    public void Mostrar(){
          for (Tarea tar :tareas) {
              System.out.println(tar.toString());
          }
      }



      public void borrarMenorA7(){
          ArrayList<Tarea> copi = new ArrayList<Tarea>(tareas);
          for (Tarea tar : copi) {
              if(tar.getDuración() < 7){
                  tareas.remove(tar);
              }
          }
      }











}



