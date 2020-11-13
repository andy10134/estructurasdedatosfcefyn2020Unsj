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

void colaPrioridad::insertar(int elemento){
     if(tope < maximo)
    {
        int i= tope;
        items[i] = elemento;
        while(i!=1 && items[i/2] > elemento)
        {
            int aux;
            aux = items[i/2];
            items[i/2] = elemento;
            items[i] = aux;
            i = i/2;
        }
        tope++;
    }
}
