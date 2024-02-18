import java.util.ArrayList;
public class Main {
    public static void main(String[] args) {

        System.out.println("TAREAS INGRESADAS:");

        Tarea ta = new Tarea();
        Tarea Tarea1 = ta.AñadirTareaProyecto("Extracción de requisitos", 12, 1);
        Tarea Tarea2 = ta.AñadirTareaProyecto("Definición de casos de uso",6,1);

        Tarea Tarea3 = ta.AñadirTareaProyecto("Diseño del modelo de datos",10,2);

        Tarea Tarea4 = ta.AñadirTareaProyecto ("Implementación de la UI",20,3);
        Tarea Tarea5 = ta.AñadirTareaProyecto ("Implementación del modelo",20,3);
        Tarea Tarea6 = ta.AñadirTareaProyecto("Implementación de las pruebas",8,3);

        Tarea Tarea7 = ta.AñadirTareaProyecto("Configuración de la base de datos", 4, 4);
        Tarea Tarea8 = ta.AñadirTareaProyecto("Instalación en el servidor", 6, 4);

        Tarea Tarea9 = ta.AñadirTareaProyecto("Programación nuevos requisitos",20,5);



        ta.Mostrar();

        //Borrar menores a 7

        ta.borrarMenorA7();

        // Tareas finalizadas fase 1

        boolean ta1 = ta.FinalizarTarea(Tarea1);
        boolean ta2 = ta.FinalizarTarea(Tarea2);

        //Motrar;

        System.out.println("--------------------------------------");

        ta.Mostrar();












    }
}