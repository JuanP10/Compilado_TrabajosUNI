/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author JUAN PABLO
 */

import java.util.ArrayList;
import java.util.Arrays;


public class Solution {
   public static Object[] reportes(ArrayList<Estudiante> grupo) {
        //EN ESTE ESPACIO PONER SU LÓGICA
        double TotalSum =0;
        float MenorNota = Integer.MAX_VALUE;
        float MayorNota = Integer.MIN_VALUE;
        String nombreEstudianteMayorNota = "";
        String nombreEstudianteMenorNota = "";
        
        //1- Promedio de notas
        //2- Estudiante menor promedio notas
        //3- menor nota
        //4- Estudiante Mayor Nota
        //5- Mayor nota
        
        for (Estudiante estudiante : grupo) {
            
            
            if(estudiante.getNota() < MenorNota){
                MenorNota = (float) estudiante.getNota();
                nombreEstudianteMenorNota = estudiante.getNombreCompleto();
            }
            
            if(estudiante.getNota() > MayorNota){
                MayorNota = (float) estudiante.getNota();
                nombreEstudianteMayorNota = estudiante.getNombreCompleto();
                       
            }
            
            TotalSum += estudiante.getNota();
           
       }
        
       double promedio =  TotalSum / grupo.size();
       
       Object[] resultados = {promedio, nombreEstudianteMenorNota, MenorNota, nombreEstudianteMayorNota, MayorNota};
        
       return resultados;
    } 
   
    public static void main(String[] args) {
    ArrayList<Estudiante> grupo = new ArrayList<>();
    grupo.add(new Estudiante("John Doe", "0123", 5.0, 4, 8));
    grupo.add(new Estudiante("Jane Doe", "9283", 4.1, 7, 13));
    grupo.add(new Estudiante("Pepito Perez", "0194", 1.5, 5, 9));
    grupo.add(new Estudiante("Fulano de tal", "9013", 2.3, 2, 6));
    
    System.out.println(Arrays.toString(Solution.reportes(grupo)));
    }
}


