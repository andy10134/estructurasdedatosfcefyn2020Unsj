#include <iostream>
#include "grafo.cpp"
#include <cstdlib>
#include <time.h>
using namespace std;

int main(int argc, char const *argv[])
{
    Grafo grafo = Grafo(5);
	string nodos[5] = {"a", "b", "c", "d", "e"};
	grafo.carganodos(nodos);
	grafo.relacionar("a", "b");
	grafo.relacionar("e", "c");
	grafo.relacionar("b", "d");
	grafo.relacionar("a", "c");
	grafo.relacionar("d", "e");
	grafo.adyacentes("a");
}
