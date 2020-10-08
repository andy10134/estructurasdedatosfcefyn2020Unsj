#ifndef ColaEnlazada_h 
#define ColaEnlazada_h
#include "Celda.h"
#include <stdlib.h>

class ColaEnlazada{
private:     //a partir de aquí todos los miembros serán privados
    Celda *pr;
    Celda *ul;
    int cant;

public:      //a patir de aquí todas las declaraciones serán de acceso público
  ColaEnlazada(Celda *pr, Celda *ul, int cant); // Constructor
  int vacia(void);
  int insertar(int elemento);
  int suprimir(void);
  Celda* recuperaPr(void);
  void recorrer(Celda *aux);
};
#endif