#include <iostream>
using namespace std;

struct NodoD{
	int dato;
	NodoD *sig;
	NodoD *ant;
};
class ListaDobleInt{
	NodoD *ptr=NULL;
	NodoD *ultimo=NULL;
	public:
		void insertarInicio(int x); 
		void mostrar();
		void insertarFin(int x);
		void eliminarInicio();
		void eliminarFin();
		bool listaVacia();
};

void eliminarFin(){

	NodoD *ultimo.ant.sig=NULL;
    NodoD *ultimo=ultimo.ant;
    delete p;
}

void ListaDobleInt::eliminarFinal(){
	if(!listaVacia()){
		NodoD *p=ptr;
		if(ptr->sig==NULL){ 
			ptr=ultimo=NULL;
		}else{ 
			NodoD *q=p;
			while (p->sig!=NULL){
				p=ultimo;
                ultimo->ant->sig=NULL;
                ultimo=ultimo->ant; 	
			}
			q->sig=NULL;
		}
		delete p;
	}
}

void ListaDobleInt::mostrar(){
	if(!listaVacia()){
		Nodo *p=ptr;
		while(p!=NULL){
			cout<<" "<<p->dato;
			p=p->sig;
		}
	}
}

int main(){
	ListaDobleInt Lista
	
	return 1; 
}

