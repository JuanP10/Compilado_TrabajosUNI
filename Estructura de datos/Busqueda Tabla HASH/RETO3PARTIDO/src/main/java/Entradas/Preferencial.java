/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Entradas;

/**
 *
 * @author JUAN PABLO
 */
public class Preferencial extends Asistente {
    
    //ESPACIO PARA INDICAR LOS ATRIBUTOS DE LA CLASE
    //Y SU MÉTODO CONSTRUCTOR
    boolean participaSorteo;
    
    
    
    
    public Preferencial (String idTiquete, String nombreCompleto, String direccionResidencia){
        super (idTiquete, nombreCompleto, direccionResidencia);
    }

    public void participarSorteo(){
        //ESPACIO PARA ESCRIBIR LA LÓGICA DEL MÉTODO
        //participarSorteo()
        if (isParticipaSorteo())
            setParticipaSorteo(false);
        else
            setParticipaSorteo(true);
        
    }
    
    //ESPACIO PARA INDICAR LOS MÉTODOS GETTER Y
    //SETTER DEL CASO
    public boolean isParticipaSorteo() {
        return participaSorteo;
    }

    public void setParticipaSorteo(boolean participaSorteo) {
        this.participaSorteo = participaSorteo;
    }
}

