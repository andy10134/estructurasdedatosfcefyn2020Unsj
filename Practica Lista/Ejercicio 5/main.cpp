#include <iostream>
#include "Lista.cpp"

using namespace std;

void eliminar(Lista lista, int N)
{
    int i=0, p, a , j, x;
    while (i < N)
    {
        p = i;
        a = lista.recuperar(i+1);
        j = lista.siguiente(i+1);
        while (p<N)
        {
            j = lista.siguiente(j);
            x = lista.recuperar(j);
            if (a == x)
            {
                lista.suprimir(j);
                N = N-1;
            }
            p++;
        }
        i++;  
    }
    lista.recorrer();
}

int main(int argc, char const *argv[])
{
    int N = 6;
    Lista lista(N);

    lista.insertar(10, 1);
    lista.insertar(5, 2);
    lista.insertar(7, 3);
    lista.insertar(5, 4);
    lista.insertar(2, 5);
    lista.insertar(10, 6);
    lista.recorrer();
    eliminar(lista, N);
    //lista.recorrer();
}

