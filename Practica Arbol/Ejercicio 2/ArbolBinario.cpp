#include "Nodo.cpp"

class ArbolBinarioB
{
private:
    Nodo *raiz;
public:
    ArbolBinarioB();
    void insertar(int element, Nodo **raizS);  //resuelto
    void suprimir(int elemento, Nodo **raizS);
    Nodo *buscar(int elemento, Nodo **raizS);  //resuelto
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

void ArbolBinarioB::suprimir(int elemento, Nodo **raizS)
{
    if(raiz != NULL)
    {
        Nodo *ant, aux;
    }else
    {
        cout << "Arbol vacio" << endl;
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