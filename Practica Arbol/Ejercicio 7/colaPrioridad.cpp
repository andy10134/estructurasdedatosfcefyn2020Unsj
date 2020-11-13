class colaPrioridad
{
private:
    int tope;
    int *items;
public:
    colaPrioridad(int cantidad);
};

colaPrioridad::colaPrioridad(int cantidad)
{
    tope = -1;
    items = new int[cantidad];
}