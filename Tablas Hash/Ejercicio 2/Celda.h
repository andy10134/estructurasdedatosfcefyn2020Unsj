#ifndef Celda_h 
#define Celda_h
#include <stdlib.h>

class Celda{
private:     //a partir de aquí todos los miembros serán privados
    int item;
    Celda *sig;

public:      //a patir de aquí todas las declaraciones serán de acceso público
  int obtenerItem(void);
  void cargaItem(int xitem);
  void cargaSig(Celda* xtope);
  Celda* obtenerSig(void);
};
#endif