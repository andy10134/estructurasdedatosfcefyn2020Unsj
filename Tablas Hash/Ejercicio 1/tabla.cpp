#include <iostream>

using namespace std;


class tablaHash
{
private:
    int *items;
    int max;
public:
    tablaHash(int cantidad);
    void buscar(int elemento);
    void insertar(int elemento);
};

tablaHash::tablaHash(int cantidad)
{
    max = cantidad;
    items = new int[max];
    int i;
    for (i = 0; i < max; i++)
    {
        items[i] = -1;
    }
}
