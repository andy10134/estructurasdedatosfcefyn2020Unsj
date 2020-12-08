#include "arbol.cpp"

int main(int argc, char const *argv[])
{
    ArbolBinarioB arbol(35);
    Nodo **aux = arbol.getRaiz();
    arbol.insertar(2, aux);
    //arbol.suprimir(2, aux);
    //arbol.buscar(2,aux);
    //arbol.nivel(2,0,aux);
    arbol.hoja(2);
    arbol.mostrar();
    return 0;
}
