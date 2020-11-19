#include <iostream>
#include "tabla.cpp"


int main(int argc, char const *argv[])
{
    tablaHash tabla = tablaHash(337);
    int i=0, aux, random;
    cout << "Ingrese el numero de claves" << endl;
    cin >> aux;

    for ( i = 0; i < aux; i++)
    {
        random = rand()%1001;
        tabla.insertar(random);
    }
}
