#include <iostream>

using namespace std;

class Celda
{
private:
    int frec;
    string eti;
    Celda *sig, *der, *izq;
public:
    Celda(int xfrec, string xeti);
    Celda * getSig();
    
    //Nodo - Getters
    Celda * getIzq();
    Celda * getDer();
    string getEti();
    int getFrec();

    //Setters
    void setSig(Celda *xsig);
    void setDer(Celda *x);
    void setIzq(Celda *x);
    void setEti(string x);
    void setFrec(int x);
};

Celda::Celda(int xfrec, string xeti)
{
    frec = xfrec;
    eti = xeti;
    sig = NULL;
    izq = NULL;
    der = NULL;
}

//getters
int Celda::getFrec()
{
    return frec;
}

string Celda::getEti()
{
    return eti;
}

Celda * Celda::getSig()
{
    return sig;
}

Celda * Celda::getIzq()
{
    return izq;
}

Celda * Celda::getDer()
{
    return der;
}

//Seters
void Celda::setFrec(int xfrec)
{
    frec = xfrec;
}

void Celda::setEti(string xeti)
{
    eti = xeti;
}

void Celda::setSig(Celda * xsig)
{
    sig = xsig;
}

void Celda::setDer(Celda * xder)
{
    der = xder;
}

void Celda::setIzq(Celda * xizq)
{
    izq = xizq;
}
