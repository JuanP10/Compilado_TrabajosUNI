#include <iostream>
#include "Pila Especificacion.h"

void PilaInt::insertar(int x){  //Pide un dato (en este caso entero) que se colocara en el tope de la pila//
	tope++;
	pila[tope]=x;
}
bool PilaInt::pilavacia(){ //Pregunta si la pila es igual a -1, si es asi, significa que la pila esta vacia//
	if(tope==-1)
		return true;
	else
		return false;
}
void PilaInt::mostrar(){ //Primero pregunta si la pila esta vacia (como en pilavacia), y luego la recorre del tope al fondo//
	if(pilavacia()==false){
		for(int i=tope; i >= 0; i--){
			std::cout<<" "<<pila[i]<<"\n";
		}
	}
}
void PilaInt::eliminar(){ //Pregunta si la pila tiene datos, y si es cierto elimina el dato del tope, o sea, el ultimo//
	if(!pilavacia()){
		tope--;
	}
}
int PilaInt::obtener(){  //Obtiene el dato del tope
	if(!pilavacia()){
		return pila [tope];
	}
}

bool PilaInt::buscar(int x){  //Busca si un dato esta en la pila, se es cierto, responde 1 y si no esta responde 0//
	for (int i=tope; i >= 0; i--){
		if (pila[i]==x){
			return true; 
		}
	}
	return false;
}

int PilaInt::cantidad(){ //Dice la cantidad de datos que hay en la pila, sabiendo que el tope se va sumando o restando//
	return ++tope;       //solo en las funciones de insertar (suma) y eliminar (resta)//
}

//Este se guarda como CPP//
