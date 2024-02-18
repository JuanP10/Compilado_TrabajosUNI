/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gui;

import datos.Equipo;
import datos.jugador;
import javax.swing.JOptionPane;

/**
 *
 * @author ESTUDIANTE
 */
public class Menu {
    public static void main(String[] args){
        new Menu().menu();
    }
    public void menu(){
        String men="\n1.Agregar jugador \n2.Listar \n3.Eliminar \n4.Buscar \n5.Fin";
        Equipo equip=new Equipo();
        fin:do {            
            String ojo=JOptionPane.showInputDialog(men);
            int op=Integer.parseInt(ojo);
            switch(op){
                case 1:{
                    String cd=JOptionPane.showInputDialog("Cedula");
                    int cedula=Integer.parseInt(cd);
                    String nombre=JOptionPane.showInputDialog("Nombre");
                    String ed=JOptionPane.showInputDialog("Edad");
                    int edad=Integer.parseInt(ed);
                    String go=JOptionPane.showInputDialog("Goles");
                    int goles=Integer.parseInt(go);
                    String sa=JOptionPane.showInputDialog("Salario");
                    float salario=Float.parseFloat(sa);
                    jugador ju=new jugador(cedula, nombre, edad, goles, salario);
                    equip.addJugador(ju);
                    JOptionPane.showMessageDialog(null, "Jugador creado con exito");
                    break;
                }
                case 2:{
                    String lis=equip.listar();
                    JOptionPane.showMessageDialog(null, lis);
                   
                    break;
                }

                case 3:{
                    JOptionPane.showInputDialog(op, "Dijite la cedula a eliminar");
                    equip.elimJugador(op);

                }

                case 4:{

                    String cedu = JOptionPane.showInputDialog("Digite el nombre");
                    Equipo equipo = equip.buscar(cedu);
                    if(equipo == null)
                        JOptionPane.showMessageDialog(null, "Elemento no encontrado");
                    else
                        JOptionPane.showMessageDialog(null, equipo);

                }
                case 5:{
                    
                    break fin;
                }
     
                default:{
                    break;
                }
            }
        } while (true);
    }
}
