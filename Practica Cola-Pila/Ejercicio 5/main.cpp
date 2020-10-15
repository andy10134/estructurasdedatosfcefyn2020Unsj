#include <iostream>
#include "Pila.h"
#include "Pila.cpp"
using namespace std;

//Comienza el juego
void comenzar(Pila *p, int disco)
{
    while (disco >= 1)
    {
        p->insertar(disco);
        disco--;
    }
}

//Reapila la pila
void reapilar(Pila *aux, Pila *p)
{
    while ( !aux->vacia() )
    {
        p->insertar(aux->suprimir());
    }
}

//Cuenta los elementos de una pila
int contarElementos(Pila *p, Pila *aux)
{
    int i = 0;

    while ( !p->vacia() )
    {
    cout << aux->insertar(p->suprimir()) << endl;
    i++;
    }

    reapilar(aux, p);
    return i;
}

//Desarma la pila para mostrarla
void mostrarTorre(Pila *p, Pila *aux)
{
    while ( !p->vacia() )
    {
    cout << aux->insertar(p->suprimir()) << endl;
    }

    reapilar(aux, p);
}

//Juego
void jugar(Pila p1, Pila p2, Pila p3, int discos)
{
    int ultimoDisco = 1;
    int cantidadPila3 = 0;
    int auxiliarTorre;
    int auxiliarTorreD;
    Pila aux;
    Pila *torres[3] = {&p1, &p2, &p3};

    cout << "Bienvenido al sufrimiento en codigo! :)" << endl;
    cout << "Ahora que comience el juego" << endl;

    while ( cantidadPila3 !=  discos)
    {
        auxiliarTorre = 0 ;
        auxiliarTorreD = 0 ;

        cout << "Tienes: " << endl;
        cout << "Pila 1" << endl;
        mostrarTorre(torres[0], &aux);

        cout << "===============================" << endl;
        cout << "Pila 2" << endl;
        mostrarTorre(torres[1], &aux);

        cout << "===============================" << endl;
        cout << "Pila 3" << endl;
        mostrarTorre(torres[2], &aux);

        cout << "===============================" << endl;
        cout << "De que torre a que torre deseas moverte: " << endl;
        cout << "Desde donde: " << endl;
        cin >> auxiliarTorre;

        //Existe la torre?
        if(3 >= auxiliarTorre && 1 <= auxiliarTorre)
        {
            //Esta vacio el origen?
            if(! torres[auxiliarTorre-1]->vacia())
            {
                cout << "Hacia donde: " << endl;
                cin >> auxiliarTorreD;

                //Existe la torre de destino?
                if(3 >= auxiliarTorreD && 1 <= auxiliarTorreD)
                {
                    ultimoDisco = aux.insertar(torres[auxiliarTorre-1]->suprimir());

                    //No esta vacia la torre de destino?
                    if(!torres[auxiliarTorreD-1]->vacia())
                    {
                        if (ultimoDisco < aux.insertar(torres[auxiliarTorreD-1]->suprimir()))
                        {
                            torres[auxiliarTorreD-1] -> insertar(aux.suprimir());
                            torres[auxiliarTorreD-1] -> insertar(aux.suprimir());

                            cantidadPila3 -= (auxiliarTorre == 3) ? (1) : (0);
                            cantidadPila3 += (auxiliarTorreD == 3) ? (1) : (0);
                        }else
                        {
                            torres[auxiliarTorreD-1] -> insertar(aux.suprimir());
                            torres[auxiliarTorre-1] -> insertar(aux.suprimir());
                            cout << "Movimiento no valido pa." << endl;
                        }                       

                    }else //Efectivamente esta vacia
                    {
                        torres[auxiliarTorreD-1] -> insertar(aux.suprimir());
                        cantidadPila3 -= (auxiliarTorre == 3) ? (1) : (0);
                        cantidadPila3 += (auxiliarTorreD == 3) ? (1) : (0);
                    }
                }else
                {
                    cout << "Torre no valida." << endl;
                }
            }else
            {
                cout << "No hay ningun disco en la torre " << auxiliarTorre << endl; 
            }
        }else
        {
            cout << "Torre no valida." << endl;
        }
    }
    cout << "Gg WP BRO gracias por jugar :)" << endl;
}

int main(int argc, char const *argv[])
{
    Pila pila1;
    Pila pila2;
    Pila pila3;
    int discos;

    cout << "Ingrese la cantidad de discos para jugar" << endl;
    cin >> discos;    
    
    comenzar(&pila1, discos);

    jugar(pila1, pila2, pila3, discos);
}
