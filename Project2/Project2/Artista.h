#pragma once
#ifndef ARTISTA_H_INCLUDED
#define ARTISTA_H_INCLUDED
#include "matriz.h"

class Artista
{

private:
	string name;
	Matriz *matriz;
	int ranking;


public:
	Artista(string name_, Matriz *matriz_,int ranking_)
	{
		name = name_;
		matriz = matriz_;
		ranking = ranking_;

	}

	string getName() { return name; };
	Matriz *getMatriz() { return matriz; };
	int getRanking() { return ranking; };
};

#endif // ARTISTA_H_INCLUDED
