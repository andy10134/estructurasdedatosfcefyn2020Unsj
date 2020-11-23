#include "Lista.cpp"

int main(int argc, char const *argv[])
{
    Lista l1;
    l1.insertar("e", 12);
    l1.insertar("a", 3);
    l1.insertar("f", 65);
    l1.hoffman();
    l1.codificar("f");
    l1.codificar("e");
    l1.codificar("a");
    //l1.mostrar();
    return 0;
}
