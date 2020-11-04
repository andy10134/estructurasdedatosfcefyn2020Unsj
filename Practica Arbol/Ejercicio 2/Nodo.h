#ifndef Nodo_h 
#define Nodo_h
#include <iostream>
#include <stdlib.h>
using namespace std;

class Nodo{
private:     //a partir de aquí todos los miembros serán privados
    int item;
    Nodo *izq, *der;

public:      //a patir de aquí todas las declaraciones serán de acceso público
    Nodo(int xitem, Nodo *izquierda, Nodo *derecha);
    int obtenerItem(void);
    void cargaItem(int xitem);
    Nodo *obtenerIzquierda(void);
    void cargarIzquierda(Nodo *izquierda);
    Nodo *obtenerDerecha(void);
    void cargarDerecha(Nodo *derecha);
};
#endif