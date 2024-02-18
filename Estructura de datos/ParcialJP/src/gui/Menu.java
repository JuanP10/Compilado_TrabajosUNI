/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gui;
import datos.Colegios;
import datos.PaisesDeColegios;
import datos.ComparatorPorNombre;
import java.util.Collections;
import javax.swing.JOptionPane;
/**
 *
 * @author Estudiante
 */
public class Menu {
    public static void main (String [] args){
        new Menu().menu();
    }
    
    public void menu(){
        
        String men = " 1. Agregar Colegio \n  2. Listar\n  3.Ordenar por Paises (Shell) \n  4.Ordenar por nombre (Comparator) \n 5. Buscar por nombre (Binaria) \n 6. Paises de Los Colegios \n 7. Salir \n";
        PaisesDeColegios Pai = new PaisesDeColegios();
        
        fin: do{
            
        String m = JOptionPane.showInputDialog(men);
            int op = Integer.parseInt(m);
            
            switch (op){
                case 1:
                    
                    String nom = JOptionPane.showInputDialog("nombre ");
                    String pai = JOptionPane.showInputDialog("Pais ");
                    Colegios al = new Colegios (nom, pai);
                    Pai.addColegio(al);
                    JOptionPane.showMessageDialog(null,"Colegio Creado");
                    break;
                
                case 2:
                    
                    JOptionPane.showMessageDialog(null, Pai.ListarColegios());
                    break;
                    
                case 3:
                    
                    JOptionPane.showMessageDialog(null,"Lista ordenada por Paises (Metodo Shell)");
                    Pai.OrdenarPorPaisesShell();
                    break;
                
                case 4:
                    Pai.OrdenarPorNombre();
                    JOptionPane.showMessageDialog(null, "Ordenado correctamente por nombre");
                    break;
                    
                case 5:
                    
                    JOptionPane.showInputDialog("Digite el nombre a buscar:  ");
                           String cid = null;
                           if(Pai.BisquedaPorNombreBinaria(cid)==-1){
                               JOptionPane.showMessageDialog(null, "El nombre no se ha encontrado");
                           }else{
                               JOptionPane.showMessageDialog(null, "El nombre se encuentra en la posicion: "+Pai.BisquedaPorNombreBinaria(cid));
                           }                               
                    break;

                    
                case 6:
                    JOptionPane.showMessageDialog(null, " Los Paises de los Colegios son: ");
                    Pai.HallarPaisesColegios();
                    break;
                    
                case 7:
                    break fin;
            }    
        }while (true);
    }
}
