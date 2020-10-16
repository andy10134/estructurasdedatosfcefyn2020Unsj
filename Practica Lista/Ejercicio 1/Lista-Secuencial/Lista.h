#ifndef LISTA_H 
#define LISTA_H
#include <stdlib.h>

class Lista{
private:     //a partir de aquí todos los miembros serán privados
    int cantidadMax;
    int tope;
    int *items;

public:      //a patir de aquí todas las declaraciones serán de acceso público
  Lista(int cantMax); // Constructor
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
  void mostrar(void);
};
#endif