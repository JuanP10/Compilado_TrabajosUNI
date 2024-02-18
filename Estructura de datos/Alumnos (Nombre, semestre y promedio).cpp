/* Manejar un conjunto de alumnos: Nombre, Semestre y Promedio
   - Captura de datos
   - Escritura de datos
   - Mejor Alumno
   -Porcentaje de alumnos en semestre 1  */

#include <iostream>
using namespace std;
#include <ctime> 


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
		cout<<"-----------------"<<endl;
	}
}
void listar(alumno v[], int n){
	for(int i=0;i<n;i++){
		cout<<" Nombre "<<v[i].nombre;
		cout<<" Semestre "<<v[i].semestre;
		cout<<" Promedio "<<v[i].promedio<<endl;
		
	}
}
string mejorAlumno(alumno v[], int n){
	string nommejor="";
	float mayor=0;
	for(int i=0;i<n;i++){
		if(v[i].promedio>mayor){
			mayor=v[i].promedio;
			nommejor=v[i].nombre;
		}
	}
	return nommejor;	
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
// promedio de promedios
// listar estudiantes reprobados
// listar estudiantes de novenos y decimo
// manejen un vector de celulares

int main(){
	
unsigned t0, t1;
 
t0=clock();
	int n=0;
	//cout<<" digite n";cin>>n;
	alumno v[10000];
	capturaDatos(v,3);
	listar(v,3);
	string res=mejorAlumno(v,4);
	cout<<" El mejor alumno es "<<res<<endl;
	cout<<" El porcentaje de alumnos semestre 1 es "<<porcenteSem1(v,3)<<"%"<<endl;
	
	t1=clock();
	
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;
	return 1;
}
