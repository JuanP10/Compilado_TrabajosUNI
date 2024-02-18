#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

typedef int Tdato;

typedef struct c{
	char marca[20];
	char linea[20];
	int cilindraje;
	int modelo;
	int precio;
	
	struct c *sig;
}Carros;

typedef struct v{
	char nombre[20];
	int edad;
	int salario;
	int doc;
	
	struct v *sig;
	Carros *lc;
}Ven;

Ven *crearNodoVen(char n[20], int e, int s, int d, Ven *sgt){
	Ven *p=(Ven*)malloc(sizeof(Ven));
	strcpy(p->nombre,n);
	p->doc=d;
	p->edad=e;
	p->salario=s;
	p->sig=sgt;
	p->lc=NULL;
	
	return p;
}
Carros *crearNodoCar(char m[20], char l[20], int mod, int p, int cc, Carros *sgt){
	Carros *q=(Carros*)malloc(sizeof(Carros));
	strcpy(q->marca, m);
	strcpy(q->linea, l);
	q->cilindraje=cc;
	q->modelo=mod;
	q->precio=p;
	q->sig=sgt;
	
	return q;
}

Ven *buscarVen(Ven *cab, int d){
	while(cab!=NULL){
		if(d == cab->doc){
			return cab;
		}else{
			cab=cab->sig;
		}
	}
}

void IngCarro(Ven *cab, int doc){
	Ven *q=buscarVen(cab, doc);
	char m[20];
	char l[20];
	int mod, p, cc;
		
	if(q!=NULL){
		cout<<"Marca: ";cin>>m;
		cout<<"Linea: ";cin>>l;
		cout<<"Modelo: ";cin>>mod;
		cout<<"Precio: ";cin>>p;
		cout<<"Cilindraje: ";cin>>cc;
		
		q->lc=crearNodoCar(m,l,mod,p,cc,q->lc);
	}else{
		cout<<"Vendedor no encontrado"<<endl;
		system("pause");
	}
}
void ImpVen(Ven *cab){
	for(Ven *i=cab; i!=NULL; i=i->sig){
		cout<<"Nombre: "<<i->nombre<<endl;
		cout<<"Edad: "<<i->edad<<endl;
		cout<<"Doc: "<<i->doc<<endl;
		cout<<"Salario: "<<i->salario<<endl;
		for(Carros *j=i->lc;j!=NULL;j=j->sig){
			cout<<"\t"<<j->marca<<endl;
			cout<<"\t"<<j->linea<<endl;
			cout<<"\t"<<j->modelo<<endl;
			cout<<"\t"<<j->cilindraje<<endl;
			cout<<"\t"<<j->precio<<endl;
		}
	}
}
void ordenar_sal(Ven *cab){
	Ven *p=cab, *j, *aux;
	
	while(p!=NULL){
		j=p->sig;
		while(j!=NULL){
			if(p->salario < j->salario){
				aux=p;
				p=j;
				j=aux;
			}
			j=j->sig;
		}
		p=p->sig;
	}
}
void calcular_sal(Ven *cab){
	int sal, adi;
	for(Ven *i=cab; i!=NULL; i=i->sig){
		cout<<"Nombre: "<<i->nombre;
		sal=i->salario;
		for(Carros *j=i->lc;j!=NULL;j=j->sig){
			adi=(float)(j->precio*0.1);
			sal+=adi;
		}
		cout<<" - Salario: "<<sal<<endl;
	}
}
int main(){
	Ven *cab=NULL;
	int op;
	char m[20], l[20];
	int aux1, aux2, aux3;
	float aux4;
	do{
		system("cls");
		cout<<"1. Ingresar Vendedor"<<endl;
		cout<<"2. Imprimir vendedor"<<endl;
		cout<<"3. Ingresar Carro a Vendedor"<<endl;
		cout<<"4. Calcular Salario"<<endl;
		cout<<"5. Ordenar por Salario"<<endl;
		cout<<"============================"<<endl;
		cout<<"Opcion: ";cin>>op;
		
		switch(op){
			case 1:{
				cout<<"Nombre: ";cin>>m;
				cout<<"Edad: ";cin>>aux1;
				cout<<"Salario: ";cin>>aux2;
				cout<<"Doc: ";cin>>aux3;
				cab = crearNodoVen(m,aux1,aux2,aux3,cab);
				break;
			}
			case 2:{
				ImpVen(cab);
				system("pause");
				break;
			}
			case 3:{
				cout<<"Ingrese Documento del vendedor: ";cin>>aux1;
				IngCarro(cab,aux1);
				break;
			}
			case 4:{
				calcular_sal(cab);
				system("pause");
				break;
			}
			case 5:{
				ordenar_sal(cab);
				break;
			}
		}
	}while(op!=0);
	system("pause");
	return 0;
}

