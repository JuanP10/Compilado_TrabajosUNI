/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gui;

import datos.ConjuntoRelojes;
import datos.Reloj;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import javax.swing.JOptionPane;
import serializacion.Persistencia;

/**
 *
 * @author ESTUDIANTE
 */
public class Menu {
   
    public static void main(String[] args) throws IOException, FileNotFoundException, ClassNotFoundException{
        menu();
    }
    
   public static void menu() throws IOException, FileNotFoundException, ClassNotFoundException{
       String men="\n1.Agregar \n2.Listar \n3.Más costoso \n4.Salir";
       int op=0;
       File archivo=new File("relojes.ob");//Accediendo al archivo relojes.ob
       ConjuntoRelojes relojes;
       if(!archivo.exists()){
           relojes=new ConjuntoRelojes();//Si no existe, creo el objeto
       }else{
           relojes=new Persistencia().recuperar();//Si existe, recupero
       }
         
       fin:do { 
           op=Integer.parseInt(JOptionPane.showInputDialog(men));
           switch(op){
               case 1:
                   String ref="REF"+(int)(Math.random()*1000);
                   float costo=(float)(Math.random()*1000);
                   int modelo=(int) (Math.random()*1000);
                   relojes.insertar(new Reloj(ref, costo, modelo));
                   JOptionPane.showMessageDialog(null, "Reloj insertado correctamente.");
                   break;
               case 2:
                   JOptionPane.showMessageDialog(null, relojes.mostrar());
                   break;
               case 3:
                   Reloj re=relojes.MasCaro();
                   JOptionPane.showMessageDialog(null, re.toString());
               case 4:
                   break;     
           }
       } while (op!=4);
       new Persistencia().guardar(relojes);
   }
}
