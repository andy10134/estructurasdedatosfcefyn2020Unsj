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

Grafo::Grafo(int cant)
{
    int i; 

    cantMax = cant;
    nodos = new string[cantMax];
    enlaces = new int*[cantMax];

    for (i = 0; i < cantMax; i++)
    {
        enlaces[i] = new int[cantMax];
    }
    
}
