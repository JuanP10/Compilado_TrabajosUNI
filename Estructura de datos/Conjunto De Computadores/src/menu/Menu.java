/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package menu;

import datos.Computador;
import datos.Computadores;
import javax.swing.JOptionPane;
/**
 *
 * @author ESTUDIANTE
 */
public class Menu {
    public static void main(String[] args) {
        new Menu().menu();
    }
    public void menu(){
        String men="\n1.Agregar Alumno \n2.Listar \n3. Ordenar por marca \n4.Ordenar por referencia \n5. Ordenar por Precio \n6. Salir";
         Computadores pc=new Computadores();
         fin:do {             
             String m=JOptionPane.showInputDialog(men);
             int op=Integer.parseInt(m);
             switch (op) {
                 case 1:
                    String ref=JOptionPane.showInputDialog("Referencia ");
                    String mar=JOptionPane.showInputDialog("Marca ");
                    String pr=JOptionPane.showInputDialog("Precio ");
                    float price=Float.parseFloat(pr);
                     Computador cp=new Computador(ref, mar, price);
                     pc.
                     JOptionPane.showMessageDialog(null, "Computador creado ");
                     break;
                 case 2:
                   JOptionPane.showMessageDialog(null, pc.listar());
                 break;
                 case 3:
                   pc.bubbleSort();
                 break;
                 case 8:
                     pc.OrdenarPorReferencia();
                     break;
                 case 4:
                     pc.OrdenarPorMarca();
                     break;
                     
                 case 5:
                     pc.OrdenarPorPrecio();
                     break;
                     
                 case 6: break fin;
                 default:
                     throw new AssertionError();
             }

         } while (true);
     }
}
