#include <iostream>
#include "ListaEnlazada.cpp"
#include "ColaSecuencial.cpp"

using namespace std;

class DiGrafo
{
private:
    string *nodos;
    int cantMax;
    ListaEnlazada * enlaces;
public:
    DiGrafo(int cant);
    int encontrarNodo(string nodo);
    void relacionar(string nodo, string nodo1);
    void adyacentesEntrada(string nodo);
    void adyacentesSalida(string nodo);
    void cargaNodos(string xnodos[5]);
    int gradoEntrada(string nodo);
    int gradoSalida(string nodo);
    void camino(string u,string v, string xcamino, int visitados[]);
    void caminoMinimo(string u,string v);
    bool conexo();
    void aciclico();
    void arbolRecubrimiento();
    void REA();
    void REP();
    void mostrar();
    
    //?
    bool verticeSumidero(string u);
    bool verticeFuente(string u);
};

DiGrafo::DiGrafo(int cant)
{
    int i,j; 

    cantMax = cant;
    nodos = new string[cantMax];

    //creacion de lista de adyacencia
    enlaces = new ListaEnlazada[cantMax];

    //carga de nodos
    for (i = 0; i < cantMax; i++)
    {
        nodos[i] = "";
    }
}

int DiGrafo::encontrarNodo(string nodo)
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

//Relacionar lista
void DiGrafo::relacionar(string nodo, string nodo2)
{
    int aux = encontrarNodo(nodo);
    int aux2 = encontrarNodo(nodo2);

    enlaces[aux].insertar(aux2,1);
}

//Adyacentes salida
void DiGrafo::adyacentesSalida(string u)
{
    int nodo = encontrarNodo(u);
    if ( nodo > -1 && nodo < cantMax)
    {
        int i;
        cout<<"Nodos adyacentes salida"<<endl;
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

//Adyacentes entrada
void DiGrafo::adyacentesEntrada(string u)
{
    int nodo = encontrarNodo(u);
    if ( nodo > -1 && nodo < cantMax)
    {
        int i;
        cout<<"Nodos adyacentes entrada: "<<endl;
        for (i = 0 ; i < cantMax; i++)
        {
            if (enlaces[i].buscar(nodo))
            {
                cout << nodos[i] << endl;
            }  
        }
    }
    else
    {
    cout<<"El nodo ingresado es incorrecto"<<endl;
    }
}

void DiGrafo::cargaNodos(string xnodos[5])
{
    int i;
    for (i = 0; i < cantMax; i++)
    {
        nodos[i] = xnodos[i];
    }
}

//Grados de entrada 
int DiGrafo::gradoSalida(string u)
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

//Grados de Salida
int DiGrafo::gradoEntrada(string u)
{
    int nodo = encontrarNodo(u);
    if ( nodo > -1 && nodo < cantMax)
    {
        int i, grado = 0;
        for (i = 0; i < cantMax; i++)
        {
            grado = grado + enlaces[i].buscar(nodo);
        }
        return(grado);
    }
    else
    {
    cout<<"El nodo ingresado es incorrecto"<<endl;
    return(-1);
    }
}

//Sumidero
bool DiGrafo::verticeSumidero(string u)
{
    return(gradoEntrada(u) > 0  && gradoSalida(u) == 0);
}

//Fuente
bool DiGrafo::verticeFuente(string u)
{
    return(gradoEntrada(u) == 0  && gradoSalida(u) > 0);
}

/*
void DiGrafo::camino(string u,string v, string xcamino, int visitados[])
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


void DiGrafo::caminoMinimo(string u, string v)
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

bool DiGrafo::conexo()
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
        cout<<"EL DiGRAFO ES CONEXO"<<endl;
        return true;
    }
    else
    {
        cout<<"EL DiGRAFO NO ES CONEXO"<<endl;
        return false;
    }
    
}

int ** DiGrafo::warshall()
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
void DiGrafo::mostrar()
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
