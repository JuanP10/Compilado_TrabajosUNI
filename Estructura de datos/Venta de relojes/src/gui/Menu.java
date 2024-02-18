/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gui;

import Serializacion.Persistencia;
import datos.ConjutoDeRelojes;
import datos.Reloj;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import javax.swing.JOptionPane;

/**
 *
 * @author ESTUDIANTE
 */


public class Menu {
    
    public static void main(String[] args) throws IOException, FileNotFoundException, ClassNotFoundException{
       menu();
    }
    
    public static void menu() throws IOException, FileNotFoundException, ClassNotFoundException {
        String men="\n 1. Agregar \n 2.Listar \n 3.Mas Costoso \n4. Salir";
        int op=0;
        
        File archivo=new File("relojes.ob");
        ConjutoDeRelojes relojes;
        if(!archivo.exists()){
            relojes = new  ConjutoDeRelojes();
        }else{
            relojes =new Persistencia().recuperar();
        }
        fin: do{
           
            op=Integer.parseInt(JOptionPane.showInputDialog(men));
            switch(op){
                case 1:
                    String ref= "REF"+(int)(Math.random()*1000);
                    float costo=(float)(Math.random()*1000);
                    int modelo = (int)(Math.random()*1000);
                    relojes.insetar(new Reloj(ref, costo, modelo));
                    JOptionPane.showMessageDialog(null, "Reloj Insertado Correctamente");
                    break;
                    
                case 2:
                    JOptionPane.showMessageDialog(null, relojes.mostrar());
                    break;
                    
                case 3:
                    Reloj re=relojes.MasCaro();
                    JOptionPane.showMessageDialog(null, re.toString());
                    break;
                    
                case 4:
                    
                    break;

            }
            
        }while(op!=4);
        new Persistencia().guardar(relojes);
    }
}
