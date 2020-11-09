#include "Nodo.h"
#include <iostream>

using namespace std;

Nodo::Nodo()
{
    izq = NULL;
    der = NULL;
}

int Nodo::obtenerItem(void)
{
    return(item);
}

void Nodo::cargaItem(int xitem)
{
    item = xitem;
}

void Nodo::obtenerIzquierda(Nodo **&x)
{
        x = &izq;
}

void Nodo::cargarIzquierda(Nodo *izquierda)
{
    izq = izquierda;
}

void Nodo::obtenerDerecha(Nodo **&x)
{
        x = &der;
}

void Nodo::cargarDerecha(Nodo *derecha)
{
    der = derecha;
}
