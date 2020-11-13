#include <iostream>
#include "colaPrioridad.cpp"


int main(int argc, char const *argv[])
{
    colaPrioridad cola = colaPrioridad(10);
    cola.insertar(10);
    cola.insertar(20);
    cola.insertar(30);
    cola.insertar(40);
    cola.insertar(50);
    cola.insertar(60);
    cola.insertar(15);
    cola.mostrar();
}
