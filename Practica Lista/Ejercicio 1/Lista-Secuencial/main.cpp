#include <iostream>
#include "Lista.h"
#include "Lista.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Lista lista(5);

    lista.insertar(1, 0);
    lista.insertar(3, 1);
    lista.insertar(5, 2);
    lista.mostrar();
    cout << "hola" << endl;
    lista.suprimir(0);
    lista.mostrar();
}
