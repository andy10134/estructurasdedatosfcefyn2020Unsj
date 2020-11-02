class ArbolBinario
{
private:
    Nodo *Raiz;
public:
    ArbolBinario(/* args */);
    int insertar(int elemento);
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
};

ArbolBinario::ArbolBinario(/* args */)
{
    Nodo = NULL;
}

