#include <iostream>
#include "Pila.h"
#include "Pila.cpp"

using namespace std;

int menu(void)
{
	int op;
	cout<<"----------------------------------------------"<<endl;
	cout<<"1. Insertar elemento en la pila"<<endl;
	cout<<"2. Eliminar elemento de la pila"<<endl;
	cout<<"3. Mostrar pila"<<endl;
	cin>>op;
	cout<<"----------------------------------------------"<<endl;
	return(op);
}


int main(int argc, char const *argv[]){
    Pila pila(5);
	int i;
	int bandera = 1;
	while (bandera)
	{
		cout<<"Ingrese numero de pila que desea utilizar: "<<endl;
		cin>>i;
		if(i == 1)
		{
			int op= menu();
			switch(op)
			{
    			case 1:
					int elemento;
					cout<<"Ingrese numero: "<<endl;
					cin>>elemento;
					pila.insertar1(elemento);
    			break;
   				case 2:
				   pila.suprimir1();
    			break;
    			case 3:
					pila.mostrar1(); 
    			break;
   				default: cout<<"Ingrese una opcion valida >:("<<endl; 
			}
		}
		else if (i == 2)
		{
			int op= menu();
			switch(op)
			{
    			case 1:
					int elemento;
					cout<<"Ingrese numero: "<<endl;
					cin>>elemento;
					pila.insertar2(elemento);
    			break;
   				case 2:
				   pila.suprimir2();
    			break;
    			case 3:
					pila.mostrar2(); 
    			break;
   				default: cout<<"Ingrese una opcion valida >:("<<endl; 
			}
		}
		else
		{
			cout<<"Valor incorrecto, por favor ingrese 1 o 2!!!"<<endl;
		}
		cout<<"Para finalizar ingrese 0"<<endl;
		cin>>bandera;
	}
}
