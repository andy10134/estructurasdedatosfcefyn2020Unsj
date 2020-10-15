#include "Lista.h"
#include <iostream>

using namespace std;

//Constructor
  Lista::Lista(int cantMax) // Constructor
{
    this -> cantidad = 0;
    this -> cantidadMaxima = cantMax;
    this -> items = new int[cantMax];
}

int Lista::vacia(void)
{
    return( this -> cantidad == 0);
}

int Lista::insertar(int x)
{
    Celda *ps1;
    ps1 = new(Celda);
    ps1->cargaItem(x);
    ps1->cargaSig( this -> tope);
    this -> tope = ps1;
    this -> cant++;
    return(ps1->obtenerItem());
}
    
int Lista::suprimir(void)
{
    Celda *aux;
    int x;
    if( this -> vacia())
    {
        cout<<"Lista vacia"<<"\n";
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

void Lista::mostrar(void)
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