#include <iostream>
#include "ArbolBinario.cpp"


int main(int argc, char const *argv[])
{
    ArbolBinarioB arbol = ArbolBinarioB();
    arbol.insertar(5, arbol.getRaiz(), True);
    arbol.insertar(10, arbol.getRaiz());
    arbol.InOrden(arbol.getRaiz());
}
