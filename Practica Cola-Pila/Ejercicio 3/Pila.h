//Definición de la clase persona -> archivo "Persona.h"
//siempre es buena idea usar macros del preprocesador para evitar compilar varias veces el mismo archivo
#ifndef Pila_h 
#define Pila_h
#include <stdlib.h>

class Pila{
private:     //a partir de aquí todos los miembros serán privados
//los datos miembro pueden ser cualquier tipo de dato, incluso otras clases como string
    int *items;
    int tope1;
    int tope2;
    int cant;

public:      //a patir de aquí todas las declaraciones serán de acceso público
  Pila(int cant); // Constructor
  int insertar1(int elemento);
  int insertar2(int elemento);
  int suprimir1(void);
  int suprimir2(void);
  void mostrar1(void);
  void mostrar2(void);
  int vacia1(void);
  int vacia2(void);
};
#endif