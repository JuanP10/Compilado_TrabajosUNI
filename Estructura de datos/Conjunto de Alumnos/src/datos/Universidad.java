/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package datos;

import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;

/**
 *
 * @author ESTUDIANTE
 */
public class Universidad {
    private final ArrayList<Alumno> alumnos=new ArrayList<>();
    
    public int busquedalinal(int codigo){
    
        for (int i = 0; i < alumnos.size(); i++) {
            Alumno ob = alumnos.get(i);
            if(ob.getCodigo()==codigo){
            return i;        
            }
            
        }
        return -1;
    }
    
    // buscar alumno por normbre 
    public Alumno buscarNombre (String nombre){
    for (Alumno alumno : alumnos) {
        if (alumno.getNombre().equals(nombre) ){
            return alumno; 
         }    
        }
   return null; 
}
    
   //borrar todos los alummnos que quedaron fuera <300
    public void borrarAlumnFBRA(){
        LinkedList<Alumno> aux=new LinkedList<>();
        for (Alumno alumno : alumnos) {
            if(alumno.getPromedio()<300){
            aux.add(alumno); 
            }
        }
        alumnos.removeAll(aux);
    }
   
    // 
    public void bubblesort(){
        for (int i = 0; i < alumnos.size(); i++) {
            for (int j = 0; j < alumnos.size()-1; j++) {
              if (alumnos.get(j).getCodigo()>alumnos.get(j+1).getCodigo()){
                  Alumno t=alumnos.get(j);
                  alumnos.set (j,alumnos.get(j+1));
                  alumnos.set (j+1,t);
              }  
                
            }
            
        }
    }
    
public void addAlumno(Alumno x){
    alumnos.add(x);
}

public String listar(){
    
    String list="";
    for (int i = 0; i < alumnos.size(); i++) {
        
        Alumno ob=alumnos.get(i);
        list+=""+ob.toString()+"\n";
     
    }
    return list;
}
//eliminar alumno por codigo 

public void eliminarAlumno ( int codigo){
   Alumno alel=null;
    for (Alumno alumno : alumnos) {
        if(alumno.getCodigo()== codigo){
            alel=alumno;
            break;
        }
        
    }
   
    alumnos.remove(alel);
    
}
//buscar por nombre- busca un alumno dado por nombre
//equals para comparar dos string

public String buscar (String nombre){
    for (Alumno alumno : alumnos) {
        if (alumno.getNombre() .equals(nombre) ){
            return alumno.toString();
            
        }
        
    }
   return null; 
}

 public String busquedaBinaria(int codigo){
     int ini=0;
     int fin=alumnos.size()-1; 
     while(ini<=fin){
        int p=(ini+fin)/2;
        if(alumnos.get(p).getCodigo()==codigo){
            return alumnos.get(p).toString();
        }else{
            if(codigo>alumnos.get(p).getCodigo()){
            ini=p+1; 
            }else{
            fin=p-1;
            }
        }
     
     }
     return "No esta";
}
 

    /**
     * @return the alumnos
     */
    public ArrayList<Alumno> getAlumnos() {
        return alumnos;
    }

    public void ordenarPorNombre() {
        Collections.sort(alumnos);
    }

    public void ordenarPorEdad() {
        Collections.sort(alumnos, new EdadComparator());
    }

    public void ordenarPorPromedio() {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
    
    
            
}



