/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package serializacion;

import datos.ConjuntoRelojes;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

/**
 *
 * @author ESTUDIANTE
 */

// Tiene una funcion que guarda y recupera

public class Persistencia {
    public void guardar(ConjuntoRelojes x) throws FileNotFoundException, IOException{//Ligar una clase(Fileout...)
        ObjectOutputStream file=new ObjectOutputStream(new FileOutputStream("relojes.ob"));//Crear un objeto de un objeto para guardar un conjunto de objetos
        file.writeObject(x);//Para escribir
        file.close();
    }
    
    public ConjuntoRelojes recuperar() throws FileNotFoundException, IOException, ClassNotFoundException{//Recuperar los archivos que se guardan
        ObjectInputStream file=new ObjectInputStream(new FileInputStream("relojes.ob"));   
        ConjuntoRelojes ob=(ConjuntoRelojes) file.readObject();
        file.close();//Para cerrar el flujo y no se pierdan datos
        return ob;
    }
}
