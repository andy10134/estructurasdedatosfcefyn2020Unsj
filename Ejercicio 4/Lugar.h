#ifndef LUGAR_H 
#define LUGAR_H

#include <stdlib.h>
#include <string>

using namespace std; 

class Lugar{
private:     //a partir de aquí todos los miembros serán privados
    string nombre;
    int codigo;

public:      //a patir de aquí todas las declaraciones serán de acceso público
    Lugar(string nombre, int codigo);
    string getNom(void);
    int getCod(void);
};
#endif