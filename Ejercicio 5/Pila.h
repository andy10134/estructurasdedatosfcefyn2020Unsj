#ifndef PILA_H 
#define PILA_H
#include "Celda.h"

using namespace std;

class Pila{
	int cant;
	Celda *tope;
	
	public:
        Pila(Celda* xtope, int xcant); // Constructor
		int vacia(void);
		int insertar(int x);
		int suprimir(void);
		void mostrar(void);
};
#endif