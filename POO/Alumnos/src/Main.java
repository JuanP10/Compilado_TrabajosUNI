import java.util.ArrayList;
import java.util.List;


//Alumnos Juan Pablo Ramirez y Santiago Candanoza //

public class Main {
    public static void main(String[] args) {
        Alumnos alumnopepe = new Alumnos("pepe","34678904");
        Alumnos alumnoAndrea = new Alumnos("Andrea","17679456");
        Alumnos alumnoAntonio = new Alumnos("Antonia","34972496");

        Curso CursoBasesDeDatos = new Curso("Diseño de Bases de Datos",50,2);
        Curso CursoAdministraciónBasesDatos = new Curso("Administración de Bases de Datos", 75, 5);

        List<Curso> cursos = new ArrayList<>();
        cursos.add(CursoBasesDeDatos);
        cursos.add(CursoAdministraciónBasesDatos);

        for (Curso curso: cursos) {
            curso.MatricularAlumno(alumnopepe);
            curso.MatricularAlumno(alumnoAndrea);
            curso.MatricularAlumno(alumnoAntonio);

            for (Alumnos a: curso.getAlumnosMatriculados()){
                System.out.println("Alumno: "+ curso.getTitulo());
                curso.CalificarAlumno(alumnoAndrea,10);
            }
        }
    }
}