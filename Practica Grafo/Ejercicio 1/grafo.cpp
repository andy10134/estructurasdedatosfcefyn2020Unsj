#include <iostream>
#include "ColaSecuencial.cpp"

using namespace std;

class Grafo
{
private:
    string *nodos;
    int cantMax;
    int ** enlaces;
public:
    Grafo(int cant);
    int encontrarNodo(string nodo);
    void relacionar(string nodo, string nodo1);
    void adyacentes(string nodo);
    void cargaNodos(string xnodos[5]);
    int grado(string nodo);
    void camino(string u,string v, string xcamino, int visitados[]);
    void caminoMinimo(string u,string v);
    void conexo();
    void aciclico();
    void arbolRecubrimiento();
    void REA();
    void REP();
    int ** warshall();
};

Grafo::Grafo(int cant)
{
    int i,j; 

    cantMax = cant;
    nodos = new string[cantMax];

    //creacion de matriz
    enlaces = new int*[cantMax];

    for (i = 0; i < cantMax; i++)
    {
        enlaces[i] = new int[cantMax];
    }
    
    //carga de nodos
    for (i = 0; i < cantMax; i++)
    {
        nodos[i] = "";
    }

    //carga de enlaces
    for (i = 0; i < cantMax; i++)
    {
        for (j = 0; j < cantMax; j++)
        {
            enlaces[i][j] = 0;
        }
    }
}

void Grafo::cargaNodos(string xnodos[5])
{
    int i;
    for (i = 0; i < cantMax; i++)
    {
        nodos[i] = xnodos[i];
    }
}

//Relacionar matriz
void Grafo::relacionar(string nodo, string nodo2)
{

    int aux = encontrarNodo(nodo);
    int aux2 = encontrarNodo(nodo2);

	enlaces[aux][aux2] = 1; 
	enlaces[aux2][aux] = 1;
}

int Grafo::encontrarNodo(string nodo)
{
    int i = 0;

    while (i < cantMax && nodos[i] != nodo)
    {
        i++;
    }
    
    if (i == cantMax)
    {
        return(-1);
    }else
    {
        return(i);
    }
    
}

void Grafo::adyacentes(string u)
{
    int nodo = encontrarNodo(u);
    if ( nodo > -1 && nodo < cantMax)
    {
        int i;
        cout<<"Nodos adyacentes"<<endl;
        for (i=0 ; i < cantMax; i++)
        {
            if (enlaces[nodo][i] == 1){
                cout<<"Nodo: "<< nodos[i] <<endl;
            }
            
        }
    }
    else
    {
    cout<<"El nodo ingresado es incorrecto"<<endl;
    }
}

void Grafo::camino(string u,string v, string xcamino, int visitados[])
{

    if (u != v)
    {
        if (visitados[encontrarNodo(u)] != 1)
        {          
            int aux = encontrarNodo(u), i;
            visitados[aux] = 1;
            string caminoAux = "" ; 
            xcamino.append(u);
            caminoAux = xcamino;
            for (i = 0; i < cantMax; i++)
            {
                if (enlaces[aux][i])
                {
                    camino(nodos[i], v, xcamino, visitados);
                    xcamino = caminoAux;
                }
            }
        }
    }else
    {
        xcamino.append(v);
        cout << xcamino << endl;
    }
}

void Grafo::caminoMinimo(string u, string v)
{
    ColaSecuencial cola = ColaSecuencial(cantMax);
    string camino;
    int aux = encontrarNodo(u), aux2 = encontrarNodo(v), *visitados = new int[cantMax], i, aux3;
    camino = "";

    for (i = 0; i < cantMax; i++)
    {
        visitados[i] = 999;
    }
    
    visitados[aux] = 0;
    cola.insertar(aux);

    while (!cola.vacia())
    {
        aux3 = cola.suprimir();
        for (i = 0; i < cantMax; i++)
        {
            if (enlaces[aux3][i] == 1)
            {
                if (visitados[i] == 999)
                {
                    visitados[i] = visitados[aux3] + 1;
                    cola.insertar(i); 
                }
                
            }
        }
        
    }

    for (i = 0; i < cantMax; i++)
    {
        cout << visitados[i] << endl;
    }   
}

int Grafo::grado(string u)
{
    int nodo = encontrarNodo(u);
    if ( nodo > -1 && nodo < cantMax)
    {
        int i, cont;
        for (i=0 ; i < cantMax; i++)
        {
            if (enlaces[nodo][i] == 1){
                cont ++;
            }
        }
        return(cont);
    }
    else
    {
    cout<<"El nodo ingresado es incorrecto"<<endl;
    return(-1);
    }
}

void Grafo::conexo()
{
    int i=0, j=0;
    int cantAux = cantAux;
    int **aux;
    aux = warshall();
    bool band = true;
    while (i<cantMax)
    {
        while (j<cantMax)
        {
            if (i != j)
            {
                if (aux[i][j] == 1000)
                {
                    band = false;
                    j = cantMax;
                    i = cantMax;
                }
            }
            j++;
        }
        i++;
    }

    if(band){
        cout<<"EL GRAFO ES CONEXO"<<endl;
    }
    else
    {
        cout<<"EL GRAFO NO ES CONEXO"<<endl;
    }
    
}

int ** Grafo::warshall()
    {
        int i,j;
        int **aux;
        aux = new int*[5];

        for (i = 0; i < cantMax; i++)
        {
            aux[i] = new int[cantMax];
        }
        for (i=0; i<cantMax; i++)
        {
            for (j=0; j<cantMax; j++)
            {
                if (enlaces[i][j] == 0)
                {
                    aux[i][j] = 1000;
                }
                else aux[i][j] = enlaces[i][j];
            }
        }
        int dt;
        for(int k = 0; k < cantMax; k++)
            for(i = 0; i < cantMax; i++)
                 for(j = 0; j < cantMax; j++)
                {
                      dt = aux[i][k] + aux[k][j];
                      if(aux[i][j] > dt)
                      aux[i][j] = dt;
                }
        return(aux);
    }