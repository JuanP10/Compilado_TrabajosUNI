#include <iostream>
using namespace std;

struct transaccion{
	int id;
	string tipo;
	int valor;
};

class ColaTrans{
	transaccion cola[100];
	int inicio=-1;
	int fin=-1;
	public:
		void ingresar (transaccion x);
		void eliminar ();
		transaccion obtener();
		
		bool colaVacia();
		int cantidad();
		void mostrar();
		bool buscar (int id);
};
void ColaTrans::ingresar(transaccion x){
	if (colaVacia()){
		inicio++;
	}
	fin++;
	cola[fin]=x;
}
bool ColaTrans::colaVacia(){
	return (inicio==-1);
}

void ColaTrans::mostrar(){
	for (int i=inicio; i<=fin; i++){
		cout<<"  "<<cola[i].id<<" - "<<cola[i].tipo<<" - "<<cola[i].valor<<endl;
	}
}


void ColaTrans::eliminar(){
	if(!colaVacia()){
		if(inicio==fin){
			inicio=fin=-1;
		}else{
			inicio++;
		}
	}
	
}
transaccion ColaTrans::obtener(){
	transaccion tv;
		if(!colaVacia()){
			return cola[inicio];
		}
		return tv;
}

bool ColaTrans::buscar(int x){
	for(int i=inicio; i<=fin; i++){
		if(cola[i].id==x){
			return true;
		}
	}
	return false;
}

int ColaTrans::cantidad(){
	return ++fin;
}
int main (){
	string men= "1.Ingresar 2.Listar 3.Atender 4.Buscar  5.Cantidad  6. Salir";
	int op;
	ColaTrans cola;
	transaccion t;
	do{
		cout<<men<<endl;
		cin>>op;
		switch(op){
			case 1:
				cout<<"Digita id: "; 
				cin>>t.id;
				cout<<"Digita tipo: "; 
				cin>>t.tipo;
				cout<<"Digita valor: "; 
				cin>>t.valor;
				cola.ingresar(t);	
				cout<<"transaccion ingresada en la cola"<<endl;	
			break;
			
			case 2: 
			    if(!cola.colaVacia()){
			    cout<<endl;
			    cola.mostrar();	
				}
			break;
			case 3:   
			  if(!cola.colaVacia()){
			  	transaccion t=cola.obtener();
			  	cola.eliminar();
			  	cout<<"Trasaccion atendida"<<t.id;
			  }else{
			  	cout<<"no hay nada en cola";
			  }
			break;
			
			case 4:{
				bool busqueda=cola.buscar(12);
				cout<<"busqueda: "<<busqueda;
			}
				
		    break;
		    
		    case 5:
		    	int cantidad=cola.cantidad();
		    	cout<<"La cantidad de datos es: "<<cantidad<<endl;
		    break;	
		    
		    //default: cout<<"Opcion no valida"<<endl;
		}
	}while(op!=4);
	
	return 1;
}
