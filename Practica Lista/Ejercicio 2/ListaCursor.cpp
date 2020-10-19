#include "ListaCursor.h"
#include "Celda.cpp"
#include <iostream>

using namespace std;

//Constructor
ListaCursor::ListaCursor(int cant)
{
    this -> items[cant]; //aca deberia ser cabeza(guarda el primer elemento), cantidad de elementos y el arreglo con las celdas
    this -> cabeza = 0;
    this -> cant = 0;
    this -> maximaCant = cant;
}

int ListaCursor::vacia(void)
{
    return( this -> cant == 0);
}

int ListaCursor::insertar(int elemento, int posicion)
{
    if( this -> vacia() && posicion ==1 )
    {
        this -> items[posicion -1].cargaItem(elemento);
        this -> items[posicion -1].cargaSig(-1); 
        this -> cant++;
        
    }else if (posicion > 0 && posicion <= this -> cant +1 && this -> cant +1 <= this -> maximaCant)
    {
        int cont=1;
        int i, aux, anterior;
        
        aux = this -> cabeza;
        while( cont < posicion -1 )
        {
            anterior = aux;
            aux = this -> items[ aux ].obtenerSig();
            cont++;
        }

        while ( i < this -> maximaCant && this -> items[i].obtenerSig() != -2 )
        {
            i++;
        }

        this -> items[i].cargaSig(aux);
        this -> items[i].cargaItem(elemento);
        this -> items[ anterior ].cargaSig(i);
        this -> cant++;        
    }
    else
    {
        cout<<"POSICION INVALIDA"<<endl;
    }
    return(0);
}


/*
Celda* ListaEnlazada::primerElemento(void)
{
    return(this -> cabeza);
}

void ListaEnlazada::mostrar(void)
{
    Celda *aux;
    aux = this -> cabeza;
    while (aux!=NULL)
    { 
        cout<<aux->obtenerItem()<<endl;
        aux = aux->obtenerSig();
    }
}


int ListaEnlazada::buscar(int elemento){
    Celda *aux;
    aux = this -> cabeza;
    while (aux!=NULL && aux->obtenerItem() != elemento)
    { 
        aux = aux->obtenerSig();
    }
}*/