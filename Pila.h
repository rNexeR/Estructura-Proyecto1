#ifndef PILA_H
#define PILA_H
#include <QString>
#include <iostream>
#include "Nodo.h"
using namespace std;

template<typename Tipo>
class Pila
{
public:
    Pila(){
        tope = NULL;
    }

    ~Pila(){

    }

    void agregar(string type, Tipo valor){
        if (!tope){
            tope = new Nodo<Tipo>(type, valor);
            return;
        }
        Nodo<Tipo>* temp = tope;
        tope = new Nodo<Tipo>(type, valor);;
        tope->sig = temp;
    }

    bool vacia(){
        if(tope)
            return false;
        return true;
    }

    bool liberarTope(){
        if(tope){
            Nodo<Tipo>* temp = tope;
            tope = tope->sig;
            delete temp;
            return true;
        }
        return false;
    }

    void limpiar(){
        while(liberarTope());
    }

    Nodo<Tipo>* getTope(){
        return tope;
    }

private:
    Nodo<Tipo>* tope;
};

#endif // PILA_H
