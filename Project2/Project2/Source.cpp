#pragma once
#include <iostream>
#include <fstream>
#include <iomanip> //para stw
#include <nlohmann/json.hpp>
#include "Cancion.h"
#include "ListaArtista.h"
#include "Pila.h"
#include "Cola.h"
#include "ListaSimple.h"
#include "ListaCircula.h"

#include "Artista.h"
#include "Album.h"
#include "Cancion.h"
#include "matriz.h"
#include "PlayList.h"
//#include "Arbol.h"
#include <cstdlib> 

using json = nlohmann::json;
using namespace std;

class Menu
{
private:
	ListaDoble<Artista> *ListArt;
	ListaDoble<Cancion> *ListBySon; // guarda todas las canciones
	//Arbol *ListArb;

public:
	Menu()
	{
	ListArt = new ListaDoble<Artista>();
	ListBySon = new ListaDoble<Cancion>;
		PrintMenu();
	}

	void PrintMenu();
	//1
	void MenuLibrary();
	void InsertarLibreria();
	void MenuReportes();
	ListaDoble<Artista> *listaTopArt(ListaDoble<Artista> *list);
	void insertarPlayList();

};



ListaDoble<Artista> *Menu::listaTopArt(ListaDoble<Artista> *list)
{
	ListaDoble<Artista> *listNueva = new ListaDoble<Artista>();
	int x = 0;
	string graf = "digraph { \n";
	graf = graf + "node[shape=box, width = 2.5, height = .75 ]; \n";
	while (x < list->getsize())
	{
		cout << "recorreViej" << endl;
		cout << list->get_element_at(x)->getName()<<endl;

		if (listNueva->getsize() == 0) {

			listNueva->add_at(list->get_element_at(0), list->get_element_at(0)->getName(),0);
			cout<<"anade a nueva: "<<listNueva->get_element_at(0)->getName()<<endl;
		}
		else {
			int x1 = 0;
			while(x1 <= listNueva->getsize())
			{
				cout << "RecorridoNuevo" << endl;
				if (x1 == listNueva->getsize())
				{
					listNueva->add_at(list->get_element_at(x), list->get_element_at(x)->getName(),x1);
				cout << "anade a nuevaFin: " << listNueva->get_element_at(0)->getName() << endl;
				break;
					
				}//final
				else {
					if (list->get_element_at(x)->getRanking()  < listNueva->get_element_at(x1)->getRanking()) {

						listNueva->add_at(list->get_element_at(x), list->get_element_at(x)->getName(),x1);
						cout << "anade a nuevamedio: " << listNueva->get_element_at(0)->getName() << endl;
						break;
					}
					else if (list->get_element_at(x)->getRanking()  == listNueva->get_element_at(x1)->getRanking())
					{
						listNueva->add_at(list->get_element_at(x), list->get_element_at(x)->getName(), x1);
						cout << "anade a nuevaigual: " << listNueva->get_element_at(0)->getName() << endl;
						break;
					}
				}

				x1++;
		}
		}

		x++;
	}
	return listNueva;
}

