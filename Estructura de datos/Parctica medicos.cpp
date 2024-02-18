#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

using namespace std;

bool esMedico();
bool mayorDe60(int x);
string tipoVacuna(int x);

// declaracion global
// int vacuna 1

struct Personas{
	int edad;
	string nombre;
	int vacuna;
	bool medico;
};

struct Nodo{
	Personas persona;
	Nodo *sig;
	Nodo *ant;
};

class ListaDoble{
	Nodo *ptr=NULL;
	Nodo *ult=NULL;
	public:
		bool listaVacia();
		void insertarInicio(Personas x);
		void insertarFinal(Personas x);
		
		void mostrar();
		void mostrarMedico();
		void mostrarMayor();	
};

bool ListaDoble::listaVacia(){
	return (ptr==NULL or ult==NULL);
}

void ListaDoble::insertarInicio(Personas x){
	Nodo *nuevo=new Nodo;
	nuevo->persona = x;
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

void ListaDoble::insertarFinal(Personas x){
	Nodo *nuevo=new Nodo;
	nuevo->persona = x;
	nuevo->sig = NULL;
	nuevo->ant = NULL;
	
	if(listaVacia()){
		ptr = nuevo;
		ult = nuevo;
	}
	else{
		ult->sig = nuevo;
		nuevo->ant = ult;
		ult = nuevo;;
	}
}

void ListaDoble::mostrar(){
	if(!listaVacia()){
		Nodo *p=ptr;
		cout<<"\n\n";
		cout<<"\tNOMBRE	MEDICO	EDAD	VACUNA\n";
		while(p!=NULL){
			cout<<"\t"<<p->persona.nombre;
			if(p->persona.medico){
				cout<<"\t"<<"SI";
			}
			else if(!p->persona.medico){
				cout<<"\t"<<"NO";
			}
			cout<<"\t"<<p->persona.edad;
			cout<<"\t"<<tipoVacuna(p->persona.vacuna);
			cout<<"\n";
			p=p->sig;
		}
		cout<<"\n";
	}
}

void ListaDoble::mostrarMedico(){
	if(!listaVacia()){
		Nodo *p=ptr;
		cout<<"\n\n\t\tSOLO PERSONAL MÉDICO\n\n";
		cout<<"\tNOMBRE	EDAD	VACUNA\n";
		while(p!=NULL){
			if(p->persona.medico==true){
				cout<<"\t"<<p->persona.nombre;
				cout<<"\t"<<p->persona.edad;
				cout<<"\t"<<tipoVacuna(p->persona.vacuna);
				cout<<"\n";
			}
			p=p->sig;
		}
		cout<<"\n";
	}
}

void ListaDoble::mostrarMayor(){
	if(!listaVacia()){
		Nodo *p=ptr;
		cout<<"\n\n\t\tSOLO MAYORES DE 60\n\n";
		cout<<"\tNOMBRE	EDAD	VACUNA\n";
		while(p!=NULL){
			if(p->persona.edad>60 and !p->persona.medico){
				cout<<"\t"<<p->persona.nombre;
				cout<<"\t"<<p->persona.edad;
				cout<<"\t"<<tipoVacuna(p->persona.vacuna);
				cout<<"\n";
			}
			p=p->sig;
		}
		cout<<"\n";
	}
}

bool esMedico(){
	char aux;
	do{
		cout<<"¿Es médico?[S/N]: "; cin>>aux;
		if(aux == 'S'){
			return true;
		}
		else if(aux == 'N'){
			return false;
		}
		else{
			cout<<"Opción incorrecta.";
		}	
	}while(aux!='S' || aux!='N');
}

bool mayorDe60(int x){
	if(x > 60)
		return true;
	else
		return false;
}

string tipoVacuna(int x){
	switch(x){
		case 1:
			return "Pfizer";
			
		case 2:
			return "Astrazeneca";
			
		case 3:
			return "Sinovac";
			
		default:
			cout<<"Vacuna no encontrada";
	}		
}

// funcion de porcentaje de vacunas
// ej: porcentaje(int x) 
// if x == 1 
//     vacuna1++;

int main(){
	setlocale(LC_ALL, "spanish");
	string menu="\n1. Ingresar Paciente.\n2. Listado todos.\n3. Listar solo personal médico.\n4. Listar solo Mayores de 60.\n5. % vacunas dado el tipo.\n6. Salir.\n";
	int op; // cantidad vacunas,  cout << (vacuna1/(vacuna1+vacuna2+vacuna3))*100 << "%"
	ListaDoble lista;
	Personas per;
	
	do{
		cout<<menu;
		cout<<"\nIngrese la opcion: "; cin>>op;
		
		switch(op){
			case 1:
				cout<<"\nDigita el nombre: "; cin>>per.nombre;
				per.medico = esMedico();
				cout<<"Digita la edad: "; cin>>per.edad;
				cout<<"Digita la vacuna aplicada (1. Pfizer - 2. Astrazeneca - 3. Sinovac): "; cin>>per.vacuna;
				
				//un llamado de funcion
				//ej: porcentaje(per.vacuna);
				
				if(per.medico){
					lista.insertarInicio(per);
					cout<<"\n\tPaciente ingresado correctamente.\n";
				}
				else if(mayorDe60(per.edad)){
					lista.insertarFinal(per);
					cout<<"\n\tPaciente ingresado correctamente.\n";
				}
				break;
				
			case 2:
				if(!lista.listaVacia())
					lista.mostrar();
				else
					cout<<"\n\tLa lista esta vacía.\n";
				break;
				
			case 3:
				if(!lista.listaVacia())
					lista.mostrarMedico();
				else
					cout<<"\n\tLa lista esta vacía.\n";
				break;
				
			case 4:
				if(!lista.listaVacia())
					lista.mostrarMayor();
				else
					cout<<"\n\tLa lista esta vacía.\n";
				break;
				
			case 5:
				// cout << "El porcentaje de persona vacuna con pfizer es " << (vacuna1/(vacuna1+vacuna2+vacuna3))*100 << "%"
				// vacuna1 / total * 100
				break;
				
			case 6:
				break;
				
			default:
				cout<<"\nOpcion no valida\n";
		}
	}while(op!=6);
	
	return 1;
}
