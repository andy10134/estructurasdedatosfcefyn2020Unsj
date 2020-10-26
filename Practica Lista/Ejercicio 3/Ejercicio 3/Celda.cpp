#include "Celda.h"
#include <iostream>
#include <string>

using namespace std;


float Celda::obtenerItem(void)
{
    return( this -> item );
}

void Celda::cargaItem(float xitem, string d)
{
    this -> item = xitem;
    this -> nom = d;
}

void Celda::cargaSig(Celda *xtope)
{
    this -> sig = xtope;
}

Celda* Celda::obtenerSig(void)
{
    return( this -> sig );
}

string Celda::obtenerNombre(void)
{
	return(this->nom);
}
