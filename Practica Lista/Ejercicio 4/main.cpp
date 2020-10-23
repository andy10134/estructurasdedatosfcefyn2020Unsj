#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include "designacion.cpp"
#include "ListaEnlazada.cpp"
using namespace std;

void contarMujeres(ListaEnlazada lista);


main()
{
    ifstream archivo; 
    string linea, arreglo[5], dato;
    int i;
    ListaEnlazada lista = ListaEnlazada(0);
    archivo.open("estadistica-designacion-magistrados-federal-nacional-por-genero-20190913.csv", ios::in);
    getline(archivo,linea); // lee la primera fila con los nombres
    while (getline(archivo,linea))
    {
        i = 0; 
        stringstream stream(linea);
        while(getline(stream, dato, ','))
        {
            arreglo[i] = dato;
            i++;
        }
        Designacion desig = Designacion(stoi(arreglo[0]), arreglo[1], arreglo[2], arreglo[3], stoi(arreglo[4]), stoi(arreglo[5]));
        /*linea2 = (char *)linea.c_str();
        dato = strtok(linea2, ",");
        anio = atoi(dato);
        dato = strtok(linea2, ",");
        cargo = std::string(dato);
        dato = strtok(linea2, ",");
        instancia = std::string(dato);
        cout << instancia << endl;
        dato = strtok(linea2, ",");
        materia = std::string(dato);
        dato = strtok(linea2, ",");
        varones = atoi(dato);
        dato = strtok(linea2, ",");
        mujeres = atoi(dato);
        Designacion desig = Designacion(anio, cargo, instancia, materia, varones, mujeres);*/
        lista.insertar(desig);
    }

   contarMujeres(lista);
}

/*Leer un tipo de cargo por teclado, y mostrar la cantidad de mujeres designadas en ese cargo por año. */
void contarMujeres(ListaEnlazada lista)
{
    string cargo;
    Designacion aux;
    int i = 1, anio = 0, cantMujeres = 0;
    cout << "Ingrese el tipo de cargo" << endl;
    cin >> cargo;
    aux = lista.recuperar(i);
    anio = aux.getAnio();

    while (aux.getAnio())
    {   
        if(anio != aux.getAnio())
        {
            cout << "La cantidad de Mujeres designadas en ese cargo en el anio " << anio << " fueron de " << cantMujeres << endl;
            anio = aux.getAnio();
            cantMujeres = 0;
        }
        if(aux.getCargo() == cargo)
        {
            cantMujeres += aux.getCantMujeres();
        }
        i++;
        aux = lista.recuperar(i);
    }
    
}