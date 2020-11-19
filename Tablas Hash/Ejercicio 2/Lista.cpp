#include "Lista.h"
#include <iostream>

using namespace std;

//Constructor
  Lista::Lista(int cantMax = 3) // Constructor
{
    this -> cantidadMax = cantMax;
    this -> items = new int[cantMax];
    this -> tope = -1;
}

//Vacia
int Lista::vacia(void)
{
    return( this -> tope == -1);
}

//Insertar
int Lista::insertar(int elemento, int posicion)
{
    int i, aux = 0;
    posicion -= 1;

    if ( this -> cantidadMax - 1 > this -> tope && posicion >= 0 )
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

    if( posicion > 0 && posicion - 1 <= this -> tope )
    {
        posicion -= 1;
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

//recuperar
int Lista::recuperar(int posicion)
{
    int aux;
    posicion -= 1;
    if( posicion >= 0 && this -> tope >= posicion )
    {
        aux = this -> items[ posicion ];
    }

    return(aux);
}

//buscar
int Lista::buscar(int elemento)
{
    int i = 0, bandera = 0;

    while ( i <= this -> tope && !bandera )
    {
        if( elemento == this -> items[ i ] )
        {
            bandera = 1;
        }else{
            i++;
        }
    }

    if( i <= this -> tope )
    {
        return(i+1);
    }else
    {
        return(-1);
    }
    
    
}

//Devuelve el primer elemento
int Lista::primerElemento(void)
{
    return( this -> items[ 0 ] );
}

//Devuelve el ultimo elemento
int Lista::ultimoElemento(void)
{
    return( this -> items[ this -> tope ] );
}

//Suiguiente elemento de la posicion
int Lista::siguiente(int posicion)
{
    int aux = -1;
    if( posicion < this -> tope )
    {
        aux = this -> items[ posicion + 1 ];
    }else
    {
        cout << "No existe posicion siguiente..." << endl; 
    }

    return(aux);    
}

//Anterior elemento de la posicion
int Lista::anterior(int posicion)
{
    int aux = -1;
    if( posicion > 0 )
    {
        aux = this -> items[ posicion - 1 ];
    }else
    {
        cout << "No existe posicion anterior..." << endl; 
    }

    return(aux);    
}

//Muestra lista
void Lista::recorrer(void)
{ 	
    int i;
    for ( i = 0; i <= this -> tope ; i++)
    {
        cout << this -> items[ i ] << endl;
    }
    
}

void Lista::cerear(void){
    int i;
    for ( i = 0; i <= this -> tope ; i++)
    {
        this -> items[i] = -1;
    }
}