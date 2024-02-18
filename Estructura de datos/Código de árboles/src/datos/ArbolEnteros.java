/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package datos;

/**
 *
 * @author CARLOS
 */
public class ArbolEnteros {
    
    Arbin<Integer> raiz;
    
    
    public boolean buscar(int x){
        if(raiz!=null){
            return buscar(raiz, x);
        }
        return false;
    }
    //insertar
    public void insertar(int x){
        if(raiz==null){
            raiz= new ArbolEnl<>(x);
        }else
            insertar(raiz, x);
    }
   
   // pre orden r-i-d
   public void preorden(Arbin<Integer> r){
       if(r!=null){
           System.out.println(" "+r.obtener());
           preorden(r.izq());
           preorden(r.der());
       }
   }
   public void inorden(Arbin<Integer> r){
       if(r!=null){
          
           inorden(r.izq());
           
           System.out.println(" "+r.obtener());
           
           inorden(r.der());
       }
   }
   //inorde
   //posorden
   //peso del arbol
   int c=0;
   public int peso(Arbin<Integer> r){
       if(r!=null){
           c++;
           peso(r.izq());
           peso(r.der());
       }
       return c;
   }
   
    /**
     * @return the raiz
     */
    public Arbin<Integer> getRaiz() {
        return raiz;
    }

    private void insertar(Arbin<Integer> r, int x) {
        if(x<r.obtener()){
            if(r.izq()==null)
                r.enlIzq(new ArbolEnl<>(x));
            else
                insertar(r.izq(), x);
            
        }else{
            if(r.der()==null)
                r.enlDer(new ArbolEnl<>(x));
            else
                insertar(r.der(), x);
                            
        }
    }

    private boolean buscar(Arbin<Integer> r, int x) {
        if(r.obtener()==x){
            return true;
        }else{
            if(x<r.obtener()){
                if(r.izq()!=null)
                    return buscar(r.izq(),x);
                else
                    return false;
                    
            }else{
                if(r.der()!=null)
                    return buscar(r.der(), x);
                else
                    return false;
            }
        }
    }
    public Arbin<Integer> mayor(Arbin<Integer> r){
        if(r.der()==null)
            return r;
        else
            return mayor(r.der());
    }
    // funcion deliminar posiblemente una de las mas dificiles pero mas importantes de arboles
    public void eliminar(int x){
        if(buscar(x))
            raiz=eliminar(raiz, x);
    }
    private Arbin<Integer> eliminar(Arbin<Integer> r, int x) {
        if(r.obtener()==x){
            return borrar(r);
        }else{
            if(x<r.obtener()){
                r.enlIzq(eliminar(r.izq(), x));
            }else{
                r.enlDer(eliminar(r.der(), x));
            } 
            return r;
        }
        
    }
    
    public static void main(String[] args) {
       ArbolEnteros ob=new ArbolEnteros();
       
       ob.insertar(10);
       ob.insertar(4);
       ob.insertar(20);
       ob.insertar(3);
       ob.insertar(12);
       
       ob.eliminar(20);
       
       ob.inorden(ob.getRaiz());
       boolean res =ob.buscar(3);
       System.out.println("Numero encontrado: "+ res);
       res = ob.buscar(5);
        System.out.println("Numero encontrado: "+ res);
       
       int pes=ob.peso(ob.getRaiz());
       System.out.println(" Peso es "+pes);
       
       
    }

    private Arbin<Integer> borrar(Arbin<Integer> r) {
        if(r.izq()==null && r.der()==null)
            return null;
        else{
            if(r.izq()==null)
                return r.der();
            else if(r.der()==null){
                    return r.izq();
            
                 }else{
                //borrancuando tiene 2 hijos
                    Arbin<Integer> may=mayor(r.izq());
                    r.cambiar(may.obtener());
                    r.enlIzq(eliminar(r.izq(), may.obtener()));
                    return r;
                }                   
        }
    }  
}
