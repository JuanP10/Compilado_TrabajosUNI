# include <iostream>
using namespace std;

struct NodoA{
	string name;
	NodoA *PrimerB;
};

struct NodoB{
	int edad;
	NodoB *PrimerA;
};

class ListaMultiple{ 
	NodoA *ptrA=NULL;
	NodoB *ptrB=NULL;
	public:
		void insertarFinal(string x, int y);  
		void eliminarFinal ();	
		void mostrar();
		bool listaVacia();
		void insertarInicio (string x);
		void eliminarInicio();   //
		int cantidad();         //
		bool buscar(string x); //
};

bool ListaMultiple::listaVacia(){
	return (ptrA==NULL || ptrB==NULL);
}

void ListaMultiple::insertarFinal(string x, int y){
	NodoA *nuevoA=new NodoA;
	NodoB *nuevoB=new NodoB;
	nuevoA->name=x;
	nuevoB->edad=y;
	nuevoA->PrimerB=NULL;
	nuevoB->PrimerA=NULL;
	if(listaVacia()){
		ptrA=nuevoA;
		ptrB=nuevoB;
	}
	else{
		NodoA *p=ptrA;
		NodoB *q=ptrB;
		while (p->PrimerB!=NULL || q->PrimerA!=NULL){
			p=p->PrimerB;
			q=q->PrimerA;
		}
		p->PrimerB=nuevoA;
		q->PrimerA=nuevoB;
	}
}

void ListaMultiple::mostrar(){
	if (!listaVacia()){
		NodoA *p=ptrA;
		NodoB *q=ptrB;
		while(p!=NULL){
			cout<<" "<<p->name;
			cout<<" "<<q->edad<<" - "<<endl;
			p=p->PrimerB;
			q=q->PrimerA;
		}
	}
}


int main(){
	ListaMultiple ListaA;
	ListaMultiple ListaB;
		
	ListaA.insertarFinal("Juan", 2);
	ListaB.insertarFinal("Jose", 23);
	ListaA.mostrar();
	ListaB.mostrar();
	return 1;
}
