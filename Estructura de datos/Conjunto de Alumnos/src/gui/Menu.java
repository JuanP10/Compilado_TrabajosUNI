/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gui;

//interface grafica de usuario

import datos.Alumno;
import datos.Universidad;
import javax.swing.JOptionPane;



/**
 *
 * @author ESTUDIANTE
 */
public class Menu {
    public static void main(String[] args) {
        new Menu().menu();
        
    }
    
    // hallar los alumnos por cada carretera 
   
 public void menu (){
     String men=" \n1.Agregar alumno \n2.Listar \n3.Eliminar \n4.Buscar \n5.ordenar  \n6.ordenar por nombre \n7.Ordenar por edad \n8. Ordenar por promedio \n9.buscar por nombre \n 10.borrar alumno \n 11.buscar por codigo(binaria) \n 12.salir";
     
     Universidad uni=new Universidad();
     //fin para que me saque 
     fin:do {  
         //devuelve cadena se debe convertir a entero
         String m=JOptionPane.showInputDialog(men);
         //conversion
         int op=Integer.parseInt(m);
         
         switch (op){
             case 1:
                 String co=JOptionPane.showInputDialog("codigo");
                 int cod = Integer.parseInt(co);
                 String nom=JOptionPane.showInputDialog("Nombre");
                 String ed=JOptionPane.showInputDialog("Edad");
                 int edad=Integer.parseInt(ed);
                 String pr=JOptionPane.showInputDialog("Promedio");
                 float prom=Float.parseFloat(pr);
                 Alumno al=new Alumno(cod, nom, edad, prom);
                 
                 
                 uni.addAlumno(al);
                
                 JOptionPane.showMessageDialog(null, "Alumno creado");
                 
                 
                 break;
             case 2:
                 JOptionPane.showMessageDialog(null, uni.listar());
                 break;
                 
             case 3:
                 String el=JOptionPane.showInputDialog("Codigo de alumno a eliminar");
                 int eli=Integer.parseInt(el);
                 uni.eliminarAlumno(eli);
                 JOptionPane.showMessageDialog(null,"alumno eliminado");
                 break;
             case 4:
                 String bu=JOptionPane.showInputDialog("Nombre de alumno a buscar ");
                 JOptionPane.showConfirmDialog(null,uni.buscar(bu));
                 break;
             case 5:
             uni.bubblesort();
                 
             case 6:
                 uni.ordenarPorNombre();
                 break;
             
             case 7: 
                 uni.ordenarPorEdad(); 
                 break;
                 
             case 8:
                 uni.ordenarPorPromedio();
                 break;
                 
             case 9:
                 nom=JOptionPane.showInputDialog("Digita nombre");
                 Alumno alu=uni.buscarNombre(nom);
                 if(alu==null){
                 JOptionPane.showMessageDialog(null, "no esta");
                 }
                 else{
                 JOptionPane.showMessageDialog(null, alu.toString());
                 }
                 break;
             case 10:
                 uni.borrarAlumnFBRA();
                 break;
             case 11:
                 String bus=JOptionPane.showInputDialog("Digite codigo");
                 int codi=Integer.parseInt(bus);
                 JOptionPane.showConfirmDialog(null,uni.busquedaBinaria(codi));
                 break;
             case 12:
                 
                break fin;
             
         }
         
         
     } while (true);
 }   
    
}


