#ifndef ListaCursor_h 
#define ListaCursor_h
#include "Celda.h"
#include <stdlib.h>

class ListaCursor{
private:     //a partir de aquí todos los miembros serán privados
    int cant;
    int cabeza;
    int maximaCant;
    Celda *items;

public:      //a patir de aquí todas las declaraciones serán de acceso público
    ListaCursor(int cant); // Constructor
    int vacia(void); //
    int insertar(int elemento, int posicion);
    int suprimir(int posicion);
    int recuperar(int posicion);
    int buscar(int elemento); //
    Celda* primerElemento(void); //
    Celda* ultimoElemento(void);
    int siguiente(int posicion);
    int anterior(int posicion);
    void mostrar(void); //
};

#endif