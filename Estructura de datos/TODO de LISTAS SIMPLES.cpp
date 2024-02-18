#include <iostream>
using namespace std;

struct Alumnos{          
    int cod;
	string name;
	float prom; 
};

struct Nodo {
	Alumnos dato;
	Nodo *sig;
};
 
class ListaSimple{ 
	Nodo *ptr=NULL;
	public:
		void insertarFinal(Alumnos x);                                 //YA//
		void insertarInicio (Alumnos x);                               //YA//
		void insertarCualquierPosicion (Alumnos x, int posicion);      //Me falta algo//                           
		void eliminarFinal ();	                                       //YA//
		void eliminarInicio ();                                        //YA//
		void eliminarXposicion (int x);                                       
		void mostrar();                                                //YA//        
		bool listaVacia();                                             //YA//
		int buscarAlumno (int x);                                      //YA//      //Se busca por medio del codigo el alumno sale su posicion en la lista//
		void alumnoMayorPromedio();                                    //YA// 
		void alumnoMenorPromedio();                                    //YA no// 
		void cambiarNombre(int x);                                     //YA//       //Se ingresa el codigo y se le cambia el nombre//
		void ordenarPorPromedio (); 
		void buscarPosicion(int x);                                    //YA//      //Se ingresa una posicion y salen los datos de este//
		int cantidad();                                                //YA//      //Cantidad de Alumnos//  
};

bool ListaSimple::listaVacia(){
	return (ptr==NULL);
}

void ListaSimple::insertarFinal(Alumnos x){
	Nodo *nuevo=new Nodo; 
	nuevo->dato=x;
	nuevo->sig=NULL;
	if(listaVacia()){
		ptr=nuevo;
	}
	else{
		Nodo *p=ptr;
		while (p->sig!=NULL){
			p=p->sig;
		}
		p->sig=nuevo;
	}
}

 void ListaSimple::insertarInicio(Alumnos x){
	Nodo *nuevo=new Nodo;
	nuevo->dato=x;
	nuevo->sig=NULL;
	if(listaVacia()){
		ptr=nuevo;
	}
	else{
		nuevo->sig=ptr;
		ptr=nuevo;
	}
}

void ListaSimple::insertarCualquierPosicion(Alumnos x, int posicion){
	Nodo *nuevo=new Nodo;
	Nodo *nuevoQ;
	nuevo->dato=x;
	nuevo->sig=NULL;
	int c=0;
	if(listaVacia()){
		ptr=nuevo;

	}
	if (posicion==1){
		nuevo->sig=ptr;
		ptr=nuevo;
	}
	Nodo *p=ptr;
	if (p->sig!=NULL){
			p=p->sig;
		}
		p->sig=nuevo;
		
	if (posicion > 1 && posicion !=NULL)
	{
		nuevoQ->sig;
		for (int i=1; i<=posicion-1 ; i++){
			nuevoQ=nuevoQ->sig;
			nuevo->sig= nuevoQ->sig;
			nuevoQ->sig=nuevo;
		}
	}
	else
	cout<<"Posicion incorrecta...";		
}
void ListaSimple::eliminarFinal(){
	if(!listaVacia()){
		Nodo *p=ptr;
		if(ptr->sig==NULL){ 
			ptr=NULL;
		}else{ 
			Nodo *q=p;
			while (p->sig!=NULL){
				q=p;
				p=p->sig;	
			}
			q->sig=NULL;
		}
		delete p;
	}
}

void ListaSimple::eliminarInicio(){
	if(!listaVacia()){
		Nodo *p=ptr;
		if(ptr->sig==NULL)
			ptr=NULL;
		else{
			ptr=ptr->sig;
			p->sig=NULL;
		}
		delete p;
	}
}


void ListaSimple::mostrar(){
	if(!listaVacia()){
		Nodo *p=ptr;
		cout<<endl;
		while(p!=NULL){
			cout<<"Codigo: "<<p->dato.cod<<" - Nombre: "<<p->dato.name<<" - Promedio: "<<p->dato.prom;
			cout<<endl;
			p=p->sig;
		}
		cout<<endl;
	}
}

int ListaSimple::buscarAlumno(int x){
	Nodo *p=ptr;
	int pos;
	if (!listaVacia()){
		Nodo *p=ptr;
		pos=1;
	    while(p->sig != NULL && p->dato.cod != x){
		p=p->sig;
		pos++;
	    }
	    if(p->dato.cod != x)
	        pos=0;	
	}
    return pos;
}

void ListaSimple::alumnoMayorPromedio(){
   if(!listaVacia()){
        Nodo *p = ptr;
        float mayor=0;
        string nombre="";
        while(p!=NULL){
            if(p->dato.prom > mayor){
            	mayor=p->dato.prom;
                nombre=p->dato.name;
                
            }
            p = p->sig;
            }
            cout<<"El Alumno con mayor promedio es: "<<nombre<<endl;
        }
}	

