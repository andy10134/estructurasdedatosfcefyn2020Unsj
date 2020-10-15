#include "Pila.h"
#include <iostream>

using namespace std;

//Constructor
Pila::Pila(int cant){
    this -> cant = cant; 
    this -> tope1 = -1;
    this -> tope2 = cant*2;
    this -> items= new int[cant*2];
}

//---------------METODOS PILA 1---------------
int Pila::insertar1(int elemento){
    if ( this -> tope1 < this -> cant-1)
	{	this ->items[++ this -> tope1] = elemento;
		return (elemento);
	}
	else
	{
		cout<<"Pila 1 llena, elimine elementos para poder agregar otros"<<endl;
		return (0);
	}
	
}

int Pila::suprimir1(void){
    int x;
	if (vacia1())
	{	cout<<"Pila vacia"<<endl;
		return(0);
	}
	else
	{ 	x = this -> items[ this -> tope1--];
		return(x);
	}
}

void Pila::mostrar1(void){
    int i;
	if (!vacia1())
	{ 	for (i= this -> tope1; i>=0; i--)
		{ 	cout<< this -> items[i]<<endl;
		}
		cout<<"cant = "<< this ->cant <<endl;
		cout<<"tope1 = "<< this ->tope1 <<endl;
	}
	else
	{
		cout<<"Pila 1 vacia"<<endl;
	}
}

int Pila::vacia1(void){
    return ( this -> tope1 == -1);
}

//---------------METODOS PILA 2---------------
int Pila::insertar2(int elemento){
	if ( this ->tope2 > this -> cant)
	{
		this ->items[-- this -> tope2] = elemento;
		return (elemento);
	}
	else
	{
		cout<<"Pila 2 llena, elimine elementos para poder agregar otros"<<endl;
		return (0);
	}
	
}

int Pila::suprimir2(void){
	int x;
	if (vacia2())
	{
		cout<<"Pila vacia"<<endl;
		return(0);
	}
	else
	{
		x = this ->items[ this -> tope2++];
		return(x);
	}
	
}

void Pila::mostrar2(void){
	int i;
	if (!vacia2())
	{
		for (i = this ->tope2; i < this -> cant*2; i++)
		{
			cout<< this -> items[i]<<endl;
		}
		cout<<"tope2 = "<< this ->tope2 <<endl;
	}
	else
	{
		cout<<"Pila 2 vacia"<<endl;
	}
}

int Pila::vacia2(void){
    return ( this -> tope2 == this ->cant*2);
}