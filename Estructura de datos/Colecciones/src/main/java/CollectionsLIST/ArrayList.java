/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package CollectionsLIST;

import java.util.List;

/**
 *
 * @author JUAN PABLO
 */
public class ArrayList {

    public static void main(String[] args) {

        List<String> ejemploLista = new java.util.ArrayList<>();

        ejemploLista.add("Juan");
        ejemploLista.add("Pedro");
        ejemploLista.add("José");
        ejemploLista.add("María");
        ejemploLista.add("Sofía");

        System.out.println(ejemploLista);

        //Cantidad de elementos
        ejemploLista.size();

        //Obtener lo que hay en un indice;
        System.out.println(ejemploLista.get(0));

        //Remover o borrar un dato
        ejemploLista.remove(0);
        ejemploLista.remove("Juan");

        //Borrar todo
        ejemploLista.clear();

        //Si la lista esta vacia
        ejemploLista.isEmpty();

        //Si queremos saber si contiene el dato en la lista
        ejemploLista.contains("José");
        //Y si queremos si esta en un indice en especifico
        ejemploLista.set(1, "Félix");

        //Si queremos extraer una sublista
        ejemploLista.subList(0, 2);

    }
}
