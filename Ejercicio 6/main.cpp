#include <iostream>
#include "ColaSecuencial.cpp"
#include "ColaEnlazada.cpp"

using namespace std;

main(){
    ColaSecuencial secuencial = ColaSecuencial(5);
    secuencial.insertar(1);
    secuencial.insertar(2);
    secuencial.recorrer();
    secuencial.suprimir();
    secuencial.recorrer();
    cout<<"----------------------------------------------"<<endl;
    ColaEnlazada enlazada = ColaEnlazada(0, 0, 5);
    enlazada.insertar(1);
    enlazada.insertar(2);
    enlazada.insertar(3);
    enlazada.recorrer();
    enlazada.suprimir();
    enlazada.recorrer();
}
