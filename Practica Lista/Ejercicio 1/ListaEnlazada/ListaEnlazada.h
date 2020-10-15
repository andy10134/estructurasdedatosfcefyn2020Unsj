#ifndef ListaEnlazada_h 
#define ListaEnlazada_h
#include "Celda.h"
#include <stdlib.h>

class ListaEnlazada{
private:     //a partir de aquí todos los miembros serán privados
    int cant;
    Celda *cabeza;

public:      //a patir de aquí todas las declaraciones serán de acceso público
  ListaEnlazada(Celda *cabeza = NULL, int cant = 0); // Constructor
  int vacia(void);
  int insertar(int elemento, int posicion);
  int suprimir(int posicion);
  int recuperar(int posicion);
  int buscar(int elemento);
  int primerElemento(void);
  int ultimoElemento(void);
  int siguiente(int posicion);
  int anterior(int posicion);
  void recorrer(void);
  void crear(void);
};

#endif