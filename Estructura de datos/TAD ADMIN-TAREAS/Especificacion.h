#include <iostream>
using namespace std;

class programas{
	int tope=-1;         
	string pila[100];
	public:
		void insertar (string x);
		void mostrar();
		int contar(string x);
		void eliminar ();
	    string obtener ();
		bool pilavacia();
		int cantidad();	
};


