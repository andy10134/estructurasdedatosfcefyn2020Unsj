#ifndef ListaEnlazada_h 
#define ListaEnlazada_h
#include "Celda.h"
#include <stdlib.h>

class ListaEnlazada{
private:     //a partir de aquí todos los miembros serán privados
    int cant;
    Celda *cabeza;

public:      //a patir de aquí todas las declaraciones serán de acceso público
  ListaEnlazada(Celda* cabeza = NULL, int cant = 0); // Constructor
  int vacia(void); //
  int insertar(string elemento ,int frecuencia, Celda *derecha, Celda *izquierda); //
  int suprimir(int posicion);
  Celda* recuperar(int posicion);
  int buscar(int elemento); //
  int primerElemento(void); // primer y ultimo devuelven el item que esta dentro de la celda
  int ultimoElemento(void);
  int siguiente(int posicion); // devuelven la posicion(cont)
  int anterior(int posicion);
  void mostrar(void); //
};

#endif