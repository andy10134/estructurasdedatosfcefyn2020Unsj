#ifndef Lista_h 
#define Lista_h
#include "Celda.h"
#include <stdlib.h>
#include <string>

class Lista{
private:     
    int cant;
    Celda *cabeza;

public:      
  Lista(); 
  int vacia(void);
  int insertar(float x, std::string d);
  int suprimir(int p);
  int recuperar(int p);
  int buscar(float x);
  int primerElemento(void);
  int ultimoElemento(void);
  int siguiente(int p);
  int anterior(int p);
  void mostrar(void); 
};

#endif
