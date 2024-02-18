#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

int main(){
	int n;
	unsigned t0, t1;
	
	cout<<"Escriba la cantidad de numeros aleatorios: ";
	cin>>n;
	
	double valor;
	srand(time(NULL));
	
	for(int i=0; i<n; i++){
		valor=rand();
		cout<<"Numero: "<<valor<<endl;
	}
	
	t0=clock();

	t1 = clock();
	
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout << "Execution Time: " << time << endl;
	
	
	return 0;
}
