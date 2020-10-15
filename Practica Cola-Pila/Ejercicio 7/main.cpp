#include <iostream>
#include "ColaEnlazada.cpp"
#include <cstdlib>

using namespace std;


int main()
{
    int frecCliente, atencionCaj, tiempoEspera = 0, cajero = 0, max = 0, reloj = 0, TMS = 90;
    ColaEnlazada cola = ColaEnlazada(0,0,0);
    cout<<"Ingrese tiempo de atencion de cajero"<<endl;
    cin>>atencionCaj;
    cout<<"Ingrese frecuencia de llegada de los clientes"<<endl;
    cin>>frecCliente;
    while (reloj < TMS)
    {
        float random = (float) (rand()%11);
        random = random/10;
        float division = (float) 1/frecCliente;
        if ( random == division)
        {
            cola.insertar(reloj);
        }
        if(cajero == 0)
        {
            if (! cola.vacia())
            {
                tiempoEspera = cola.suprimir();
                tiempoEspera = reloj - tiempoEspera;
                if (tiempoEspera > max)
                {
                    max = tiempoEspera;
                }
                cajero = atencionCaj;
            }
            
        }
        reloj++;
        if (cajero > 0)
        {
            cajero --;
        }
        
    }
    cout<<"Tiempo de espera max: "<<max<<endl;
        
}
