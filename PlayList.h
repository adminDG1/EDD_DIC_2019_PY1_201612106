#ifndef PLAYLIST_H_INCLUDED
#define PLAYLIST_H_INCLUDED
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include "Pila.h"
#include "Cola.h"
#include "ListaCircular.h"

using namespace std;

template <class T>
class PlayList
{

private:
    string name;
    string type;
    Pila *p;
    Cola *c;
    ListaCircular *lc;

public:

    PlayList(string name_, string type_,Pila p_)
    {

        name = name_;
        type = type_;
        p = p_;
    }

    PlayList(string name_, string type_,Cola c_)
    {

        name = name_;
        type = type_;
        c = c_;
    }

    PlayList(string name_, string type_,ListaCircular lc_)
    {

        name = name_;
        type = type_;
        lc = lc_;
    }



    //T getPlayList(){ return estructura;};

};
    //int getsize(){return size;}
    /*aqui se inicializan los metodos que usaremos
      para  la Hoja de trabajo1*/




/*
template <class T>
T ListaCircular <T>::print_back_front()
{
           Nodo *aux = this->last; //apunta al ultimo par recorrer desde el final
        int x = 0;

        while(x != this->size){ //recorre alrevez 1 vez

            if(x == this->size){ break;}
            cout<<aux->getDato()<<endl;// imprime
            aux = aux -> getBefore();// apunta al anterior para recorrer
            x++;
        }

}
*/



#endif // ListaCircular_H_INCLUDED

