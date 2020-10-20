#include <iostream>
#include "ListaEnlazada.cpp"

using namespace std;

main(){
    int posicion, elemento;
    ListaEnlazada lista = ListaEnlazada(NULL, 0);
    lista.insertar(2,1);
    lista.insertar(3, 2);
    lista.insertar(1, 1);
    lista.mostrar();
    posicion = lista.buscar(3);
    elemento = lista.suprimir(3);
    cout<<elemento<<endl;
    lista.mostrar();
    cout<<"elemento recuperado de la posicion 1: "<<lista.recuperar(1)<<endl;
}




/*----------------------------------------------------------------------------------------------
public bool insertar (int x, int posicion)        //Inserta POR POSICIÓN
{
if (ultimo < max) {
                                if ((posicion > 0) && (posicion <= ultimo+1)) {
                                        for (int i = ultimo; i > posicion; i--) {
                                                elementos [i] = elementos [i - 1];
                                        }
                                        elementos [posicion] = x;
                                        ultimo++;
                                        return true;
                                } else {
                                        Console.WriteLine ("Posición incorrecta.");
                                        return false;
                                }
                        } else {
                                Console.WriteLine ("Lista llena.");
                                return false;
                        }
                }

void Leer()
{
        ifstream infile; 
        string linea;
        int i=-2, j=0;
        infile.open("Magistrados.csv", ios::in);
        while (getline(infile, linea))
        {
                string columna;
                stringstream strstr(linea); // Convierte a string la linea obtenida
                i++;
                if (i != -1)
                {
                        while (getline(strstr, columna, ','))
                        {
                                A[i][j] = columna; 
                                j++;
                        }
                }
                j = 0;
        }
}*/