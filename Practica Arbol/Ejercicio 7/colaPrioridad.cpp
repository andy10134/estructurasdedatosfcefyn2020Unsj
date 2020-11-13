#include <iostream>;

using namespace std;


class colaPrioridad
{
private:
    int *items;
    int maximo;
public:
    colaPrioridad(int cantidad);
    void suprimir();
    void insertar(int elemento);
};

colaPrioridad::colaPrioridad(int cantidad)
{
    maximo = cantidad;
    items = new int[cantidad];
    items[0] = 0;
}

void colaPrioridad::suprimir()
{
    if (items[0] > 0)
    {

    }else
    {
        cout << "El arbol esta vacio"  << endl;
    }    
}

void colaPrioridad::insertar(int elemento){
     if(items[0] < maximo)
    {
        int i= items[0];
        items[i] = elemento;
        while(i!=1 && items[i/2] > elemento)
        {
            int aux;
            aux = items[i/2];
            items[i/2] = elemento;
            items[i] = aux;
            i = i/2;
        }
        items[0]++;
    }
}
