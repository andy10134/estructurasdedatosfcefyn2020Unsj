#include <iostream>
#include "tabla.cpp"
#include <cstdlib>
#include <time.h>
using namespace std;


int main(int argc, char const *argv[])
{
    int i=0, aux, random;
    cout << "Ingrese el numero de claves" << endl;
    cin >> aux;

    for ( i = 0; i < aux; i++)
    {
        random = rand()%5;
        
    }
    

        tablaHash tabla = tablaHash();
}
