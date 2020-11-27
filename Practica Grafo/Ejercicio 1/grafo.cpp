#include <iostream>

using namespace std;

class Grafo
{
private:
    string *nodos;
    int cantMax;
    int ** enlaces;
public:
    Grafo(int cantNodos);
};

Grafo::Grafo(int cant, int xenlaces[][], string xnodos[])
{
    int i,j; 

    cantMax = cant;
    nodos = new string[cantMax];
    enlaces = new int*[cantMax];

    for (i = 0; i < cantMax; i++)
    {
        enlaces[i] = new int[cantMax];
    }
    
    //carga de nodos
    for (i = 0; i < cantMax; i++)
    {
        nodos[i] = xnodos[i];
    }

    //carga de enlaces
    for (i = 0; i < cantMax; i++)
    {
        for (j = 0; i < cantMax; j++)
        {
            enlaces[i][j] = xenlaces[i][j];
        }
    }
}
