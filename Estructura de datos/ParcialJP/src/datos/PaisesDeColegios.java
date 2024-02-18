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
 * @author Estudiante
 */
public class PaisesDeColegios {
    private ArrayList<Colegios> colegios = new ArrayList<>();
    
     
    //Agregar Colegio 
    
    public void addColegio (Colegios x){
        colegios.add(x);
    }
    
    //Listas Colegios
    
    public String ListarColegios (){
        String list = " ";
        for (int i=0 ;i < colegios.size(); i++){
            Colegios obtener = colegios.get(i);
            list+= " "+ obtener.toString()+"\n";
        }
        return list;
    }
    
    //Ordenamiento por Paises Algoritmo Cualquiera
    
    public void OrdenarPorPaisesShell (){
    int salto,i,j,k;
    salto=colegios.size()/2;
        while(salto>0){
            for(i=salto; i<colegios.size(); i++){
                j=i-salto;
                while(j>=0){
                    k=j+salto;
                    if(colegios.get(j).getPaises().equals(j)){
                        j=-1;
                    }
                    else{
                       Colegios t=colegios.get(j);
                       colegios.set(j, colegios.get(j+1));
                       colegios.set(j+1, t);
                        j=j-salto;
                    }
                }
            }
            salto=salto/2;
        }
        
    }
    
   //Ordenamiento Comparator Nombre
   
   public void OrdenarPorNombre(){
       Collections.sort(colegios, new ComparatorPorNombre());
   }
   
   
   //Busqueda Binaria por nombre
   
   public int BisquedaPorNombreBinaria (String Nombre){
        int i=0;
        int j=colegios.size()-1;
        while(i<=j){
            int p=(i+j)/2;
            if (colegios.get(j).getNombre()==Nombre){
                return p;
            }
            else{
                if(Nombre != colegios.get(j).getNombre()){
                    i=p+1;
                }
                else{
                    j=p-1;
                }
            }
        }
        return -1;
   }
   
   //Paises de los Colegios
   
   public LinkedList <Colegios> HallarPaisesColegios(){
       LinkedList<Colegios> aux= new LinkedList<>();
        for (int i = 0; i < colegios.size(); i++) {
            Colegios ot = colegios.get(i);
            aux.add(ot);

        }
       return aux;
       
       
   }
 
}
