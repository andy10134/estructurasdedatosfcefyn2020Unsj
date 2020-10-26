#include <iostream>
#include "ListaEnlazada.cpp"

using namespace std;

void hoffman(ListaEnlazada lista);

int main(int argc, char const *argv[])
{
    ListaEnlazada lista;

    lista.insertar("F",15);
    lista.insertar("G",9);
    lista.mostrar();

}

void hoffman(ListaEnlazada lista)
{
    if(!lista.vacia())
    {
        Celda *aux = lista.recuperar(1);
        Celda *aux1 = lista.recuperar(2);

        if(aux1 != NULL)
        {          
            lista.insertar(aux -> obtenerEtiqueta() + aux1 -> obtenerEtiqueta() ,
                           aux -> obtenerItem() + aux1 -> obtenerItem(),
                           aux,
                           aux1);

        }
    }else
    {
        cout << "Lista Vacia" << endl;
    }
     
}