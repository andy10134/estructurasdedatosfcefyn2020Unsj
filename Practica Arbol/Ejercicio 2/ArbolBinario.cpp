#include "Nodo.cpp"

class ArbolBinarioB
{
private:
    Nodo *raiz;
public:
    ArbolBinarioB(/* args */);
    int insertar(int element, Nodo *aux);
    int suprimir(int elemento, Nodo *raiz);
    Nodo *buscar(int elemento);
    int nivel();
    bool hoja(int elemento, int elemento2);
    bool hijo(int elemento, int elemento2);
    bool padre(int elemento);
    int *camino(int inicio, int destino);
    int altura(int elemento);
    void InOrden(Nodo *raiz);
    void PreOrden(Nodo *raiz);
    void PostOrden(Nodo *raiz);
    Nodo *getRaiz();
};

ArbolBinarioB::ArbolBinarioB(/* args */)
{
    raiz = NULL;
}

Nodo *ArbolBinarioB::getRaiz()
{
    return(raiz);
}

int ArbolBinarioB::insertar(int elemento, Nodo * raizS )
{
    if (raizS == NULL)
    {
        raizS = new (Nodo);
        raizS -> cargarIzquierda(NULL);
        raizS -> cargarDerecha(NULL);
        raizS -> cargaItem(elemento);

    }else
    {
        if (elemento > raizS -> obtenerItem())
        {
            insertar(elemento, raizS -> obtenerDerecha());
        }else
        {
            insertar(elemento, raizS -> obtenerIzquierda());
        }
    }
}

int ArbolBinarioB::suprimir(int elemento, Nodo *raiz)  //no esta terminado xd
{
    if(raiz != NULL)
    {
	Nodo *aux;
        if(raiz->obtenerItem() == elemento)
        {
            
        }
        else
        {
            if(raiz->obtenerItem() > elemento)
            {
                suprimir(elemento, raiz->obtenerDerecha());
            }
            else
            {
                suprimir(elemento, raiz->obtenerIzquierda());
            }
	    }
    }
    else
    {
        cout<<"no se puede suprimir"<<endl;
	    return(0);
    } 
}

void ArbolBinarioB::InOrden(Nodo *raiz){
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
}