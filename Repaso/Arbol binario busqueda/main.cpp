#include "arbol.cpp"

int main(int argc, char const *argv[])
{
    ArbolBinarioB arbol(35);
    Nodo **aux = arbol.getRaiz();
    arbol.insertar(2, aux);
    arbol.insertar(36, aux);
    arbol.insertar(5, aux);
    //arbol.insertar(4, aux);
    //arbol.insertar(8, aux);
    arbol.insertar(1, aux);
    //arbol.buscar(2,aux);
    //arbol.nivel(2,0,aux);
    arbol.hoja(2);
    //arbol.suprimir(5);
    //arbol.InOrden(aux);
    // Muestra todos los nodos arbol.PreOrden(aux);
    arbol.PostOrden(aux);
    arbol.altura(aux,0);
    arbol.mostrar();
    return 0;
}
