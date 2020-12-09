#include <iostream>

using namespace std;

struct bucket
{
    int items[5];
    int contador;
} ;

class tablaHash
{
private:
    bucket *buckets;
public:
    tablaHash();
    int hash(int elemento);
    void insertar(int elemento);
    void buscar(int elemento);
};

tablaHash::tablaHash()
{
    buckets = new bucket[211];

    int i;

    for (i = 0; i < 211; i++)
    {
        buckets[i].contador = 0;        
    }
}

int tablaHash::hash(int elemento)
{
    elemento = elemento%1000;
    elemento = elemento%200;
    return(elemento);
}

void tablaHash::insertar(int elemento)
{
    int clave = hash(elemento);
    int i = 0, j = 200, contador;

    while (i < 5 && i < buckets[clave].contador && buckets[clave].items[i] != elemento )
    {
        i++;
    }

    if (i == 5)
    {
        contador = 5;
        i=0;

        while (contador != buckets[clave].contador && buckets[j].items[i] != elemento)
        {

            if (clave == hash(buckets[j].items[i]))
            {
                contador++;
            }
            
            i++;
            if (i == 5)
            {
                i = 0;
                j++;
            }
        }

        if (contador == buckets[clave].contador)
        {   
            while (j < 211 && buckets[j].contador == 5)
            {
                j++;
            }

            if (j < 211)
            {
                buckets[j].items[buckets[j].contador] = elemento;
                buckets[j].contador++;
            }else
            {
                cout << "Overflow lleno" << endl;
            }


        }else
        {
            cout << "El elemento ya existia" << endl;
        }

    }else
    {
        if (i == buckets[clave].contador)
        {    
            buckets[clave].items[buckets[clave].contador] = elemento;
            buckets[clave].contador++;
        }else
        {
            cout << "El elemento ya existia" << endl;
        }
        
    }
}
