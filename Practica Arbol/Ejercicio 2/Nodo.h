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
    Nodo();
    int obtenerItem(void);
    void cargaItem(int xitem);
    void obtenerIzquierda(Nodo **&x);
    void cargarIzquierda(Nodo *izquierda);
    void obtenerDerecha(Nodo **&x);
    void cargarDerecha(Nodo *derecha);
};
#endif