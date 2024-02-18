#include <iostream>
using namespace std;

void ColaAvion::aproximacion(transaccion x){
	if(colaVacia()){
		inicio++;
	}
	fin++;
	datosAvion[fin]=x;
}

void ColaAvion::eliminar(){
	if(!colaVacia()){
		if(inicio==fin){
	   	  inicio=fin=-1;	
		}else{
			inicio++;
		}
	}
}

Avion ColaAvion::obtener(){
	Avion tv;
	if(!colaVacia()){
		return cola[inicio];
	}
	return tv;
}

bool ColaAvion::colaVacia(){
	return (inicio==-1);
}
void ColaAvion::mostrar(){
	for(int i=inicio;i<=fin;i++){
		cout<<" "<<Avion[i].referencia<<" "<<Avion[i].aerolinea<<" "<<Avion[i].codAterrizaje<<" "<<Avion[i].emergencia<<"\n";
}

bool ColaAvion::buscar(int referencia){
	for(int i=inicio; i<=fin; i++){
		if(Avion[i].referencia==x){
			return true;
		}
	}
	return false;
}

int ColaAvion::cantidad(){
	return ++fin;
}


