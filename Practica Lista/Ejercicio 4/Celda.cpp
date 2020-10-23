#include "Celda.h"
#include "designacion.h"
#include <iostream>

using namespace std;


Designacion Celda::obtenerItem(void)
{
    return( this -> item );
}

void Celda::cargaItem(Designacion xitem)
{
    this -> item = xitem;
}

void Celda::cargaSig(Celda *xtope)
{
    this -> sig = xtope;
}

Celda* Celda::obtenerSig(void)
{
    return( this -> sig );
}