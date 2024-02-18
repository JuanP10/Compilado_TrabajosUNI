/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Serializacion;

import datos.ConjutoDeRelojes;
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
    public void guardar (ConjutoDeRelojes x) throws FileNotFoundException, IOException{
        ObjectOutputStream file = new ObjectOutputStream (new FileOutputStream("relojes.ob"));
        file.writeObject(x);
        file.close();
    }
    public ConjutoDeRelojes recuperar () throws FileNotFoundException, IOException, ClassNotFoundException{
        ObjectInputStream file = new ObjectInputStream (new FileInputStream("relojes.ob"));
        ConjutoDeRelojes ob = (ConjutoDeRelojes)file.readObject();
        file.close();
        return ob;
    }
}
    
