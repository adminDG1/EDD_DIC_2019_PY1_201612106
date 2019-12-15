#ifndef ARTISTA_H_INCLUDED
#define ARTISTA_H_INCLUDED
#include "matriz.h"

class Artista
{

private:
    string name;
    Matriz *matriz;

    string getName(){return name;};
    Matriz *getMatriz(){return matriz;};

public:
    Artista(string name_,Matriz *matriz_)
    {
        name = name_;
        matriz = matriz_;

    }


};

#endif // ARTISTA_H_INCLUDED
