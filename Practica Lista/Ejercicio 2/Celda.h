#ifndef Celda_h 
#define Celda_h
#include <stdlib.h>

class Celda{
private:     //a partir de aquí todos los miembros serán privados
    int item;
    int sig;

public:      //a patir de aquí todas las declaraciones serán de acceso público
    int obtenerItem(void);
    void cargaItem(int xitem);
    void cargaSig(int xtope);
    int obtenerSig(void);
};
#endif