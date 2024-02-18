#include <iostream>
#include <ctime> 
#include <iomanip>
using namespace std;


struct Nodo{
	string dato;
	Nodo *sig;
};

class ListaSimple{
	Nodo *ptr=NULL;
	public:
		void insFinal(string x);
		void insInicio(string x);
		
		void elimFinal();
		
		void mostrar();
		bool listaVacia();
};

void ListaSimple::elimFinal(){
	if(!listaVacia()){
		Nodo *p=ptr;
		if(ptr->sig==NULL){
			ptr=NULL;
		}else{
			Nodo *q=p;
			while(p->sig!=NULL){
				q=p;
				p=p->sig;
			}
			q->sig=NULL;
		}
		delete p;
	}
}
void ListaSimple::insInicio(string x){
	Nodo *nuevo=new Nodo;
	nuevo->dato=x;
	nuevo->sig=NULL;
	
	if(listaVacia()){
		ptr=nuevo;
	}
	else{
		nuevo->sig=ptr;
		ptr=nuevo;
	}
}



void ListaSimple::mostrar(){
	if(!listaVacia()){
		Nodo *p=ptr;
		while(p!=NULL){
			cout<<" "<<p->dato;
			p=p->sig;
		}
	}
}

bool ListaSimple::listaVacia(){
	return (ptr==NULL);
}
void ListaSimple::insFinal(string x){
	Nodo *nuevo=new Nodo;
	nuevo->dato=x;
	nuevo->sig=NULL;
	
	if(listaVacia()){
		ptr=nuevo;
	}else{
		Nodo *p=ptr;
		while(p->sig!=NULL){
			p=p->sig;
		}
		p->sig=nuevo;
	}
}

int main(){
	unsigned t0, t1;
 
    t1=clock();
	ListaSimple lista;
	
	//lista.insFinal("Es");
	lista.insFinal("Martes");
	//lista.insInicio("Hoy");
	//lista.elimFinal();
	lista.mostrar();
	cout<<endl;
	
 
    t1=clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " <<time << endl;
	return 1;
}
