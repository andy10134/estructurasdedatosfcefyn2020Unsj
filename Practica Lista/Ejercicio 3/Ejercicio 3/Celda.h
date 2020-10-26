#ifndef Celda_h 
#define Celda_h
#include <stdlib.h>
#include <string>

class Celda{
private:     
    float item;
    Celda *sig;
	std::string nom;

public:   
  float obtenerItem(void);
  std::string obtenerNombre(void);
  void cargaItem(float xitem,std::string d);
  void cargaSig(Celda* xtope);
  Celda* obtenerSig(void);
};
#endif
