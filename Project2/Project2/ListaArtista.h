#pragma once
#ifndef ListaDoble_H_INCLUDED
#define ListaDoble_H_INCLUDED
#include <iostream>
#include <sstream>
using namespace std;

template <class T>
class ListaDoble
{
	class Nodo {

	public:
		Nodo(T *x, string name_)
		{

			next = 0;
			before = 0;
			dato = x;
			name = name_;

		}

		Nodo *getNext() { return next; }
		Nodo *getBefore() { return before; }
		void setNext(Nodo *n) { next = n; }
		void setBefore(Nodo *n) { before = n; }
		T *getDato() { return dato; }
		string getName() { return name; };

	private:
		Nodo *next;
		Nodo *before;
		T *dato;
		string name;

	};

private:
	int size;
	Nodo *first;
	Nodo *last;
	bool isEmpty() { return size == 0; }
	string grafica;

public:
	ListaDoble() {

		first = 0;
		last = 0;
		size = 0;
		grafica = "";

	}

	int getsize() { return size; }
	/*aqui se inicializan los metodos que usaremos
	para  la Hoja de trabajo1*/
	void add_first(T *dato, string name);
	void add_last(T *dato, string name);
	void add_at(T *dato,string name, int index);
	T *get_element_at(int index);
	void print_front_back();
	T print_back_front();

	void addOrder(T *dato, string name);
	int ordenAlfabetico(string name);
	void graph();

};

template <class T>
int ListaDoble<T>::ordenAlfabetico(string name)
{

	char stringsep[90];
	strcpy_s(stringsep, name.c_str());
	

	if (stringsep[0] == 'a' || stringsep[0] == 'A') {
		return 0;

	}
	else if (stringsep[0] == 'b' || stringsep[0] == 'B') {

		return 1;

	}
	else if (stringsep[0] == 'c' || stringsep[0] == 'C') {

		return 2;

	}
	else if (stringsep[0] == 'd' || stringsep[0] == 'D') {

		return 3;

	}
	else if (stringsep[0] == 'e' || stringsep[0] == 'E') {

		return 4;

	}
	else if (stringsep[0] == 'f' || stringsep[0] == 'F') {

		return 5;

	}
	else if (stringsep[0] == 'g' || stringsep[0] == 'G') {

		return 6;

	}
	else if (stringsep[0] == 'h' || stringsep[0] == 'H') {

		return 7;

	}
	else if (stringsep[0] == 'i' || stringsep[0] == 'I') {

		return 8;

	}
	else if (stringsep[0] == 'j' || stringsep[0] == 'J') {

		return 9;

	}
	else if (stringsep[0] == 'k' || stringsep[0] == 'K') {

		return 10;

	}
	else if (stringsep[0] == 'l' || stringsep[0] == 'L') {

		return 11;

	}
	else if (stringsep[0] == 'm' || stringsep[0] == 'M') {

		return 12;

	}
	else if (stringsep[0] == 'n' || stringsep[0] == 'N') {

		return 13;

	}
	else if (stringsep[0] == 'ñ' || stringsep[0] == 'Ñ') {

		return 14;

	}
	else if (stringsep[0] == 'o' || stringsep[0] == 'O') {

		return 15;

	}
	else if (stringsep[0] == 'p' || stringsep[0] == 'P') {

		return 16;

	}
	else if (stringsep[0] == 'q' || stringsep[0] == 'Q') {

		return 17;

	}
	else if (stringsep[0] == 'r' || stringsep[0] == 'R') {

		return 18 ;

	}
	else if (stringsep[0] == 's' || stringsep[0] == 'S') {

		return 19;

	}
	else if (stringsep[0] == 't' || stringsep[0] == 'T') {

		return 20;

	}
	else if (stringsep[0] == 'u' || stringsep[0] == 'U') {

		return 21;

	}
	else if (stringsep[0] == 'v' || stringsep[0] == 'V') {

		return 22;

	}
	else if (stringsep[0] == 'w' || stringsep[0] == 'W') {

		return 23;

	}
	else if (stringsep[0] == 'x' || stringsep[0] == 'X') {

		return 24;

	}
	else if (stringsep[0] == 'y' || stringsep[0] == 'Y') {

		return 25;

	}
	else if (stringsep[0] == 'z' || stringsep[0] == 'Z') {

		return 26;

	}
	else { return -1; }

}


