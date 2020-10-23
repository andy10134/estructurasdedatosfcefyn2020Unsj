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
    string linea, cargo, instancia, materia;
    char* linea2;
    string arreglo[5];
    std::string dato;
    int anio, varones, mujeres, i;
    ListaEnlazada lista = ListaEnlazada(0);
    archivo.open("estadistica-designacion-magistrados-federal-nacional-por-genero-20190913.csv", ios::in);
    getline(archivo,linea); // lee la primera fila con los nombres
    while (getline(archivo,linea))
    {
        /*i = 0; 
        stringstream stream(linea);
        while(getline(stream, dato, ','))
        {
            arreglo[i] = dato;
            i++;
        }
        Designacion desig = Designacion(std::stoi(arreglo[0]), arreglo[1], arreglo[2], arreglo[3], std::stoi(arreglo[4]), std::stoi(arreglo[5]));*/
        linea2 = (char *)linea.c_str();
        dato = strtok(linea2, ",");
        anio = atoi(dato);
        dato = strtok(linea2, ",");
        cargo = std::string(dato);
        dato = strtok(linea2, ",");
        instancia = std::string(dato);
        dato = strtok(linea2, ",");
        materia = std::string(dato);
        dato = strtok(linea2, ",");
        varones = atoi(dato);
        dato = strtok(linea2, ",");
        mujeres = atoi(dato);
        Designacion desig = Designacion(anio, cargo, instancia, materia, varones, mujeres);
        lista.insertar(desig);
    }
}