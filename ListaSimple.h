#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED
#include <iostream>
#include "Cancion.h"

using namespace std;

class ListaSimple
{

    class NodoSimple
    {

private:
    Cancion *dato;
    NodoSimple *next;

public:
    NodoSimple(Cancion *dato_)
    {

    next = 0;
    dato = dato_;

    }

    Cancion *getCancion(){ return dato;}
    NodoSimple *getNext(){return next;}
    NodoSimple *setNext(NodoSimple *n){ next = n;}


    };

private:
    NodoSimple *first;
    NodoSimple *last;
    int size;
    bool isEmpty(){return size == 0;};

public:

    ListaSimple
    {

    size = 0;
    first = 0;
    last = 0;

    }

    void getSize(){return size;}
    void push(Cancion *dato);

};

void ListaSimple::push(Cancion *dato)
{

if(isEmpty())
    {
         NodoSimple *aux = new NodoSimple(dato);
        this->first = aux;
        this->last = aux;
        size++;

    } else
    {
        NodoCola *aux = new NodoCola(dato);
        this->last->setNext(aux);
        this->last = aux;
        size++;

    }

}

#endif // LISTASIMPLE_H_INCLUDED
