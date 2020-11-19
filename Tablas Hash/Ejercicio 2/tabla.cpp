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

int tablaHash::hash(int elemento)
{
    elemento = (elemento/1000)+(elemento%1000);
    if(elemento > 337){
        elemento = elemento%337;
    }
    return(elemento);
}

tablaHash::tablaHash(int cantidad)
{
    max = cantidad;
    items = new ListaEnlazada[max];
}
