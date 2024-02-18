/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author JUAN PABLO
 */
public class Peaje {
    String filaCoches [];
    String cochesFlyPass [];
    boolean estadoPeaje ;
    int cantidadCochesAtendidos =1, cocheEnAtencion =0;

    
    public Peaje(String[] filaCoches) {
        this.filaCoches = filaCoches;
        int cantidad = filaCoches.length;
        this.cochesFlyPass = new String [cantidad];
        
        for (int i = 0; i < filaCoches.length; i++) {
            cochesFlyPass [i]= ", ";
        }
        
    
    }

    
    
    public void proximoCoche(){
        if (estadoPeaje) {
            cocheEnAtencion +=1;
            cantidadCochesAtendidos +=1;
        }
    }
    
    public void agregarCocheFlyPass(){
        String cocheABuscar = filaCoches[cocheEnAtencion];
        for(String coche:cochesFlyPass){
            if(coche.equals(cocheABuscar)){
                break;
            }
            if(" ".equals(coche)){
                coche = cocheABuscar;
            }
        }
        
    }
    
    
    public void cambiarEstadoPeaje(){
        if (!estadoPeaje == false) {
            estadoPeaje = false;
        }
        else{
            estadoPeaje=true;
        }
    }

    public static void main (String [] args){
        
        
    }
    
    
    
    
    
    
    
    //////////////////////////////////////////////////////////////
    public String[] getFilaCoches() {
        return filaCoches;
    }

    public Peaje(String[] filaCoches, String[] cochesFlyPass, boolean estadoPeaje) {
        this.filaCoches = filaCoches;
        this.cochesFlyPass = cochesFlyPass;
        this.estadoPeaje = estadoPeaje;
    }

    public String[] getCochesFlyPass() {
        return cochesFlyPass;
    }

    public boolean isEstadoPeaje() {
        return estadoPeaje;
    }

    public int getCantidadCochesAtendidos() {
        return cantidadCochesAtendidos;
    }

    public int getCocheEnAtencion() {
        return cocheEnAtencion;
    }
    
    
}

    
    

