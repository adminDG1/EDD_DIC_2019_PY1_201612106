#pragma once
#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED
#include <iostream>
#include <fstream>
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

		Cancion *getCancion() { return dato; }
		NodoSimple *getNext() { return next; }
		void setNext(NodoSimple *n) { next = n; }


	};

private:
	NodoSimple *first;
	NodoSimple *last;
	int size;
	bool isEmpty() { return size == 0; };
	int getSize() { return size; };

public:

	ListaSimple()
	{

		size = 0;
		first = 0;
		last = 0;

	}

	void push(Cancion *dato);
	void print_front_back();
	void graph();
	void printCancion(string name);
	//void addOrder(Cancion *cancion, string nombre);

};

void ListaSimple::push(Cancion *dato)
{

	if (isEmpty())
	{
		NodoSimple *aux = new NodoSimple(dato);
		this->first = aux;
		this->last = aux;
		size++;

	}
	else
	{
		NodoSimple *aux = new NodoSimple(dato);
		this->last->setNext(aux);
		this->last = aux;
		size++;

	}

}

void ListaSimple::print_front_back()
{

	NodoSimple *aux = this->first; //empieza apuntando al primero par recorrer
	int x = 0;
	cout << "-----------Canciones----------" << endl;
	cout << endl;
	while (x != this->size) { // para hasta que se recorra toda la lista 1 vez
		if (x == this->size) { break; }
		cout << endl;
		cout <<"Name: "<< aux->getCancion()->getName() << endl; // obtiene e imprime los datos
		cout << "---------------------------";
		cout << endl;
		aux = aux->getNext(); // apunta al siguiente para recorrer
		x++;
	}


}

void ListaSimple::printCancion(string name)
{
	NodoSimple *aux = this->first; //empieza apuntando al primero par recorrer
	int x = 0;
	while (x != this->size) { // para hasta que se recorra toda la lista 1 vez

		if (x == this->size) { break; }
		if (aux->getCancion()->getName() == name)
		{
			cout << "Name: " << aux->getCancion()->getName() << endl; // obtiene e imprime los datos
			cout << "Rating: " << aux->getCancion()->getRating() << endl;
			cout << "File: " << aux->getCancion()->getFile() << endl;
			cout << "---------------------------";
			
		}

		aux = aux->getNext(); // apunta al siguiente para recorrer
		x++;
	}

}

void ListaSimple::graph()
{
	NodoSimple *aux = this->first;
	string graf = "digraph { \n";
	graf = graf + "node[shape=box, width = 2.5, height = .75 ]; \n";

	//cout << " digraph {" << endl;
	//cout << "node[shape=box, width = 2.5, height = .75 ];" << endl;

	

		while (aux != 0) { // para hasta que se recorra toda la lista 1 vez
						   //cout << "entro" << endl;
			if (aux->getNext() == 0) { graf = graf + "\n"; break; };
			//cout << aux->getName() << "->" << aux->getNext()->getName() << endl; // obtiene e imprime los datos
			graf = graf + "\"" + aux->getCancion()->getName()+ "\"";
			graf = graf + "->";
			graf = graf + "\"" + aux->getNext()->getCancion()->getName()+ "\"";
			graf = graf + "\n";
			graf = graf + "\n";

			aux = aux->getNext(); // apunta al siguiente para recorrer
									//x++;
		}
	 

	  //cout << endl;
	  //cout << "}" << endl; //el final del dot
	graf = graf + "\n";
	graf = graf + "}";

	ofstream g("graficaSimple.dot");
	//cout << graf << endl;
	g << graf;
	g.close();
	system("dot -Tpng graficaSimple.dot -o grafSimple.png");
	system("grafSimple.png");


}

//agrega en orden
/*
void ListaSimple::addOrder(Cancion *dato, string name)
{

	if (this->isEmpty()) {

		this->add_first(dato, name);

	}
	else {

		if (ordenAlfabetico(name) > ordenAlfabetico(this->last->getName())) {


			this->add_last(dato, name);

		}
		else if (ordenAlfabetico(name) < ordenAlfabetico(this->first->getName())) {

			this->add_first(dato, name);

		}
		else {

			Nodo *temp = this->first;

			while (temp != 0) {

				if (this->ordenAlfabetico(temp->getNext()->getName()) >= this->ordenAlfabetico(name)) {

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
*/
#endif // LISTASIMPLE_H_INCLUDED
