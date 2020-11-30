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
        return (x);
    }
    else
    {
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