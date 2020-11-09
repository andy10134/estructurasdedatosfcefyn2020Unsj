#include "Nodo.cpp"

class ArbolBinarioB
{
private:
    Nodo *raiz;
public:
    ArbolBinarioB();
    void insertar(int element, Nodo **raizS);
    int suprimir(int elemento, Nodo **raizS);
    Nodo *buscar(int elemento);
    int nivel();
    bool hoja(int elemento, int elemento2);
    bool hijo(int elemento, int elemento2);
    bool padre(int elemento);
    int *camino(int inicio, int destino);
    int altura(int elemento);
    void InOrden(Nodo **raizS);
    void PreOrden(Nodo **raiz);
    void PostOrden(Nodo **raiz);
    void getRaiz(Nodo **&x);
};

ArbolBinarioB::ArbolBinarioB()
{
    raiz = NULL;
}

void ArbolBinarioB::getRaiz(Nodo **&x)
{
    x = &raiz;
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
        InOrden(raizS);
        a->obtenerDerecha(raizS);
        InOrden(raizS);
	}
}

void ArbolBinarioB::PostOrden(Nodo **raizS){
	if(raiz != NULL)
	{
		Nodo *a = *raizS;
        a->obtenerIzquierda(raizS);
        InOrden(raizS);
        a->obtenerDerecha(raizS);
        InOrden(raizS);
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