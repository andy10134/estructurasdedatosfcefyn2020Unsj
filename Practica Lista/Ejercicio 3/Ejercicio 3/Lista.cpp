#include "Lista.h"
#include "Celda.h"
#include <iostream>
#include <iomanip>

#include <string>

using namespace std;

Lista::Lista()
{
	this->cabeza = NULL;
	this->cant = 0;
}

/*int Lista::insertar(int x, int p)                //Insertar por posicion
{
	if ( p > 0 && p <= cant+1)
	{
		Celda *aux;
		aux = new (Celda);
		aux->cargaItem(x);
		if (this->cabeza == NULL)
		{
			aux->cargaSig(NULL);
			this->cabeza = aux;
		}
		else
		{
			int contador = 2;
			Celda *ant = this->cabeza;
			Celda *sig = ant->obtenerSig();
			
			while(contador != p && sig != NULL)
			{
				ant = sig;
				sig = ant->obtenerSig();
				contador++;
			}
			aux->cargaSig(sig);
			ant->cargaSig(aux);
		}
		this->cant++;
		return 1;
	}
	else
	{
		cout << "Posicion no valida" << endl;
		return 0;
	}
}*/

int Lista::insertar(float x,string d)
{
	Celda *aux;
	aux = new (Celda);
	aux->cargaItem(x, d);
	if (this->cabeza == NULL)
	{
		aux->cargaSig(NULL);
		this->cabeza = aux;
	}
	else
	{
		if (this->cabeza->obtenerItem() < x)
		{
			aux->cargaSig(this->cabeza);
			this->cabeza = aux;
		}
		else
		{
			Celda *ant = this->cabeza;
			Celda *sig = ant->obtenerSig();
		
			while(sig != NULL && sig->obtenerItem() > x)
			{
				ant = sig;
				sig = ant->obtenerSig();
			}
			aux->cargaSig(sig);
			ant->cargaSig(aux);
		}
		
	}
	this->cant++;
	return 1;
}

int Lista::suprimir(int p)
{
	if(!this->vacia())
	{
		if ( p > 0 && p < cant+1)
		{
			int devolver;
			if (p == 1)
			{
				Celda *aux = this->cabeza->obtenerSig();
				devolver = this->cabeza->obtenerItem();
				delete(this->cabeza);
				this->cabeza = aux;
			
			}
			else
			{
				int contador = 2;
				Celda *ant = this->cabeza;
				Celda *sig = ant->obtenerSig();
			
				while(contador != p && sig != NULL)
				{
					ant = sig;
					sig = ant->obtenerSig();
					contador++;
				}
				devolver = sig->obtenerItem();
				ant->cargaSig(sig->obtenerSig());
				delete(sig);
			}
			this->cant--;
			return devolver;	
		}
		else
		{
			cout << "Posicion no valida" << endl;
			return 0;
		}
	}
}


int Lista::recuperar(int posicion)
{
	if(!this->vacia())
	{
    	if (posicion > 0 && posicion < this -> cant +1)
    	{
        	Celda *aux;
        	int cont=1;
        	aux = this -> cabeza;
    	    while (cont != posicion)
        	{ 
            	cont++;
            	aux = aux->obtenerSig();
        	}
        	return(aux->obtenerItem());
    	}
    	else
		{
        	cout<<"POSICION INVALIDA"<<endl;
        	return 0;
    	}
	}
}


int Lista::buscar(float x)
{
    Celda *aux;
    int cont=1;
    aux = this -> cabeza;
    while (aux!=NULL && aux->obtenerItem() != x)
    { 
        cont++;
        aux = aux->obtenerSig();
    }
    if(aux == NULL)
    {
        cout<<"No se encontro el elemento en la lista"<<endl;
        return 0;
    }
    else
    {
        cout<<"Se encontro el elemento en la posicion "<<cont<<" de la lista"<<endl;
        return(cont);
    }
    
}


int Lista::vacia(void)
{
	if(cant==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Lista::primerElemento(void)
{
	if (!this->vacia())
	{
		return this->cabeza->obtenerItem();
	}
	else
	{
		return 0;
	}
}

int Lista::ultimoElemento(void)
{
	if (!this->vacia())
	{
		Celda *aux = this->cabeza;
		Celda *sig = aux->obtenerSig();
		while(sig !=NULL)
		{
			aux = sig;
			sig = sig->obtenerSig();
		}
		return (aux->obtenerItem());
	}
	else
	{
		return 0;
	}
}

int Lista::siguiente(int p)
{
	if (p < cant && p > 0)
	{
		return(p++);
	}
	else
	{
		return 0;
	}
}

int Lista::anterior(int p)
{
	if (p > 1 && p < cant+1)
	{
		return(p--);
	}
     else
	 {
     	return 0;
	 }
}


void Lista::mostrar(void)
{
	Celda *aux = this->cabeza;
	cout << setw(20) << "Provincia" << setw(30)<< "   Superficie Afectada\n" <<endl;
	while (aux != NULL)
	{
		cout << setw(20) << aux->obtenerNombre() << setw(24) << aux->obtenerItem() <<endl;
		aux=aux->obtenerSig();
	}
} 
