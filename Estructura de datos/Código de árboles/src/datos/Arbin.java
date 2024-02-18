/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package datos;

/**
 *
 * @author CARLOS
 */
public interface Arbin<E> {
    E obtener();
    Arbin<E> izq();
    Arbin<E> der();
    void enlIzq(Arbin<E> x);
    void enlDer(Arbin<E> x);
    void cambiar(E x);
}
