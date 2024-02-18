/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Datos;

import java.util.ArrayList;
import java.util.Collections;
/**
 *
 * @author ESTUDIANTE
 */
public class FacultadING {
    private ArrayList<Carreras> carreras = new ArrayList<>(); 
    
    //Agregar carrera 
    
    public void addCarrera (Carreras x){
        carreras.add(x);
    }
    
    //Listas carreras 
    
    public String Listar (){
        String list = " ";
        for (int i=0 ;i < carreras.size(); i++){
            Carreras obtener = carreras.get(i);
            list+= " "+ obtener.toString()+"\n";
        }
        return list;
    }
    
    //Ordenar por codigo (shell)
    
    public void OrdenarPorCodigoShell (){
    int salto,i,j,k;
    salto=carreras.size()/2;
        while(salto>0){
            for(i=salto; i<carreras.size(); i++){
                j=i-salto;
                while(j>=0){
                    k=j+salto;
                    if(carreras.get(j).getCodigo()<carreras.get(j+1).getCodigo()){
                        j=-1;
                    }
                    else{
                       Carreras t=carreras.get(j);
                       carreras.set(j, carreras.get(j+1));
                       carreras.set(j+1, t);
                        j=j-salto;
                    }
                }
            }
            salto=salto/2;
        }
        
    }
    
    //Buscar por nombre (secuencial)
   
   public Carreras buscarNombre(String nombre){
         for (Carreras carrera : carreras) {
            if (carrera.getNombre().equalsIgnoreCase(nombre)){
                return carrera;
            }
        }
         return null;
    }
   
   //Ordenar por nombre Comparator
   
   public void OrdenarPorNombre (){
        Collections.sort(carreras);
    }
   
    //Busqueda por Codigo metodo binario 
   
    public int BusquedaPorCodigoBinaria (int codigo){
        int i=0;
        int j=carreras.size()-1;
        while(i<=j){
            int p=(i+j)/2;
            if (carreras.get(j).getCodigo()==codigo){
                return p;
            }
            else{
                if(codigo >carreras.get(j).getCodigo()){
                    i=p+1;
                }
                else{
                  j=p-1;
                }
            }
        }
        return -1;
    }
    
    
    //Ordenar por número de semestre (Shell)
    
    public void OrdenarPorSemestreShell (){
        int salto,i,j,k;
        salto=carreras.size()/2;
        while(salto>0){
            for(i=salto; i<carreras.size(); i++){
                j=i-salto;
                while(j>=0){
                    k=j+salto;
                    if(carreras.get(j).getSemestre()<carreras.get(j+1).getSemestre()){
                        j=-1;
                    }
                    else{
                       Carreras t=carreras.get(j);
                       carreras.set(j, carreras.get(j+1));
                       carreras.set(j+1, t);
                        j=j-salto;
                    }
                }
            }
            salto=salto/2;
        }
        
    }
    
    
    //Eliminar carreras tecnicas
    
    public void EliminarCarrerasTecnicas (){
        Carreras Carreraelim=null;
        for (Carreras carrera : carreras) {
            if (carrera.getTecnica().equalsIgnoreCase("SI")){
            } else {
                Carreraelim=carrera;
                break;
            }
        }
        carreras.remove(Carreraelim);
    }

    //Hallar todas las carreras de 8vo semestre
    
    public Carreras HallarCarreras8voSemestre (){
        for (Carreras carrera : carreras) {
            if(carrera.getSemestre()== 8){
            return carrera;
            }
        }
        return null;
    }
    
}    
    

