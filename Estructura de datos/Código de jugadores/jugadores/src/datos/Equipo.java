/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package datos;

import java.util.ArrayList;

/**
 *
 * @author ESTUDIANTE
 */
public class Equipo {
    private ArrayList<jugador> jugadores;

    public Equipo() {
        this.jugadores = new ArrayList<>();
    }
    
    public void addJugador(jugador x){
        jugadores.add(x);
    }
    
    public String listar(){
        String lis="";
        for(int i = 0; i < jugadores.size(); i++){
            jugador ob = jugadores.get(i);
            lis+=" "+ob.toString()+"\n";
        }
        return lis;
    }
    
    public void elimJugador(int cedula){
        jugador el=null;
        for(jugador jugadore : jugadores){
            if(jugadore.getCedula()==cedula){
                el=jugadore;
                break;
            }
        }
        jugadores.remove(el);
    }
    //buscar por nombre
    public String buscar(String nom){
        for (jugador jugadore : jugadores){
            if(jugadore.getNombre().equals(nom)){
                return jugadore.toString();
            }
            
        }
        return null;
    }
    
    
    
    
    /**
     * @return the jugadores
     */
    public ArrayList<jugador> getJugadores() {
        return jugadores;
    }
    
}
