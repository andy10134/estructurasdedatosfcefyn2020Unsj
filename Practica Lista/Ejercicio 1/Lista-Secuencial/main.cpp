#include <iostream>
#include "Lista.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Lista lista(6);

    lista.insertar(10, 1);
    lista.insertar(5, 2);
    lista.insertar(7, 3);
    lista.insertar(5, 4);
    lista.insertar(2, 5);
    lista.insertar(10, 6);
    lista.recorrer();
}