void Menu::PrintMenu() {

	int op;


	cout << "                ---------------------------------------------MENU---------------------------------------------" << endl;
	cout<< endl;
	cout << "                                    -               1 -  Carga                       -" << endl;
	cout << "                                    --------------------------------------------------" << endl;
	cout << "                                    -               2 -  Search Artista              -" << endl;
	cout << "                                    --------------------------------------------------" << endl;
	cout << "                                    -               3 -  Search Cancion              -" << endl;
	cout << "                                    --------------------------------------------------" << endl;
	cout << "                                    -               4 -  VerPlayLists                -" << endl;
	cout << "                                    --------------------------------------------------" << endl;
	cout << "                                    -               5 -  Reportes                    -" << endl;
	cout << endl;
	cout << "                ----------------------------------------------------------------------------------------------" << endl;
	cout << "\n";
	cout << "                            INGRESE UNA OPCION   --->  ";
	cin >> op;
	cout << "\n";

		//variables case 2:



	// Verificar Opción Ingresada
		if (op == 1)
		{

			system("cls");
			cout << "\nOpcion Ingresada -> 1" << endl;
			MenuLibrary();
		
		}
		else if (op == 2)
		{
			
				system("cls");
				cout << "-----------------Artistas-----------------" << endl;
				ListArt->print_front_back();
				cout << "-------------SeleccionaArtista------------" << endl;
				int opArt;
				cin >> opArt;
				system("cls");
				cout << "-----------------Albums-------------------" << endl;
				ListArt->get_element_at(opArt)->getMatriz()->graph();
				cout << endl;
				cout << "-------------SeleccionaAlbum--------------" << endl;
				cout << endl;
				cin.ignore();
				cout << "-------------IngresaNombre--------------" << endl;
				string opAlbN;
				getline(cin, opAlbN);
				cout << endl;
				cout << "-------------IngresaAno--------------" << endl;
				int opAlbA;
				cin >> opAlbA;
				cout << endl;
				cin.ignore();
				cout << "-------------IngresaMes--------------" << endl;
				string opAlbM;
				getline(cin, opAlbM);
				cout << endl;
				system("cls");
				//ListArt->get_element_at(0)->getMatriz()->obtenerNodo("Septiembre", 2019, "Shaped By Fire")->getAlbum()->getLista()->print_front_back();
				ListArt->get_element_at(opArt)->getMatriz()->obtenerNodo(opAlbM, opAlbA, opAlbN)->getAlbum()->getLista()->print_front_back();//muestro canciones album
				cout << endl;
				cout << "-------------SeleccionaCancion--------------" << endl;
				cout << endl;
				cout << "-------------IngresaNombre--------------" << endl;
				string opCanN;
				getline(cin, opCanN);

				ListArt->get_element_at(opArt)->getMatriz()->obtenerNodo(opAlbM, opAlbA, opAlbN)->getAlbum()->getLista()->printCancion(opCanN);//muestro canciones album
				cout << endl;

				getline(cin, opCanN);
				PrintMenu();

		}
		else if (op == 3)
		{
			system("cls");
			cout << "\nOpcion Ingresada -> 3" << endl;
			ListBySon->print_front_back();
			cout << "-------------SeleccionaCancion------------" << endl;
			int opArt;
			cin >> opArt;
			cout << endl;
			cout << "-------------DatosCancion------------" << endl;
			cout << endl;
			cout << ListBySon->get_element_at(opArt)->getName()<< endl;
			cout << endl;
			cout << ListBySon->get_element_at(opArt)->getFile()<< endl;
			cout << ListBySon->get_element_at(opArt)->getRating() << endl;
			cout << "----------------------------------------" << endl;
			std::cin.get();
			PrintMenu();
		}
		else if (op == 4)
		{
			cout << "\nOpcion Ingresada -> 4" << endl;
	
		}
		else if (op == 5)
		{
			cout << "\nOpcion Ingresada -> 5" << endl;
			system("cls");
			MenuReportes();
		}
		else {}


	std::cin.get();
}

void Menu::MenuLibrary()
{
	int op;


	cout << "                ---------------------------------------------MENU---------------------------------------------" << endl;
	cout << endl;
	cout << "                                    -               1 -  CargaLibreria               -" << endl;
	cout << "                                    --------------------------------------------------" << endl;
	cout << "                                    -               2 -  CargaPlayList              -" << endl;
	cout << "                                    --------------------------------------------------" << endl;
	cout << endl;
	cout << "                3- Regresa Menu                                                       " << endl;
	cout << endl;
	cout << "                ----------------------------------------------------------------------------------------------" << endl;
	cout << "\n";
	cout << "                            INGRESE UNA OPCION   --->  ";
	cin >> op;
	cout << "\n";

	// Verificar Opción Ingresada
	switch (op) {

	case 1:

		system("cls");
		cout << "\nCargandoLibreria -> 1" << endl;
		InsertarLibreria();
		MenuLibrary();
		break;

	case 2:

		system("cls");
		cout << "\nOpcion Ingresada -> 2" << endl;
		break;

	case 3:

		system("cls");
		PrintMenu();
		break;

	}
	std::cin.get();

}

