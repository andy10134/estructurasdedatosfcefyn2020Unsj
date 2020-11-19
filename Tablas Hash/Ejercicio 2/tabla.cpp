#include <iostream>
#include "Lista.cpp"

using namespace std;


class tablaHash
{
private:
    Lista *items;
    int max;
public:
    tablaHash(int cantidad);
    int buscar(int elemento);
    int hash(int elemento);
    void insertar(int elemento);
};

int tablaHash::hash(int elemento)
{
    elemento = (elemento/10)+(elemento%10);
    if(elemento > 337){
        elemento = elemento%337;
    }
    return(elemento);
}

tablaHash::tablaHash(int cantidad)
{
    max = cantidad;
    items = new Lista[max];
    int i;
    for (i = 0; i < max; i++)
    {
        items[i].cerear();
    }
}
