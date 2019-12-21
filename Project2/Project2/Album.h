#pragma once
#ifndef ALBUM_H_INCLUDED
#define ALBUM_H_INCLUDED
#include "Cancion.h"
#include "ListaSimple.h"
#include <iostream>
#include <fstream>
#include <iomanip> //para stw

using namespace std;

class Album {

private:
	string name;
	string month;
	int ano;
	ListaSimple *lista;
	int rating;

public:
	Album(string name_, string month_, int ano_, ListaSimple *lista_,int rating_)
	{
		name = name_;
		month = month_;
		ano = ano_;
		lista = lista_;
		rating = rating_;

	}

	string getName() { return name; };
	void setName(string n) { name = n; };
	string getMonth() { return month; };
	int getAno() { return ano; };
	int getRating() { return rating; };

	void setMonth(string m) { month = m; };
	ListaSimple *getLista() { return lista; };
	void setLista(ListaSimple *l) { lista = l; };

};


#endif // ALBUM_H_INCLUDED
