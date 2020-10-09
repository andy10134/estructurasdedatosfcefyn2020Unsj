#include "Lugar.h"
#include <stdlib.h>
#include <string>

using namespace std;

Lugar::Lugar(string nombre, int codigo)
{
    this -> codigo = codigo;
    this -> nombre = nombre;
}

int Lugar::getCod(void)
{
    return( this -> codigo );
}

string Lugar::getNom(void)
{
    return( this -> nombre );
}