void Menu::InsertarLibreria()
{
	////////////////////////////////////
	//para leer al json

	ifstream i("Library_test.json");
	json j;
	i >> j; // paso todo el archivo a el json

	json j2, j3, j4, jalbums, j5, j6, j7;

	string albums;//guarda el  arreglo albums

	Matriz *listMat;
	ListaSimple *ListSim;

	Artista *varArt;
	Album *varAlb;


	// special iterator member functions for objects
	for (json::iterator it = j.begin(); it != j.end(); ++it) { //obtengo contenido de library

	/*	std::cout << it.key() << "->" << it.value() << "\n";
		cout << endl;
		cout << endl;*/

		j2 = it.value();
	}

/*	cout << j2 << endl;//imprimo el arreglo
	cout << endl;
	cout << endl;
	*/


	// iterate the array
	for (json::iterator it = j2.begin(); it != j2.end(); ++it) //itero el arreglo obtengo artistas con json
	{
	/*	cout << "-----------------------------artistas con Json--------------------------" << endl;
		std::cout << *it << "\n";
		cout << endl;
		*/
		j3 = *it;//consigo los artistas;

		for (json::iterator it2 = j3.begin(); it2 != j3.end(); ++it2)
		{
			string nameAlb = "art";//guardo el nombre del album
			listMat = new Matriz();
			int rankA = 0;

		//	std::cout << it2.value() << "\n";// obtengo albums y nombre artista en json
			j4 = it2.value();
			//cout << endl;
		//	cout << endl;
			for (json::iterator it3 = j4.begin(); it3 != j4.end(); ++it3) //obtengo los albums y el nombre separados del artista
			{
				//std::cout << it3.key() << "->" << it3.value() << "\n";
				//cout << endl;
				//cout << endl;

				jalbums = it3.key(); // obtengo llave albums y llave name
				//cout << endl;




				if (jalbums.get_to(albums) == "Albums") // si la llave es igual a los albums //ya casteadas a string sin ""
				{

					//itero el array en it3.value()de los albums
					for (json::iterator it4 = it3.value().begin(); it4 != it3.value().end(); ++it4) //obtengo los albums del artista separados 
					{
						ListSim = new ListaSimple(); //nuevo obj listaSim
					//	std::cout << *it4 << "\n";
						//cout << endl;
						//cout << endl;
						j5 = *it4;

						string nameA;
						string MonthA;
						int yearA = 0;
						int RatingA = 0;

						for (json::iterator it5 = j5.begin(); it5 != j5.end(); ++it5) //obtengo las caracteristicas de el album
						{															 // Month , Name , Songs , Year , Name
							//std::cout << it5.key() << "->" << it5.value() << "\n";
							//cout << endl;
							//cout << endl;

							j6 = it5.value();

							if (it5.key() == "Songs") // obtengo el json de las canciones
							{
								for (json::iterator it6 = j6.begin(); it6 != j6.end(); ++it6) //obtengo el json de las canciones
								{

								//	cout << *it6 << endl;
									//cout << endl;
									j7 = *it6;

									Cancion *can;
									string nameCan;
									string fileCan;
									int ratCan;
									for (json::iterator it7 = j7.begin(); it7 != j7.end(); ++it7) // obtengo los datos de las canciones 
									{

										if (it7.key() == "Name")
										{
										//	cout << "-----------------------------Name Cancion--------------------------" << endl;
											//std::cout << it7.value() << "\n";
											json nC = it7.value();
											string strname;
											nC.get_to(strname);
											nameCan = strname;
										}
										else if (it7.key() == "File")
										{
											//cout << "----------------------------- File Cancion--------------------------" << endl;
											//std::cout << it7.value() << "\n";
											json nF = it7.value();
											string strfile;
											nF.get_to(strfile);
											fileCan = strfile;

										}
										else if (it7.key() == "Rating")
										{
											//cout << "----------------------------- Rating Cancion--------------------------" << endl;
											//std::cout << it7.value() << "\n";
											json rat = it7.value();
											string stringo;
											rat.get_to(stringo);
											ratCan = atoi(stringo.c_str());
											RatingA = RatingA + ratCan;
										}

									}
									can = new Cancion(nameCan, ratCan, fileCan);
									
									ListSim->push(can);
									ListBySon->addOrder(can,nameCan);//guarda a una lista todas las canciones ordenadas

								}

							}
							else if (it5.key() == "Name") // else para Month , Name  , Year , Name del album
							{
								//cout << "-----------------------------Name Album--------------------------" << endl;
								//cout << it5.value() << endl;
								json rat = it5.value();
								string strname;
								rat.get_to(strname);
								nameA = strname;

							}
							else if (it5.key() == "Month")
							{
								//cout << "-----------------------------Month Album--------------------------" << endl;
								//cout << it5.value() << endl;
								json rat = it5.value();
								string strmonth;
								rat.get_to(strmonth);
								MonthA = strmonth;
							}
							else if (it5.key() == "Year")
							{
								//cout << "-----------------------------Year Album--------------------------" << endl;
								//cout << it5.value() << endl;
								json rat = it5.value();
								string stryear;
								rat.get_to(stryear);
								yearA = atoi(stryear.c_str());
							}

						}
						rankA = rankA + RatingA;//rankA guarda rank artista
						varAlb = new Album(nameA, MonthA, yearA, ListSim,RatingA); //creo album
						cout << RatingA << endl;
						listMat->InsertarNodo(varAlb, yearA, MonthA);
					}
				}     //
				else // else entra si el key no es Albums en Name, del artista
				{

					//cout << "-----------------------------Nombre Artista--------------------------" << endl;
					//cout << it3.value() << endl;

					json rat = it3.value();
					string strname;
					rat.get_to(strname);
					nameAlb = strname;

				}


			}//fin for 2

			varArt = new Artista(nameAlb, listMat,rankA); // guardo el artista
			ListArt->addOrder(varArt, nameAlb);
		} // fin for 1
		//cout << endl;
	}

	//ListArt->graph();
}//insertar Libreria

