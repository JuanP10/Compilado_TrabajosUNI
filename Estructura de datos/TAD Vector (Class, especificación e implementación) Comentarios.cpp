/* Diseñar un TAD vector  */
# include <iostream>
using namespace std; 

/* 1er paso.  Definir que tipos de datos manejará el vector, en este caso Enteros 
   2do paso.  Definir la estructura de datos*/

class VectorEnteros {
	//Estructura de datos
	int v[1000];
	int n=0;
	//especificacion (operaciones abstractas - El ¿QUE hace? el TAB)
	//Public es lo que el usuario podrá ver
	public: 
		void adicionar (int x);
		void mostrar ();
		int cantidad ();
		bool buscar(int x);
		
		
		void modificar(int x, int y);
		void borrar (int x);
};

/* 3er paso.  Definir la implementación (El CÓMO)*/

void VectorEnteros::adicionar(int x){
	v[n]=x;
	n++;
}

void VectorEnteros::mostrar(){
	for (int i=0; i<n; i++){
		cout<<"  "<<v[i];
	}
}

int VectorEnteros::cantidad(){
	return n;
}

bool VectorEnteros::buscar(int x){
	for (int i=0; i<n ; i++){
		if (v[i]==x){
			return true; 
		}
	}
	return false;
}
 void VectorEnteros::modificar(int x, int y){
 	for (int i=0; i<n ; i++){
 		if (v[i]==x){
			v[1]=y; 
		}
	 }
 }
 
 void VectorEnteros::borrar(int x){
	//Si alguien ingresa 8, y 8 esta en el indice 2, el index 2 lo igualamos al vector siguiente y la cantidad de elementos le restamos en 1
	for(int i=0;i<n;i++){
		if(v[i]==x){
			for(int j=i;j<n;j++){
				v[j] = v[j+1];
			}
			n--;
		}
	}
}

int main(){
	//Usar TAD//
	VectorEnteros v1;
	v1.adicionar(10);
	v1.adicionar(3);
	v1.adicionar(4);
	
	v1.mostrar();
	cout<<endl;
	int can= v1.cantidad();
	cout <<"La cantidad de datos es "<<can<<endl;
	cout<<endl;
	bool res= v1.buscar(4);
	cout<<"Busqueda "<<res;

	cout<<endl;
	v1.modificar(3,9);
	cout<<endl;
	v1.borrar(8);
	cout<<"\nNuevo vector:\n\t ";
	v1.mostrar();
	
	return 1;
}

