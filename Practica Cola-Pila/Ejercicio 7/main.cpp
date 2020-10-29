#include <iostream>
#include "ColaEnlazada.cpp"
#include <cstdlib>
#include <time.h>

using namespace std;


int main()
{
    int frecCliente = 2, atencionCaj = 5, tiempoEspera = 0, cajero = 0, max = 0, reloj = 0, TMS = 90;
    ColaEnlazada cola = ColaEnlazada(0,0,0);
    /*cout<<"Ingrese tiempo de atencion de cajero"<<endl;
    cin>>atencionCaj;
    cout<<"Ingrese frecuencia de llegada de los clientes"<<endl;
    cin>>frecCliente;*/
    srand(time(NULL));
    while (reloj < TMS)
    {
        /*float random = (float) (rand()%11);
        random = random/10;
        float division = (float) 1/frecCliente;*/
        int random = rand()%5;
        int division = 1;
        if ( random == division) //probabilidad de que llegue alguien a la cola
        {
            cola.insertar(reloj);
            cout<<"entro alguien a la cola"<<endl;
        }
        if(cajero == 0)
        {
            if (! cola.vacia())
            {
                tiempoEspera = cola.suprimir();
                tiempoEspera = reloj - tiempoEspera; //calcula cuanto tiempo espero el chabon en la cola
                if (tiempoEspera > max)
                {
                    max = tiempoEspera; //se guarda el max de tiempo de espera
                }
                cajero = atencionCaj; //iniciar cajero en 5
                cout<<"el cajero atendio a alguien"<<endl;
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
