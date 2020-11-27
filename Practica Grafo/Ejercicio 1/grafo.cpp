#include <iostream>

using namespace std;

class Grafo
{
private:
    string *nodos;
    int cantMax;
    int * enlaces;
public:
    Grafo(int cantNodos);
};

Grafo::Grafo(int cant)
{
    cantMax = cant;
    nodos = new string[cantMax];
    enlaces = new int[cantMax][cantMax];
}
