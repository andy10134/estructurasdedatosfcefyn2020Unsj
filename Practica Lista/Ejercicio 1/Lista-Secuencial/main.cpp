#include <iostream>
#include "Lista.h"
#include "Lista.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Lista lista(3);

    lista.insertar(1, 1);
    lista.insertar(3, 2);
    lista.insertar(5, 3);
    lista.recorrer();
}
