#include <iostream>
using namespace std;
#include "Especificacion.h"

void programas :: insertar(string x){
	tope++;
	pila[tope]=x;
}

void programas :: mostrar(){
	for(int i=tope ; i>=0 ; i--){
		cout<<" "<<pila[i]<<"\n";
	}
}

int programas :: contar(string x){
	int z=0;
	for(int i=tope ; i>=0 ; i--){
		if(pila[i]==x){
			z++;
		}
	}
	return z;
}

bool programas :: pilavacia(){
	if(tope==-1)
     	return true;
	else
	    return false;
}

void programas::eliminar(){
	tope--;	
}

string programas::obtener(){
	return pila[tope];
}
int programas::cantidad(){
	return ++tope;
}

programas BaseXTope (programas p){  
	programas aux;               
	programas nuevo;
	aux.insertar(p.obtener());
	nuevo.insertar(p.obtener());
	p.eliminar();
	
	while (!p.pilavacia()){
		aux.insertar(p.obtener());
		p.eliminar();
		if (p.cantidad()==1){
			break;
		}	
	} 

	while (!aux.pilavacia()){
	    nuevo.insertar(aux.obtener()); 
		aux.eliminar();	
	}
	
	nuevo.insertar(p.obtener());
	p.eliminar();
	return nuevo;
}







