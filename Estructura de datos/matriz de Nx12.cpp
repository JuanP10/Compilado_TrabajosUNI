/* Desarrollar un programa en C++ usando el editor Dev C++ y funciones que forme 
una matriz de Nx12 que contiene las ventas de las N sucursales de una empresa durante los 12  meses del año. 
El programa debe informar, total de ventas de la empresa, total de ventas por cada sucursal, sucursal 
que más vendió durante el año, y el mes que menos vendió la empresa.
Recomendaciones: Para hacer una prueba del programa, no coloque en numero de meses, sino 
que coloque un numero menor para que la revisión sea más rápida.
Haga una tabla de datos para que pueda comparar con la informaciónque produce el programa
 */
#include <iostream>
using namespace std;
void hacer_matriz (int N){
	int matriz [100][100];
	for(int i=0; i<N; i++){
		for(int j=0; j<3; j++){
			cout<<"dijite un numero: "<<"["<<i<<"]"<<"["<<j<<"]";
			cin>>matriz[i][j];
		}
	}
	cout<<"la matriz es: "<<endl;
	for(int i=0; i<N; i++){
		for(int j=0; j<3; j++){
			cout<<matriz[i][j];
		}	
		cout<<endl;
	}
	cout<<"El total de la empresa es: "<<endl;
	int total=0;
	for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < 3; j++ ) {
            total = total + matriz[i][j];
        }
    }
    cout<<total<<endl;
	cout<<"El total de cada sucursal es: "<<endl;
	int suma_t[N];
	int suma=0;
	for (int i=0; i<N; i++){
		suma=matriz[i][0]+matriz[i][1]+matriz[i][2];
		cout<<suma<<endl;
		suma_t[i]=suma;	
	}
	
	cout<<"La sucursal que mas vendio es: "<<endl;
	int mayor=0;
	for (int i=0; i<N; i++){
		if (mayor<suma_t[i]){
			mayor=suma_t[i];
			cout<<mayor;
		}
	}
}
int main(){
	int N;
	cout<<"Digite el numero de sucrusales de la empresa: ";
	cin>>N;
	hacer_matriz (N);
return 0;
}



