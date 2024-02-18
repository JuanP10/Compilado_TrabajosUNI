/* Manejar un conjunto de alumnos: Nombre, Semestre y Promedio
   - Captura de datos
   - Escritura de datos
   - Mejor Alumno
   - Porcentaje de alumnos en semestre 1 
   - promedio de promedios
   - listar estudiantes reprobados
   - listar estudiantes de novenos y decimo
   - manejen un vector de celulares */

#include <iostream>
using namespace std;

struct alumno{
   string nombre;
   int semestre;
   float promedio;	
};

void capturaDatos(alumno v[], int n){
	for(int i=0;i<n;i++){
		cout<<" Digita nombre ";cin>>v[i].nombre;
		cout<<" Digita semestre ";cin>>v[i].semestre;
		cout<<" Digita promedio ";cin>>v[i].promedio;
		cout<<"-------------------------------------"<<endl;
	}
}
void listar(alumno v[], int n){
	cout<<"------------Escritura de datos------------------"<<endl;
	for(int i=0;i<n;i++){
		cout<<" Nombre "<<v[i].nombre;
		cout<<", el semestre es "<<v[i].semestre;
		cout<<" y su promedio es "<<v[i].promedio<<endl;
	}
	cout<<"------------------------------------------------"<<endl;
}
string mejorAlumno(alumno v[], int n){
	string AlumnoMejor="";
	float mayor=0;
	for(int i=0;i<n;i++){
		if(v[i].promedio>mayor){
			mayor=v[i].promedio;
			AlumnoMejor=v[i].nombre;
		}
	}
	return AlumnoMejor;	
}
float PromediosPromedios (alumno v[], int n){
	float suma=0, prom=0 ;
	for(int i=0;i<n;i++){
		suma=suma+v[i].promedio++;
		prom=suma/4;	
	}
	return prom;
}

string AlumnosRepro(alumno v[], int n){
	cout<<"Los estudiantes reprobados son: ";
	for(int i=0;i<n;i++){
		if(v[i].promedio<300){
			cout<<v[i].nombre<<" - ";
		}
	}	
}

string AlumnosNueveyOcho(alumno v[], int n){
	cout<<"Los estudiantes de Noveno y Octavo semestre son: ";
	for(int i=0;i<n;i++){
		if(v[i].semestre==9 || v[i].semestre==8){
			cout<<v[i].nombre<<" - ";
		}
	}	
}

float porcenteSem1(alumno v[], int n){
	int c=0;
	float por=0;
	for(int i=0;i<n;i++){
	   	if(v[i].semestre==1){
	   		  c++;
		   }
	}
	por= (float)c/n * 100 ;
	
	return por; 
	
}

int main(){
	int n=0;
	//cout<<" digite n";cin>>n;
	alumno v[10000];
	capturaDatos(v,4);
	listar(v,4);
	string res=mejorAlumno(v,4);
	cout<<" El mejor alumno es "<<res<<endl;
	cout<<"------------------------------------------------"<<endl;
	cout<<" El porcentaje de alumnos semestre 1 es "<<porcenteSem1(v,4)<<"%"<<endl;
	cout<<"------------------------------------------------"<<endl;
	cout<<"El promedio de los promedios es de "<< PromediosPromedios(v,4)<<endl;
	cout<<"------------------------------------------------"<<endl;
	cout<<AlumnosRepro(v,4)<<endl;
	cout<<"------------------------------------------------"<<endl;
	cout<<AlumnosNueveyOcho(v,4)<<endl;
	return 1;
}
