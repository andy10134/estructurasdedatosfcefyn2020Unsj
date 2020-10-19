#include "Celda.h"
#include <iostream>

using namespace std;

Celda::Celda(int item=0, int sig=-2)
{
    this -> item = item;
    this -> sig = sig;
}

int Celda::obtenerItem(void)
{
    return( this -> item );
}

void Celda::cargaItem(int xitem)
{
    this -> item = xitem;
}

void Celda::cargaSig(int xtope)
{
    this -> sig = xtope;
}

int Celda::obtenerSig(void)
{
    return( this -> sig );
}