#include <iostream>
using namespace std;

struct Articulo{
	int cod;
	string descrip;
	float precio;
	void escribir(){
		cout<<" "<<cod<<" "<<descrip<<" "<<precio<<endl;
	}
};

struct Nodo{
	Articulo dato;
	Nodo *sig;
};

class ListaCircularArt{
	Nodo *cursor=NULL;
	public:
		bool listaVacia(){
			return (cursor==NULL);
		}
		void insertarFinal(Articulo x){
			Nodo *nuevo=new Nodo;
			nuevo->dato=x;
			if(listaVacia()){
				cursor=nuevo;
			}else{
				Nodo *p=cursor;
				do{
					p=p->sig;
				}while(p->sig!=cursor); //Hasta el final de la lista
				p->sig=nuevo;
			}
			nuevo->sig=cursor;
		}
		void mostrar(){
			if(!listaVacia()){
				Nodo *p=cursor;
				do{
					//cout<<" "<<p->dato.cod<<" "<<p->dato.descrip<<" "<<p->dato.precio<<endl;
					p->dato.escribir();
					p=p->sig;
				}while(p!=cursor); //Explora toda la lista
			}
		}
		void eliminarFin(){
			if(!listaVacia()){
				if(cursor->sig==cursor){
					Nodo *q=cursor;
					delete q;
					cursor=NULL;
				}else{
					Nodo *p=cursor;
					Nodo *q=p;
					do{
						q=p;
						p=p->sig;
					}while(p->sig!=cursor);
					q->sig=cursor;
					delete p;
				}
			}
		}
};


int main (){
	ListaCircularArt Lista;
	
	Articulo a1;
	a1.cod=10;
	a1.descrip="XXX";
	a1.precio=9000;
	Lista.insertarFinal(a1);
	
	Articulo a2;
	a2.cod=30;
	a2.descrip="YYYY";
	a2.precio=3000;
	Lista.insertarFinal(a2);
	
	Articulo a3;
	a3.cod=200;
	a3.descrip="ZZZ";
	a3.precio=40000;
	Lista.insertarFinal(a3);
	
	
	Lista.eliminarFin();
	Lista.mostrar();	
	
	return 1;
}
