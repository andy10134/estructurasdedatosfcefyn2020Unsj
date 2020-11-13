class colaPrioridad
{
private:
    int *items;
    int maximo;
public:
    colaPrioridad(int cantidad);
    void suprimir();
    void insertar(int elemento);
};

colaPrioridad::colaPrioridad(int cantidad)
{
    maximo = cantidad;
    items = new int[cantidad];
    items[0] = 1;
}


