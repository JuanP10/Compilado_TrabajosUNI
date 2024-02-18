#include <iostream>
using namespace std;

struct Vacunados{
	string nombre;
	bool tipo;  //Si es medico (1) o no (0)
	int edad;
	string vacunaApl;
	Vacunados *sig;
	Vacunados *ant;
};

class ListaDoble{
	Vacunados *ptr=NULL;
	Vacunados *ult=NULL;
	
	public:
		void entradaPrinci(string nombre, bool tipo, int edad, string VacunaApl);
		void entradaSecun(string nombre, bool tipo, int edad, string VacunaApl);
		void mostrar();
		bool listaVacia();
};

bool ListaDoble::listaVacia(){
	return (ptr==NULL || ult==NULL);
}

void ListaDoble:: entradaPrinci(string nombre, bool tipo, int edad, string VacunaApl){
	Vacunados *nuevo = new Vacunados;
	nuevo->nombre = nombre;
	nuevo->tipo = tipo;
	nuevo->edad = edad;
	nuevo->vacunaApl = VacunaApl;
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

void ListaDoble::entradaSecun(string nombre, bool tipo, int edad, string VacunaApl){
	Vacunados *nuevo = new Vacunados;
	nuevo->nombre = nombre;
	nuevo->tipo = tipo;
	nuevo->edad = edad;
	nuevo->vacunaApl = VacunaApl;
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
		Vacunados *p=ptr;
		while(p!=NULL){
			cout<<" - "<<p->nombre;
			cout<<" - "<<p->tipo;
			cout<<" - "<<p->edad;
			cout<<" - "<<p->vacunaApl;
			p=p->sig;
		}
	}
}

int main {
	string name;
    bool tipe;  
    int age;
    string vacunaApl;	
    ListaDoble lista;
    
cout<<"1. Ingresar Paciente 2. Listado todos 3. Listar solo personal médico 4. Listar solo Mayores de 60.  5.% vacunas dado el tipo"<<endl;
int op;
	do{
		cout<<"Ingresa el número que deseas: ";
		cin>>op;
    	switch(op){
			case 1:
				string asociado;
			    cout<<"Es asociado al centro medico? responda si o no";
				cin>>asociado;
				if(asociado=="si"){
					Lista.entradaPrin(name, type, age, vacunaApl);
				}else if (asociado=="No"){
					Lista.entradaSecun(name, type, age, vacunaApl)
				}else
				cout<<"Respuesta incorrecta"<<endl;
			break;
			case 2: 
			    cout<<endl;
			    Lista.mostrar();
			    cout<<endl;
			break; 		
	}	
	}while(op!=5);
	
	return 1;
}
