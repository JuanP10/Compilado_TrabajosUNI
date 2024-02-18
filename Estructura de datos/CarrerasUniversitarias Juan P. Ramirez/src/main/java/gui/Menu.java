/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package gui;

import Datos.Carreras;
import Datos.FacultadING;
import javax.swing.JOptionPane;

/**
 *
 * @author ESTUDIANTE
 */

public class Menu {
    public static void main (String [] args){
        new Menu().menu();
    }
    
    public void menu(){
        
        String men = " 1. Agregar Carrera \n  2. Listar\n  3.Ordenar por Codigo (Shell) \n  4. Buscar por nombre \n  5.Ordenar por nombre \n 6. Buscar por codigo (Binaria) \n 7. Ordenar por numero de semestres \n 8. Borrar todas las tecnicas \n 9. Hallar carreras de 8va smestre \n 10. Salir \n";
        FacultadING ing = new FacultadING();
        
        fin: do{
            
        String m = JOptionPane.showInputDialog(men);
            int op = Integer.parseInt(m);
            
            switch (op){
                case 1:
                    
                    String co = JOptionPane.showInputDialog("codigo ");
                    int cod = Integer.parseInt(co);
                    String nom = JOptionPane.showInputDialog("nombre ");
                    String tec = JOptionPane.showInputDialog("¿Es tecnica? (SI/NO) ");
                    String sem = JOptionPane.showInputDialog("Semestre? ");
                    int seme = Integer.parseInt(sem);
                    Carreras al = new Carreras (cod, nom, tec, seme);
                    ing.addCarrera(al);
                    JOptionPane.showMessageDialog(null,"Carrera creada");
                    break;
                
                case 2:
                    
                    JOptionPane.showMessageDialog(null,ing.Listar());
                    break;
                    
                case 3:
                    
                    JOptionPane.showMessageDialog(null,"Lista ordenada por codigo (Metodo Shell)");
                    ing.OrdenarPorCodigoShell();
                    break;
                    
                case 4:
                    
                    nom = JOptionPane.showInputDialog("Digite el nombre");
                    Carreras programas = ing.buscarNombre(nom);
                    if(programas==null){
                        JOptionPane.showMessageDialog(null, "Elemento no encontrado");
                    }
                    else{
                        JOptionPane.showMessageDialog(null, programas.toString());
                    }
                    break;
                
                case 5:
                    JOptionPane.showMessageDialog(null, "Lista Ordenada por Nombres");
                    ing.OrdenarPorNombre();  
                  
                    break;
                    
                case 6:
                    
                    String ci = JOptionPane.showInputDialog("Digite codigo a buscar:  ");
                           int cid=Integer.parseInt(ci);
                           if(ing.BusquedaPorCodigoBinaria(cid)==-1){
                               JOptionPane.showMessageDialog(null, "El codigo no se ha encontrado");
                           }else{
                               JOptionPane.showMessageDialog(null, "El codigo se encuentra en la posicion: "+ing.BusquedaPorCodigoBinaria(cid));
                           }                               
                    break;
                
                case 7:
                    
                    JOptionPane.showMessageDialog(null," Lista ordenada por numero se semestres (Metodo Shell)");
                    ing.OrdenarPorSemestreShell();
                    
                    break;
                    
                case 8:
                    ing.EliminarCarrerasTecnicas();
                    JOptionPane.showMessageDialog(null," Carreras Tecnicas Eliminadas ");
                    break;
                    
                case 9:
                    JOptionPane.showMessageDialog(null," Las carreras con ocho semestres son: ");
                    ing.HallarCarreras8voSemestre();
                    break;
                    
                case 10:
                    break fin;
            }    
        }while (true);
    }
}
