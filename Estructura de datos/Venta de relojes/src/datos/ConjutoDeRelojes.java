/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package datos;

import est.datos.Arbin;
import est.datos.ArbolEnl;
import java.io.Serializable;

/**
 *
 * @author ESTUDIANTE
 */
public class ConjutoDeRelojes implements Serializable{
    private Arbin<Reloj> raiz;
    private float mayor;
    private Reloj RelojMasCostoso;
    
    public void insetar (Reloj x){
        if(raiz==null){
            raiz=new ArbolEnl<>(x);
        }
        else
            insertar(raiz, x);
    }
    String con="";
    public String mostrar (){
        con="";
        inorden(raiz);
        return con;
    }

    private void insertar(Arbin<Reloj> r, Reloj x) {
        if (x.getRef().compareTo(r.obtener().getRef())<0){
            if (r.izq()==null)
                r.enlIzq(new ArbolEnl<>(x));
            else
                insertar(r.izq(),x);
        }else{
            if(x.getRef().compareTo(r.obtener().getRef())>0){
                if (r.der()==null)
                    r.enlDer(new ArbolEnl<>(x));    
                else
                    insertar(r.der(),x);
                
        }
         else
             throw new UnsupportedOperationException("No se Puede Insertar");
            }
    }     

    private void inorden(Arbin<Reloj> r) {
        if(r!=null){
            inorden(r.izq());
            con+=r.obtener().toString()+"\n";
            inorden(r.der());
        }
    }
    
    public Reloj MasCaro(){
        mayor=0;
        MasCostoso(raiz);
        return RelojMasCostoso;
    }

    private void MasCostoso(Arbin<Reloj> r) {
        if(r!=null){
            if(r.obtener().getCosto()> mayor){
                mayor=r.obtener().getCosto();
                RelojMasCostoso=r.obtener();
            }
            MasCostoso(r.izq());
            MasCostoso(r.der());
        }
    }
}
