#include "Nodo.h"
#include <iostream>

using namespace std;


Nodo::Nodo(int xitem= 0, Nodo *izquierda= NULL, Nodo *derecha= NULL)
{
    item = xitem;
    izq = izquierda;
    der = derecha;
}

int Nodo::obtenerItem(void)
{
    return(item);
}

void Nodo::cargaItem(int xitem)
{
    item = xitem;
}

Nodo* Nodo::obtenerIzquierda(void)
{
    return(izq);
}

void Nodo::cargarIzquierda(Nodo *izquierda)
{
    izq = izquierda;
}

Nodo* Nodo::obtenerDerecha(void)
{
    return(der);
}

void Nodo::cargarDerecha(Nodo *derecha)
{
    der = derecha;
}