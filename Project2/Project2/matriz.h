#pragma once
#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

class Matriz
{

	class NodoMatriz
	{

	};

};





class Columna
{

	class NodoColumna
	{
	private:
		NodoColumna *next;
		NodoColumna *before;
		string ano;


	public:

		NodoColumna(string ano_)
		{
			ano = ano_;
			next = 0;
			before = 0;
		}

		NodoColumna *getNext() { return next; };
		NodoColumna *getBefore() { return before; };
		void setNext(NodoColumna *n) { next = n; };
		void setBefore(NodoColumna *n) { before = n; };
		string getAno() { return ano; };

	};

private:
	NodoColumna *first;
	NodoColumna *last;
	int size;
	int isEmpty() { return size; };

public:

	Columna() {
		first = 0;
		last = 0;
		size = 0;
	}

	void buscarColumna(NodoColumna *look, string ano) {}
	void add_first(string ano);
	void add_last(string ano);
	void addOrder(string ano);

};

void Columna::add_first(string ano)
{
	NodoColumna *n = new NodoColumna(ano);
	if (isEmpty())
	{
		this->first = n;
		this->last = n;
		this->size++;

	}
	else
	{

		n->setNext(this->first);
		this->first->setBefore(n);
		this->first = n;
		this->size++;

	}
}

void Columna::add_last(string ano)
{
	if (isEmpty())
	{
		this->add_first(ano);

	}
	else {

		NodoColumna *n = new NodoColumna(ano);
		this->last->setNext(n);
		n->setBefore(this->last);
		this->last = n;
		this->size++;

	}

}

void Columna::addOrder(string ano)
{
	istringstream iss(ano);
	int ano_entrada;
	int ano_nodoF;
	int ano_nodoL;
	int ano_nodo;

	iss >> ano_entrada;

	if (this->isEmpty()) {

		this->add_first(ano);

	}
	else {

		istringstream isss(this->first->getAno());
		istringstream issss(this->last->getAno());

		isss >> ano_nodoF;
		issss >> ano_nodoL;

		if (ano_entrada > ano_nodoL) {

			this->add_last(ano);

		}
		else if (ano_entrada < ano_nodoF) {

			this->add_first(ano);

		}
		else {

			NodoColumna *temp = this->first;

			while (temp != 0) {

				istringstream isssss(temp->getNext()->getAno());
				isssss >> ano_nodo;

				if (ano_nodo >= ano_entrada) {

					NodoColumna *nuevo = new NodoColumna(ano);
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

class Filas {

	class NodoFilas {



	};

};


#endif // MATRIZ_H_INCLUDED
