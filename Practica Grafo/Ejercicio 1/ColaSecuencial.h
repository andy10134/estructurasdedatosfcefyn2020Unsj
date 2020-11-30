#ifndef ColaSecuencial_h 
#define ColaSecuencial_h
#include <stdlib.h>

class ColaSecuencial{
private:     //a partir de aquí todos los miembros serán privados
    int *items;
    int max;
    int pr;
    int ul;
    int cant;

public:      //a patir de aquí todas las declaraciones serán de acceso público
  ColaSecuencial(int cant); // Constructor
  int vacia(void);
  int insertar(int elemento);
  int suprimir(void);
  void recorrer(void);
};
#endif