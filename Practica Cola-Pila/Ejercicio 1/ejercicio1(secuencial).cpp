#include <stdio.h>
#include<iostream>
using namespace std;

class Pila{
	int* items;
	int tope;
	int cant;
	public:
		Pila(int xcant=0):
		cant(xcant){
			tope=-1;
			items=new int[cant];
		}
		
		int vacia(void)
		{ 	return (tope==-1);
		}
		
		int insertar(int x)
		{	if (tope<cant-1)
			{	items[++tope]=x;
				return (x);
			}
			else return (0);
		}
		
		int suprimir(void)
		{ 	int x;
			if (vacia())
			{	printf("%s","Pila vacia");
				return(0);
			}
			else
			{ 	x=items[tope--];
				return(x);
			}
		}
		
		void mostrar(void)
		{ 	int i;
			if (!vacia())
			{ 	for (i=tope; i>=0; i--)
				{ 	cout<<items[i]<<endl;
				}
			}
		}
};


main(){
	cout<<"holi"<<"\n";
	Pila p1(3);
	p1.insertar(1);
	p1.insertar(2);
	p1.insertar(3);
	p1.mostrar();
}
