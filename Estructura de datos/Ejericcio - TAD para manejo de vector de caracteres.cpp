/* Diseñar un TAD para manejo de vector de caracteres. Realice el tad, implementación y prueba en
c++ y pruebe el TAD. */

#include <iostream>
using namespace std;

	class VectCart{
	char v[100];
	int n=0;
	public:
		void insertarCart(char a);
		void borrarCart(char a);
		void CambiarCart(char a, char b);
		void mostrar();
};
void VectCart::insertarCart(char a){
	v[n] = a;
	n++;
}
void VectCart::borrarCart(char a){
	for(int i=0;i<n;i++){
		if(v[i]==a){
			for(int j=i;j<n;j++){
				v[j] = v[j+1];
			}
			n--;
		}
	}
}
void VectCart::CambiarCart(char a, char b){
    for (int i=0; i<n ; i++){
 		if (v[i]==a){
			v[1]=b; 
		}
	 }
}
void VectCart::mostrar(){
	for(int i = 0; i < n; i++){
		cout<<"  "<<v[i];
	}
}

int main(){
	VectCart vector;
	vector.insertarCart('J');
	vector.insertarCart('U');
	vector.insertarCart('A');
	vector.insertarCart('N');
	vector.mostrar();
	cout<<"\n";
	vector.borrarCart('A'); 
	vector.CambiarCart('A','N'); 
	vector.mostrar();
}

