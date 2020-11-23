#include "Celda.cpp"

class Lista
{
private:
    Celda * cab;
    int cant;
public:
    Lista();
    bool vacia();
    int insertar(string eti,int frec);
    Celda *recuperar(int posicion);
    int suprimir(int posicion);
    void mostrar();
    void hoffman();
    string codificarCaracter(string c,  Celda *raiz, string codigo, bool &b);
    string codificar(string cadena);
    int buscar(int elemento);
};

Lista::Lista()
{
    cant = 0;
    cab = NULL;
}

bool Lista::vacia()
{
    return cant == 0;
}

int Lista::insertar(string eti,int frec)
{
    Celda *aux;
    aux = new Celda(frec, eti);

   if (vacia())
    {
        aux->setSig(cab);
        cab = aux;
    }
    else
    {
        if (cab->getFrec() > frec)
        {
            aux->setSig(cab);
            cab = aux;
        }else
        {
            Celda *ant = cab;
            Celda *sig = ant->getSig();

            while(sig != NULL && sig->getFrec() < frec)
            {
                ant = sig;
                sig = ant->getSig();
            }
            aux->setSig(sig);
            ant->setSig(aux);
        }

    }
    cant++;
    return 1;

}

void Lista::mostrar()
{
    Celda *aux;
    aux = cab;
    while (aux!=NULL)
    { 
        cout << aux->getEti() << " - ";
        cout << aux->getFrec() << endl;
        aux = aux->getSig();
    }
}


Celda* Lista::recuperar(int posicion)
{
    if (posicion > 0 && posicion < cant +1)
    {
        if(vacia())
        {
            cout<<"no se puede recuperar porque la lista esta vacia"<<endl;
        }
        else
        {
            Celda *aux;
            int cont=1;
            aux = cab;
            while (cont != posicion)
            { 
                cont++;
                aux = aux->getSig();
            }
            return(aux);
        }
    }else
    {
        cout<<"POSICION INVALIDA"<<endl;
        return(NULL);
    }
}


void Lista::hoffman()
{
    if(!vacia())
    {
        Celda *nuevo, *aux, *aux2;
        int auxfrec;

        while (cant > 1)
        {
            aux = recuperar(1);
            aux2 = recuperar(2);
            auxfrec = aux->getFrec() + aux2->getFrec() ;
            insertar(( aux->getEti() + aux2->getEti() ),
                     auxfrec
                    );

            nuevo = recuperar(buscar(auxfrec));
            
            nuevo -> setDer(aux);
            nuevo -> setIzq(aux2);


            suprimir(1);
            suprimir(1);
        }
        
    }else
    {
        cout << "La lista se encuentra vacia" << endl;
    }
    
}


int Lista::suprimir(int posicion)
{
    if (posicion > 0 && posicion <= cant +1)
    {
        Celda* aux;
        int cont=1, elemento;
        if(vacia())
        {
            cout<<"no se puede suprimir porque la lista esta vacia"<<endl;
        }
        else
        {
            if (posicion == 1)
            {
                aux = cab;
                elemento = cab->getFrec();
                cab = cab->getSig();
                aux->setSig(NULL);
            }
            else
            {
                aux = cab;
                Celda* anterior = cab;
                while(cont != posicion)
                {
                    anterior = aux;
                    aux = aux->getSig();
                    cont++;
                }
                elemento = aux->getFrec();
                anterior->setSig(aux->getSig());
                aux->setSig(NULL);
                cout<<"El elemento ha sido suprimido"<<endl; 
            }       
        }
        cant --;
        return(elemento);
    }
    else
    {
        cout<<"POSICION INVALIDA"<<endl;
        return(0);
    }
}

string Lista::codificarCaracter(string c, Celda *raiz, string codigo , bool &b)
{
    if (raiz!=NULL)
    {
        if (raiz ->getEti() == c)
        {
            b = true;
            cout << codigo << endl;
        }else
        {
            if (raiz ->getEti().length() > 1)
            {                
                string aux = codigo;
                codigo.append("0");
                codificarCaracter(c, raiz ->getDer(), codigo, b);
                if (!b)
                {
                    codigo = aux;
                    codigo.append("1");
                    codificarCaracter(c, raiz ->getIzq(), codigo, b);   
                }            
            }
        }
    }    
}

string Lista::codificar(string cadena)
{
    int i, max;
    string xd = "";
    bool ban = false;
    max = cadena.length();

/*    for (i = 0; i < max; i++)
    {
    }
*/
    codificarCaracter(cadena, cab, xd, ban);
    
}


int Lista::buscar(int elemento){
    if (vacia())
    {
        cout<<"no se puede Buscar porque la lista esta vacia"<<endl;
    }
    else
    {
        Celda *aux;
        int cont=1;
        aux = cab;
        while (aux!=NULL && aux->getFrec() != elemento)
        { 
            cont++;
            aux = aux->getSig();
        }
        if(aux == NULL)
        {
            cout<<"No se encontro el elemento en la lista"<<endl;
        }
        else
        {
            return(cont);
        }
    }
}