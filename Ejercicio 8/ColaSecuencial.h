#ifndef ColaSecuencial_h 
#define ColaSecuencial_h
#include <stdlib.h>

class ColaSecuencial{
private:     //a partir de aquí todos los miembros serán privados
    int *items;
    int max;
    int pr;
    int ul;
    int cant;
    int medico;
    int tiempo;
    int cola;

public:      //a patir de aquí todas las declaraciones serán de acceso público
  ColaSecuencial(int cant); // Constructor
  int vacia(void);
  int insertar(int elemento);
  int suprimir(void);
  void recorrer(void);
  int getMedico(void);
  void setMedico(void);
  void decrementarMedico(void);
  int getTiempo(void);
  void setTiempo(int x);
  void obtenerPromedio(int i);
};
#endif