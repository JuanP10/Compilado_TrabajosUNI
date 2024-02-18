#include <iostream>
#include <conio.h>

using namespace std;

void primera_matriz(int m1[4][5]);

void segunda_matriz(int m2[4][5]);



int main(){
	int m1[4][5];
	int m2[4][5];
	primera_matriz(m1);
	segunda_matriz(m2);
	
	
	
	getch();
	return 0;
}

void primera_matriz(int m1[4][5]){
	int mayor = 0;
	for(int i=0;i<4;i++){
		for(int j=0;j<5;j++){
		
	cout<<"ingrese los valores de la primera matriz ["<<i<<"["<<j<<"]: ";
		cin>> m1[i][j];
		
		if(m1[i][j]<mayor)
		mayor = m1[i][j];
		}
		
	}
}

void segunda_matriz(int m2[4][5]){
	for(int i=0;i<4;i++){
		for(int j=0;j<5;j++){
			cout<<"ingrese los valores de segunda matriz ["<<i<<"["<<j<<"]: ";
		cin>> m2[i][j];
		}
}
}
