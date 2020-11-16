#include "Nodo.cpp"

class ArbolBinarioB
{
private:
    Nodo *raiz;
public:
    ArbolBinarioB();
    void insertar(int element, Nodo **raizS);  //resuelto
    void suprimir(Nodo **raizS, int elemento);
    Nodo *buscar(int elemento,Nodo **raizS);  //resuelto
    int nivel(int elemento, Nodo **raizS, bool *bandera);  //resuelto
    bool hoja(int elemento, Nodo **raizS); //resuelto
    bool hijo(int elemento, int elemento2, Nodo **raizS); //resuelto
    bool padre(int elemento, int elemento2, Nodo **raizS); //resuelto
    void camino(int elemento, Nodo *ancestro, bool &bandera,int *arreglo, int &cont);
    int altura(Nodo **raizS, int altura);
    void InOrden(Nodo **raizS);  //resuelto
    void PreOrden(Nodo **raiz);  //resuelto
    void PostOrden(Nodo **raiz);  //resuelto
    void getRaiz(Nodo **&x); //resuelto
};

ArbolBinarioB::ArbolBinarioB()
{
    raiz = NULL;
}

void ArbolBinarioB::getRaiz(Nodo **&x)
{
    x = &raiz;
}

void ArbolBinarioB::suprimir(Nodo **raizL, int x)
{
	Nodo **raizS = raizL;
	if (*raizS != NULL)
	{
		int izqder;
		Nodo *padre, *hijo;
		padre=NULL;
		hijo=*raizS;
		while(hijo->obtenerItem() != x && hijo != NULL)
		{
			padre=hijo;
			if(hijo->obtenerItem() < x)
			{
				hijo->obtenerDerecha(raizS);
				izqder=1;
			}else
			{
				hijo->obtenerIzquierda(raizS);
				izqder=0;
			}
			hijo=*raizS;
		}
		if (hijo != NULL)
		{
			switch(hijo->obtenerGrado())
			{
				case 0:
					if(hijo == *raizL)
					{
						*raizL = NULL;
					}else{
						if(izqder == 1)
						{
							padre->cargarDerecha(NULL);
						}else{
							padre->cargarIzquierda(NULL);
						}	
					}
					delete(hijo);
					break;
				
				case 1:
					hijo->obtenerDerecha(raizS);
					if(*raizS==NULL)
					{
						hijo->obtenerIzquierda(raizS);
					}
					if(hijo == *raizL)
					{
						*raizL = *raizS;
					}else{
						if(izqder == 1)
						{
							padre->cargarDerecha(*raizS);
						}else{
							padre->cargarIzquierda(*raizS);
						}
					}
					delete(hijo);
					break;
					
				case 2:
					
					Nodo *nuevo = hijo;
					Nodo *nodo;
					int izd=0;
			        nuevo -> obtenerIzquierda(raizS);
    			    while (*raizS != NULL)
    			    {
    			    	izd++;
    			    	nodo = nuevo;
        			    nuevo = *raizS;
        			    nuevo -> obtenerDerecha(raizS);
       				}
       				nuevo->obtenerIzquierda(raizS);
        			
       				if(izd < 2)
       				{
       					nodo -> cargarIzquierda(*raizS);
					}else{
						nodo -> cargarDerecha(*raizS);
					}
        			
        			
        			
        			hijo->obtenerDerecha(raizS);
        			nuevo ->cargarDerecha(*raizS);
        			hijo->obtenerIzquierda(raizS);
        			nuevo->cargarIzquierda(*raizS);

					if(hijo == *raizL)
					{
						*raizL = nuevo;
					}else{
						if(izqder == 1)
						{
							padre->cargarDerecha(nuevo);
						}else{
							padre->cargarIzquierda(nuevo);
						}
					}
					delete(hijo);
					break;
			}
		}
	}
}
void ArbolBinarioB::insertar(int elemento, Nodo **raizS)
{

    if (*raizS == NULL)
    {
        Nodo * aux;
        aux = new (Nodo);
        aux -> cargarIzquierda(NULL);
        aux -> cargarDerecha(NULL);
        aux -> cargaItem(elemento);
        *raizS = aux;
    }else
    {
            Nodo *a = *raizS;
        if (elemento > a -> obtenerItem())
        {
                a -> obtenerDerecha(raizS);
            insertar(elemento, raizS);
        }else
        {
                a -> obtenerIzquierda(raizS);
            insertar(elemento, raizS);
        }
    }
}


Nodo* ArbolBinarioB::buscar(int elemento, Nodo **raizS)
{
    if (*raizS != NULL)
    {
        Nodo *a = *raizS;
        if (elemento != a->obtenerItem())
        {
            if (a->obtenerItem() < elemento)
            {
                a->obtenerDerecha(raizS);
            }
            else
            {
                a->obtenerIzquierda(raizS);
            }
            return(buscar(elemento, raizS));
        }
        else
        {
            return(a);
        }
    }
}

