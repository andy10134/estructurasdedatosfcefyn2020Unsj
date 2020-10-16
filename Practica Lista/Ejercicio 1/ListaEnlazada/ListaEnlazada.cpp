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
        Celda* anterior, aux;
        int cont=1;
        if(vacia())
        {
            cout<<"no se puede suprimir porque la lista esta vacia"<<endl;
        }
        else
        {
            if (posicion == 1)
            {
                aux = this -> cabeza->obtenerSig();

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

int ListaEnlazada::recuperar(int posicion)
{
    if (posicion > 0 && posicion <= this -> cant +1)
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
}

int ListaEnlazada::buscar(int elemento){
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
    }
    else
    {
        cout<<"Se encontro el elemento en la posicion "<<cont<<" de la lista"<<endl;
        return(cont);
    }
    
}