void Menu::MenuReportes()
{
	int op;


	cout << "                ---------------------------------------------MENU---------------------------------------------" << endl;
	cout << endl;
	cout << "                                    -               1 -  Artist                       -" << endl;
	cout << "                                    --------------------------------------------------" << endl;
	cout << "                                    -               2 -  Discography                  -" << endl;
	cout << "                                    --------------------------------------------------" << endl;
	cout << "                                    -               3 -  Album                        -" << endl;
	cout << "                                    --------------------------------------------------" << endl;
	cout << "                                    -               4 -  PlayList                     -" << endl;
	cout << "                                    --------------------------------------------------" << endl;
	cout << "                                    -               5 -  Top 5 Albums by Artist       -" << endl;
	cout << "                                    --------------------------------------------------" << endl;
	cout << "                                    -               6 -  Top 5 Artist                 -" << endl;
	cout << "                                    --------------------------------------------------" << endl;
	cout << endl;
	cout << "                7 ->  RegresaMenu                                                      " << endl;
	cout << endl;
	cout << "                ----------------------------------------------------------------------------------------------" << endl;
	cout << "\n";
	cout << "                            INGRESE UNA OPCION   --->  ";
	cin >> op;
	cout << "\n";

	int cont = 0;
	// Verificar Opción Ingresada
	switch (op) {

	case 1:

		try
		{
			system("cls");
			ListArt->graph();
			MenuReportes();
		}
		catch (const std::exception&)
		{

		}

		break;

	case 2:
		
		try
		{
			system("cls");
			cout << "-----------------Artistas-----------------" << endl;
			ListArt->print_front_back();
			cout << "-------------SeleccionaArtista------------" << endl;
			int opArt;
			cin >> opArt;
			system("cls");
			cout << "-----------------Albums-------------------" << endl;
			ListArt->get_element_at(opArt)->getMatriz()->graficar();
			MenuReportes();
		}
		catch (const std::exception&)
		{

		}
		
		break;

	case 3:

		try
		{
			system("cls");
			cout << "-----------------Artistas-----------------" << endl;
			ListArt->print_front_back();
			cout << "-------------SeleccionaArtista------------" << endl;
			int opArt;
			cin >> opArt;
			system("cls");
			cout << "-----------------Albums-------------------" << endl;
			ListArt->get_element_at(opArt)->getMatriz()->graph();
			cout << endl;
			cout << "-------------SeleccionaAlbum--------------" << endl;
			cout << endl;
			cin.ignore();
			cout << "-------------IngresaNombre--------------" << endl;
			string opAlbN;
			getline(cin, opAlbN);
			cout << endl;
			cout << "-------------IngresaAno--------------" << endl;
			int opAlbA;
			cin >> opAlbA;
			cout << endl;
			cin.ignore();
			cout << "-------------IngresaMes--------------" << endl;
			string opAlbM;
			getline(cin, opAlbM);
			cout << endl;
			system("cls");
			ListArt->get_element_at(opArt)->getMatriz()->obtenerNodo(opAlbM, opAlbA, opAlbN)->getAlbum()->getLista()->graph();//muestro canciones album
			MenuReportes();
		}
		catch (const std::exception&)
		{

		}
		break;

	case 4:

		system("cls");
		cout << "\nOpcion Ingresada -> 4" << endl;

		break;
	case 5:

		system("cls");
		cout << "-----------------Artistas-----------------" << endl;
		ListArt->print_front_back();
		cout << "-------------SeleccionaArtista------------" << endl;
		int opArt;
		cin >> opArt;
		cout << "------------------------------------------" << endl;
		//cont = 0;
		//while (cont <= 4)
		
	//	{	
			//if (cont < ListArt->get_element_at(opArt)->getMatriz()->obtenerTop5()->getsize())
		//	{
//				cout << cont + 1 << ": " << ListArt->get_element_at(opArt)->getMatriz()->obtenerTop5()->get_element_at(cont)->getName() << ListArt->get_element_at(opArt)->getMatriz()->obtenerTop5()->get_element_at(cont)->getRating() << endl;
		ListArt->get_element_at(opArt)->getMatriz()->obtenerTop5()->graph_back_front();
			//}
			//cont++;
		//}
		cin >> opArt;
		system("cls");
		MenuReportes();
		break;

	case 6:

		system("cls");
		
		listaTopArt(ListArt)->graph_back_front_Art();
		MenuReportes();
		break;

	case 7:

		system("cls");
		cout << "\nOpcion Ingresada -> 7" << endl;
		PrintMenu();
		break;

	default:
		break;

	}
	std::cin.get();
}

