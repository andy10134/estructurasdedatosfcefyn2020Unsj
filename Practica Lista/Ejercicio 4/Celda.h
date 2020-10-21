#ifndef Celda_h 
#define Celda_h
#include <stdlib.h>
#include "designacion.h"

class Celda{
private:     //a partir de aquí todos los miembros serán privados
    Designacion item;
    Celda *sig;

public:      //a patir de aquí todas las declaraciones serán de acceso público
  Designacion obtenerItem(void);
  void cargaItem(Designacion xitem);
  void cargaSig(Celda* xtope);
  Celda* obtenerSig(void);
};
#endif