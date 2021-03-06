#include "ColaEnlazada.h"
#include "Celda.cpp"
#include <iostream>

using namespace std;

//Constructor
ColaEnlazada::ColaEnlazada(Celda* pr, Celda* ul, int cant){
    this -> pr = pr;
    this -> ul = ul;
    this -> cant = cant;
}

int ColaEnlazada::vacia(void)
{
    return( this -> cant == 0);
}

int ColaEnlazada::insertar(int x)
{ 
    Celda *ps1;
    ps1=new(Celda);
    ps1->cargaItem(x);
    ps1->cargaSig(NULL);
    if (this -> ul==NULL)
    {   
        this -> pr=ps1;
    }
    else
    {   
        this -> ul->cargaSig(ps1);
    }
    this -> ul=ps1;
    this -> cant++;
    return( this -> ul->obtenerItem() );
}

int ColaEnlazada::suprimir(void)
{   
    Celda *aux;
    int x;
    if (vacia())
    { 
        cout<<"Cola vacia"<<endl;
        return(0);
    }
    else
    { 
        aux= this -> pr;
        x= this -> pr->obtenerItem();
        this -> pr= this -> pr->obtenerSig();
        this -> cant--;
        if ( this -> pr == NULL)
        {
            this -> ul= NULL;
            
        }
        free(aux);
        return(x); //wtf no entiendo que es esto
    }
}
Celda* ColaEnlazada::recuperaPr(void)
{
    return(this -> pr);
}
void ColaEnlazada::recorrer(void)
{
    Celda *aux;
    aux = this -> pr;
    while (aux!=NULL)
    { 
        cout<<aux->obtenerItem()<<endl;
        aux = aux->obtenerSig();
    }
}
