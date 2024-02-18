#include <iostream>
#include "Especificacion.h"
using namespace std;

int main (){
	programas Pila;
	
	Pila.insertar("Teams");
	Pila.insertar("Chrome");
	Pila.insertar("Word");
	Pila.insertar("Word");
	Pila.insertar("Purple Place");
	Pila.insertar("Dev C++");
	
	cout<<"La pila es: "<<endl;
	Pila.mostrar();
	
	cout<<endl;
	int contar=Pila.contar("Word");
	cout<<"Se contaron "<<contar<<" veces el programa Word"<<endl;
	cout<<endl;
	
	cout<<"El tope de la pila es:  "<<Pila.obtener()<<endl;
	
	Pila.eliminar();
	cout<<endl;
	
	cout<<"Eliminado el tope, la pila queda: "<<endl;
	Pila.mostrar();
	
    cout<<endl;
//	programas copia= BaseXTope();
	cout<<"La pila copiada es:"<<endl;
	//copia.mostrar();
	
	/* Falta copiar la pila y colocar una dato cualquiera en el tope*/
	

	return 1;
}
