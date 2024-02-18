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
public class AgenciaInvestigadores {
 private final ArrayList<Investigador> investigator = new ArrayList<>();
 
    /**
     *
     * @param x
     */
    public void addInvestigador(Investigador x){
        investigator.add(x);
   }
  public String listar(){
        String lis=" ";
        for (int i = 0; i < investigator.size(); i++) {
            Investigador ob = investigator.get(i);
            lis+=" "+ob.toString()+"\n";
        }
        return lis;
    }
   public int busquedaLineal(int cedula){
        for (int i = 0; i < investigator.size(); i++) {
            Investigador ob = investigator.get(i);
            if(ob.getCedula()==cedula)
                return i;
        }
        return -1;

    }
    public void bubbleSort(){
        for (int i = 0; i < investigator.size(); i++) {
            for (int j = 0; j < investigator.size()-1; j++) {
                if(!investigator.get(j).getNombre().equals(investigator.get(j+1).getNombre())){
                    Investigador t=investigator.get(j);
                    investigator.set(j, investigator.get(j+1));
                    investigator.set(j+1, t);
                }
            }
            }
    }   

    void busquedaLineal() {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
  /*  public void borrarMenos20(){
        for (Investigador investigator : investigator) {
            if (investigator.getEdad()<20) {
                aux.add(investigator);
            }  
}
    }*/
}
  
