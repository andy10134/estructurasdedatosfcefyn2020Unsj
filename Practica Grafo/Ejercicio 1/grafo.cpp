#include <iostream>

using namespace std;

class Grafo
{
private:
    string *nodos;
    int cantMax;
    int ** enlaces;
public:
    Grafo(int cant, int xenlaces[][], string xnodos[]);
    void relacionar(string nodo, string nodo);
    void adyacentes(string u);
    void camino(string u,string v);
    void caminoMinimo(string u,string v);
    void conexo();
    void aciclico();
    void arbolRecubrimiento();
    void REA();
    void REP();
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
        for (j = 0; i < cantMax; j++)
        {
            enlaces[i][j] = 0;
        }
    }
}

//Relacionar matriz
void Grafo::relacionar(string nodo, string nodo2)
{
    int aux = encontrarNodo(nodo, nodos, cantMax), aux2 = encontrarNodo(nodo2, nodos, cantMax);

	enlaces[aux][aux2] = 1; 
	enlaces[aux2][aux] = 1;
}

int encontrarNodo(string nodo, string arr[], int cant)
{
    int i = 0;

    while (i < cant arr[i] != nodo)
    {
        i++;
    }
    
    if (i == cant)
    {
        return(-1);
    }else
    {
        return(i);
    }
    
}