#include <iostream>
#include "ListaEnlazada.cpp"

using namespace std;


class tablaHash
{
private:
    ListaEnlazada *items;
    int max;
public:
    tablaHash(int cantidad);
    int buscar(int elemento);
    int hash(int elemento);
    void insertar(int elemento);
    void mostrar(void);
};

tablaHash::tablaHash(int cantidad)
{
    max = cantidad;
    items = new ListaEnlazada[max];
}

int tablaHash::hash(int elemento)
{
    elemento = (elemento/1000)+(elemento%1000);
    if(elemento > 337){
        elemento = elemento%337;
    }
    return(elemento);
}

void tablaHash::insertar(int elemento)
{
    int clave = hash(elemento);
    Celda *aux;
    int cont=1;
    aux = items[clave].getcabeza();
    while (aux!=NULL && aux->obtenerItem() != elemento)
    { 
        aux = aux->obtenerSig();
    }
    if(aux == NULL)
    {
        items[clave].insertar(elemento, 1);
    }
    else
    {
        cout<<"el elemento ya esta en la lista"<<endl;
    }
}

int tablaHash::buscar(int elemento)
{
    int clave = hash(elemento);
    return(items[clave].buscar(elemento));
}

void tablaHash::mostrar(){
    int i;
    cout<<"oaoaoaoaoaoaoaoaoaoaoao"<<endl;
    for (i = 0; i < max; i++)
    {
        items[i].mostrar();
        cout<<"-----------------"<<endl;

    }
}