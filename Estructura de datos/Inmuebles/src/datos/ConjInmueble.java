/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package datos;
import java.util.ArrayList;
/**
 *
 * @author Estudiante
 */
public class ConjInmueble {
    private ArrayList<Inmuebles> inmu = new ArrayList<>();
    
    //Añadir Inmueble
    public void addInmueble (Inmuebles x){
        inmu.add(x);
    }
    
    public String listar(){
        String list="";
        
        for (int i = 0; i < inmu.size(); i++) {
            Inmuebles get = inmu.get(i);
            list+=" "+get.toString();
        }
        return list;
    }
    //Dado el código decir todos sus datos
    
    public String buscar(int cd){
        for (Inmuebles inmuebles : inmu) {
            if(inmuebles.getCodigo()==cd) {
                return inmuebles.toString();
            }
        }
        return null;
    }
    
    //Listas todos los inmuebles tipo "CASA"
    
    public String listarTipoCASA(){
        String ListCasa="";
        for (int i = 0; i < inmu.size(); i++) {
            Inmuebles get = inmu.get(i);
            if(get.getTipo().equals("CASA"))
            ListCasa+=" "+get.toString();
        }
           return ListCasa; 
    }
    
    //Hallar inmueble más caro
    
    public String InmuCaro(){
        int may=0;
        for (Inmuebles inmuebles : inmu) {
            if(inmuebles.getPrecio()>= may){
            }
        }
    }
        
    //Eliminar inmueble
    public void borrarInmueble (int cd){
        Inmuebles el=null;
        for (Inmuebles inmuebles : inmu) {
            if(inmuebles.getCodigo()==cd){
                el=inmuebles;
                break;
            }
        } 
    }

}
