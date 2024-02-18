/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package datos;

/**
 *
 * @author Estudiante
 */
public class Conjuntodeautos {
    private Auto autos[] = new Auto[10000];
    private int na=0;
    
    public Conjuntodeautos() {
    }
    // Insertar un auto.
    public void addAuto(Auto x){
        autos[na]=x;
        na++;
    }
    
    public float promedio(){
        float sum=0;
        for (int i = 0; i < na; i++) {
            sum=sum+autos[i].getPrecio();
        }
        float prom=sum/na;
        return prom;
    }
    
    public void burbuja(){
        for (int i = 0; i < na; i++) {
            for (int j = 0; j < na-1; j++) {
                if(autos[j].getModelo()>autos[j+1].getModelo()){
                    Auto t=autos[j];
                    autos[j]=autos[j+1];
                    autos[j+1]=t;
                }
            }
        }
    }
    
    public String listar(){
        String lis="";
        for (int i = 0; i < na; i++) {
            lis=lis+" "+autos[i].toString()+"\n";
        }
        return lis;
    }
    
    
    /**
     * @return the autos
     */
    public Auto[] getAutos() {
        return autos;
    }

    /**
     * @return the na
     */
    public int getNa() {
        return na;
    }

    
}
