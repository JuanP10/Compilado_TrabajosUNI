#include <iostream>
#include "Pila Especificacion.h"
using namespace std; 

int main(){
	PilaInt pila;
	pila.insertar(9);      //La pila saldria asi: 4 2 8 12 9 , pero eliminamos el tope (4) entonces sale: 2 8 12 9
	pila.insertar(12);     //Por ello, el tope actual es 2.
	pila.insertar(8);      //Y la pila actual es 2 8 12 9
	pila.insertar(2);      //Luego busca el 12 y como esta coloca el 1 (0 es falso y 1 es verdadero) 
	pila.insertar(4);	   //Por ultimo, escribe la cantidad de datos de la pila actual, que en este caso es 4 (2 8 12 9). 
	pila.eliminar();
	
	cout<<"El tope de la actual pila es: "<<pila.obtener();
	cout<<endl;
	cout<<endl;
	cout<<"La pila Actual es: "<<endl;
	pila.mostrar();
	
	cout<<endl;
	bool busqueda= pila.buscar(12);
	cout<<"Busqueda: "<<busqueda;
	
	cout<<endl;
	int cantidad= pila.cantidad();
	cout <<"La cantidad de datos es: "<<cantidad<<endl;
	
	return 1;
}

//Se guarda como CPP//
