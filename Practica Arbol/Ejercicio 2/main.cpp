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

    cout<<"-------------------------------"<<endl;
    cout<<"InOrden"<<endl;
    arbol.InOrden(aux);
    cout<<"-------------------------------"<<endl;

    //buscar
    Nodo *resultado = arbol.buscar(10, aux);
    if(resultado != NULL){
        cout<<"se encontro el elemento ("<<resultado->obtenerItem()<<")"<<endl;
    }else
    {
        cout<<"no se encontro el elemento"<<endl;
    }
    cout<<"-------------------------------"<<endl;

    //nivel
    bool bandera= true;
    int nivel = arbol.nivel(11, aux, &bandera);
    if(bandera){
        cout<<"nivel del nodo: "<<nivel<<endl;
    }
    else
    {
        cout<<"no se encontro el elemento en el arbol"<<endl;
    }
    cout<<"-------------------------------"<<endl;

    //hoja
    bool resultado1 = arbol.hoja(11, aux);
    if(resultado1){
        cout<<"este nodo es una hoja :)"<<endl;
    }else
    {
        cout<<"este nodo no es una hoja :("<<endl;
    }
    cout<<"-------------------------------"<<endl;

    //hijo
    int hijo = 11, padre = 10;
    resultado1 = arbol.hijo(hijo, padre, aux);
    if(resultado1){
        cout<<"el nodo "<<hijo<<" es hijo del nodo "<<padre<<endl;
    }else
    {
        cout<<"el nodo "<<hijo<<" no es hijo del nodo "<<padre<<endl;
    }
    cout<<"-------------------------------"<<endl;


    bool bandera2 = true;
    resultado = arbol.buscar(5, aux);
    int arreglo[arbol.altura(aux, 0)], cont = 0;
    if(resultado != NULL){
        arbol.camino(2, resultado, bandera2, &arreglo[0], cont);
        if(bandera2){
            int i;
            cout<<"camino:"<<endl;
            for(i=0; i<=cont; i++){
                cout<<"- "<<arreglo[i]<<endl;
            }
        }
        else
        {
            cout<<"no existe el camino"<<endl;
        }
    }
    else
    {
        cout<<"no se puede realizar el metodo camino porque el ancestro no existe  en el arbol"<<endl;
    }
    cout<<"-------------------------------"<<endl;

    //altura
    int altura = arbol.altura(aux, 0);
    cout<<"altura del arbol: "<<altura<<endl;
    cout<<"-------------------------------"<<endl;

}
