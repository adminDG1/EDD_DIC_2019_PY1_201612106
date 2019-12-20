#pragma once
#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <iostream>
#include "Cancion.h"
using namespace std;

class Pila
{

	class NodoPila
	{

	private:

		NodoPila *before;
		Cancion *cancion;

	public:

		NodoPila(Cancion *cancion_)
		{

			before = 0;
			cancion = cancion_;

		}

		NodoPila *getBefore() { return before; }
		void setBefore(NodoPila *before_) { before = before_; }
		Cancion *getCancion() { return cancion; };

	};

private:
	int size;
	NodoPila *last;
	bool isEmpty() { return size == 0; };

public:
	Pila()
	{
		size = 0;
		last = 0;

	}

	void push(Cancion *cancion);
	void pop();
	void printPila();

	void graph();

};

void Pila::push(Cancion *cancion)
{

	if (isEmpty())
	{
		NodoPila *aux = new NodoPila(cancion);
		this->last = aux;
		size++;

	}
	else
	{
		NodoPila *aux = new NodoPila(cancion);
		aux->setBefore(this->last);
		this->last = aux;
		size++;

	}

}

void Pila::pop()
{
	if (isEmpty())
	{

	}
	else
	{
		NodoPila *aux = this->last;
		this->last = this->last->getBefore();
		aux->setBefore(0);
		delete aux;
		size--;
	}


}

void Pila::printPila()
{

	NodoPila *aux = this->last; //apunta al ultimo par recorrer desde el final
	int x = 0;

	while (aux != 0) { //recorre alrevez 1 vez

		std::cout << x << ":" << aux->getCancion()->getName() << endl;// imprime
		aux = aux->getBefore();// apunta al anterior para recorrer
		x++;
	}


}

void Pila::graph()
{
	NodoPila *aux = this->last;
	string graf = "digraph { \n";
	graf = graf + "node[shape=box, width = 2.5, height = .75 ]; \n";

	//cout << " digraph {" << endl;
	//cout << "node[shape=box, width = 2.5, height = .75 ];" << endl;

	
		while (aux != 0) { // para hasta que se recorra toda la lista 1 vez
						   //cout << "entro" << endl;
			if (aux->getBefore() == 0) { graf = graf + "\n"; break; };
			//cout << aux->getName() << "->" << aux->getNext()->getName() << endl; // obtiene e imprime los datos
			graf = graf +"\"" +aux->getCancion()->getName()+ "\"";
			graf = graf + "->";
			graf = graf + "\"" + aux->getBefore()->getCancion()->getName()+"\"";
			graf = graf + "\n";
			graf = graf + "\n";

			aux = aux->getBefore(); // apunta al siguiente para recorrer
								  //x++;
		}


	//cout << endl;
	//cout << "}" << endl; //el final del dot
	graf = graf + "\n";
	graf = graf + "}";

	ofstream g("graficaPila.dot");
	//cout << graf << endl;
	g << graf;
	g.close();
	system("dot -Tpng graficaPila.dot -o grafPila.png");
	system("grafPila.png");


}

#endif // PILA_H_INCLUDED
