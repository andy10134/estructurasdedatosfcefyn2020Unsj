#include "Lista.h"
#include <iostream>

using namespace std;

//Constructor
  Lista::Lista(int cantMax) // Constructor
{
    this -> cantidadMax = cantMax;
    this -> items = new int[cantMax];
    this -> tope = -1;
}

int Lista::vacia(void)
{
    return( this -> tope == -1);
}

//Insertar
int Lista::insertar(int elemento, int posicion)
{
    int i, aux = 0;

    if ( this -> cantidadMax > this -> tope )
    {
        if ( posicion - 1 <= this -> tope )
        {
            for ( i = this -> tope; i >= posicion ; i--)
            {
                this -> items[ i + 1 ] = this -> items[ i ];
            }
            this -> items[ posicion ] = elemento;
            this -> tope ++;
            aux = elemento;
        } else
        {
            cout << "La posicion no existe en la lista" << endl;
        }
    } else
    {
        cout << "La lista esta llena" << endl;
    }
    return(aux);
}

//Suprimir
int Lista::suprimir(int posicion)
{
    int i, aux = 0;

    if( posicion - 1 <= this -> tope )
    {
        aux = this -> items[ posicion ];

        for ( i = posicion; i <= this -> tope; i++)
            {
                this -> items[ i ] = this -> items[ i + 1 ];
            }
            this -> tope --;
    }else
    {
        cout << "No existe la posicion" << endl;
    }
    return(aux);
}


void Lista::mostrar(void)
{ 	
    int i;
    for ( i = 0; i <= this -> tope ; i++)
    {
        cout << this -> items[ i ] << endl;
    }
    
}

  
// INTENTO DE CARGA  
/*    if( this -> tope < this -> cantidadMax)
    {
        if( posicion -1 == this -> tope)
        {
            cout << "xd" << endl;
            this -> items[posicion] = elemento;
            this -> tope ++;
        }
    }    
    */