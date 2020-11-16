#include <iostream>

using namespace std;


class tablaHash
{
private:
    int *items;
    int max;
public:
    tablaHash(int cantidad);
    int buscar(int elemento);
    void insertar(int elemento);
};

tablaHash::tablaHash(int cantidad)
{
    max = cantidad;
    items = new int[max];
    int i;
    for (i = 0; i < max; i++)
    {
        items[i] = -1;
    }
}

void tablaHash::insertar(int elemento)
{
    int i=0, aux;

    aux = elemento%max;

    if (items[aux] == -1)
    {
        items[aux] = elemento;
    }else
    {   
        int aux2 = (aux2+1)%max;
        while (aux != aux2 && items[aux2] != -1 && items[aux2] == elemento)
        {
            aux2 = (aux2+1)%max;           
        }
        
        if (aux2 == aux)
        {
            cout << "Tabla saturada" << endl;
        }else if (items[aux2] == elemento)
        {
            cout << "Ya se ha insertado ese elemento" << endl;
        }else        
        {
            items[aux] = elemento;
            cout << "Exito" << endl;
        }
        
        
    }   
}


int tablaHash::buscar(int elemento)
{
    int i=0, aux, cont = 1;

    aux = elemento%max;

    if (items[aux] == elemento)
    {
        cout << "Se encontro el elemento, cont:" <<cont<<endl;
        return(aux);
    }else
    {   
        int aux2 = (aux+1)%max;
        while (aux != aux2 && items[aux2] == -1 && items[aux2] == elemento)
        {
            cont ++;
            aux2 = (aux2+1)%max;     
        }
        if (aux2 == aux)
        {
            cout << "No se encontro el elemento, cont:" <<cont<< endl;
            return(-1);
        }else if (items[aux2] == -1)
        {
            cout << "No se encontro el elemento, cont:" <<cont<< endl;
            return(-1);
        }else        
        {
            cout << "Se encontro el elemento, cont:" <<cont<< endl;
            return(aux2);
        }
    }   
}

