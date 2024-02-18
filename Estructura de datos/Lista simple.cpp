#include <iostream>
using namespace std;
#include <ctime> 
 
struct Nodo{          //Creacion del nodo en una lista simple, guarda la variable y el siguiente que es un puntero//
    string dato;
	Nodo *sig;   //Es un puntero, guarda las direcciones de memoria//
};

class ListaSimple{  //Creacion de lista simple, guarda el ptr como puntero que es igual a Nulo//
	Nodo *ptr=NULL;
	public:
		void insertarFinal(string x);  //Inserta dato por el final
		void eliminarFinal ();	
		void mostrar();
		bool listaVacia();
		void insertarInicio (string x);
		void eliminarInicio();   //
		int cantidad();         //
		bool buscar(string x); //
};

 int ListaSimple::cantidad(){
	Nodo p;
	int total;
	if(ptr!=NULL){
		p=ptr;
		total = 1;
	
	while (p->dato !=NULL){
		p=p->dato;
		total++;
	    }
    }
   else 
   cout<<"Lista vacia";
   return total;
}

bool ListaSimple::buscar(string x){
	while(p=NULL){
	if(dato==x){
		return true;
		}
	}
	return false;
} 

bool ListaSimple::listaVacia(){
	return (ptr==NULL);
}

void ListaSimple::insertarFinal(string x){
	Nodo *nuevo=new Nodo; //Crear el nodo//
	nuevo->dato=x;
	nuevo->sig=NULL;
	if(listaVacia()){
		ptr=nuevo;
	}
	else{
		Nodo *p=ptr;
		while (p->sig!=NULL){
			p=p->sig;
		}
		p->sig=nuevo;
	}
}
void ListaSimple::mostrar(){
	if (!listaVacia()){
		Nodo *p=ptr;
		while(p!=NULL){
			cout<<" "<<p->dato;
			p=p->sig;
		}
	}
}

void ListaSimple::insertarInicio(string x){
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

void ListaSimple::eliminarFinal(){
	if(!listaVacia()){
		Nodo *p=ptr;
		if(ptr->sig==NULL){ 
			ptr=NULL;
		}
		else{  
			Nodo *q=p;
			while (p->sig!=NULL){
				q=p;
				p=p->sig;	
			}
			q->sig=NULL;
		
		}
		delete p;
	}
}

int main(){
	#include <ctime> 
 
    unsigned t0, t1;
 
    t0=clock();
    
	ListaSimple Lista;
	Lista.insertarFinal("Hoy");
	Lista.insertarFinal("es");
	Lista.insertarFinal("Martes");
	Lista.insertarInicio("Unimag");
	Lista.insertarInicio("Sistemas");
	Lista.eliminarFinal();
	Lista.eliminarFinal(); 
	Lista.mostrar();
	bool busqueda=ListaSimple.buscar("es");
	cout<<"busqueda: "<<busqueda;
	
	t1 = clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
cout << "Execution Time: " << time << endl;
	return 1;
}


