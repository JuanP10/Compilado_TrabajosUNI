import java.util.ArrayList;
import java.util.List;

public class Curso {
    private final String titulo;
    private final double precioMatricula;
    private List<Alumnos> alumnosMatriculados;
    private final int cupo;

    private List<Calificacion> calificacion;

    public String getTitulo() {
        return titulo;
    }

    public double getPrecioMatricula() {
        return precioMatricula;
    }

    public List<Alumnos> getAlumnosMatriculados() {
        return alumnosMatriculados;
    }

    public Curso(String titulo, double precioMatricula, int cupo) {
        this.titulo = titulo;
        this.precioMatricula = precioMatricula;
        this.cupo = cupo;

        alumnosMatriculados = new ArrayList<>();
        calificacion = new ArrayList<>();
    }

    public boolean MatricularAlumno (Alumnos alumnos){
        if (alumnosMatriculados.contains(alumnos) &&  alumnos.getCredito() >= precioMatricula && alumnosMatriculados.size()<cupo){
            alumnosMatriculados.add(alumnos);
            alumnos.Decrementar(precioMatricula);
            return true;
        }
        return false;
    }

    public boolean CalificarAlumno(Alumnos alumnos, int nota){
        if(alumnosMatriculados.contains(alumnos) && (nota >= 0 && nota <=10) && !calificacion.contains(alumnos) ){
            Calificacion NuevaCalificacion = new Calificacion(nota, alumnos);
            calificacion.add(NuevaCalificacion);
            return true;
        }
        return false;

    }

}
