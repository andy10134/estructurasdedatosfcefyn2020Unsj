#ifndef Pila_h 
#define Pila_h
#include "Celda.h"

using namespace std;

class Pila{
	int cant;
	Celda *tope;
	
	public:
        Pila(Celda* xtope=NULL, int xcant=0); // Constructor
		int vacia(void);
		int insertar(int x);
		int suprimir(void);
		void mostrar(void);
};
#endif