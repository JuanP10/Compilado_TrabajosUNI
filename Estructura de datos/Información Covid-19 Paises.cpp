#include<iostream>
#include<cstring>
#include <iomanip>
using namespace std;      //Casos  - Recupera2- muertes-población- V.Totales- P.Vacunadas-P.C.vacunadas//
float datos_paises[12][7]={{33740545, 27190648, 600478, 332696143 , 273545207, 157485596, 123282685},/*EEUU*/
                           {25227970, 21590003, 278751, 1491827403, 182251006, 141764335, 40486671}, /*INDIA*/
    			           {15657891, 14097287, 436537, 213877218 , 52771668 , 35801333 , 16970335}, /*BRASIL*/
    			           {5881137 , 5152566 , 107812, 65399664  , 29313935 , 20328622 , 8985313},  /*FRANCIA*/
    			           {5127548 , 4961120 , 44983 , 85129663  , 25772743 , 14947740 , 10825003}, /*TURQUIA*/
		    	           {4949573 , 4563254 , 116211, 145989144 , 23970334 , 14313416 , 9656918},  /*RUSIA*/
			               {4452756 , 4279267 , 127684, 68197203  , 56992075 , 36704672 , 20287403}, /*UK*/
			               {4162576 , 3715389 , 124296, 60384095  , 27416033 , 19033056 , 8627856},  /*ITALIA*/
			               {3615860 , 3333587 , 79432 , 46770603  , 23970334 , 14313416 , 9656918},  /*ESPAÑA*/
			               {3608292 , 3300700 , 8687  , 84017817  , 40240529 , 30865621 , 9374908},  /*ALEMANIA*/
			               {3335965 , 2973267 , 71027 , 45557248  , 9927783  , 8023563  , 1904220},  /*ARGENTINA*/
			               {3131410 , 2931280 , 81809 , 51355369  , 7459332  , 4601785  , 2857547}}; /*COLOMBIA*/
			               
