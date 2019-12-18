#pragma once
#ifndef CANCION_H_INCLUDED
#define CANCION_H_INCLUDED
#include <iostream>

using namespace std;

class Cancion {

private:
	string name;
	int rating;
	string file;

public:
	Cancion(string name_, int rating_, string file_)
	{

		name = name_;
		rating = rating_;
		file = file_;

	}

	string getName() { return name; }
	string setName(string n) { name = n; }
	int getRating() { return rating; }
	int setRating(int r) { rating = r; }


};

#endif // CANCION_H_INCLUDED
