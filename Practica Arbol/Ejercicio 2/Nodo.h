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
    Nodo(int xitem= 0, Nodo *izquierda= NULL, Nodo *derecha= NULL);
    int obtenerItem(void);
    void cargaItem(int xitem);
    Nodo *obtenerIzquierda(void);
    void cargarIzquierda(Nodo *izquierda);
    Nodo *obtenerDerecha(void);
    void cargarDerecha(Nodo *derecha);
};
#endif