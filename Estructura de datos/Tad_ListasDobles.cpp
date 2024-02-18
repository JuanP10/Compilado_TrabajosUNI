/*
Estudiantes: 
	Jesus Javier Diaz Vasquez
	Juan Pablo Ramirez Gutierrez
	Andres Felipe Antequera Cruz
	Javier Eduardo Figueroa Torrijo
	Heyris Michelle Granados Mendriz
*/

#include <iostream>

using namespace std;
struct Nodo{
	int dato;
	Nodo *sig;
	Nodo *ant;
};

class ListaDoble{
	Nodo *ptr=NULL;
	Nodo *ult=NULL;
	
	public:
		void insertarInicio(int x);
		void insertarFinal(int x);
		void mostrar();
		void eliminarInicio();
		void eliminarFin();
		bool listaVacia();
};

bool ListaDoble::listaVacia(){
	return (ptr==NULL || ult==NULL);
}

void ListaDoble::insertarInicio(int x){
	Nodo *nuevo = new Nodo;
	nuevo->dato = x;
	nuevo->sig = NULL;
	nuevo->ant = NULL;
	
	if(listaVacia()){
		ptr = nuevo;
		ult = nuevo;
	}
	else{
		nuevo->sig = ptr;
		ptr->ant = nuevo;
		ptr = nuevo;
	}
}

void ListaDoble::insertarFinal(int x){
	Nodo *nuevo = new Nodo;
	nuevo->dato = x;
	nuevo->sig = NULL;
	nuevo->ant = NULL;
	
	if(listaVacia()){
		ptr = nuevo;
		ult = nuevo;
	}
	else{
		ult->sig = nuevo;
		nuevo->ant = ult;
		ult = nuevo;
	}
}

void ListaDoble::mostrar(){
	if(!listaVacia()){
		Nodo *p=ptr;
		while(p!=NULL){
			cout<<" "<<p->dato;
			p=p->sig;
		}
	}
}

void ListaDoble::eliminarInicio(){
	if(!listaVacia()){
		Nodo *p=ptr;
		if(ptr->sig==NULL){ 
			ptr=ult=NULL;
		}else{ 
			p = ptr; // 3 4 5
			ptr = ptr->sig;  // 4 
			ptr->ant = NULL;
		}
		delete p;
	}
}

void ListaDoble::eliminarFin(){
	if(!listaVacia()){
		Nodo *p=ptr;
		if(ptr->sig==NULL){ 
			ptr=ult=NULL;
		}else{ 
			p = ult;
			ult->ant->sig = NULL;
			ult = ult->ant;
		}
		delete p;
	}
}

int main(){
	ListaDoble lista;
	
	lista.insertarInicio(6);
	lista.insertarInicio(4);
	lista.insertarFinal(7);
	lista.insertarFinal(10);
	lista.mostrar();
	
	cout<<endl;
	/*lista.eliminarFin();
	lista.eliminarFin();
	
	lista.mostrar();
	
	
	lista.eliminarInicio();
	lista.mostrar();*/
	
	cout<<endl;
	return 1;
}
