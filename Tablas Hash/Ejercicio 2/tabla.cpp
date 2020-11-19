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
    void insertar(int elemento);
};

tablaHash::tablaHash(int cantidad)
{
    max = cantidad;
    items = new ListaEnlazada[max];
}