int ArbolBinarioB::nivel(int elemento, Nodo **raizS,bool *bandera){
    if (*raizS != NULL)
    {
        Nodo *a = *raizS;
        if (elemento != a->obtenerItem())
        {
            
            if (a->obtenerItem() < elemento)
            {
                a->obtenerDerecha(raizS);
            }
            else
            {
                a->obtenerIzquierda(raizS);
            }
            return(1 + nivel(elemento, raizS, bandera));
        }
        else
        {
            return(1);
        }
    }
    else
    {
        *bandera = false;
        return(0);
    }
    
}

bool ArbolBinarioB::hoja(int elemento, Nodo **raizS){
    Nodo* nodo = buscar(elemento, raizS);
    if(nodo != NULL){
        if(nodo->obtenerGrado() == 0){
            return(true);
        }
        return(false);
    }
    else
    {
        cout<<"no se encontro el nodo"<<endl;
    }
}

bool ArbolBinarioB::hijo(int elemento, int padre, Nodo **raizS){
    Nodo* nodo = buscar(padre, raizS);
    if(nodo != NULL){
        Nodo** aux;
        nodo->obtenerDerecha(aux);
        Nodo* hijo = *aux;
        if(hijo->obtenerItem() == elemento){
            return(true);
        }
        nodo->obtenerIzquierda(aux);
        hijo = *aux;
        if(hijo->obtenerItem() == elemento){
            return(true);
        }
        else
        {
            return(false);
        }
    }
    else
    {
        cout<<"no se encontro el nodo"<<endl;
    }
}

bool ArbolBinarioB::padre(int elemento, int padre, Nodo **raizS){
    Nodo* nodo = buscar(padre, raizS);
    if(nodo != NULL){
        Nodo** aux;
        nodo->obtenerDerecha(aux);
        Nodo* hijo = *aux;
        if(hijo->obtenerItem() == elemento){
            return(true);
        }
        nodo->obtenerIzquierda(aux);
        hijo = *aux;
        if(hijo->obtenerItem() == elemento){
            return(true);
        }
        else
        {
            return(false);
        }
    }
    else
    {
        cout<<"no se encontro el nodo"<<endl;
    }
}

void ArbolBinarioB::camino(int elemento, Nodo* aux, bool &bandera, int *arreglo, int &cont){
    if (aux != NULL)
    {
        arreglo[cont] = aux->obtenerItem();
        Nodo **a;
        if(aux->obtenerItem() != elemento){
            if (aux->obtenerItem() < elemento)
            {
                aux->obtenerDerecha(a);
            }
            else
            {
                aux->obtenerIzquierda(a);
            }
            return(camino(elemento, *a, bandera, arreglo, cont+=1));
        }  
    }
    else
    {
        bandera = false;
    }
}


int ArbolBinarioB::altura(Nodo **raizS, int max){
    if(*raizS != NULL)
    {
        Nodo *a = *raizS;
        Nodo** b;
        getRaiz(b);
        bool bandera= true;
        int n = nivel(a->obtenerItem(), b, &bandera);
        if(n > max){
            max = n;
        }
        a->obtenerIzquierda(raizS);
        altura(raizS, max);
        a->obtenerDerecha(raizS);
        altura(raizS, max);
    }
    else
    {
        return(max);
    }
}

void ArbolBinarioB::InOrden(Nodo **raizS){
    if(*raizS != NULL)
    {
        Nodo *a = *raizS;
        a->obtenerIzquierda(raizS);
        InOrden(raizS);
        cout<<a->obtenerItem()<<endl;
        a->obtenerDerecha(raizS);
        InOrden(raizS);
    }
}

void ArbolBinarioB::PreOrden(Nodo **raizS){
	if(*raizS != NULL)
	{
        Nodo *a = *raizS;
        cout<<a->obtenerItem()<<endl;
        a->obtenerIzquierda(raizS);
        PreOrden(raizS);
        a->obtenerDerecha(raizS);
        PreOrden(raizS);
	}
}

void ArbolBinarioB::PostOrden(Nodo **raizS){
	if(raiz != NULL)
	{
		Nodo *a = *raizS;
        a->obtenerIzquierda(raizS);
        PostOrden(raizS);
        a->obtenerDerecha(raizS);
        PostOrden(raizS);
        cout<<a->obtenerItem()<<endl;
	}
}
/*void ArbolBinarioB::InOrden(Nodo *raiz){
    cout<<"busca"<<endl;
	if(raiz != NULL)
	{
		InOrden(raiz->obtenerIzquierda());
		cout<<raiz->obtenerItem()<<endl;
		InOrden(raiz->obtenerDerecha());
	}
}

void ArbolBinarioB::PreOrden(Nodo *raiz){
	if(raiz != NULL)
	{
		cout<<raiz->obtenerItem()<<endl;
        InOrden(raiz->obtenerIzquierda());
		InOrden(raiz->obtenerDerecha());
	}
}

void ArbolBinarioB::PostOrden(Nodo *raiz){
	if(raiz != NULL)
	{
		InOrden(raiz->obtenerIzquierda());
		InOrden(raiz->obtenerDerecha());
        cout<<raiz->obtenerItem()<<endl;
	}
}*/