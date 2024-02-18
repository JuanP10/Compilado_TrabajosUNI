#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int main(){
	int cantidad, ValorUni;
	float Subtotal, x, y;
	char MasProductos, IVA;
	do{
	    cout<<"Ingrese el valor unitario del producto: ";
	    cin>>ValorUni;
	    
	    cout<<"Cantidad a cobrar del producto: ";
	    cin>>cantidad;
	    
	    Subtotal=ValorUni*cantidad;
	    
	    cout<<"El producto tiene IVA? ";
	    cin>>IVA;
	    if(IVA== 'S'){
		Subtotal=Subtotal+0.19;
		cout<<"IVA incluido";
	    }
	    if(IVA=='N'){
		cout<<"PRODUCTO SIN IVA  ";
	    }
	    cout<<endl;
	    
	    
	    
	    cout<<"SUBTOTAL: ";
		cout<<Subtotal;
		cout<<endl;
		
	    cout<<"hay mas productos por comprar? ";
	    cin>>MasProductos;
	    
	}while(MasProductos == 'S');
	
	
	cout<<"TOTAL: ";
	cout<<Subtotal;
	cout<<endl;
	system("pause");
 return EXIT_SUCCESS;
	
	

	
	
	
	
	
}