template <class T>
void ListaDoble<T>::add_first(T *dato,string name)
{
	Nodo *n = new Nodo(dato,name);
	//En el siguiente if else is esta vacia la lista agregamos el nodo y sera el primero y el ultimo
	if (isEmpty())
	{
		this->first = n;
		this->last = n;
		this->size++;

	}
	else
	{

		n->setNext(this->first); //al nuevo nodo crado, le desimos que su siguiente apunte al primero
		this->first->setBefore(n);//el anterior del primero apunta al nuevo
		this->first = n;//ahora el primero sera el nuevo

		this->size++;

	}
}
template <class T >
void ListaDoble<T>::add_last(T *dato, string name)
{
	Nodo *n = new Nodo(dato,name);

	if (isEmpty())
	{ //si esta vacia los dos apuntadores primero y ultimo apuntan al nuevo
		this->first = n;
		this->last = n;
		this->size++;

	}
	else {

		this->last->setNext(n); // el siguiente del ultimo apunta al nuevo
		n->setBefore(this->last);// el anterior del nuevo apunta al ultimo
		this->last = n;// el ultimo apunta al nuevo

		this->size++;

	}

}

template <class T>
void ListaDoble<T>::add_at(T *dato,string name, int index)
{
	if (index > 0 && index <= this->size)
	{
		if (index == 0) { this->add_first(dato,name); return; } // si agrega al inicio
		if (index == this->size) { this->add_list(dato,name); return; } //para agregar al final

		Nodo *aux = this->first;
		int x = 0;
		while (x != this->size) {

			if (x == index) { break; }
			aux = aux->getNext(); // el auxiliar apuntara al siuiente para moverse en la lista hasta encontrar el indice
			x++;
		}
		Nodo *n = new Nodo(dato,name);
		aux->getBefore()->setNext(n);// el siguiente del anterior del auxiliar apuntara al nuevo
		n->setBefore(aux->getBefore()); // el anterior del nuevo apuntara al anterior del aux
		n->setNext(aux); // el siguiente del nuevo apuntara al aux
		aux->setBefore(n); //el anterior del aux apuntara al nuevo
		this->size++;

	}

}

template <class T>
T *ListaDoble <T>::get_element_at(int index)
{

	if (index >= 0 && index< size)
	{
		Nodo *iterador = this->first; // nos ayudara a recorrer la lista
		int x = 0;
		while (iterador != 0)
		{
			if (index == x) { return iterador->getDato(); break; } //al encontrar el dato de ese nodo
			iterador = iterador->getNext();// continua hasta que se cumpla la condicion o con un break
			x++;
		}
	}

}

template <class T>
void ListaDoble <T>::print_front_back()
{
	cout << endl;
	Nodo *aux = this->first; //empieza apuntando al primero par recorrer
	int x = 0;
	while (x != this->size) { // para hasta que se recorra toda la lista 1 vez

		if (x == this->size) { break; }
		
		cout <<x<<": "<<aux->getName() << endl; // obtiene e imprime los datos
		aux = aux->getNext(); // apunta al siguiente para recorrer
		x++;
	}


}

template <class T>
T ListaDoble <T>::print_back_front()
{
	Nodo *aux = this->last; //apunta al ultimo par recorrer desde el final
	int x = 0;

	while (x != this->size) { //recorre alrevez 1 vez

		if (x == this->size) { break; }
		cout << aux->getDato() << endl;// imprime
		aux = aux->getBefore();// apunta al anterior para recorrer
		x++;
	}

}

template <class T>
void ListaDoble<T>::addOrder(T *dato, string name)
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

template <class T>
void ListaDoble<T>::graph()
{
	Nodo *aux = this->first;
	string graf = "digraph { \n";
	graf = graf + "node[shape=box, width = 2.5, height = .75 ]; \n";

	//cout << " digraph {" << endl;
	//cout << "node[shape=box, width = 2.5, height = .75 ];" << endl;

	/*if (this->size == 1)
	{
		graf = graf + aux->getName();
		//cout << aux->getName() << endl;
	}*/

		while (aux != 0) { // para hasta que se recorra toda la lista 1 vez
			//cout << "entro" << endl;
			if (aux->getNext() == 0){  break;}
			
				//cout << aux->getName() << "->" << aux->getNext()->getName() << endl; // obtiene e imprime los datos
				graf = graf +"\""+ aux->getName()+"\"";
				graf = graf + "->";
				graf = graf +"\""+ aux->getNext()->getName()+"\"";
				graf = graf + "\n";
				graf = graf + "\""+aux->getNext()->getName()+"\"";
				graf = graf + "->";
				graf = graf + "\""+aux->getName()+"\"";
				graf = graf + "\n";
		
			aux = aux->getNext(); // apunta al siguiente para recorrer
			//x++;
		}

	cout << endl;
	cout << "}" << endl; //el final del dot
	graf = graf + "\n";
	graf = graf + "}";

	ofstream g("graficaDob.dot");
	cout << graf << endl;
	g << graf;
	g.close();
	system("dot -Tpng graficaDob.dot -o grafDoble.png");
	system("grafDoble.png");


}

#endif // ListaDoble_H_INCLUDED

