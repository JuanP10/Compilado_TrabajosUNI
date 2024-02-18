/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gui;

import datos.ConjRelojes;
import datos.Reloj;
import java.io.File;
import java.io.IOException;
import javax.swing.JOptionPane;
import serializacion.Persistencia;

/**
 *
 * @author ESTUDIANTE
 */
public class Menu {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        menu();
    }
    
    public static void menu() throws IOException, ClassNotFoundException{
        String men="1.Agrgar Reloj\n 2.Listar \n3.Mas costoso \n4.Salir";
        int op=0;
        
        File archivo= new File("relojes.ob");
        ConjRelojes relojes;
        if(!archivo.exists()){
            relojes=new ConjRelojes();
        }else{
            relojes=new Persistencia().recuperar();
        }
        
      
        
        do{
            op=Integer.parseInt(JOptionPane.showInputDialog(men));
            switch(op){
                case 1:
                    String ref="REF" +(int)(Math.random()*1000);
                    float costo=(float)(Math.random()*1000);
                    int modelo=(int)(Math.random()*2022);
                    relojes.insertar(new Reloj(ref, costo, modelo));
                    JOptionPane.showMessageDialog(null, "Reloj Insertar");
                    break;
                case 2:
                    JOptionPane.showMessageDialog(null, relojes.mostrar());
                    break;
                case 3:
                    Reloj re=relojes.Mascaro();
                    JOptionPane.showMessageDialog(null, re.toString());
                    break;
                case 4:
                    break;
            }
            
        }while(op!=4);
        new Persistencia().guardar(relojes);
    }
    
}