string paises[12]={"EEUU","INDIA","BRAZIL","FRANCE","TURKEY","RUSSIA","UNITED KINGDOM","ITALY","SPAIN","GERMANY","ARGENTINA","COLOMBIA"};
//1. Función para hallar casos ACTIVOS de los países//
int hallar_casos_activos(int pais){
	int activos=0;
	activos=datos_paises[pais][0]-(datos_paises[pais][1]+datos_paises[pais][2]);
	return activos;
}
//1.1 función para mostrar los casos ACTIVOS de los países//
void casos_activos(){
 	int filas=12;
	float activos=0;
	for (int i=0; i<filas; i++){
		cout<<paises[i]<<" - "<<hallar_casos_activos(i)<<endl;
	}
}
//2. Función para hallar casos RECUPERADOS de los países//
void casos_recuperado (){
	int filas=12;
	float recuperados=0;
	for (int i=0; i<filas; i++){
		recuperados=(datos_paises[i][1]*100)/datos_paises[i][3];
		cout<<paises[i]<<" - "<<setprecision(3)<<recuperados<<" %"<<endl;
	}
}
//3. Función para hallar casos MUERTES de los países//
void casos_muerte (){
	int filas=12;
	float muerte=0;
	for (int i=0; i<filas; i++){
		muerte=(datos_paises[i][2]*100)/datos_paises[i][3];
		cout<<paises[i]<<" - "<<setprecision(2)<<muerte<<" %"<<endl;
	}	
}
//4. Función para hallar casos POBLACIÓN CONTAGIADA de los países//
void rellenar_poblacion_contagiada (float poblacion_contagiada[]){
	int filas=12;
	float pobl_cont=0;
	for (int i=0; i<filas; i++){
		pobl_cont=(hallar_casos_activos(i)*100)/datos_paises[i][3];
		poblacion_contagiada[i]=pobl_cont;
	}
}
//4.1 Función para mostrar los casos de POBLACIÓN CONTAGIADA de los países//
void casos_pobl_cont (float poblacion_contagiada[]){
	int filas=12;
	float pobl_cont=0;
	rellenar_poblacion_contagiada(poblacion_contagiada);
	for (int i=0; i<filas; i++){
		cout<<paises[i]<<" - "<<setprecision(2)<<poblacion_contagiada[i]<<" %"<<endl;
	}
}
// 5. Función para hallar el país con MENOR contagio//
int hallar_pais_menor_contagio(float poblacion_contagiada[]){
	rellenar_poblacion_contagiada(poblacion_contagiada);
	float menor=poblacion_contagiada[0];
	int indice_menor=0;
	for(int i=0;i<12;i++){
		if(poblacion_contagiada[i]<menor){
			menor=poblacion_contagiada[i];
			indice_menor=i;
		}
	}
	cout<<"el pais con menor indice de contagio es: "<<paises[indice_menor]<<" con el valor de: "<<menor<<"%"<<endl; 
}
// 6. Función para hallar el país con MAYOR CONTAGIO//
int hallar_pais_mayor_contagio(float poblacion_contagiada[]){
	rellenar_poblacion_contagiada(poblacion_contagiada);
	float mayor=poblacion_contagiada[0];
	int indice_mayor=0;
	for(int i=0;i<12;i++){
		if(poblacion_contagiada[i]>mayor){
			mayor=poblacion_contagiada[i];
			indice_mayor=i;
		}
	}
	
	cout<<"el pais con mayor indice de contagio es: "<<paises[indice_mayor]<<" con el valor de: "<<mayor<<endl; 
}
// 7. Función para hallar y mostrar la LISTA DECRECIENTE de los países por porcentaje de CONTAGIO//
int hallar_paises_decrecientes(float poblacion_contagiada[]){
	rellenar_poblacion_contagiada(poblacion_contagiada);
	float poblacion_contagiada_cpy[12];
	string paises_cpy[12];
	for(int i=0;i<12;i++){
		poblacion_contagiada_cpy[i]=poblacion_contagiada[i];
		paises_cpy[i]=paises[i];
	}
	for(int i=0;i<12;i++){
		for(int j=0;j<12;j++){
			if(poblacion_contagiada_cpy[i]>=poblacion_contagiada_cpy[j]){
				float aux=poblacion_contagiada_cpy[i];
				poblacion_contagiada_cpy[i]=poblacion_contagiada_cpy[j];
				poblacion_contagiada_cpy[j]=aux;
				string pais_aux=paises_cpy[i];
				paises_cpy[i]=paises_cpy[j];
				paises_cpy[j]=pais_aux;
			}
		}
	}
	for(int i=0;i<12;i++){
		cout<<"el pais: "<<paises_cpy[i]<<" tiene una poblacion contagiada de: "<<poblacion_contagiada_cpy[i]<<endl;
	}
}	
// 8. Función para hallar el país con MENOR RIESGO de CONTAGIO//
void casos_riesgo_cont (){
	int filas=12;
	float riesgo_cont=0;
	float riesgos_cont[12];
	for (int i=0; i<filas; i++){
		riesgos_cont[i]=(datos_paises[i][6]*100)/datos_paises[i][3];
	}	
	float mayor=riesgos_cont[0];
	int indice_mayor=0;
	for(int i=0;i<12;i++){
		if(riesgos_cont[i]>mayor){
			mayor=riesgos_cont[i];
			indice_mayor=i;
		}
	}
	cout<<"el pais con mayor indice de contagio es: "<<paises[indice_mayor]<<" con el valor de: "<<mayor<<"%"<<endl; 
}
//9. Función para hallar la POBLACIÓN VACUNADA por país//
void pobl_vac (){
	int filas=12;
	float pobl_vac=0;
	for (int i=0; i<filas; i++){
		pobl_vac=(datos_paises [i][5]*100)/datos_paises[i][3];
		cout<<paises[i]<<" - "<<setprecision(3)<<pobl_vac<<" %"<<endl;
	}
}
//10. Función para hallar la POBLACIÓN TOTALMENTE VACUNADA por país//
void pobl_comp_vac (){
	int filas=12;
	float pobl_comp_vac=0;
	for (int i=0; i<filas; i++){
		pobl_comp_vac=(datos_paises [i][6]*100)/datos_paises[i][3];
		cout<<paises[i]<<" - "<<setprecision(3)<<pobl_comp_vac<<" %"<<endl;
	}
}
int main(){		    
	int info;
	float poblacion_contagiada[12];
	do{
		cout<<"----------------------------------------"<<endl;
		cout<<"Coloque el digito en el que desea saber la informacion"<<endl;
		cout<<"[1] Casos Activos"<<endl; 
		cout<<"[2] Porcentaje de casos recuperados"<<endl; 
		cout<<"[3] Porcentaje de casos de fallecidos"<<endl; 
		cout<<"[4] Porcentaje de poblacion contagiada"<<endl; 
		cout<<"[5] pais con mayor poblacion contagiada"<<endl;
		cout<<"[6] Pais con menor poblacion contagiada"<<endl;
		cout<<"[7] Listado de paises decreciente de poblacion contagiada"<<endl;
		cout<<"[8] Pais con menor riesgo de contagio"<<endl;
		cout<<"[9] Porcentaje de vacunados"<<endl;   
		cout<<"[10] Porcentaje de vacunados completamente"<<endl;  
		cout<<"[11] Salir"<<endl;  
		cin>>info;
		switch (info){
			case 1: casos_activos();
			break;   
			case 2: casos_recuperado();
			break;
			case 3: casos_muerte();
			break;
			case 4: casos_pobl_cont(poblacion_contagiada);
			break;
			case 5: hallar_pais_menor_contagio(poblacion_contagiada);
			break;
			case 6: hallar_pais_mayor_contagio(poblacion_contagiada);
			break;
			case 7: hallar_paises_decrecientes(poblacion_contagiada);
			break;
			case 8: casos_riesgo_cont ();
			break;
			case 9: pobl_vac();
			break;
			case 10: pobl_comp_vac();
			break;
		}
	}while(info!=11);
	return 0; 
}
  
