#include <iostream>
#include "ListaCursor.h"
#include "ListaCursor.cpp"


using namespace std;

main(){
    int posicion, elemento;
    ListaCursor lista(3);
    lista.insertar(2,1);
    lista.insertar(3,1);
    lista.insertar(5,3);
    lista.mostrar();
    cout<<lista.buscar(5)<<endl;
    cout<<lista.recuperar(3)<<endl;
    cout<<lista.siguiente(1)<<endl;
    cout<<lista.anterior(1)<<endl;
}
