#ifndef NODO_H
#define NODO_H
#include <iostream>
using namespace std;

template<typename Tipo>
class Nodo
{
public:
    Nodo(string type, Tipo valor)
    {
        tipo = type;
        this->valor = valor;
        sig = NULL;
    }
    ~Nodo(){

    }

    string tipo;
    Tipo valor;
    Nodo<Tipo>* sig;
};

#endif // NODO_H
