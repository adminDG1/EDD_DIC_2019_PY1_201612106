#ifndef LISTAARTISTA_H_INCLUDED
#define LISTAARTISTA_H_INCLUDED

#include <iostream>
using namespace std;

template <class T>
class ListaDoble
{
    class Nodo{

public:
    Nodo(T x, string name_)
    {

        next = 0;
        before = 0;
        dato = x;
        name = name_;

    }

    Nodo *getNext(){ return next;}
    Nodo *getBefore(){return before;}
    void setNext(Nodo *n){next = n;}
    void setBefore(Nodo *n){before = n;}
    T getDato(){ return dato;}
    string getName(){return name};


private:
    Nodo *next;
    Nodo *before;
    T dato;
    string name;

    };

private:
    int size;
    Nodo *first;
    Nodo *last;
    bool isEmpty(){return size == 0;}

public:
    ListaDoble(){

        first = 0;
        last = 0;
        size = 0;

    }

    int getsize(){return size;}
    void add_first(T dato, string name);
    void add_last(T dato, string name);
    void add_at(T dato, int index);
    T get_element_at(int index);

    T remove_first();
    T remove_last();
    T remove_at(int index);
    T print_front_back();

    void addOrder(string name);
    int ordenAlfabetico(string name);

};

template <class T>
int ListaDoble<T>::ordenAlfabetico(string name)
{

 char stringsep[90];
 strcpy(stringsep,name.c_str());

 if(stringsep[0] == 'a' || stringsep[0] == 'A'){
    return 0;

 } else if(stringsep[0] == 'b' || stringsep[0] == 'B'){

    return 1;

 } else if (stringsep[0] == 'c' || stringsep[0] == 'C'){

    return 2;

 }

}

template <class T>
void ListaDoble<T>::addOrder(T dato, string name)
{

    if(this->isEmpty()){

        this->addFirst(dato , name));

} else {

    if(this->orderAlfabetico(name) > this->ordenAlfabetico(this->last->getName())){


        this->addLast(dato, name);

    } else if(this->orderAlfabetico(name) < this->ordenAlfabetico(this->first->getName())){

        this->addFirst(dato, name);

    } else{

        Nodo *temp = this->first;

        while(temp != 0){

            if(this->ordenAlfabetico(temp->getNext()->getName() >= this->ordenAlfabetico(name))){

                    Nodo *nuevo = new Nodo(dato, name);
                    nuevo->setNext(temp->getNext());
                    nuevo->setBefore(temp);
                    temp->getNext()->setBefore(nuevo);
                    temp->setNext(nuevo);
                    break;

            }
            temp = temp->getNext();


        }

        this->size++;

    }

}

}

template <class T>
void ListaDoble<T>::add_first(T dato)
{
Nodo *n = new Nodo(dato);
if (isEmpty())
{
    this ->first = n;
    this ->last = n;
    this ->size++;

} else
{

    n->setNext(this->first);
    this->first->setBefore(n);
    this->first = n;
    this ->size++;

}
}
template <class T >
void ListaDoble<T>::add_last(T dato)
{
    if(isEmpty())
    {
        this->add_first(dato);
    } else{

    Nodo *n = new Nodo(dato);
    this -> last ->setNext(n);
    n->setBefore(this->last);
    this -> last = n;
    this -> size++;

    }

}

template <class T>
void ListaDoble<T>::add_at(T dato, int index)
{
    if(index >= 0 && index <= this-> size)
    {
        if(index == 0){this ->add_first(dato); return;}
        if(index == this->size){this -> add_list(dato); return;}

        Nodo *aux = this->first;
        int x = 0;
        while(aux != 0){

            if(x == index){ break;}
            aux = aux -> getNext();
            x++;
        }
        Nodo *n = new Nodo(dato);
        aux -> getBefore()->setNext(n);
        n -> setBefore(aux->getBefore());
        n -> setNext(aux);
        aux -> setBefore(n);
        this -> size++;

    }

}

//Metodos para remover Nodos

template <class T>
T ListaDoble<T>::remove_first()
{

    if(!isEmpty())
    {

        if(this->size == 1){

            this->first = 0;
            this->last = 0;
            size--;

        } else{

            Nodo *aux = this->first;
            this->first = this->first->getNext();
            aux->getNext()->setBefore(0);
            aux->setNext(0);
            delete aux;
            cout<<aux->getDato()<<endl;
            size--;

        }

    }

}


template <class T>
T ListaDoble<T>::remove_last()
{

    if(!isEmpty())
    {

        if(this->size == 1){

            this->first = 0;
            this->last = 0;
            size--;

        } else{

            Nodo *aux = this->last;
            this->last = this->last->getBefore();
            aux->getBefore()->setNext(0);
            aux->setBefore(0);
            delete aux;

            cout<<aux->getDato()<<endl;
            size--;

        }

    }

}



template<class T>
T ListaDoble<T>::remove_at(int index)
{

    if(index >= 0 && index <= this-> size)
    {
        if(index == 0)
        {
            this ->remove_first();
        }
        else if(index == this->size-1)
        {
            this -> remove_last();
        }
        else
        {

        Nodo *aux = this->first;
        int x = 0;
        while(aux != 0)
        { //aqui cambiar a x != sife

            if(x == index){ break;}
            aux = aux -> getNext();
            x++;
        }

        aux->getBefore()->setNext(aux->getNext());
        aux->getNext()->setBefore(aux->getBefore());
        delete aux;
        cout<<aux->getDato()<<endl;
        this -> size--;
        }

    }

}

template <class T>
T ListaDoble <T>::get_element_at(int index)
{

    if(index >= 0 && index< size)
    {
        Nodo *iterador = this->first;
        int x = 0;
        while(iterador != 0)
        {
            if(index == x){ return iterador->getBefore()->getDato(); iterador -> getDato();}
            iterador = iterador->getNext();
            x++;
        }
    }

}

template <class T>
T ListaDoble <T>::print_front_back()
{

        Nodo *aux = this->first;
        int x = 0;
        while(x != this->size){

            if(x == this->size){ break;}
            cout<<aux->getDato()<<endl;
            aux = aux -> getNext();
            x++;
        }


}


#endif // LISTAARTISTA_H_INCLUDED
