#include <iostream>
using namespace std; 

int viaj=0;
void llenarTanque (int M, int x){
	int p=0;
	if(x>M){
		cout<<"Num de viajes es: "<<viaj;
	}
	else{
		cout<<" Digite P"; cin>>p;
		x=x+p;
		viaj++;
		llenarTanque(M,x);
	}
}

int fibonaci (int n){
	if (n==1 || n==2)
	    return 1;	
	else
	   return fibonaci(n-1)+fibonaci(n-2);
}

int factorial (int n){
	if(n==1)
	   return 1;
	else
	    return n*factorial(n-1);
}

/*void numerosPares (int n){
	if(n==0)
	return 0;
	else 
	return numerosPares(n-1)+2;
}
*/

int serie (int n){
	if(n==1)
	   return 1;
	else
	   return serie(n-1)*2+1; 
}


int potencia(float base, int exp) {
if (exp == 0){
   return 1;		
}
else
 return base * potencia(base,exp - 1);
} 

void leerVector(int v[], int i, int n){
	if(i<n){
		cout<<" Digita dato"; cin>>v[i];
		leerVector(v,i+1,n);
	}
}

void escribaVector(int v[], int i, int n){
	if(i<n){
		cout<<" "<<v[i];
		escribaVector(v,i+1,n);
	}
}
//hayar mayor en un vector
int may=0;
int mayor(int v[], int i, int n){
	if(i<n){
		if(v[i]>may){
			may=v[i];
		}
		mayor(v,i+1,n);
	}
	return may;
}

//Imprimir vector inversamente
void imprimirInvVector(int v[100], int i, int n){
	if(i<n){
		cout<<" "<<v[i];
		imprimirInvVector(v,i+1,n);
	}
}

//% de numeros pares
int porNumPares(int v[], int i, int n){
	if(i<n){
		if(v[i]%2==0){
			return 1+porNumPares(v,i+1,n);
		}
		else{
			return porNumPares(v,i+1,n);
		}
	}
	return 0;
}
float porNPares(int v[], int i, int n){
	int cont=porNumPares(v,0,n);
	return (float)cont/n*100;
}

//cantidad de veces que se repite un número
int contarX(int v[], int i, int n, int x){
	if(i<n){
		int cont=0;
		if(v[i]==x){
			cont=1;
		}
		return cont+contarX(v, i+1, n,x);
	}
	return 0;
}


//ejercicios
//dado un vector y un dato x decir si esta o no
//promedio de números
//imprmir la mitad de un vector
//Dato un vectoru A, decir si los elementos estan en otro vector B

void leerMatriz(int m[][100], int i,int j, int n){
	if(i<n){
		cout<<" Digite dato ";cin>>m[i][j];
		if(j<=n-1){
			leerMatriz(m,i,j+1,n);
		}
		else{
			leerMatriz(m, i+1,0,n);
		}
	}
}

void escribirMatriz(int m[][100], int i,int j, int n){
	if(i<n){
		cout<<"  "<<m[i][j];
		if(j<=n-1){
			escribirMatriz(m,i,j+1,n);
		}
		else{
			cout<<endl;
			escribirMatriz(m, i+1,0,n);
		}
	}
}

//promedio de numeros de la matriz
float sum=0;
float promedio(int m[][100], int i, int j, int n){
	if(i<n){
		sum=sum+m[i][j];
		if(j<n-1){
			promedio(m,i,j+1,n);
		}
		else{
			promedio(m,i+1,0,n);
		}	
	}
	return sum/(n*n);
}

void escribirVectorInv(int v[], int i, int n){
	if(i>=0){
		cout<<" "<<v[i];
		escribaVector(v,i-1,n);
	}
}
//hallar el mayor matriz


// imprimir inversamente la diagonal
// imprimir diagonal superior
// sumar lo de arriba de la diagonal superior

int main(){
	//int n=3;
	//int res=factorial(n);
	//cout<<"El factorial de "<< n<< " Es igual a: " <<res;
	int n;
	cout<<"Digite n"; cin>>n;
	int m[100][100];
	leerMatriz(m,0,0,n);
	escribirMatriz(m,0,0,n);
	float pr=promedio(m,0,0,n);
	cout<< " el promedio es: "<<pr;
	//llenarTanque(M,0);
	/*int v[100];
	leerVector(v,0,n);
	escribaVector(v,0,n);
	int may=mayor(v,0,n);
	cout<<" El mayor es "<<may;*/
	cout<<endl;
	imprimirInvVector(v,0,n);
	cout<<"Porcentaje num pares: "<<porNPares(v,0,n)<<"%";
	cout<<endl;
	cout<<"Contar "<<contarX(v,0,n,3);
	cout<<endl;
	
	return 1;
}
