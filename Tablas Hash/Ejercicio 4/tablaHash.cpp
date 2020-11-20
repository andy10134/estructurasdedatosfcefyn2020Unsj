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
    bucket *items;
public:
    tablaHash();
    int hash(int elemento);
    void insertar(int elemento);
    void buscar(int elemento);
};

tablaHash::tablaHash()
{
    items = new bucket[211];
}

void tablaHash::insertar(int elemento)
{
    int clave = hash(elemento);

    if (items[clave].contador < 5)
    {
        items[clave].items[items[clave].contador] = elemento;
        items[clave].contador++;
    }else
    {
        int i = 200;
        while (i < 211 && items[i].contador > 5)
        {
            i++;
        }

        if (i != 211)
        {
            items[i].items[items[i].contador] = elemento;
            items[i].contador++;
            items[clave].contador++;
        }else
        {
            cout << "Overflow Lleno" << endl;
        }
        
    }
    
    
}
