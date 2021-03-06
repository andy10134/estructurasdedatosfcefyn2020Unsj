#include <iostream>
#include "ListaEnlazada.cpp"
#include "ColaSecuencial.cpp"

using namespace std;

class Grafo
{
private:
    string *nodos;
    int cantMax;
    ListaEnlazada * enlaces;
public:
    Grafo(int cant);
    int encontrarNodo(string nodo);
    void relacionar(string nodo, string nodo1);
    void adyacentes(string nodo);
    void cargaNodos(string xnodos[5]);
    int grado(string nodo);
    void camino(string u,string v, string xcamino, int visitados[]);
    void caminoMinimo(string u,string v);
    bool conexo();
    void aciclico();
    void arbolRecubrimiento();
    void REA();
    void REP();
    int ** warshall();
    void mostrar();
};

Grafo::Grafo(int cant)
{
    int i,j; 

    cantMax = cant;
    nodos = new string[cantMax];

    //creacion de matriz
    enlaces = new ListaEnlazada[cantMax];

    //carga de nodos
    for (i = 0; i < cantMax; i++)
    {
        nodos[i] = "";
    }
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

//Relacionar matriz
void Grafo::relacionar(string nodo, string nodo2)
{
    int aux = encontrarNodo(nodo);
    int aux2 = encontrarNodo(nodo2);

    enlaces[aux].insertar(aux2,1);
    enlaces[aux2].insertar(aux,1);
}

void Grafo::adyacentes(string u)
{
    int nodo = encontrarNodo(u);
    if ( nodo > -1 && nodo < cantMax)
    {
        int i;
        cout<<"Nodos adyacentes"<<endl;
        for (i=1 ; i <= enlaces[nodo].largo(); i++)
        {
            cout << nodos[enlaces[nodo].recuperar(i)] << endl;            
        }
    }
    else
    {
    cout<<"El nodo ingresado es incorrecto"<<endl;
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

int Grafo::grado(string u)
{
    int nodo = encontrarNodo(u);
    if ( nodo > -1 && nodo < cantMax)
    {
        return(enlaces[nodo].largo());
    }
    else
    {
    cout<<"El nodo ingresado es incorrecto"<<endl;
    return(-1);
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

/*
void Grafo::caminoMinimo(string u, string v)
{
    ColaSecuencial cola = ColaSecuencial(cantMax);
    int aux = encontrarNodo(u), aux2 = encontrarNodo(v), *padre = new int[cantMax], *distancia = new int[cantMax], i, aux3;
    bool encontrado = false, *visitados = new bool[cantMax];

    for (i = 0; i < cantMax; i++)
    {
        distancia[i] = 999;
        padre[i] = -1;
        visitados[i] = false;
    }
    
    distancia[aux] = 0;
    cola.insertar(aux);

    while (!cola.vacia())
    {
        aux3 = cola.suprimir();
        visitados[aux3] = true;

        i = 0;
        while( i < cantMax  )
        {
            if (enlaces[aux3][i] == 1)
            {
                if (!visitados[i])
                {
                    if (distancia[i] > distancia[aux3] + 1)
                    {
                        distancia[i] = distancia[aux3] + 1;
                        padre[i] = aux3;
                        
                        cola.insertar(i); 
                    }       
                }        
            }
            i++;
        }      
    }

    for (i = 0; i < cantMax; i++)
    {
        cout << padre[i] << endl;
    }
    
    i = padre[aux2];
    cout << nodos[aux2];

    while (i != -1)
    {
        cout << " <-- " << nodos[i] ;
        i = padre[i];
    }
    
}

bool Grafo::conexo()
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
        return true;
    }
    else
    {
        cout<<"EL GRAFO NO ES CONEXO"<<endl;
        return false;
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
*/
void Grafo::mostrar()
{
	int i, j;

	for ( i = 0; i < cantMax; i++)
	{
        cout << nodos[i];
        for (j = 1; j <= enlaces[i].largo(); j++)
        {
            cout << " -> " << nodos[enlaces[i].recuperar(j)];
        }
        cout << endl;
	}
}
