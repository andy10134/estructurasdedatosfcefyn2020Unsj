#ifndef designacion_h 
#define designacion_h
#include "designacion.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

class Designacion{
private:     //a partir de aquí todos los miembros serán privados
    int anio;
    string cargo;
    string instancia;
    string materia;
    int cant_varones;
    int cant_mujeres;

public:      //a patir de aquí todas las declaraciones serán de acceso público
    Designacion(int anio, string cargo, string instancia, string materia, int varones, int mujeres); // Constructor
    int getAnio(void);
    string getCargo(void);
    string getInstancia(void);
    string getMateria(void);
    int getCantVarones(void);
    int getCantMujeres(void);
    void setAnio(int);
    void setCargo(string);
    void setInstancia(string);
    void setMateria(string);
    void setCantVarones(int);
    void setCantMujeres(int);
};

#endif