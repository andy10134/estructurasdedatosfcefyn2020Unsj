#include "ListaCursor.h"
#include "Celda.cpp"
#include <iostream>

using namespace std;

//Constructor
ListaCursor::ListaCursor(int cant)
{
    this -> items[cant];
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
    if(  )
    {

    }
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