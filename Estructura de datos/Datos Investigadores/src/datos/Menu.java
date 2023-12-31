/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package datos;

import javax.swing.JOptionPane;

/**
 *
 * @author ESTUDIANTE
 */

 public class Menu {
     public static void main(String[] args) {
        String men="\n1.Agregar Investigador \n2.Listar \n.3 Ordenar por Nombre (algoritmo propio) \n.4 Buscar por cedula(Lineal) ";
       
        AgenciaInvestigadores inv=new AgenciaInvestigadores();
        fin:do {            
            String m=JOptionPane.showInputDialog(men);
            int op=Integer.parseInt(m);
            switch(op){
                case 1:
                    String nom=JOptionPane.showInputDialog("Inserte el nombre del Investigador");
                    String ced=JOptionPane.showInputDialog("Inserte La cédula");
                    int cedula=Integer.parseInt(ced);
                    String ed=JOptionPane.showInputDialog("Inserte la edad");
                    int edad=Integer.parseInt(ed);
                    String ciu=JOptionPane.showInputDialog("Inserte la ciudad del investigador");
                    String pa=JOptionPane.showInputDialog("Inserte el país del investigador");

                    Investigador inve=new Investigador(nom,cedula, edad, ciu, pa);
                    inv.addInvestigador(inve);
                    JOptionPane.showMessageDialog(null, "Investigador agregado correctamente");
                    break;
                case 2: JOptionPane.showMessageDialog(null, inv.listar());
                    break;
                case 3: 
                    inv.bubbleSort();
                    JOptionPane.showMessageDialog(null, inv.listar());
                    break;
                case 4: 
                    inv.busquedaLineal();
                    JOptionPane.showMessageDialog(null, inv.listar());
                    break;
                case 5:
                    break fin;
            }
        }while (true);
        
      }
 }
   
