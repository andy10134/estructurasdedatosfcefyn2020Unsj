#include "ListaCursor.h"
#include "Celda.cpp"
#include <iostream>

using namespace std;

//Constructor
ListaCursor::ListaCursor(int cant)
{
    this -> items[cant]; //aca deberia ser cabeza(guarda el primer elemento), cantidad de elementos y el arreglo con las celdas
    this -> cabeza = 0;
    this -> cant = 0;
    this -> maximaCant = cant;
}

int ListaCursor::vacia(void)
{
    return( this -> cant == 0);
}

int ListaCursor::insertar(int elemento, int posicion)
{
    if (posicion > 0 && posicion <= this -> cant +1 && this -> cant +1 <= this -> maximaCant)
    {
        Celda* nuevo;
        Celda aux;
        nuevo = new(Celda);
        int cont=1;
        int i;
        nuevo->cargaItem(elemento);
        nuevo->cargaSig(NULL);
        
        aux = this -> items[ this -> cabeza ];
        while( aux.obtenerSig() != -1 && cont <= posicion )
        {
            aux = this -> items[ aux.obtenerSig() ];
            cont ++;
        }
        i = aux.obtenerSig();
        nuevo -> cargaSig(i);
        
        i = 0;
        
        while ( i < this -> maximaCant && this -> items[i].obtenerSig() != -2 )
        {
            i++;
        }

        this -> items[i] = nuevo;
        
    }
    else
    {
        cout<<"POSICION INVALIDA"<<endl;
    }
    return(0);
}


/*
Celda* ListaEnlazada::primerElemento(void)
{
    return(this -> cabeza);
}

void ListaEnlazada::mostrar(void)
{
    Celda *aux;
    aux = this -> cabeza;
    while (aux!=NULL)
    { 
        cout<<aux->obtenerItem()<<endl;
        aux = aux->obtenerSig();
    }
}


int ListaEnlazada::buscar(int elemento){
    Celda *aux;
    aux = this -> cabeza;
    while (aux!=NULL && aux->obtenerItem() != elemento)
    { 
        aux = aux->obtenerSig();
    }
}*/