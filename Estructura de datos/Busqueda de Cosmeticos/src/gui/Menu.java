/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gui;

import datos.BeautyStore;
import datos.Cosmetico;
import javax.swing.JOptionPane;

/**
 *
 * @author -USER-
 */
public class Menu{
    public static void main(String[] args) {
        menu();
    }
   
    public static void menu() {
        String men="1. Agregar \n 2.Listar \n 3.Eliminar por Código \n4. Precios Menores \n5. Salir";
        BeautyStore Beauty = new BeautyStore();
        fin: do{
         String m=JOptionPane.showInputDialog(men);
         int op=Integer.parseInt(m);
            switch(op){
                case 1:
                    String tip= JOptionPane.showInputDialog("Tipo");
                    String co=JOptionPane.showInputDialog("codigo");
                    int cod = Integer.parseInt(co);
                    String pr=JOptionPane.showInputDialog("Precio");
                    float Pre=Integer.parseInt(pr);
                    String cant=JOptionPane.showInputDialog("cantidad");
                    int can=Integer.parseInt(cant);
                    String var= JOptionPane.showInputDialog("Variación");
  
                    Beauty.insertar(new Cosmetico(tip, cod, Pre, can, var));
                    JOptionPane.showMessageDialog(null, "Cosmetico Insertado Correctamente");
                    break;
                    
                case 2:
                    JOptionPane.showMessageDialog(null, Beauty.mostrar());
                    break;
                    
                case 3:
                   String el=JOptionPane.showInputDialog("Digite el codigo del cosmetico a eliminar");
                   int eli=Integer.parseInt(el);
                   Beauty.ElimCodigo(eli);
                   JOptionPane.showMessageDialog(null,"Cosmetico eliminado");
                    
                    break;
                    
                case 4:
                    
                    break;

            }
            
        }while(true);
    }
       
    
}

