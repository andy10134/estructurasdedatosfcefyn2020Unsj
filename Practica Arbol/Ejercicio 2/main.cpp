#include <iostream>
#include "ArbolBinario.cpp"


int main(int argc, char const *argv[])
{
    Nodo **aux;
    ArbolBinarioB arbol = ArbolBinarioB();
    arbol.getRaiz(aux);
    arbol.insertar(5, aux);
    arbol.insertar(10, aux);
    arbol.insertar(11, aux);
    arbol.insertar(4, aux);
    arbol.insertar(2, aux);
    arbol.InOrden(aux);
    Nodo *resultado = arbol.buscar(10, aux);
    if(resultado != NULL){
        cout<<"se encontro el elemento ("<<resultado->obtenerItem()<<")"<<endl;
    }else
    {
        cout<<"no se encontro el elemento"<<endl;
    }
    bool bandera= true;
    int nivel = arbol.nivel(12, aux, &bandera);
    if(bandera){
        cout<<"nivel del nodo: "<<nivel<<endl;
    }
    else
    {
        cout<<"no se encontro el elemento en el arbol"<<endl;
    }
    
}
