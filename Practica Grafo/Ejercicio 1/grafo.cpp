#include <iostream>

using namespace std;

class Grafo
{
private:
    string *nodos;
    int cantMax;
    int ** enlaces;
public:
    Grafo(int cant,  int xenlaces[][], string xnodos[]);
    void adyacentes(string u);
    void grado();
    void camino(string u,string v);
    void caminoMinimo(string u,string v);
    void conexo();
    void aciclico();
    void arbolRecubrimiento();
    void REA();
    void REP();
};

Grafo::Grafo(int cant, int xenlaces[][], string xnodos[])
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

void Grafo::adyacentes(string u)
{
    u = u-1;
    if ( u > -1 && u < cant)
    {
        int i;
        cout<<"Nodos adyacentes"<<endl;
        for (i=0 ; i < cant; i++)
        {
            if (enlaces[u][i] == 1){
                cout<<"Nodo: "<<i+1<<endl;
            }
            
        }
    }
    else
    {
    cout<<"El nodo ingresado es incorrecto"<<endl;
    }
}
