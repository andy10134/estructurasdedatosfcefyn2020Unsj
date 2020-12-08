#include <iostream>

using namespace std;

class Nodo
{
private:
    int dato;
    Nodo *izq, *der;
public:
    Nodo(int xdato);
    Nodo();
    void setIzq(Nodo *xaux);
    void setDer(Nodo *xaux);
    void setDato(int xdato);
    Nodo *getIzq();
    Nodo *getDer();
    int getDato();
};

Nodo::Nodo(int xdato)
{
    dato = dato;
    izq = NULL;
    der = NULL;
}

Nodo::Nodo()
{
}

Nodo * Nodo::getIzq()
{
    return(izq);
}

Nodo * Nodo::getDer()
{
    return(der);
}

int Nodo::getDato()
{
    return(dato);
}

void Nodo::setIzq(Nodo * xaux)
{
    izq = xaux;
}

void Nodo::setDer(Nodo * xaux)
{
    der = xaux;
}

void Nodo::setDato(int xdato)
{
    dato = xdato;
}
