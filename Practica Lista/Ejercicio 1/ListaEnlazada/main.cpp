#include <iostream>
#include "ListaEnlazada.cpp"

using namespace std;

main(){
    int posicion, elemento;
    ListaEnlazada lista = ListaEnlazada(NULL, 0);
    lista.insertar(2,1);
    lista.insertar(3, 2);
    lista.insertar(1, 1);
    lista.mostrar();
    posicion = lista.buscar(3);
    elemento = lista.suprimir(3);
    cout<<elemento<<endl;
    lista.mostrar();
}
