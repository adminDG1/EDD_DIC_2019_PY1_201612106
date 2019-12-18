 #include <iostream>
#include <sstream>
#include "Pila.h"
#include "Cola.h"
#include "Cancion.h"
#include "Album.h"
#include "ListaSimple.h"
#include "matriz.h"
#include "PlayList.h"
#include "ListaArtista.h"

using namespace std;

int main(){

    Pila *p = new Pila();
    p->push("hello");
    p->push("hello1");
    p->push("hello2");
    p->printPila();
    cout<<endl;
    cout<<endl;
    cout<<endl;
    Cola *c = new Cola();
    c->enqueue("hello");
    c->enqueue("hello1");
    c->enqueue("hello2");
    c->printCola();
    cout<<endl;
    c->dequeue();
    c->dequeue();
    c->printCola();
    cout<<endl;
    cout<<endl;

    Cancion *ca = new Cancion("Paradise",5,"Paradise.mp3");
    Cancion *ca2 = new Cancion("Lay to me",4,"LTM.mp3");
    cout<<ca->getName()<<":"<<ca->getRating()<<endl;
    cout<<endl;
    cout<<endl;

    ListaSimple *ls = new ListaSimple();
    ls->push(ca);
    ls->push(ca2);
    //ls->print_front_back();

    Album *a = new Album("album1","julio",2015,ls);
    cout<<a->getName()<<endl;
    cout<<"Contenido album:"<<endl;
    a->getLista()->print_front_back();
    cout<<endl;
    cout<<endl;
    Matriz *ma = new Matriz();

    Artista *ar = new Artista("pedro",ma);

    ListaDoble *doble = new ListaDoble();
    doble->add_first(ar,ar->getName());
    doble->print_front_back();

  //  arbol<*estructuras> *hn = new arbol<*estructuras>();

  ListaCircular<Artista> *hn = new ListaCircular<Artista>();
  hn->add_first(ar);
  Artista *primero = hn->get_element_at(0);
  cout<<"Primero:"<<hn->get_element_at(0)->getName()<<endl;

}

