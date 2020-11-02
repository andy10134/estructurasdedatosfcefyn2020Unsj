#include "Nodo.cpp"

class ArbolBinarioB
{
private:
    Nodo *raiz;
public:
    ArbolBinarioB(/* args */);
    int insertar(int element, Nodo *aux);
    int suprimir(int elemento);
    Nodo *buscar(int elemento);
    int nivel();
    bool hoja(int elemento, int elemento2);
    bool hijo(int elemento, int elemento2);
    bool padre(int elemento);
    int *camino(int inicio, int destino);
    int altura(int elemento);
    int InOrden();
    int PreOrden();
    int PostOrden();
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