void ListaSimple::alumnoMenorPromedio(){
   if(!listaVacia()){
        Nodo *p = ptr;
        float menor=0;
        string nombre="";
        while(p!=NULL){
            if(p->dato.prom > menor) {
            	menor=p->dato.prom;
                nombre=p->dato.name;
            }
            p = p->sig;
            }
            cout<<"El Alumno con el menor promedio es: "<<nombre<<endl;
        }
}

void ListaSimple::cambiarNombre(int x){
    if(!listaVacia()){
        Nodo *p = ptr;
        while(p!=NULL){
            if(p->dato.cod == x){
                cout<<"\tIngrese el nuevo nombre para el Alumno con el codigo "<< p->dato.cod<<": ";
                cin >> p->dato.name;
                break;
            }
            if(p->sig == NULL){
                break;
            }
            p = p->sig;
        }
    }
}

void ListaSimple::buscarPosicion(int x){
	if(!listaVacia()){
		Nodo *p=ptr;
		cout<<"\n\n";
		int i=1;
		while(p!=NULL){
			if(i==x){
				cout<<"Nombre: "<<p->dato.name;
				cout<<"Codigo: "<<p->dato.cod;
				cout<<"Promedio: "<<p->dato.prom;
				cout<<"    ";
			}
			p=p->sig;
			i++;
		}
		cout<<"\n";
	}
}

int ListaSimple::cantidad(){
	Nodo *p;
	p=ptr;
	int total=0;
	while (p!=NULL){
		total++;
		p=p->sig;
	    }
     return total;
}

int main (){
    Alumnos a;
	ListaSimple Lista;
	string menu= "1. Insertar por el Final    2. Insertar por el Inicio     3. Insertar en cualquier posicion";
	string menu2="4. Eliminar por el final    5. Eliminar por el Inicio     6. Eliminar en cualquier posicion";
	string menu3="7. mostrar                  8. Buscar Alumno por cod      9. Alumno Mayor promedio";
	string menu4="10.Alumno Menor promedio    11. Cambiar nombre por cod    12. Ordenar por Mayor Promedio";   
	string menu5="13. posicion                14. Cantidad                  15. Salir";
	int num;
	int posicion;
	do{
		cout<<"___________________________________________________________________________________________________________"<<endl;
 		cout<<menu<<endl;
 		cout<<menu2<<endl;
 		cout<<menu3<<endl;
 		cout<<menu4<<endl;
 		cout<<menu5<<endl;
 		cout<<"___________________________________________________________________________________________________________"<<endl;
 		cout<<endl;
		cin>>num;
		cout<<endl;
		switch (num){
			case 1: 
				cout<<"Digita el nombre del Alumno: "; 
				cin>>a.name;
				cout<<"Digita el codigo del alumno: " ; 
				cin>>a.cod;
				cout<<"Digita el promedio del alumno: " ; 
				cin>>a.prom;
				Lista.insertarFinal(a);
			break;
			
			case 2:
				cout<<"Digita el nombre del Alumno: "; 
				cin>>a.name;
				cout<<"Digita el codigo del alumno: " ; 
				cin>>a.cod;
				cout<<"Digita el promedio del alumno: " ; 
				cin>>a.prom;
				Lista.insertarInicio(a);				
			break;
			
            case 3:
            	cout<<"Digite la posicion en que desea colocarlo: ";
				cin>>posicion;
				cout<<"Digita el nombre del Alumno: "; 
				cin>>a.name;
				cout<<"Digita el codigo del alumno: " ; 
				cin>>a.cod;
				cout<<"Digita el promedio del alumno: " ; 
				cin>>a.prom;
				Lista.insertarCualquierPosicion(a, posicion);				
			break; 			
			 
			case 4:
			Lista.eliminarFinal();
			cout<<"se ha eliminado el dato por el final"<<endl; 
			break;
			
			case 5:
			Lista.eliminarInicio();
			cout<<"se ha eliminado el dato por el inicio"<<endl; 
			break;
			
			case 6: 
			{
				int posi;
				cout<<"Digite la posicion del dato que desea borrar: "; cin>>posi;
				Lista.eliminarXposicion(posi);
				cout<<"Elemento borrado"<<endl;					
			}
			break;
			
			case 7:
			Lista.mostrar();
			cout<<endl;
			break; 
			
			case 8:
			{
				int codigo;
				cout<<"Digite el codigo del Alumno en que desea saber su poscion: "; cin>>codigo;
				cout<<"La posicion del Alumno es: " << Lista.buscarAlumno(codigo)<<endl;					
			}
			break;
				
			case 9:
			Lista.alumnoMayorPromedio();
			break;
			
			case 10:
			Lista.alumnoMenorPromedio();
			break;
			
			case 11:
			float codigo;	
			cout<<"Digite el codigo del estudiante en que desea cambiar su nombre: ";cin>>codigo; 	
			Lista.cambiarNombre(codigo);
			break;
				
			case 13:
		    int aux;
		    cout<<"Ingrese la posicion a buscar: "; cin>>aux;
		    Lista.buscarPosicion(aux);
			break;    
			
			case 14:
			cout<<"La cantidad de datos es: "<<Lista.cantidad();
			cout<<endl;
			break;  				
		}
	 }while (num!=15);
 	return 1;
 }
