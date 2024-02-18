#include "iostream"
#include "PilaInt.h"

using namespace std;

void llenar(PilaInt &p, int n){
	for(int i=0; i<n; i++){
		p.insertar(i);
	}
}

void duplicar(PilaInt &p){
	PilaInt aux;
	while(!p.pilavacia()){
		aux.insertar(p.obtener());
		p.eliminar();
	}
	while(!aux.pilavacia()){
		p.insertar(aux.obtener());
		p.insertar(aux.obtener());
		aux.eliminar();
	}
}

int NumPostivos (PilaInt &p){
	for (int i=tope; i >= 0; i--){
		if (pila[i]>0){
			return tope++;
		}
}

int main(){
	PilaInt pil;
	int n;
	cout<<" Datos a generar: "; cin>>n;
	llenar(pil, n);
	pil.mostrar();
}
