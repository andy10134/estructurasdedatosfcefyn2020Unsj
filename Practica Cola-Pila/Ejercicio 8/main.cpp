#include <iostream>
#include "ColaEnlazada.cpp"
#include "ColaSecuencial.cpp"
#include <cstdlib>

using namespace std;

void derivar(ColaSecuencial colas[4], int reloj)
{
    int op = 0;
    while (op == 0)
    {
        cout<<"INGRESE ESPECIALIDAD (1-Ginecologia, 2- Clinica, 3-Oftalmologia, 4- Pediatria)"<<endl;
        cin>>op;
        switch (op)
        {
        case 1:
            colas[0].insertar(reloj);
            break;
        case 2:
            colas[1].insertar(reloj);
            break;
        case 3:
            colas[2].insertar(reloj);
            break;
        case 4:
            colas[3].insertar(reloj);
            break;
        default:
            cout<<"ingreso mal el numero, ingrese otra vez"<<endl;
            op = 0;
        }
        
    }
}

float random(int i)
{
    float random = (float) (rand()%i);
    return (random);
}

void medicos(ColaSecuencial colas[4], int reloj)
{
    int i, x;
    for(i=0; i<4; i++)
    {
        if (colas[i].getMedico() == 0)
        {
            if (! colas[i].vacia())
            {
                x = colas[i].suprimir();
                x = reloj - x;
                colas[i].setTiempo(x);
                colas[i].setMedico();
            }
        }
        if (colas[i].getMedico() > 0)
        {
            colas[i].decrementarMedico();
        }
         
    }
}

int main(){
    ColaEnlazada turnos = ColaEnlazada(0,0,0);
    ColaSecuencial colas[4] = {ColaSecuencial(10), ColaSecuencial(10), ColaSecuencial(10), ColaSecuencial(10)};
    int secretario = 0, tiempoEspera = 0, cantCola = 0, atendidos = 0, x;
    int TMS = 90, reloj = 0;  //TMS = 240
    while (reloj < TMS)
    {
        if (random(3) <= 1 && reloj < 60)
        {
            turnos.insertar(reloj);
            cantCola ++;
        }
        if (secretario == 0 && reloj < 60)
        {
            if (! turnos.vacia())
            {
                x = turnos.suprimir();
                x = reloj - x;
                tiempoEspera += x;
                atendidos ++;
                secretario = 2;
                derivar(colas, reloj);
            }
        }
        int i;
        medicos(colas, reloj);
        reloj++;
        (secretario > 0)?secretario --:0;
    }
    cout<<"tiempo promedio de espera en la cola de turnos: "<<tiempoEspera/atendidos<<" minutos"<<endl;
    cout<<"Personas que no pudieron obtener turno: "<<cantCola - atendidos<<endl;
    int i;
    for (i = 0; i < 4; i++)
    {
        colas[i].obtenerPromedio(i);
    }
    
} 