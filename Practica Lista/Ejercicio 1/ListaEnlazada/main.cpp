#include <iostream>
#include "ListaEnlazada.cpp"

using namespace std;

main(){
    int posicion;
    ListaEnlazada lista = ListaEnlazada(NULL, 0);
    cout<<"EN QUE POSICION QUIERE INSERTAR EL ELEMENTO"<<endl;
    cin>>posicion;
    lista.insertar(3,posicion);
    lista.insertar(3, 2);
    lista.mostrar();
}
