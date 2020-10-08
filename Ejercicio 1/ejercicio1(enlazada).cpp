#include <stdio.h>
#include <iostream>

using namespace std;

class celda{
	int item;
	celda* sig;
	
	public:
		int obtenerItem(void)
		{
			return(item);
		}
		
		void cargaItem(int xitem)
		{
			item = xitem;
		}
		
		void cargarSig(celda* xtope){
			sig = xtope;
		}
		
		celda* obtenerSig(void){
			return(sig);
		}
};

class Pila{
	int cant;
	celda *tope;
	
	public:
		Pila(celda* xtope=NULL, int xcant=0):
			tope(xtope), cant(xcant)
			{}
			
		int vacia(void)
		{
			return(cant == 0);
		}
		
		int insertar(int x)
		{
			celda *ps1;
			ps1=new(celda);
			ps1->cargaItem(x);
			ps1->cargarSig(tope);
			tope=ps1;
			cant++;
			return(ps1->obtenerItem());
		}
		
		int suprimir(void)
		{
			celda *aux;
			int x;
			if(vacia())
			{
				cout<<"Pila vacia"<<"\n";
				return(0);
			}
			else
			{
				aux=tope;
				x = tope->obtenerItem();
				tope = tope->obtenerSig();
				cant--;
				delete(aux);
				return(x);
			}
		}
		
		void mostrar(void)
		{ 	
			celda *aux;
			if (!vacia())
			{ 	aux= tope;
				while(aux != NULL)
				{ 	cout<<aux->obtenerItem()<<endl;
					aux = aux->obtenerSig();
				}
			}
		}
};

main(){
	cout<<"holi"<<"\n";
	Pila p1 = Pila();
	p1.insertar(1);
	p1.insertar(2);
	p1.insertar(3);
	p1.mostrar();
	//p1.suprimir();
	//p1.mostrar();
}
