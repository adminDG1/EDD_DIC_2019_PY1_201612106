#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <iostream>
using namespace std;

class Cola
{

class NodoCola
{

private:

    NodoCola *before;
    string cancion;

public:

    NodoCola(string cancion_)
    {

    before = 0;
    cancion = cancion_;

    }

    NodoCola *getbefore(){return before;}
    NodoCola *setbefore(NodoCola *before_){ before = before_;}
    string getCancion(){return cancion;};


};

private:
    int size;
    NodoCola *last;
    NodoCola *first;
    bool isEmpty(){ return size == 0;};

public:
    Cola()
    {
        size = 0;
        last = 0;
        first = 0;

    }

    void enqueue(string cancion);
    void dequeue();
    void printCola();

};

void Cola::enqueue(string cancion)
{

    if(isEmpty())
    {
         NodoCola *aux = new NodoCola(cancion);
        this->first = aux;
        this->last = aux;
        size++;

    } else
    {
        NodoCola *aux = new NodoCola(cancion);
        this->last->setbefore(aux);
        this->last = aux;
        size++;

    }

}

void Cola::dequeue()
{
    if(isEmpty())
    {

    } else
    {
        NodoCola *aux = this->first;
        this->first = this->first->getbefore();
        aux->setbefore(0);
        delete aux;
        size--;
    }


}

void Cola::printCola()
{

        NodoCola *aux = this->first; //apunta al ultimo par recorrer desde el final
        int x = 0;

        while(aux != 0){ //recorre alrevez 1 vez

        cout<<x<<":"<<aux->getCancion()<<endl;// imprime
        aux = aux -> getbefore();// apunta al anterior para recorrer
        x++;
        }


}


#endif // COLA_H_INCLUDED
