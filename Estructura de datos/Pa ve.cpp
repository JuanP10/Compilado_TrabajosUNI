#include <iostream>

using namespace std;

struct Articulo{
	int codigo;
	string descripcion;
	float precio;
	void escribir(){
		cout<<" "<<codigo<<" "<<descripcion<<" "<<precio<<"\n";
	}
};
struct NodoA{
	Articulo dato;
	NodoA *sig;
};
class ListaCircArt{
	NodoA *cursor=NULL;
	public:
		bool listaVacia(){
			return (cursor==NULL);
		}
		void insertarFin(Articulo x){
			NodoA *nuevo=new NodoA;
			nuevo->dato=x;
			if(listaVacia()){
				cursor=nuevo;
			}else{
				NodoA *p=cursor;
				do{
					p=p->sig;
				}while(p->sig!=cursor); //final de la lista
				p->sig=nuevo;
			}
			nuevo->sig=cursor;
			
		}
		void mostrar(){
			if(!listaVacia()){
				NodoA *p=cursor;
				do{
					//cout<<" "<<p->dato.codigo<<" "<<p->dato.descripcion<<" "<<p->dato.precio<<"\n";
					p->dato.escribir();
					p=p->sig;
				}while(p!=cursor); //explora toda la lista
			}
		}
	
};

int main(){
	ListaCircArt lista;
	Articulo a1;
	a1.codigo=10;
	a1.descripcion="XXX";
	a1.precio=9000;
	lista.insertarFin(a1);
	
	Articulo a2;
	a2.codigo=20;
	a2.descripcion="YYY";
	a2.precio=888;
	lista.insertarFin(a2);
	
	Articulo a3;
	a3.codigo=30;
	a3.descripcion="ZZZ";
	a3.precio=777;
	lista.insertarFin(a3);
	
	lista.mostrar();

	
	return 1;
}

