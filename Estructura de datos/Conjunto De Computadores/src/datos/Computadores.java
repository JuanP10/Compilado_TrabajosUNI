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
public class Computadores {
    private ArrayList<Computador> compu = new ArrayList<>();

    /**
     * @return the compu
     */
    public ArrayList<Computador> getCompu() {
        return compu;
    }
    
    public void addComputador(Computador x){
       compu.add(x);
    }
    public String listar(){
      String lis="";
        for (int i = 0; i < compu.size(); i++) {
            Computador get = compu.get(i);
            lis+=" "+get.toString()+"\n";
        }
       return lis;
    }
    public void OrdenarPorPrecio(){
        for (int i = 0; i < compu.size(); i++) {
            for (int j = 0; j < compu.size()-1; j++) {
                if(compu.get(j).getPrecio()>compu.get(j+1).getPrecio()){
                       Computador t=compu.get(j);
                       compu.set(j, compu.get(j+1));
                       compu.set(j+1, t);
                    }
                
            }
            
        }
    }


    
    
      
    }

