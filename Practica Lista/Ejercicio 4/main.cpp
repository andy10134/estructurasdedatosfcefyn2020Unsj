#include <iostream>
#include <fstream>
#include <string.h>
#include "designacion.cpp"
#include "ListaEnlazada.cpp"
using namespace std;

void contarMujeres(ListaEnlazada lista);


main()
{
    ifstream archivo; 
    string linea, cargo, instancia, materia;
    char* linea2, *dato;
    int anio, varones, mujeres;
    ListaEnlazada lista = ListaEnlazada(0);
    archivo.open("estadistica-designacion-magistrados-federal-nacional-por-genero-20190913.csv", ios::in);
    while (getline(archivo,linea))
    {
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

    lista.mostrar();
}

/*Leer un tipo de cargo por teclado, y mostrar la cantidad de mujeres designadas en ese cargo por año. */
void contarMujeres(ListaEnlazada lista)
{
    string cargo;
    Designacion aux;
    cout << "Ingrese el tipo de cargo" << endl;
    cin >> cargo;
    int i = 0;
    aux = lista.recuperar(i);
    while (aux.getAnio())
    {   
        if(aux.getCargo())
        i++;
        aux = lista.recuperar(i);
    }
    
}