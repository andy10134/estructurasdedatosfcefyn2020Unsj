#include "Pila.h"
#include <iostream>

using namespace std;

//Constructor
Pila::Pila(int cant, int tope1=0, int tope2=0){
    this -> cant = cant; 
    this -> tope1 = tope1;
    this -> tope2 = tope2;
}