void Menu::insertarPlayList()
{
	//-----------------------------------------------for para las playList---------------------------------------------------------------

/*	PlayList *play;
	Pila *pilaPlay;
	Cola *colaplay;
	ListaCircular<Cancion> *circularPlay;
	ListaDoble<Cancion> *doblePlay;
*/
	ifstream i2("Playlist_Rock.json");
	json js0;
	i2 >> js0; // paso todo el archivo a el json
	json js1;
	json js2;


	for (json::iterator it = js0.begin(); it != js0.end(); ++it) //for recibe json playList

	{
		if (it.key() == "Type")
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
				cout << *it1 << endl;
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
}

int main()
{
	Menu *menu = new Menu();
	/*
	//PrintMenu();
	ListaDoble<Cancion> *ld = new ListaDoble<Cancion>();
	Cancion *c = new Cancion("Aila", 3, "file.mp3");
	Cancion *c1 = new Cancion("Fila", 3, "file1.mp3");
	Cancion *c2 = new Cancion("Bila", 3, "file2.mp3");
	ld->addOrder(c, c->getName());
	ld->addOrder(c1, c1->getName());
	ld->addOrder(c2, c2->getName());
	ld->print_front_back();
	//ld->graph();

	Pila *pi = new Pila();
	pi->push(c);
	pi->push(c1);
	pi->push(c2);

	Cola *col = new Cola();
	col->enqueue(c);
	col->enqueue(c1);
	col->enqueue(c2);

	ListaSimple *ls = new ListaSimple();
	ls->push(c);
	ls->push(c1);
	ls->push(c2);
	//ls->graph();
	*/

	/*
	cout<<o["weather"]<<endl;
	string stringo;
	o["weather"].get_to(stringo);
	cout << stringo << endl;
	*/
	
		//cout << j3 << endl;

		//ListArt->graph();

//		ListArt->get_element_at(0)->getMatriz()->obtenerNodo("Septiembre",2019, "Shaped By Fire")->getAlbum()->getLista()->graph();

		//listMat->graficar();
		//ListSim->graph();
		
//-----------------------------------------------for para las playList---------------------------------------------------------------

		/*
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
		*/



	std::cin.get();
		return 0;
}


 
