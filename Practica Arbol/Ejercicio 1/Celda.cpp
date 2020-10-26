#include "Celda.h"
#include <iostream>

using namespace std;


int Celda::obtenerItem(void)
{
    return( this -> frec );
}

void Celda::cargaItem(string etiqueta, int frecuencia, Celda *izq = NULL, Celda *der = NULL)
{
    this -> etiqueta = etiqueta;
    this -> frec = frecuencia;
    this -> izq = izq;
    this -> der = der;
}

void Celda::cargaSig(Celda *xtope = NULL)
{
    this -> sig = xtope;
}

Celda* Celda::obtenerSig(void)
{
    return( this -> sig );
}

//Metodos del nodo
Celda* Celda::obtenerIzquierda(void)
{
    return( this -> izq );
}

void Celda::cargarIzquierda(Celda *izq)
{
    this -> izq = izq;
}

Celda* Celda::obtenerDerecha(void)
{
    return( this -> izq );
}

void Celda::cargarDerecha(Celda *der)
{
    this -> der = der;
}

void Celda::cargarEtiqueta(string etiqueta)
{
    this -> etiqueta = etiqueta;
}


string Celda::obtenerEtiqueta(void)
{
    return( this -> etiqueta );
}