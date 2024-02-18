
public class Calificacion {
    private int nota;
    private Alumnos alumnos;

    public Calificacion(int nota, Alumnos alumnos) {
        this.nota = nota;
        this.alumnos = alumnos;
    }

    public int getNota() {
        return nota;
    }

    public Alumnos getAlumnos() {
        return alumnos;
    }
}
