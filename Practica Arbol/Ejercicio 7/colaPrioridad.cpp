class colaPrioridad
{
private:
    int tope;
    int *items;
    int maximo;
public:
    colaPrioridad(int cantidad);
    void suprimir();
    void insertar(int elemento);
};

colaPrioridad::colaPrioridad(int cantidad)
{
    tope = 1;
    maximo = cantidad;
    items = new int[cantidad];
}

