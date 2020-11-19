#include <iostream>
#include "ListaEnlazada.cpp"

using namespace std;


class tablaHash
{
private:
    ListaEnlazada *items;
    int max;
public:
    tablaHash(int cantidad);
    int buscar(int elemento);
    int hash(int elemento);
    void insertar(int elemento);
};

tablaHash::tablaHash(int cantidad)
{
    max = cantidad;
    items = new ListaEnlazada[max];
}

int tablaHash::hash(int elemento)
{
    elemento = (elemento/1000)+(elemento%1000);
    if(elemento > 337){
        elemento = elemento%337;
    }
    return(elemento);
}

void tablaHash::insertar(int elemento)
{
    int clave = hash(elemento);
    items[clave].insertar(elemento, 1);
}

int tablaHash::buscar(int elemento)
{
    int clave = hash(elemento);
    items[clave].buscar(elemento);
}