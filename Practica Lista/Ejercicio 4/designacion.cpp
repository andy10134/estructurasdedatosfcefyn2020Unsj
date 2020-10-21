#include "designacion.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

Designacion::Designacion(int anio, string cargo, string instancia, string materia, int varones, int mujeres)
{
    this -> anio = anio;
    this -> cargo = cargo;
    this -> instancia = instancia;
    this -> materia = materia;
    this -> cant_varones = varones;
    this -> cant_mujeres = mujeres;
}

int Designacion::getAnio(void)
{
    return(this-> anio);
}

string Designacion::getCargo(void)
{
    return(this-> cargo);
}

string Designacion::getInstancia(void)
{
    return(this-> instancia);
}

string Designacion::getMateria(void)
{
    return(this-> materia);
}

int Designacion::getCantVarones(void)
{
    return(this-> cant_varones);
}

int Designacion::getCantMujeres(void)
{
    return(this-> cant_mujeres);
}

void Designacion::setAnio(int anio)
{
    this-> anio = anio;
}

void Designacion::setCargo(string cargo)
{
    this-> cargo = cargo;
}

void Designacion::setInstancia(string instancia)
{
    this-> instancia = instancia;
}

void Designacion::setMateria(string materia)
{
    this-> materia = materia;
}

void Designacion::setCantVarones(int varones)
{
    this-> cant_varones = varones;
}

void Designacion::setCantMujeres(int mujeres)
{
    this-> cant_varones = mujeres;
}
