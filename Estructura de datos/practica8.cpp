#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Students{
	int cod;
	string name;
	float avg;
};

struct Nodo{
	Students student;
	Nodo *sig;
};

class ListaSimple{
	Nodo *ptr=NULL;
	public:
		void insFinal(Students x);
		void insInicio(Students x);
		
		void mostrar();
		bool listaVacia();
		void elimFinal();
		void elimInicio();
		
		void buscarPosicion(int x);
		
};

void ListaSimple::elimInicio(){
	if(!listaVacia()){
		Nodo *p=ptr;
		if(ptr->sig==NULL)
			ptr=NULL;
		else{
			ptr=ptr->sig;
			p->sig=NULL;
		}
		delete p;
	}
}

void ListaSimple::insInicio(Students x){
	Nodo *nuevo=new Nodo;
	nuevo->student = x;
	/*cout<<"Ingrese el codigo: "; cin>>nuevo->student.cod;
	cout<<"Ingrese el nombre: "; cin>>nuevo->student.name;
	cout<<"Ingrese el promedio: "; cin>>nuevo->student.avg;
	*/
	nuevo->sig=NULL;
	
	if(listaVacia()){
		ptr=nuevo;
	}else{
		nuevo->sig=ptr;  
		ptr=nuevo;
	}
}

bool ListaSimple::listaVacia(){
	return (ptr==NULL);
}

void ListaSimple::insFinal(Students x){
	Nodo *nuevo=new Nodo;
	nuevo->student = x;
	/*cout<<"Ingrese el codigo: "; cin>>nuevo->student.cod;
	cout<<"Ingrese el nombre: "; cin>>nuevo->student.name;
	cout<<"Ingrese el promedio: "; cin>>nuevo->student.avg;
	*/
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

void ListaSimple::buscarPosicion(int x){
	if(!listaVacia()){
		Nodo *p=ptr;
		cout<<"\n\n";
		int i=1;
		while(p!=NULL){
			if(i==x){
				cout<<" "<<p->student.cod;
				cout<<" "<<p->student.name;
				cout<<" "<<p->student.avg;
				cout<<"    ";
			}
			p=p->sig;
			i++;
		}
		cout<<"\n";
	}
}

void ListaSimple::mostrar(){
	if(!listaVacia()){
		Nodo *p=ptr;
		cout<<"\n\n";
		while(p!=NULL){
			cout<<"\t "<<p->student.cod;
			cout<<" "<<p->student.name;
			cout<<" "<<p->student.avg;
			cout<<"    ";
			p=p->sig;
		}
		cout<<"\n";
	}
}

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

int main(){
	string menu="\n1. Insertar por el final.\n2. Obtener por posicion.\n3. Eliminar por el final.\n4. Mostrar.\n5. Salir.\n";
	int op;
	ListaSimple lista;
	Students st;
	
	do{
		cout<<menu;
		cout<<"Ingrese la opcion: ";cin>>op;
		
		switch(op){
			case 1:
				cout<<"\nDigita el codigo: "; cin>>st.cod;
				cout<<"Digita el nombre: "; cin>>st.name;
				cout<<"Digita el promedio: "; cin>>st.avg;
				lista.insFinal(st);
				break;
				
			case 2:
				int aux;
				cout<<"\n\tIngrese la posicion a buscar: "; cin>>aux;
				lista.buscarPosicion(aux);
				break;
				
			case 3:
				lista.elimFinal();
				break;
				
			case 4:
				if(!lista.listaVacia())
					lista.mostrar();
				else
					cout<<"\n\tLa lista esta vacia.\n";
				break;
				
			case 5:
				break;
				
			default: cout<<"\nOpcion no valida\n";
		}
	}while(op!=5);
	
	return 1;
}
