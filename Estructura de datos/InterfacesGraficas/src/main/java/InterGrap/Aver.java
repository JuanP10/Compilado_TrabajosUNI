/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package InterGrap;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;



/**
 *
 * @author JUAN PABLO
 */
public class Aver {
    public static void main (String [] args){
      JFrame frame = new JFrame("Mi primera GUI");          
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);          
        frame.setSize(300, 300);         
        JButton button1 = new JButton("Botón 1");         
        JButton button2 = new JButton("Botón 2");         
        frame.getContentPane().add(button1);         
        frame.getContentPane().add(button2);         
        frame.setVisible(true);   
       
    
    }    
    
 }

    
