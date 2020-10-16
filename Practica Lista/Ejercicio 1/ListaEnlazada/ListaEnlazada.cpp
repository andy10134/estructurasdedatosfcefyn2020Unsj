#include "ListaEnlazada.h"
#include "Celda.cpp"
#include <iostream>

using namespace std;


//Constructor
ListaEnlazada::ListaEnlazada(Celda* cabeza, int cant){
    this -> cant = cant;
}

int ListaEnlazada::vacia(void)
{
    return( this -> cant == 0);
}

int ListaEnlazada::insertar(int elemento, int posicion){
    cout<<"entro"<<endl;
    if (posicion > 0 && posicion <= this -> cant +1)
    {
        Celda* nuevo;
        nuevo = new(Celda);
        int cont=1;
        nuevo->cargaItem(elemento);
        cout<<"entro al primer if"<<endl;
        if(vacia())
        {
            this -> cabeza = nuevo;
            cout<<"SE INSERTO EL ELEMENTO EN LA PRIMERA POSICION PORQUE ESTA VACIA CAPO"<<endl;
        }
        else
        {
            if (posicion -1 == 0)
            {
                nuevo->cargaSig(this -> cabeza);
                this -> cabeza = nuevo;
                cout<<"SE INSERTO EL ELEMENTO EN LA PRIMERA POSICION"<<endl;
            }
            else
            {
                Celda* aux = this -> cabeza;
                Celda* anterior = this -> cabeza;
                while(cont != posicion)
                {
                    anterior = aux;
                    aux = aux->obtenerSig();
                    cont++;
                }
                anterior->cargaSig(nuevo);
                nuevo->cargaSig(aux);
                cout<<"El elemento ha sido insertado en el lugar que corresponde"<<endl;
            }            
        }
        this -> cant ++;
    }
    else
    {
        cout<<"POSICION INVALIDA"<<endl;
    }
    return(0);
}


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
}