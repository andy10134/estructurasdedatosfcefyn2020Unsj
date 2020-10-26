#ifndef Celda_h 
#define Celda_h
#include <iostream>
#include <stdlib.h>
using namespace std;

class Celda{
private:     //a partir de aquí todos los miembros serán privados
    int frec;
    string etiqueta;
    Celda *sig, *izq, *der;

public:      //a patir de aquí todas las declaraciones serán de acceso público
  int obtenerItem(void);
  void cargaItem(string etiqueta, int frecuencia, Celda *izq = NULL, Celda *der = NULL);
  void cargaSig(Celda* xtope);
  Celda* obtenerSig(void);
  //nodo
  Celda *obtenerIzquierda(void);
  void cargarIzquierda(Celda *izq);
  Celda *obtenerDerecha(void);
  void cargarDerecha(Celda *der);
  void cargarEtiqueta(string etiqueta);
  string obtenerEtiqueta(void);
};
#endif