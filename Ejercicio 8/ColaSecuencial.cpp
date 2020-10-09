#include "ColaSecuencial.h"
#include <iostream>

using namespace std;

//Constructor
ColaSecuencial::ColaSecuencial(int max=0){
    this -> max = max; 
    this -> pr = 0;
    this -> ul = 0;
    this -> cant = 0;
    this -> items= new int[max];
    this -> medico = 0;
    this -> tiempo = 0;
    this -> cola = 0;
}

int ColaSecuencial::vacia(void)
{
    return ( this -> cant == 0 );
}

int ColaSecuencial::insertar(int x)
{
    if ( this -> cant < this -> max)
    {
        this -> items[ this -> ul ]=x;
        this -> ul = ( this -> ul+1)% this -> max;
        this -> cant++;
        this -> cola++;
        return (x);
    }
    else
    {
        cout<<"Cola llena"<<endl;
        return(0);
    }
}

int ColaSecuencial::suprimir(void)
{
    int x;
    if (vacia())
    {
        cout<<"Cola vacia"<<endl;
        return(0);
    }
    else
    {
        x = this -> items[ this -> pr];
        this -> pr = ( this -> pr + 1)% this -> max;
        this -> cant --;
        return(x);
    }
}

void ColaSecuencial::recorrer(void)
{
    int i,j;
    if(!vacia())
    {
        i = this -> pr;
        j = 0;
        for(i; j< this -> cant; i=(i+1)% this -> max, j++)
        {
            cout<< this -> items[i] <<endl;
        }
    }
}

int ColaSecuencial::getMedico(void)
{
    return( this -> medico );
}

void ColaSecuencial::setMedico(void)
{
    this -> medico = 20;
}

void ColaSecuencial::decrementarMedico(void)
{
    this -> medico --;
}

int ColaSecuencial::getTiempo(void)
{
    return( this -> tiempo );
}


void ColaSecuencial::setTiempo(int x)
{
    this -> tiempo += x;
}

void ColaSecuencial::obtenerPromedio(int i)
{
    int prom = getTiempo() / this -> cola;
    cout<<"Tiempo Promedio de espera de especialidad "<< i+1<<": "<<prom<<endl;
}