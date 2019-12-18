#pragma once
#include <iostream>
#include <fstream>
#include <iomanip> //para stw
#include <nlohmann/json.hpp>
#include "Cancion.h"
#include "ListaArtista.h"
#include <cstdlib> 

using json = nlohmann::json;
using namespace std;

int main()
{
	ListaDoble<Cancion> *ld = new ListaDoble<Cancion>();
	Cancion *c = new Cancion("Aila", 3, "file.mp3");
	Cancion *c1 = new Cancion("Fila", 3, "file1.mp3");
	Cancion *c2 = new Cancion("Bila", 3, "file2.mp3");
	ld->addOrder(c, c->getName());
	ld->addOrder(c1, c1->getName());
	ld->addOrder(c2, c2->getName());
	ld->print_front_back();
	ld->graph();
	/*
	// a JSON value
	json j_original = R"({
  "baz": [{"bar":"b1"},{"bar1":"b1"}],
  "foo": {"bar":"b","bar3":"h"}
})"_json;

	// access members with a JSON pointer (RFC 6901)
	cout << j_original["/foo/bar3"_json_pointer] << endl;
	cout << j_original["/baz/1/bar1"_json_pointer] << endl;
	//cout<<j_original["baz/Name"]<<endl;
	// "two"

	// ]

	// create a JSON object with different entry types
	json js =
	{
		{ "integer", 1 },
		{ "floating", 42.23 },
		{ "string", "hello world" },
		{ "boolean", true },
		{ "object",{ { "key1", 1 },{ "key2", 2 } } },
		{ "array",{ 1, 2, 3 } }
	};

	// access existing values
	//int v_integer = j_original.value("foo", 0);
	//cout << v_integer<<endl;

	
	cout << endl;



	//

	// create an array using push_back
	json jd;
	jd.push_back("foo");
	jd.push_back(1);
	jd.push_back(true);

	// also use emplace_back
	jd.emplace_back(1.78);
	cout << jd << endl;

	// iterate the array
	for (json::iterator it = jd.begin(); it != jd.end(); ++it) {
		std::cout << *it << '\n';
	}

	/* range-based for
	for (auto& element : jd) {
		std::cout << element << '\n';
	}

	// getter/setter
	const auto tmp = jd[0].get<std::string>();
	jd[1] = 42;
	bool foo = jd.at(2);

	// range-based for
	for (auto& element : jd) {
		std::cout << element << '\n';
	} */
	cout << endl;
	cout << endl;

	/////////////////////////////////////////////
	/*
	json o;
	o["foo"] = 23;
	o["bar"] = false;
	o["baz"] = 3.141;

	// also use emplace
	o.emplace("weather", "sunny");

	cout << o << endl;

	// special iterator member functions for objects
	for (json::iterator it = o.begin(); it != o.end(); ++it) {
		std::cout << it.key() << " : " << it.value() << "\n";
	}
	cout << endl;
	cout<<o["weather"]<<endl;
	string stringo;
	o["weather"].get_to(stringo);
	cout << stringo << endl;
	*/
	
	////////////////////////////////////
	//para leer al json

	ifstream i("test.json");
	json j;
	i >> j; // paso todo el archivo a el json

	json j2;
	json j3;
	json j4;
	json jalbums;
	json j5;
	json j6;
	json j7;

	string albums;//guarda el  arreglo albums
	/*
	string serialized_string = j.dump();
	//cout << serialized_string << endl;
	cout << endl;
	cout << j["/Library/1/Artist/Name"_json_pointer] << endl;
	cout << endl;
	cout << endl; */

	// special iterator member functions for objects
	for (json::iterator it = j.begin(); it != j.end(); ++it) { //obtengo contenido de library

		std::cout << it.key() << "->" << it.value() << "\n";
		cout << endl;
		cout << endl;

		j2 = it.value();
	}
	cout << j2<<endl;//imprimo el arreglo
	cout << endl;
	cout << endl;

	
		// iterate the array
		for (json::iterator it = j2.begin(); it != j2.end(); ++it) //itero el arreglo obtengo artistas con json
		{
			cout << "-----------------------------artistas con Json--------------------------" << endl;
			std::cout << *it  << "\n";
			cout << endl;
			
			j3 = *it;//consigo los artistas;
			for (json::iterator it2 = j3.begin(); it2 != j3.end(); ++it2)
			{
				
				std::cout  << it2.value() << "\n";// obtengo albums y nombre artista en json
				j4 = it2.value();
				cout << endl;
				cout << endl;
				for (json::iterator it3 = j4.begin(); it3 != j4.end(); ++it3) //obtengo los albums y el nombre separados del artista
				{
					std::cout << it3.key() << "->" << it3.value() << "\n";
					cout << endl;
					cout << endl;

					jalbums = it3.key(); // obtengo llave albums y llave name
					cout << endl;

					if (jalbums.get_to(albums) == "Albums") // si la llave es igual a los albums //ya casteadas a string sin ""
					{
						//itero el array en it3.value()de los albums
						for (json::iterator it4 = it3.value().begin(); it4 != it3.value().end(); ++it4) //obtengo los albums del artista separados 
						{

							std::cout << *it4 << "\n";
							cout << endl;
							cout << endl;
							j5 = *it4;
							for (json::iterator it5 = j5.begin(); it5 != j5.end(); ++it5) //obtengo las caracteristicas de el album
							{															 // Month , Name , Songs , Year , Name
								std::cout << it5.key() << "->" << it5.value() << "\n";
								cout << endl;
								cout << endl;

								j6 = it5.value();

								if (it5.key() == "Songs") // obtengo el json de las canciones
								{
									

									for (json::iterator it6 = j6.begin(); it6 != j6.end(); ++it6) //obtengo el json de las canciones
									{
										
										cout << *it6 << endl;
										cout << endl;
										j7 = *it6;
										for (json::iterator it7 = j7.begin(); it7 != j7.end(); ++it7) // obtengo los datos de las canciones 
										{
											if (it7.key() == "Name")
											{
												cout << "-----------------------------Name Cancion--------------------------" << endl;
												std::cout  << it7.value() << "\n";

											}
											else if(it7.key() == "File")
											{
												cout << "----------------------------- File Cancion--------------------------" << endl;
												std::cout << it7.value() << "\n";

											}
											else if (it7.key() == "Rating")
											{
												cout << "----------------------------- Rating Cancion--------------------------" << endl;
												std::cout << it7.value() << "\n";
											}

										}

									}

								} else if (it5.key() == "Name") // else para Month , Name  , Year , Name
								{
									cout << "-----------------------------Name Album--------------------------" << endl;
									cout << it5.value() << endl;
								}
								else if (it5.key() == "Month")
								{
									cout << "-----------------------------Month Album--------------------------" << endl;
									cout << it5.value() << endl;
								}
								else if (it5.key() == "Year")
								{
									cout << "-----------------------------Year Album--------------------------" << endl;
									cout << it5.value() << endl;
								}
								
							}

						}
					}     //
					else // else entra si el key no es Albums en Name, del artista
					{

						cout << "-----------------------------Nombre Artista--------------------------" << endl;
						cout <<it3.value()<< endl;

					}
				}//fin for 2

			} // fin for 1
			cout << endl;
		} 

		//cout << j3 << endl;

//-----------------------------------------------for para las playList---------------------------------------------------------------

		ifstream i2("Playlist_Rock.json");
		json js0;
		i2 >> js0; // paso todo el archivo a el json
		json js1;
		json js2;

		for (json::iterator it = js0.begin(); it != js0.end(); ++it) //for recibe json playList
		
		{
			if (it.key() == "Type" )
			{
				cout << "-----------------------------TIPOPLayLIStss--------------------------" << endl;
				if (it.value() == "Stack")
				{
					cout << it.value() << endl;
				}

				else if (it.value() == "Queue")
				{
					cout << it.value() << endl;
				}
				else if (it.value() == "Shuffle")
				{
					cout << it.value() << endl;
				}
				else if (it.value() == "Circular")
				{
					cout << it.value() << endl;
				}
			}
			else if (it.key() == "Songs")
			{
				cout << "-----------------------------Songs PlayList--------------------------" << endl;
				js1 = it.value();
				for (json::iterator it1 = js1.begin(); it1 != js1.end(); ++it1) //for recibe json de las Canciones de la PlayList
				{ 
					cout << *it1<<endl;
					js2 = *it1;
					for (json::iterator it2 = js2.begin(); it2 != js2.end(); ++it2) // obttengo los datos del json
					{
						if (it2.key() == "Year")
						{
							cout << "-----------------------------Year Song--------------------------" << endl;
							cout << it2.value() << endl;
						}
						else if (it2.key() == "Month")
						{
							cout << "-----------------------------Month song--------------------------" << endl;
							cout << it2.value() << endl;
						}
						else if (it2.key() == "Album")
						{
							cout << "-----------------------------Album song--------------------------" << endl;
							cout << it2.value() << endl;
						}
						else if (it2.key() == "Song")
						{
							cout << "-----------------------------song song--------------------------" << endl;
							cout << it2.value() << endl;
						}
						else if (it2.key() == "Artist")
						{
							cout << "-----------------------------artista song--------------------------" << endl;
							cout << it2.value() << endl;
						}
						
					}

				}//fin for
			}


		}//fin for padre

	std::cin.get();
}


 