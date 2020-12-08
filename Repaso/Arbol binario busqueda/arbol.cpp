//#include "nodo.cpp"
#include <iostream>
using namespace std;

struct Nodo
{
    int dato;
    Nodo * izq = NULL;
    Nodo * der = NULL;
};


class ArbolBinarioB
{
private:
    Nodo *raiz;    
public:
    ArbolBinarioB(int dato);
    void insertar(int dato, Nodo ** raiz);
    void suprimir(int dato, Nodo ** raiz);
    Nodo * buscar(int dato, Nodo ** raiz);
    int nivel(int dato,int contador, Nodo ** raiz);
    bool hoja(int dato);
    bool hijo(int padre, int hijo);
    bool padre(int padre, int hijo, Nodo ** raiz);
    void camino(int destino, Nodo ** raiz);
    int altura();
    
    void mostrar();
    Nodo ** getRaiz();
};

ArbolBinarioB::ArbolBinarioB(int dato)
{
    raiz = new Nodo;
    raiz->dato = dato;
    raiz->der = NULL;
    raiz->izq = NULL;
}

Nodo ** ArbolBinarioB::getRaiz()
{
    return(&raiz);
}

void ArbolBinarioB::insertar(int dato, Nodo ** raiz)
{
    Nodo * aux = *raiz;
    if (aux != NULL)
    {
        if (aux->dato < dato)
        {
            insertar(dato, &(aux->der));
        }else
        {
            insertar(dato, &(aux->izq));
        }
    }else
    {
        Nodo * nuevoNodo = new Nodo;
        nuevoNodo->dato = dato;
        nuevoNodo->izq = NULL;
        nuevoNodo->der = NULL;
        *raiz = nuevoNodo; 
    }    
}

void ArbolBinarioB::suprimir(int dato, Nodo ** raiz)
{
    Nodo * aux = *raiz;
    
    if (aux == NULL)
    {
        cout << "No se ha encontrado el elemento en el arbol" << endl;
    }else if (aux->dato != dato)
    {
        if (aux->dato < dato)
        {
            suprimir(dato, &(aux->der));
        }else
        {
            suprimir(dato, &(aux->izq));
        }
    }else
    {
        Nodo * nodoEliminar = new Nodo;
        nodoEliminar = *raiz;
        delete(nodoEliminar);
        *raiz = NULL; 
    }    
}

Nodo * ArbolBinarioB::buscar(int dato, Nodo ** raiz)
{
    Nodo * aux = *raiz;
    
    if (aux != NULL)
    {
        if (aux->dato != dato)
        {
            if (dato > aux->dato)
            {
                buscar(dato, &(aux->der));
            }else
            {
                buscar(dato, &(aux->izq));
            }
        }else
        {
            cout << "Se encontro " << dato << endl;
            return(aux);
        }        
    }else
    {
        cout << "No se ha encontrado el elemento" << endl;
        return(NULL);
    }
}

int ArbolBinarioB::nivel(int dato,int contador, Nodo ** raiz)
{
    Nodo * aux = *raiz;
    
    if (aux != NULL)
    {
        if (aux->dato != dato)
        {

            if (dato > aux->dato)
            {
                nivel(dato, contador+1, &(aux->der));
            }else
            {
                nivel(dato, contador+1, &(aux->izq));
            }
        }else
        {
            cout << "El nivel es " << contador << endl;
            return(contador);
        }        
    }else
    {
        cout << "No se ha encontrado el elemento" << endl;
        return(0);
    }
    
    return(0);
}

bool ArbolBinarioB::hoja(int dato)
{
    Nodo * aux = buscar(dato, getRaiz());
    
    if (aux == NULL)
    {
        cout << "No es existe el nodo" << endl;
        return(false);
    }else if (aux->der == NULL && aux->izq == NULL)
    {
        cout << "El nodo " << dato << " es hoja" << endl;
        return(true);
    }else
    {
        cout << "No es hoja" << endl;
        return(false);
    }
}

bool ArbolBinarioB::hijo(int padre, int hijo)
{
    
}
void ArbolBinarioB::mostrar()
{
    cout << "Fin";
}
