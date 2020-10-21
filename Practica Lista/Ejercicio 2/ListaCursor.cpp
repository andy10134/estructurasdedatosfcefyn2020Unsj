#include "ListaCursor.h"
#include "Celda.cpp"
#include <iostream>

using namespace std;

//Constructor
ListaCursor::ListaCursor(int cant)
{
    this -> items = new Celda[cant]; //aca deberia ser cabeza(guarda el primer elemento), cantidad de elementos y el arreglo con las celdas
    this -> cabeza = 0;
    this -> cant = 0;
    this -> maximaCant = cant;
}

int ListaCursor::vacia(void)
{
    return( this -> cant == 0);
}

int ListaCursor::insertar(int elemento, int posicion)
{
    if (posicion > 0 && posicion <= this -> cant +1 && this -> cant +1 <= this -> maximaCant)
    {
        if( this -> vacia() )
        {
            this -> items[0].cargaItem(elemento);
            this -> items[0].cargaSig(-1); 


        }else if( posicion ==1 )
        {
            int i = 0;
            while ( i < this -> maximaCant && this -> items[i].obtenerSig() != -2 )
            {
                i++;
            }
            this -> items[i].cargaSig( this -> cabeza );
            this -> items[i].cargaItem(elemento);
            this -> cabeza = i;
        
        }
        else
        {

            int cont=1;
            int i, aux, anterior;
            
            aux = this -> cabeza;
            while( cont < posicion )
            {
                anterior = aux;
                aux = this -> items[ aux ].obtenerSig();
                cont++;
            }

            i = 0;
            while ( i < this -> maximaCant && this -> items[i].obtenerSig() != -2 )
            {
                i++;
            }

            this -> items[i].cargaSig(aux);
            this -> items[i].cargaItem(elemento);
            this -> items[ anterior ].cargaSig(i);
        
        }
        
        this -> cant++;
        return(elemento);

    }else
    {
        cout<<"POSICION INVALIDA"<<endl;
        return(0);
    }
}

int ListaCursor::suprimir(int posicion)
{
    int cont = 1, aux, elemento;

    if( this -> vacia())
    {
        cout << "Arreglo vacio Imposible borrar datos" << endl;
    }else if (posicion > 0 && posicion <= this -> cant )
    {
        if (posicion == 1)
        {
            elemento = this -> items[ aux ].obtenerItem();
			aux = this -> items[ this -> cabeza ].obtenerSig();
            this -> items[ this -> cabeza ].cargaSig(-2);
            this -> cabeza = aux;
        }else
        {
            int aux, anterior;
            
            while( posicion > cont )
            {
                aux = anterior;
                aux = this -> items[aux].obtenerSig();
                cont++;
            }
			elemento = this -> items[ aux ].obtenerItem();
            this -> items[ anterior ].cargaSig( this -> items[ aux ].obtenerSig() );
            this -> items[ aux ].cargaSig(-2);
        }
		this -> cant--;
		return(elemento);
    }else
    {
        cout << "Posicion no valida" << endl;
    }
    
    return(0);
}

void ListaCursor::mostrar(void)
{
    int aux, cant = 0;
    aux = this -> cabeza;

    while ( aux != -1 )
    {
        cout << this -> items[ aux ].obtenerItem() << " - Posicion: " << cant+1 << endl;
        aux = this -> items[ aux ].obtenerSig();
        cant++;
    }
    
}


int ListaCursor::primerElemento(void)
{
	if(!vacia())
	{
		return(this-> items[cabeza].obtenerItem());
	}
	else
	{
		cout<<"lista vacia"<<endl;
		return(0);
	}
}


int ListaCursor::ultimoElemento(void)
{
	if(!vacia())
	{
		int aux, anterior;
		aux = this -> cabeza;
		while(aux != -1)
		{
			anterior = aux;
			aux = this -> items[aux].obtenerSig();
		}
		return(this -> items[anterior].obtenerItem());
	}
	else
	{
		cout<<"Lista Vacia"<<endl;
		return(0);
	}
}


int ListaCursor::recuperar(int posicion)
{
	if(!vacia())
	{
		if(posicion > 0 && posicion <= this -> cant+1)
		{
			int cont = 1;
			int aux;
			aux = this -> cabeza;
			while(cont != posicion)
			{
				aux = this -> items[aux].obtenerSig();
				cont ++;
			}
			return(this -> items[aux].obtenerItem());
		}
		else
		{
			cout<<"posicion invalida"<<endl;
		}
	}
	else
	{
		cout<<"Lista Vacia"<<endl;
	}
	return(0);
}


int ListaCursor::buscar(int elemento)
{
	if(!vacia())
	{
		int cont = 1;
		int aux, anterior;
		aux = this -> cabeza;
		while(this -> items[aux].obtenerItem() != elemento && aux != -1)
		{
			aux = this -> items[aux].obtenerSig();
			cont ++;
		}
		if(aux != 1)
		{
			return(cont);
		}
		else
		{
			cout<<"no se encontro el elemento"<<endl;
			return(-1);
		}
	}
	else
	{
		cout<<"Lista Vacia"<<endl;
	}
	return(0);
}


int ListaCursor::siguiente(int posicion)
{
	if(!vacia())
	{
		if(posicion > 0 && posicion <= this -> cant+1)
		{
			int cont = 1;
			int aux, anterior;
			aux = this -> cabeza;
			while(cont != posicion)
			{
				anterior = aux;
				aux = this -> items[aux].obtenerSig();
				cont ++;
			}
			return(this -> items[aux].obtenerSig());
		}
		else
		{
			cout<<"posicion invalida"<<endl;
		}
	}
	else
	{
		cout<<"Lista Vacia";
	}
	return(-1);
}

int ListaCursor::anterior(int posicion)
{
	if(!vacia())
	{
		if(posicion > 1 && posicion <= this -> cant+1)
		{
			int cont = 1;
			int aux, anterior;
			aux = this -> cabeza;
			while(cont != posicion)
			{
				anterior = aux;
				aux = this -> items[aux].obtenerSig();
				cont ++;
			}
			return(anterior);
		}
		else
		{
			cout<<"posicion invalida"<<endl;
		}
	}
	else
	{
		cout<<"Lista Vacia";
	}
	return(-1);
}