package src;

import java.util.ArrayList;

public class App{
    public static void main (String[] args) {
        Concurso concurso1 = new Concurso("sesion1", 2);
        Concurso concurso2 = new Concurso("sesion2", 3);
        Concurso concurso3 = new Concurso("sesion3", 3);

        ArrayList<Concurso> list = new ArrayList<Concurso>();
        list.add(concurso1);
        list.add(concurso2);
        list.add(concurso3);

    for(Concurso concursos: list) {
            System.out.println("Concursos: "+concursos.getConcurso());

            concursos.añadirEquipos("equipo 1");
            concursos.añadirEquipos("equipo 2");
            concursos.añadirEquipos("equipo 3");

            Envio envio1 = new Envio("equipo 1", 1,"Respuesta 1");
            Envio envio2 = new Envio("equipo 2",2,"Respuesta 2");
            Envio envio3 = new Envio("equipo 3",2,"Respuesta 3");

            ArrayList<String> equipos = concursos.mostrarEquipos();
            for (String equip:equipos) {
                concursos.registrarEnvios(envio1);
                concursos.registrarEnvios(envio2);
                concursos.registrarEnvios(envio3);
                System.out.println(equip);

            }

        }
    }
}



