#pragma once
#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <iostream>
#include "Cancion.h"
using namespace std;

class Cola
{

	class NodoCola
	{

	private:

		NodoCola *before;
		Cancion *cancion;

	public:

		NodoCola(Cancion *cancion_)
		{

			before = 0;
			cancion = cancion_;

		}

		NodoCola *getbefore() { return before; }
		void setbefore(NodoCola *before_) { before = before_; }
		Cancion *getCancion() { return cancion; };

	};

private:
	int size;
	NodoCola *last;
	NodoCola *first;
	bool isEmpty() { return size == 0; };

public:
	Cola()
	{
		size = 0;
		last = 0;
		first = 0;

	}

	void enqueue(Cancion *cancion);
	void dequeue();
	void printCola();
	void graph();

};

void Cola::enqueue(Cancion *cancion)
{

	if (isEmpty())
	{
		NodoCola *aux = new NodoCola(cancion);
		this->first = aux;
		this->last = aux;
		size++;

	}
	else
	{
		NodoCola *aux = new NodoCola(cancion);
		this->last->setbefore(aux);
		this->last = aux;
		size++;

	}

}

void Cola::dequeue()
{
	if (isEmpty())
	{

	}
	else
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

	while (aux != 0) { //recorre alrevez 1 vez

		cout << x << ":" << aux->getCancion() << endl;// imprime
		aux = aux->getbefore();// apunta al anterior para recorrer
		x++;
	}


}

void Cola::graph()
{
	NodoCola *aux = this->first;
	string graf = "digraph { \n";
	graf = graf + "node[shape=box, width = 2.5, height = .75 ]; \n";

	//cout << " digraph {" << endl;
	//cout << "node[shape=box, width = 2.5, height = .75 ];" << endl;


	
		while (aux != 0) { // para hasta que se recorra toda la lista 1 vez
						   //cout << "entro" << endl;
			if (aux->getbefore() == 0) { graf = graf + "\n"; break; };
			//cout << aux->getName() << "->" << aux->getNext()->getName() << endl; // obtiene e imprime los datos
			graf = graf +"\""+ aux->getCancion()->getName()+ "\"";
			graf = graf + "->";
			graf = graf + "\"" + aux->getbefore()->getCancion()->getName()+ "\"";
			graf = graf + "\n";
			graf = graf + "\n";

			aux = aux->getbefore(); // apunta al siguiente para recorrer
									//x++;
		}
	

	  //cout << endl;
	  //cout << "}" << endl; //el final del dot
	graf = graf + "\n";
	graf = graf + "}";

	ofstream g("graficaCola.dot");
	//cout << graf << endl;
	g << graf;
	g.close();
	system("dot -Tpng graficaCola.dot -o grafCola.png");
	system("grafCola.png");


}


#endif // COLA_H_INCLUDED
