/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package datos;

import est.datos.Arbin;
import est.datos.ArbolEnl;
import java.io.Serializable;
import java.util.ArrayList;
import javax.swing.JOptionPane;
import java.util.LinkedList;

/**
 *
 * @author -USER-
 */
public class BeautyStore implements Serializable{
    private Arbin<Cosmetico> raiz;
    
    public void insertar(Cosmetico x){
        if(raiz==null)
            raiz=new ArbolEnl<>(x);
        else
            insertar(raiz,x);
    } 
    
    private void insertar(Arbin<Cosmetico> r, Cosmetico x) {
        if(x.getTipo().compareTo(r.obtener().getTipo())<0){
            if(r.izq()==null)
                r.enlIzq(new ArbolEnl<>(x));
            else
                insertar(r.izq(), x);
        }else{
            if(x.getTipo().compareTo(r.obtener().getTipo())>0){
                if(r.der()==null)
                    r.enlDer(new ArbolEnl<>(x));
                else
                    insertar(r.der(), x);
            }else
                throw new UnsupportedOperationException("No se puede insertar el cosmetico");
        }
    }
    
    String con="";
    public String mostrar(){
        con="";
        inorden(raiz);
        return con;
    }
    
    private void inorden(Arbin<Cosmetico> r) {
        if(r!=null){
            inorden(r.izq());
            con+=r.obtener().toString()+"\n";
            inorden(r.der());
        }
    } 
    //Mostrar el producto más barato
    
    Arbin<Cosmetico> productoMasBarato (Arbin<Cosmetico> r ){
        if(r.der()==null){
            return r;
        }else{
            menor(r.der());
        }
        return r;
    }
    
    Arbin<Cosmetico> menor (Arbin<Cosmetico>r){
        while(r.izq()!=null)
            r=r.izq();
        return r;
    }
    
    //Funciones de mostrar precios menores a mayores
    
    ArrayList <Arbin<Cosmetico>> Cosmeticos = new ArrayList<>();
    public ArrayList<Arbin<Cosmetico>> PreciosMenores (Arbin<Cosmetico> r){
        if(r!=null){
            PreciosMenores(r.izq());
            Visita(r);
            PreciosMenores(r.der());
        }
        return Cosmeticos;
    } 
    
    public void Visita (Arbin<Cosmetico> r){
        int may=0;
        if(r.obtener().getPrecio()<may){
            Cosmeticos.add(r);
        }
    }
    
    public void mostrar (ArrayList<Cosmetico> cosmeticos){
        for (int i = 0; i < cosmeticos.size(); i++) {
            JOptionPane.showInputDialog(cosmeticos.get(i));
        }   
    }
    
    //Funciones para eliminar cosmetico por código
    
    public void ElimCodigo (int cd){
       if(buscar(raiz,cd)){
          raiz=eliminar(raiz,cd);
       }
    }
    boolean buscar (Arbin<Cosmetico> r, int cd){
        while(r!=null && r.obtener().getCodigo()==cd){
            if(r.obtener().getCodigo()>cd){
                r=r.izq();
            }else{
                r=r.der();
            }
        }
        return r!=null;
    }
          
    public Arbin <Cosmetico> eliminar(Arbin<Cosmetico>r, int cd){
        if(r.obtener().equals(cd)){
            return borrar(r,cd);
        }
        else{
            if(cd<r.obtener().getCodigo()){
                r.enlIzq((eliminar(r.izq(),cd)));
            }else{
               r.enlDer((eliminar(r.izq(),cd)));
            }
        }
        return r;
    }
    
    public Arbin <Cosmetico> borrar (Arbin<Cosmetico> r, int cd){
        if(r.izq()==null && r.der()==null){
            return null;
        }else{
            if(r.izq()==null){
                return r.der();
            }else{
                if(r.der()==null){
                    return r.izq();
                }else{
                    Arbin <Cosmetico> may = mayor(r.izq());
                    r.cambiar(may.obtener());
                    r.enlIzq(eliminar(r.izq(),may.obtener().getCodigo()));
                    return r;
                }
            }
        }
        
    }
    
    Arbin <Cosmetico> mayor (Arbin<Cosmetico>r){
       while(r.der()!=null){
           r=r.der();
       }
       return r;
    }
    
    //Hallar los cosmeticos con un costo menor a x
    
    Arbin<LinkedList<Cosmetico>>r;
    LinkedList<Cosmetico>lista;
    LinkedList<Cosmetico> hallarCosmeticosMenoraX(int x){
        lista = new LinkedList<>();
        proceso(r, x);
        return lista;
    } 
    
    public void proceso (Arbin<LinkedList<Cosmetico>>r, int x){
        if(r!=null){
            LinkedList<Cosmetico>ListaC=r.obtener();
            for (Cosmetico cosme : ListaC) {
                if(cosme.getPrecio()>x){
                    lista.add(cosme);
                }
                
            }
            proceso(r.izq(),x);
            proceso(r.der(),x);
        }
    }
    
    
    //Buscar cosmetico con el precio p
    
    boolean buscar(Arbin<Cosmetico> r, float p) {
        if(r.obtener().getPrecio()==p)
            return true;
        else{
            if(p<r.obtener().getPrecio()){
                if(r.izq()!=null)
                    return buscar(r.izq(),p);
                else
                    return false;
            }else{
                if(r.der()!=null)
                    return buscar(r.der(),p);
                else
                    return false;
            }
        }
    }
    
    
    
}
