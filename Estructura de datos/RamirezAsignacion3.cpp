//Colas de listas simples, TODO//
//Recuerda, Ingresa por el final, y sale por el inicio//
//Recuerda, En PILAS se ingresa por el final y también sale por el final//

#include <iostream>
using namespace std;

struct Clientes{
	string nombre;
	int edad;
};

struct Nodo {
	Clientes dato;
	Nodo *sig;
}; 
class ColaClientes{
	Nodo *ptr=NULL;
	public:
		void Agregar (Clientes x);   // 
		void borrar ();              //
		bool Vacia();                //
		void mostrar();              //
		void obtener(string x);      //   
		int cantidad();              //
		void ClienteMayorEdad();     //
};
void ColaClientes::ClienteMayorEdad(){
   if(!Vacia()){
        Nodo *p = ptr;
        int mayor=0;
        string nombre="";
        while(p!=NULL){
            if(p->dato.edad > mayor){
            	mayor=p->dato.edad;
                nombre=p->dato.nombre;
            }
            p = p->sig;
            }
            cout<<"El cliente con la mayor edad es: "<<nombre<<endl;
        }
}	

bool ColaClientes::Vacia(){
	return (ptr==NULL);
}

void ColaClientes::Agregar(Clientes x){
	Nodo *nuevo=new Nodo;
	nuevo->dato=x;
	nuevo->sig=NULL;
	if(Vacia()){
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

void ColaClientes::mostrar(){
	if(!Vacia()){
		Nodo *p=ptr;
		cout<<endl;
		while(p!=NULL){
			cout<<"Nombre: "<<p->dato.nombre<<" - Edad: ";
			cout<<p->dato.edad;
			cout<<endl;
			p=p->sig;
		}
		cout<<endl;
	}
}
void ColaClientes::borrar(){
	if(!Vacia()){
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
	
int ColaClientes::cantidad(){
	Nodo *p;
	p=ptr;
	int total=0;
	while (p!=NULL){
		total++;
		p=p->sig;
	    }
     return total;
}
    
void ColaClientes::obtener(string x){
	if(!Vacia()){
		Nodo *p=ptr;
		while(p!=NULL){
			if(p->dato.nombre==x)
			cout<<"Nombre: "<<p->dato.nombre<<" - Edad: ";
			cout<<p->dato.edad;
			cout<<endl;
			p=p->sig;
		}
		cout<<endl;
	}	
}

int main(){
 	Clientes c;
 	ColaClientes Lista;
 	string menu="1. agregar, 2. borrar, 3. obtener, 4. cantidad, 5. mostrar y 6. Mostrar el cliente con mayor edad y 7. salir ";
 	int num;
 	do{
 		cout<<menu<<endl;
		cin>>num;
		cout<<endl;
		switch (num){
			case 1: 
				cout<<"Digita el nombre del Cliente: "; 
				cin>>c.nombre;
				cout<<"Digita la edad del Cliente: " ; 
				cin>>c.edad;
				cout<<endl;
				Lista.Agregar(c);
			break;	
			
			case 2:
				Lista.borrar();
				cout<<"Elemento borrado"<<endl;
				break;
			
			case 3:
				{
				string name;
				cout<<"Digite el nombre del cliente que desea buscar: ";
				cin>>name;
				Lista.obtener(name);					
				}
				break;
				
			case 4:
				cout<<"La cantidad de datos es: "<<Lista.cantidad();
				cout<<endl;
				break;
				
			case 5:
			    if(!Lista.Vacia()){
			    cout<<endl;
			    Lista.mostrar();	
				}
			break;	
			
			case 6:
		    Lista.ClienteMayorEdad();
			break;      				
		}
	 }while (num!=7);
 	return 1;
 }
