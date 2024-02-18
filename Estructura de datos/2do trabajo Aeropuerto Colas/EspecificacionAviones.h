#include <iostream>
using namespace std;

struct Avion{
	int referencia;
	string aerolinea;
	int codAterrizaje;
	int emergencia;  
};

class ColaAvion{
	Avion datosAvion [100];
	int inicio=-1;
	int fin=-1;
	public:
		void aproximacion (Avion x);
		void eliminar();
		bool colaVacia();
		void mostrar();
		Avion obtener();
		int cantidad();
		bool buscar (int referencia);
};
