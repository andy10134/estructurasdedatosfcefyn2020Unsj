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
    void suprimir(int dato);
    Nodo * buscar(int dato, Nodo ** raiz);
    int nivel(int dato,int contador, Nodo ** raiz);
    bool hoja(int dato);
    bool hijo(int padre, int hijo);
    bool padre(int padre, int hijo, Nodo ** raiz);
    void camino(int origen,int destino);
    int altura();
    void InOrden(Nodo **raizS);
    
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

void ArbolBinarioB::suprimir(int dato)
{
    Nodo * aux , * padreEliminar ;
    aux = this -> raiz;
    bool izq = false;

    while (aux != NULL && aux->dato != dato)
    {
        padreEliminar = aux;
        
        if (aux -> dato < dato)
        {
            aux = aux -> der;
            izq = false;
        }else
        {
            aux = aux -> izq;
            izq = true;
        }       
    }

    if (aux == NULL)
    {
        cout << "No se ha encontrado el elemento en el arbol" << endl;
    }else if (aux->der == NULL && aux->izq == NULL )
    {
        if (izq)
        {
            padreEliminar -> izq = NULL;
        }else
        {
            padreEliminar -> der = NULL;                
        }
        delete(aux);

    }else if (aux->der == NULL || aux->izq == NULL )
    {
        Nodo * nodoEliminar;
        nodoEliminar = aux;
        if (aux->der != NULL)
        {
            aux = aux->der; 
        }else
        {
            aux = aux->izq; 
        }
        delete(nodoEliminar);
    } else
    {
        Nodo * nodoSucesor , *padre;
        nodoSucesor = aux -> der;
        padre = aux;

        while (nodoSucesor -> izq != NULL)
        {
            padre = nodoSucesor;
            nodoSucesor = nodoSucesor -> izq;
        }
        
        if (nodoSucesor -> der != NULL)
        {
            padre -> izq = nodoSucesor -> der;
        }
        aux -> dato = nodoSucesor ->dato;        
        
        delete(nodoSucesor);
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
                return(buscar(dato, &(aux->der)));
            }else
            {
                return(buscar(dato, &(aux->izq)));
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


void ArbolBinarioB::InOrden(Nodo **raizS){
    
    Nodo *aux = *raizS;

    if(aux != NULL)
    {
        InOrden(&(aux -> izq));
        cout<< aux -> dato <<endl;
        InOrden(&(aux -> der));
    }
}

/*
bool ArbolBinarioB::hijo(int padre, int hijo)
{
    
}*/

void ArbolBinarioB::mostrar()
{
    cout << "Fin";
}
