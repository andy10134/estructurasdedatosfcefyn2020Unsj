#include "Nodo.h"
#include <iostream>

using namespace std;

class Nodo{
private:     //a partir de aquí todos los miembros serán privados
    int item;
    Nodo *izq, *der;

public:      //a patir de aquí todas las declaraciones serán de acceso público
    Nodo();
    int obtenerItem(void);
    void cargaItem(int xitem);
    void obtenerIzquierda(Nodo **&x);
    void cargarIzquierda(Nodo *izquierda);
    void obtenerDerecha(Nodo **&x);
    void cargarDerecha(Nodo *derecha);
};

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
