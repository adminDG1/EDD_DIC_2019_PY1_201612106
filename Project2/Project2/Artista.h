#pragma once
#ifndef ARTISTA_H_INCLUDED
#define ARTISTA_H_INCLUDED
#include "matriz.h"

class Artista
{

private:
	string name;
	Matriz *matriz;



public:
	Artista(string name_, Matriz *matriz_)
	{
		name = name_;
		matriz = matriz_;

	}

	string getName() { return name; };
	Matriz *getMatriz() { return matriz; };

};

#endif // ARTISTA_H_INCLUDED
