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
    if (posicion > 0 && posicion <= this -> cant +1)
    {
        Celda* nuevo;
        nuevo = new(Celda);
        int cont=1;
        nuevo->cargaItem(elemento);
        nuevo->cargaSig(NULL);
        if(vacia())
        {
            this -> cabeza = nuevo;
            cout<<"SE INSERTO EL ELEMENTO EN LA PRIMERA POSICION PORQUE ESTA VACIA CAPO"<<endl;
        }
        else
        {
            if (posicion == 1)
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

int ListaEnlazada::primerElemento(void)
{
    return(this -> cabeza->obtenerItem());
}

int ListaEnlazada::ultimoElemento(void)
{
    Celda* aux;
    aux = this -> cabeza;
    while (aux->obtenerSig() != NULL)
    {
        aux= aux->obtenerSig();
    }
    return(aux->obtenerItem());
}

int ListaEnlazada::siguiente(int posicion)
{
    if (posicion <= this -> cant +1)
    {
       return(posicion++);
    }
}

int ListaEnlazada::anterior(int posicion)
{
    if (posicion > 1)
    {
       return(posicion--);
    }
}

int ListaEnlazada::suprimir(int posicion)
{
    if (posicion > 0 && posicion <= this -> cant +1)
    {
        Celda* aux;
        int cont=1, elemento;
        if(vacia())
        {
            cout<<"no se puede suprimir porque la lista esta vacia"<<endl;
        }
        else
        {
            if (posicion == 1)
            {
                aux = this -> cabeza;
                elemento = this -> cabeza->obtenerItem();
                this -> cabeza = this -> cabeza->obtenerSig();
                delete(aux);
            }
            else
            {
                aux = this -> cabeza;
                Celda* anterior = this -> cabeza;
                while(cont != posicion)
                {
                    anterior = aux;
                    aux = aux->obtenerSig();
                    cont++;
                }
                elemento = aux->obtenerItem();
                anterior->cargaSig(aux->obtenerSig());
                delete(aux);
                cout<<"El elemento ha sido suprimido"<<endl; 
            }       
        }
        this -> cant --;
        return(elemento);
    }
    else
    {
        cout<<"POSICION INVALIDA"<<endl;
        return(0);
    }
}

int ListaEnlazada::recuperar(int posicion)
{
    if (posicion > 0 && posicion < this -> cant +1)
    {
        if(vacia())
        {
            cout<<"no se puede recuperar porque la lista esta vacia"<<endl;
        }
        else
        {
            Celda *aux;
            int cont=1;
            aux = this -> cabeza;
            while (cont != posicion)
            { 
                cont++;
                aux = aux->obtenerSig();
            }
            return(aux->obtenerItem());
        }
    }
    else
    {
        cout<<"POSICION INVALIDA"<<endl;
    }
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
    cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
}

int ListaEnlazada::buscar(int elemento){
    if (vacia())
    {
        cout<<"no se puede suprimir porque la lista esta vacia"<<endl;
    }
    else
    {
        Celda *aux;
        int cont=1;
        aux = this -> cabeza;
        while (aux!=NULL && aux->obtenerItem() != elemento)
        { 
            cont++;
            aux = aux->obtenerSig();
        }
        if(aux == NULL)
        {
            cout<<"No se encontro el elemento en la lista"<<endl;
            return(1);
        }
        else
        {
            //cout<<"Se encontro el elemento en la posicion "<<cont<<" de la lista"<<endl;
            return(0);
        }
    }
}

Celda* ListaEnlazada::getcabeza(void)
{
    return(this->cabeza);
}