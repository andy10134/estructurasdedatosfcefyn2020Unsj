#include <iostream>
#include "grafo.cpp"
#include <cstdlib>
#include <time.h>
using namespace std;

//Relacionar matriz
void relacionar(int x[5][5] ,int nodo, int nodo2)
{
	x[nodo][nodo2] = 1; 
	x[nodo2][nodo] = 1;
}

//Iniciar matriz
void inicializar(int x[5][5], int p[])
{
	int i, j;

	cout << endl;
	//Inicializa el arreglo
	p[0] = 0;
	p[1] = 1;
	p[2] = 2;
	p[3] = 3;
	p[4] = 4;
	p[5] = 5;

	//Cerea la matriz
	for ( i = 0; i < 5; i++)
	{
		for ( j = 0; j < 5; j++)
		{
			x[i][j]=0;
		}
	}

	//LLena la matriz con sus adyancencias
	relacionar(x, , );
	relacionar(x, , );
	relacionar(x, , );
	relacionar(x, , );
	relacionar(x, , );
	relacionar(x, , );
	relacionar(x, , );

	cout << endl;
}

int main(int argc, char const *argv[])
{
    int enlaces[5][5];
	int nodos[5];

	inicializar(enlaces, nodos);
}
