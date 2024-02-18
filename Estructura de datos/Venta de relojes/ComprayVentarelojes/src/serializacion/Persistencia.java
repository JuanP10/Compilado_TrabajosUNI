/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package serializacion;

import datos.ConjRelojes;
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
public class Persistencia {
    
    public void guardar(ConjRelojes x) throws FileNotFoundException, IOException{
        ObjectOutputStream file=new ObjectOutputStream(new FileOutputStream("relojes.ob"));
        file.writeObject(x);
        file.close();
    }
    
    public ConjRelojes recuperar () throws FileNotFoundException, IOException, ClassNotFoundException{
        ObjectInputStream file=new ObjectInputStream(new FileInputStream("relojes.ob"));
        ConjRelojes ob=(ConjRelojes) file.readObject();
        file.close();
        return ob;
    }
    
}
