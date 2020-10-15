#include "Pila.h"
#include <iostream>

#include "Celda.h"
#include "Celda.cpp"

using namespace std;

//Constructor
Pila::Pila(Celda* xtope=NULL, int xcant=0)
{
    this -> cant = xcant;
    this -> tope = xtope;
}

int Pila::vacia(void)
{
    return( this -> cant == 0);
}

int Pila::insertar(int x)
{
    Celda *ps1;
    ps1 = new(Celda);
    ps1->cargaItem(x);
    ps1->cargaSig( this -> tope);
    this -> tope = ps1;
    this -> cant++;
    return(ps1->obtenerItem());
}
    
int Pila::suprimir(void)
{
    Celda *aux;
    int x;
    if( this -> vacia())
    {
        cout<<"Pila vacia"<<"\n";
        return(0);
    }
    else
    {
        aux = tope;
        x = tope->obtenerItem();
        this -> tope = this -> tope-> obtenerSig();
        cant--;
        delete(aux);
        return(x);
    }
}

void Pila::mostrar(void)
{ 	
    Celda *aux;
    if (! this -> vacia())
    { 	aux = this -> tope;
        while(aux != NULL)
        { 	cout << aux->obtenerItem() << endl;
            aux = aux->obtenerSig();
        }
    }
}