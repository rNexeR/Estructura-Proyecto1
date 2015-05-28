#ifndef COLA_H
#define COLA_H

#include "Nodo.h"
#include <iostream>
using namespace std;

template<typename Tipo>
class Cola
{
public:
    int size;
    Cola(){
        frente = NULL;
        ultimo = NULL;
        size = 0;
    }

    ~Cola(){

    }

    void agregar(string type, Tipo valor){
        if(!frente){
            frente = new Nodo<Tipo>(type, valor);
            ultimo = frente;
            size++;
            return;
        }
        ultimo->sig = new Nodo<Tipo>(type, valor);
        ultimo = ultimo->sig;
        size++;
    }

    bool vacia(){
        if(frente)
            return false;
        return true;
    }

    bool liberarFrente(){
        if(frente){
            Nodo<Tipo>* temp = frente;
            frente = frente->sig;
            delete temp;
            size--;
            return true;
        }
        ultimo = NULL;
        return false;
    }

    void limpiar(){
        while(liberarFrente());
        size = 0;
    }

    Nodo<Tipo>* getFrente(){
        return frente;
    }

private:
    Nodo<Tipo>* frente, *ultimo;
};

#endif // COLA_H
