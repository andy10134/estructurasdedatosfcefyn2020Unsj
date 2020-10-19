#include <iostream>
#include "ListaCursor.h"
#include "ListaCursor.cpp"


using namespace std;

main(){
    int posicion, elemento;
    ListaCursor lista(3);
    lista.insertar(2,1);
    lista.insertar(3,2);
    lista.insertar(5,3);
    lista.mostrar();
}
