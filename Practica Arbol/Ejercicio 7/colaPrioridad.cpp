#include <iostream>

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
    void mostrar();
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
        items[1] = items[items[0]];
        items[0]--;

        int i = 1;
        int aux;
        while (items[i] > items[i*2] && i*2 < items[0])
        {       
            if (items[0] >= i*2+1)
            {
                if(items[i*2] < items[i*2+1])
                {
                    aux = items[i*2];
                    items[i*2] = items[i];
                    items[i] = aux; 
                    i = i*2;
                }else
                {
                aux = items[i*2+1];
                items[i*2+1] = items[i];
                items[i] = aux; 
                i = i*2+1;
                }
            }else
            {
                aux = items[i*2];
                items[i*2] = items[i];
                items[i] = aux; 
            }
            
        }
        
    }else
    {
        cout << "El arbol esta vacio"  << endl;
    }    
}

void colaPrioridad::insertar(int elemento){
    if(items[0] < maximo)
    {
        items[0]++;
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
    }
}

void colaPrioridad::mostrar(){
    int i;
    for (i = 1; i <= items[0]; i++)
    {
        cout<<items[i]<<endl;
    }
}