/* Hacer una estructura con marcas de celulares, el precio y su cantidad, con ella decir
el celular más caro y más barato, la suma total de cada uno de los celulares. */

#include <iostream>
#include <ctime> 
using namespace std; 
unsigned t0, t1;
 
t0=clock()

struct celulares {
	string marca;
	float precio;
	int cantidad;
};

void datos (celulares v[], int n){
	for (int i=0; i<n ; i++){
		cout<<"Digite la marca: ";cin>>v[i]. marca;
		cout<<"Digite la el precio: ";cin>>v[i]. precio;
		cout<<"Digite la cantidad: ";cin>>v[i]. cantidad;
		cout<<"----------------------"<<endl;
	}
}
string celMasCaro(celulares v[], int n){
	string celcaro="";
	float mayor=0;
	for(int i=0;i<n;i++){
		if(v[i].precio>mayor){
			mayor=v[i].precio;
			celcaro=v[i].marca;
		}
	}
	return celcaro;	
}
string celMasBarato(celulares v[], int n){
	string celbarato="";
	float menor=0;
	for(int i=0;i<n;i++){
		if(v[i].precio<menor){
			menor=v[i].precio;
			celbarato=v[i].marca;
		}
	}
	return celbarato;	
}
t1 = clock();

int main (){
	int n=0;
	celulares v[5];
	datos(v,5);
	cout<<"El celular mas economico es: "<<celMasBarato(v,5)<<endl;
	cout<<"El celular mas caro es: "<<celMasCaro(v,5)<<endl;
	
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
cout << "Execution Time: " << time << endl;

	return 1;
}


