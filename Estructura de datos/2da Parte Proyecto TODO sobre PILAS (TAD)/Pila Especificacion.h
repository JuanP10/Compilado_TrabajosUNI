#include <iostream>

class PilaInt{           //Pila de enteros//
	int tope=-1;         //Si el tope de la pila es igual a -1 significa que esta vacia//
	int pila[100];
	public:
		void insertar(int x); //Coloca un nuevo dato que se posicionara en el tope//
		void eliminar();      //Elimina el dato del tope//
		int obtener();        //Obtiene el dato del tope//
		void mostrar();       //Muestra la pila completa//
		int cantidad();       //Te dice la cantidad de datos que hay en la pila//
		bool buscar(int x);   //Busca si un dato esta en la pila//
		bool pilavacia();     //Determina si la pila esta vacia. Es un estado, no imprime nada//
};

/* Especificación. Este se guarda como Head File. */
