
#include "ListaCircular.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>

using namespace std;
int objetoLista = 0;

int main(){

    ListaCircular <string> *list = new ListaCircular<string>();
    list->add_last("1");
    list->add_last("2");
    list->add_last("3");
    list->add_last("4");
   // list->print_front_back();
    list->graph();
}
