#include <iostream>
#include "Pila.h"

using namespace std;

main(){
	cout  <<  "holi"<<  "\n";
	Pila p1(NULL, 0);
	p1.insertar(1);
	p1.insertar(2);
	p1.insertar(3);
	p1.mostrar();
	//p1.suprimir();
	//p1.mostrar();
}
