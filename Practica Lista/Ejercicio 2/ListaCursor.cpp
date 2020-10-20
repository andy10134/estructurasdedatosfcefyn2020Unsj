#include "ListaCursor.h"
#include "Celda.cpp"
#include <iostream>

using namespace std;

//Constructor
ListaCursor::ListaCursor(int cant)
{
    this -> items = new Celda[cant]; //aca deberia ser cabeza(guarda el primer elemento), cantidad de elementos y el arreglo con las celdas
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
    if (posicion > 0 && posicion <= this -> cant +1 && this -> cant +1 <= this -> maximaCant)
    {
        if( this -> vacia() )
        {
            this -> items[0].cargaItem(elemento);
            this -> items[0].cargaSig(-1); 


        }else if( posicion ==1 )
        {
            int i = 0;
            while ( i < this -> maximaCant && this -> items[i].obtenerSig() != -2 )
            {
                i++;
            }
            this -> items[i].cargaSig( this -> cabeza );
            this -> items[i].cargaItem(elemento);
            this -> cabeza = i;
        
        }
        else
        {

            int cont=1;
            int i, aux, anterior;
            
            aux = this -> cabeza;
            while( cont < posicion )
            {
                anterior = aux;
                aux = this -> items[ aux ].obtenerSig();
                cont++;
            }

            i = 0;
            while ( i < this -> maximaCant && this -> items[i].obtenerSig() != -2 )
            {
                i++;
            }

            this -> items[i].cargaSig(aux);
            this -> items[i].cargaItem(elemento);
            this -> items[ anterior ].cargaSig(i);
        
        }
        
        this -> cant++;
        return(elemento);

    }else
    {
        cout<<"POSICION INVALIDA"<<endl;
        return(0);
    }
}

int ListaCursor::suprimir(int posicion)
{
    int cont = 1;
    if (posicion > 0 && posicion <= this -> cant )
    {
        if (posicion == 1)
        {
            items[0].cargaSig(-2); 
            this -> cabeza = this -> items[0].obtenerSig();
        }
        
    }
    
}

void ListaCursor::mostrar(void)
{
    int aux, cant = 0;
    aux = this -> cabeza;

    while ( aux != -1 )
    {
        cout << this -> items[ aux ].obtenerItem() << " - Posicion: " << cant+1 << endl;
        aux = this -> items[ aux ].obtenerSig();
        cant++;
    }
    
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