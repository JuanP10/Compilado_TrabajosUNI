/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Poli;

/* Tenemos un programa el cual mostrará los datos de los vehiculos


/**
 *
 * @author JUAN PABLO
 */
public class Principal {

    public static void main(String[] args) {
        //Crear objetos
        Vehiculos misVehiculos[] = new Vehiculos[4];

        //El primero es de vehivulos, por eso solo mostrará los tres atributos
        misVehiculos[0] = new Vehiculos("A8", "FORD", "34JGS");

        //Este hará poliformismo y el objeto cambirá de forma, mostrando los tres atributos y NumPuertas y Tiempo
        misVehiculos[1] = new VehTurismo(3, 4, "A8", "FORD", "346HSDG");

        /*
          Este hará poliformimos y como heredará de VehTurimos, tendrá los atributos
          de VehTurimos que heredó de Vehiculos, y además el atributo de VehDeportivos
        */
        misVehiculos[2] = new VehDeportivos(3, 4, 2022, "A8", "FORD", "3847sdkf");

    }

}
