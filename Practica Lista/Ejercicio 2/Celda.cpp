#include "Celda.h"
#include <iostream>

using namespace std;


int Celda::obtenerItem(void)
{
    return( this -> item );
}

void Celda::cargaItem(int xitem)
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