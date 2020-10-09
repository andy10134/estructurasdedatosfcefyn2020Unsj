#include <iostream>
#include "Pila.h"
#include "Pila.cpp"
#include "Lugar.h"
#include "Lugar.cpp"

using namespace std;

//Relacionar matriz
void relacionar(int x[8][8] ,int lugar, int lugar2)
{
	x[lugar][lugar2] = 1; 
	x[lugar2][lugar] = 1;
}

//Mostrar matriz
void mostrar(int x[8][8],string p[])
{
	int i, j;

	cout << endl;

	for ( i = 0; i < 8; i++)
	{
		cout << "    |";
		for ( j = 0; j < 8; j++)
		{
			cout << " " << x[i][j];
		}
		cout << " | " << p[i] << endl;
	}
}

//Iniciar matriz
void inicializar(int x[8][8], string p[])
{
	int i, j;

	cout << endl;

	p[0] = "Cordoba";
	p[1] = "Villa Maria";
	p[2] = "Rosario";
	p[3] = "San Pedro";
	p[4] = "Buenos Aires";
	p[5] = "Bahia Blanca";
	p[6] = "San Luis";
	p[7] = "Mendoza";

	for ( i = 0; i < 8; i++)
	{
		for ( j = 0; j < 8; j++)
		{
			x[i][j]=0;
		}
	}

	relacionar(x, 1-1, 2-1);
	relacionar(x, 2-1, 3-1);
	relacionar(x, 2-1, 7-1);
	relacionar(x, 3-1, 4-1);
	relacionar(x, 4-1, 5-1);
	relacionar(x, 5-1, 7-1);
	relacionar(x, 5-1, 6-1);
	relacionar(x, 6-1, 7-1);
	relacionar(x, 7-1, 8-1);

	cout << endl;

	mostrar(x, p);
}

//Recorrer mapa
void recorrer(int x[8][8], string p[], Pila p1, int origen, int destino)
{
	int aux = origen;
	aux--;
	
	p1.insertar(aux);

	while (aux != (destino - 1) )
	{
		cout << endl << "----Se encuentra en " << p[aux] << endl;
		cout << endl << "----Puede ir a: " << endl;

		for (size_t i = 0; i < 8; i++)
		{
			if(x[aux][i])
			{
				cout << i+1 << " - " << p[i] << endl;
			}
		}

		cin >> aux;
		aux--;
		p1.insertar(aux);		
	}
	
	//Mostrar recorrido
	cout << endl << "----Recorrido de vuelta----" << endl;

	while(!p1.vacia())
	{
		cout << endl << p[p1.suprimir()];
	}

	cout << "< - Origen" << endl;
}

main()
{
	int x[8][8], origen, destino, i, j;
	Pila p1;
	string provincias[8];

	inicializar(x, provincias);

	cout << endl << "Ingrese el Origen 1-8" << endl;
	cin >> origen;
	cout << "Ingrese el Destino 1-8" << endl;
	cin >> destino;

	recorrer(x, provincias, p1, origen, destino);
}
