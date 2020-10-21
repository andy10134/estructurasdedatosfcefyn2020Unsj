#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include "designacion.cpp"
#include "ListaEnlazada.cpp"
using namespace std;


main()
{
ifstream archivo; 
string linea;
string arreglo[5];
int i=0;
ListaEnlazada lista = ListaEnlazada(0);
archivo.open("estadistica-designacion-magistrados-federal-nacional-por-genero-20190913.csv", ios::in);
while (getline(archivo,linea))
{
    while(i != 6)
    {
        arreglo[i] = strtok(const_cast<char*>(linea), ",");
        i++;
    }
    Designacion desig = Designacion(arreglo[0], arreglo[1], arreglo[2], arreglo[3], arreglo[4], arreglo[5]);
    lista.insertar(desig);
    i = 0;
}
}