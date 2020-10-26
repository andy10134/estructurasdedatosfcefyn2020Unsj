#include <iostream>
#include <fstream>
#include <sstream>
#include "Lista.h"

using namespace std;

main()
{
Lista lista = Lista();
ifstream archivo; 
string linea, provincia;
int i=-2, j=0, a;
float sumatoria=0, num;
string A[200][15];
archivo.open("forestales.csv", ios::in);
while (getline(archivo, linea))
{
    string columna;
    stringstream strstr(linea); // Convierte a string la linea obtenida
    i++;
    if (i != -1)
    {
        while (getline(strstr, columna, ';'))
        {
            A[i][j] = columna; 
            j++;
        }
    }
    j = 0;
}
i++;
provincia=A[0][3];
for (a=0; a<i; a++)
{
	if ( provincia == A[a][3] )
	{
		stringstream floatValue(A[a][6]);
		num = 0;
		floatValue >> num;
		sumatoria += num;
	}
	else
	{
		lista.insertar(sumatoria, provincia);
		sumatoria = 0;
		stringstream floatValue(A[a][6]);
		num = 0;
		floatValue >> num;
		sumatoria += num;
		provincia = A[a][3];
	}
}
printf("Lista de mayor a menor de las provincias, con respecto a su superficie afectada:\n\n");
lista.mostrar();
}
