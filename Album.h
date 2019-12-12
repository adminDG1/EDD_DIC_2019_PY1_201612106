#ifndef ALBUM_H_INCLUDED
#define ALBUM_H_INCLUDED
#include "Cancion.h"

class Album{

private:
    string name;
    string month;
    int ano;
    Cancion *cancion;

public:
    Album(string name_,string month_,int ano_,Cancion *cancion_)
    {
        name = name_;
        month = month_;
        ano = ano_;
        cancion = cancion_;

    }

    string getName(){ return name;};
    void setName(string n){ name = n;};
    string getMonth(){return month};
    int getAno(){return ano;};
    void setMonth(string m){ month= m;};
    Cancion *getCancion(){return cancion;};
    setCancion(Cancion *c){cancion = c;};

};


#endif // ALBUM_H_INCLUDED
