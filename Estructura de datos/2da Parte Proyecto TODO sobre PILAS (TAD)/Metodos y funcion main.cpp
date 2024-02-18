#include <iostream>
#include "Pila Especificacion.h"
using namespace std; 

void llenar(PilaInt &p, int n){  //Mandando la Pila Original// En este llenas la pila desde "i-1" hasta 0//
	for(int i=0;i<n;i++){        //Ejemplo: si dice 5, la pila es 4 3 2 1 0
		p.insertar(i);
	}
}

void duplicar (PilaInt &p){       //creas una pila auxiliar, recorres la pila original preguntando si esta vacia        
	PilaInt aux;                  //Luego todos los datos obtenidos se guardaran en el auxiliar y la pila original se borrará//
	while (!p.pilavacia()){
		aux.insertar(p.obtener());
		p.eliminar();
	}
	while (!aux.pilavacia()){      //Con este ciclo recorremos ahora la pila auxiliar e insertamos los datos obtenidos
		p.insertar(aux.obtener()); //en la pila auxiliar, y esa la borramos. 
		p.insertar(aux.obtener());
		aux.eliminar();             //Si la pila original es 4 3 2 1 0 , la duplicada sera 4 4 3 3 2 2 1 1 0 0//
	}
}

PilaInt copiar(PilaInt p){     //Similar al duplicado, creo una pila auxiliar y una pila copia, entro al ciclo 
	PilaInt cop;               // e inserto la pila original a la auxiliar y elimino la de la original
	PilaInt aux;
	while (!p.pilavacia()){
		aux.insertar(p.obtener());
		p.eliminar();
	}
	while (!aux.pilavacia()){        //Con este ciclo, recorro la pila auxiliar y le inserto los dato a la pila copia. 
		cop.insertar(aux.obtener()); // Para retornar la pila copia
		aux.eliminar();
	}
	return cop;
}

//-----------------------------------///

int cambiarBaseXTope (PilaInt &p){
	
}






int main(){
	PilaInt pil;
	int n;
	cout<<"Datos a generar "; cin>>n;
	llenar(pil,n);
	pil.mostrar();
	
	cout<<endl;
	duplicar(pil);
	cout<<"La pila duplicada es:"<<endl;
	pil.mostrar();
	
	cout<<endl;
	PilaInt copia=copiar(pil);
	cout<<"La pila copiada es:"<<endl;
	copia.mostrar();
	
	cout<<endl;
	cout<<"La pila original es:"<<endl;
	pil.mostrar();
}

//Se guarda como CPP//
