 #include <iostream>
#include <sstream>
#include "Pila.h"
#include "Cola.h"

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
}
