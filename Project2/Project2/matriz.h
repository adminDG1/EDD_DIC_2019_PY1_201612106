#pragma once
#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED
#pragma once  
#include <iostream>
#include "Album.h"
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include "ListaArtista.h"

using namespace std;


class Matriz {

	class Nodo {

	private:
		// Información De Nodo
		Album* album;
		int año; // Cabecera X
		string mes; // Cabecera Y

					// Apuntadores
		Nodo* siguiente;
		Nodo* anterior;
		Nodo* arriba;
		Nodo* abajo;
		Nodo* adelante;
		Nodo* atras;

	public:

		Nodo(int año_, string mes_)
		{
			año = año_;
			mes = mes_;

			siguiente = 0;
			anterior = 0;
			arriba = 0;
			abajo = 0;
			adelante = 0;
			atras = 0;

		}

		Nodo(Album* album_, int año_, string mes_)
		{
			album = album_;
			año = año_;
			mes = mes_;

			siguiente = 0;
			anterior = 0;
			arriba = 0;
			abajo = 0;
			adelante = 0;
			atras = 0;

		}

		Album* getAlbum() { return album; };
		int getAño() { return año; };
		string getMes() { return mes; };
		Nodo* getSiguiente() { return siguiente; };
		Nodo* getAnterior() { return anterior; };
		Nodo* getArriba() { return arriba; };
		Nodo* getAbajo() { return abajo; };
		Nodo* getAdelante() { return adelante; };
		Nodo* getAtras() { return atras; };

		void setSiguiente(Nodo* siguiente_) { siguiente = siguiente_; };
		void setAnterior(Nodo* anterior_) { anterior = anterior_; };
		void setArriba(Nodo* arriba_) { arriba = arriba_; };
		void setAbajo(Nodo* abajo_) { abajo = abajo_; };
		void setAdelante(Nodo* adelante_) { adelante = adelante_; };
		void setAtras(Nodo* atras_) { atras = atras_; };

	};

private:

	Nodo *cabecera;

public:
	Matriz()
	{
		Nodo* nuevo = new Nodo(0, "0");
		cabecera = nuevo;

	}

	Nodo* getCabecera() { return cabecera; };

	void InsertarNodo(Album* album, int año, string mes)
	{
		// Agregar Cabeceras
		AgregarCabecera_x(año);
		AgregarCabecera_y(mes);

		// Crear Nodo
		Nodo* nuevo = new Nodo(album, año, mes);

		// Recorrer CabeceraX
		Nodo* temp = cabecera;
		while (temp != 0)
		{

			if (año == temp->getAño()) // Encontrar Año De Nodo A Insertar
			{

				if (temp->getAbajo() == 0) // Lista de año vacia
				{
					nuevo->setArriba(temp);
					temp->setAbajo(nuevo);

				}
				else
				{
					// Recorremos Mes
					Nodo* temp2 = temp;
					while (temp2 != 0)
					{
						if (ordenaMes(mes) == ordenaMes(temp2->getMes()))//insertar en z
						{
							Nodo* tempo = temp2;
							if (tempo->getAdelante() == 0)
							{
								tempo->setAdelante(nuevo);
								nuevo->setAtras(tempo);

							}
							else { // ARREGLAR AQUI
								tempo = tempo->getAdelante();
								while (tempo != 0)
								{
									if (tempo->getAdelante() == 0)
									{
										nuevo->setAtras(tempo);
										tempo->setAdelante(nuevo);
										break;
									}
									tempo = tempo->getAdelante();
								}
							}
							break;
						}
						else if (ordenaMes(mes) < ordenaMes(temp2->getMes()))
						{
							// Apuntadores
							temp2->getArriba()->setAbajo(nuevo);
							nuevo->setArriba(temp2->getArriba());
							nuevo->setAbajo(temp2);
							temp2->setArriba(nuevo);
							break;

						}
						else if (temp2->getAbajo() == 0)
						{
							// Colocar De Ultimo El Nodo
							nuevo->setArriba(temp2);
							temp2->setAbajo(nuevo);
							break;

						}

						temp2 = temp2->getAbajo();
					}

				}

			}

			temp = temp->getSiguiente();
		}

		// Recorrer CabeceraY
		Nodo* temp3 = cabecera;
		while (temp3 != 0)
		{

			if (ordenaMes(mes) == ordenaMes(temp3->getMes()))
			{

				if (temp3->getSiguiente() == 0) // Si Lista Me Vacia // MODIFICAMOS GETABAJO() A GETSIGUIENTE()
				{
					temp3->setSiguiente(nuevo);
					nuevo->setAnterior(temp3);
					break;
				}
				else  //en caso ya haya nodos
				{

					// Recorrer Años
					Nodo* temp4 = temp3;
					while (temp4 != 0)
					{
						if (año == temp4->getAño())
						{
							break;
						}
						else if (año < temp4->getAño())
						{
							// Apuntadores
							temp4->getAnterior()->setSiguiente(nuevo);
							nuevo->setAnterior(temp4->getAnterior());
							nuevo->setSiguiente(temp4);
							temp4->setAnterior(nuevo);
							break;

						}
						else if (temp4->getSiguiente() == 0) {

							// Colocar De Ultimo
							nuevo->setAnterior(temp4);
							temp4->setSiguiente(nuevo);
							break;

						}


						temp4 = temp4->getSiguiente();
					}

				}

			}

			temp3 = temp3->getAbajo();
		}

	}//fin insertar nodo

	void AgregarCabecera_x(int año)
	{

		// Crear Nodo CabeceraX
		Nodo* nuevaCabezaX = new Nodo(año, "0");

		// Verificar Si CabeceraX Vacia
		if (cabecera->getSiguiente() == 0)
		{

			// Apuntadores
			cabecera->setSiguiente(nuevaCabezaX);
			nuevaCabezaX->setAnterior(cabecera);
		}
		else // CabeceraX No Esta Vacia
		{

			// Recorrer CabeceraX
			Nodo* temp = cabecera->getSiguiente();
			while (temp != 0)
			{

				if (año == temp->getAño())
				{
					break;
				}
				else if (año < temp->getAño()) // Verificar Año Y Colocar Nuevo Nodo En Orden
				{
					// Apuntadores
					nuevaCabezaX->setAnterior(temp->getAnterior());
					nuevaCabezaX->setSiguiente(temp);

					temp->getAnterior()->setSiguiente(nuevaCabezaX);
					temp->setAnterior(nuevaCabezaX);
					break;

				}
				else if (temp->getSiguiente() == 0) // Si temp es ultimo
				{
					temp->setSiguiente(nuevaCabezaX);
					nuevaCabezaX->setAnterior(temp);
					break;
				}

				temp = temp->getSiguiente();
			}

		}
	}

	void AgregarCabecera_y(string mes) {

		// Crear Nodo CabeceraY
		Nodo* nuevaCabezaY = new Nodo(0, mes);


		// Recorrer CabeceraY
		Nodo* temp = cabecera;
		while (temp != 0)
		{


			if (ordenaMes(mes) == ordenaMes(temp->getMes()))
			{
				break;
			}
			else if (ordenaMes(mes) < ordenaMes(temp->getMes())) // Verificar Mes Y Colocar Nuevo Nodo En Orden
			{
				// Apuntadores
				nuevaCabezaY->setArriba(temp->getArriba());
				nuevaCabezaY->setAbajo(temp);

				temp->getArriba()->setAbajo(nuevaCabezaY);
				temp->setArriba(nuevaCabezaY);
				break;

			}
			else if (temp->getAbajo() == 0) // Si temp es ultimo
			{
				temp->setAbajo(nuevaCabezaY);
				nuevaCabezaY->setArriba(temp);
				break;
			}

			temp = temp->getAbajo();
		}




	}

	void recorer() {

		Nodo* rec = cabecera;
		while (rec != 0)
		{
			cout << rec->getAño() << endl;
			cout << "\n";

			rec = rec->getSiguiente();
		}

	}

	void graph()
	{
		try
		{



			Nodo* aux = this->cabecera->getSiguiente(); //empieza apuntando al primero par recorrer

			while (aux != 0) { // recorre cabeceras en x


				Nodo* aux2 = aux->getAbajo();
				while (aux2 != 0) // recorrer en y 
				{ 
					int cast = aux2->getAño();
					stringstream power;
					power << cast;
					string pepe = power.str(); //tendra el ano

					cout << "Name: " << aux2->getAlbum()->getName()<< endl;
					cout << "Year: " << aux2->getAlbum()->getAno() << endl;
					cout << "Month: " << aux2->getAlbum()->getMonth() << endl;
					cout << "-------------------------------------------" << endl;
					if (aux2->getAdelante() != 0) // recorre en z
					{
						Nodo* aux3 = aux2->getAdelante();
						while (aux3 != 0)
						{
							cout << "Name: " << aux3->getAlbum()->getName() << endl;
							cout << "Year: " << aux3->getAlbum()->getAno() << endl;
							cout << "Month: " << aux3->getAlbum()->getMonth() << endl;
							cout << "-------------------------------------------" << endl;
							aux3 = aux3->getAdelante();
						}

					} //fin if en z

					aux2 = aux2->getAbajo();
				}//fin while y

				aux = aux->getSiguiente(); // apunta al siguiente para recorrer

			}//fin while x
		}
		catch (const std::exception&)
		{

		}

	}

	int ordenaMes(string mes)
	{

		if (mes == "Enero" || mes == "enero")
		{
			return 1;
		}
		else if (mes == "Febrero" || mes == "febrero")
		{
			return 2;
		}
		else if (mes == "Marzo" || mes == "marzo")
		{
			return 3;
		}
		else if (mes == "Abril" || mes == "abril")
		{
			return 4;
		}
		else if (mes == "Mayo" || mes == "mayo")
		{
			return 5;
		}
		else if (mes == "Junio" || mes == "junio")
		{
			return 6;
		}
		else if (mes == "Julio" || mes == "julio")
		{
			return 7;
		}
		else if (mes == "Agosto" || mes == "agosto")
		{
			return 8;
		}
		else if (mes == "Septiembre" || mes == "septiembre")
		{
			return 9;
		}
		else if (mes == "Octubre" || mes == "octubre")
		{
			return 10;
		}
		else if (mes == "Noviembre" || mes == "noviembre")
		{
			return 11;
		}
		else if (mes == "Diciembre" || mes == "diciembre")
		{
			return 12;
		}
		else {
			return 0;
		}
	}

	void graficar() {

		// Variable Para Guardar Graficación
		int contX = 0;
		string graf = "digraph { \n";
		graf = graf + "node[shape=box3d, style=filled ]; \n";
		// Recorrer Matriz
		Nodo* tempX = cabecera;
		//cout << "entra a graficar" << endl;
		while (tempX != 0) // Recorrer Cada Nodo En X
		{

			Nodo* tempY = tempX;
			while (tempY != 0) // Recorrer Cada Nodo En (X,Y) Donde Y AUMENTA
			{
				// GRAFICAR NODO (X,Y)
				if (contX == 0) //cabeceras en y
				{
					if (tempY->getMes() == "0") { //cabezera (0,0)

						stringstream ss1;
						ss1 << tempY->getSiguiente()->getAño();
						string str1 = ss1.str();

						stringstream ss2;
						ss2 << contX + 1;
						string str2 = ss2.str();

						graf = graf + tempY->getMes() + "[fillcolor=\"#1EB3C5\" pos=\" 0,0!\"];" + "\n";
						graf = graf + tempY->getMes() + "->" + str1 + "; \n";
						graf = graf + tempY->getMes() + "->" + tempY->getAbajo()->getMes() + "; \n";

					}
					else
					{ // en  mes(0,Y)

						stringstream ss;
						ss << ordenaMes(tempY->getMes());
						string str = ss.str();

						graf = graf + tempY->getMes() + "[fillcolor=\"#1EC59E\" pos=\" 0,-" + str + "!\"];" + "\n";

						// Para Apuntadoressss
						if (tempY->getArriba() != 0) // Apuntador Arriba
						{
							graf = graf + tempY->getMes() + "->" + tempY->getArriba()->getMes() + "; \n";;
						}
						if (tempY->getSiguiente() != 0) // Apuntador Siguiente
						{
							graf = graf + tempY->getMes() + "->" +"\""+ tempY->getSiguiente()->getAlbum()->getName()+"\"" + "; \n";
						}
						if (tempY->getAbajo() != 0)//Apuntador Abajo
						{
							graf = graf + tempY->getMes() + "->" + tempY->getAbajo()->getMes() + "; \n";
						}
					}

				}
				else
				{ // va a recorrer los años 
					if (tempY->getMes() == "0")
					{
						stringstream ss1;
						ss1 << tempY->getAño();
						string str1 = ss1.str();

						stringstream ss2;
						ss2 << contX;
						string str2 = ss2.str();

						graf = graf + str1 + "[fillcolor=\"#1EC59E\" pos=\" " + str2 + ",0!\"];" + "\n";

						//apuntadores
						if (tempY->getAnterior() != 0) // Apuntador Anterior
						{
							stringstream ss3;
							ss3 << tempY->getAnterior()->getAño();
							string str3 = ss3.str();

							graf = graf + str1 + "->" + str3 + "; \n";
						}
						if (tempY->getSiguiente() != 0) // Apuntador Derecha 
						{

							stringstream ss4;
							ss4 << tempY->getSiguiente()->getAño();
							string str4 = ss4.str();

							graf = graf + str1 + "->" + str4 + "; \n";
						}
						if (tempY->getAbajo() != 0) // Apuntador Abajo
						{
							graf = graf + str1 + "->" + "\"" +tempY->getAbajo()->getAlbum()->getName() + "\"" + "; \n";
						}

					}
					else
					{ // para recorrer los nodos con albumnes

						stringstream ss2;
						ss2 << contX;
						string str2 = ss2.str();

						stringstream ss3;
						ss3 << ordenaMes(tempY->getMes());
						string str3 = ss3.str();

						graf = graf + "\"" + tempY->getAlbum()->getName() + "\"" + "[fillcolor=\"#F1F116\" pos=\" " + str2 + ",-" + str3 + "!\"];" + "\n";

						//Apuntadores
						if (tempY->getArriba() != 0) // apuntador arriba
						{
							if (tempY->getArriba()->getMes() == "0") // apuntador arriba a cabeceras
							{
								stringstream ss3;
								ss3 << tempY->getArriba()->getAño();
								string str3 = ss3.str();

								graf = graf + "\"" + tempY->getAlbum()->getName()+"\"" + "->" + str3 + "; \n";
							}
							else // apunta arriba a un album
							{
								graf = graf + "\"" +tempY->getAlbum()->getName()+"\"" + "->" + "\"" +tempY->getArriba()->getAlbum()->getName()+"\"" + "; \n";
							}

						}
						if (tempY->getAnterior() != 0) // apuntador a la izquierda
						{

							if (tempY->getAnterior()->getAño() == 0) // apuntador a la izquierda es una cabezera
							{
								graf = graf + "\"" + tempY->getAlbum()->getName() + "\"" + "->" + tempY->getAnterior()->getMes() + "; \n";

							}
							else  // apunta a la izquierda  a un album
							{
								graf = graf + "\"" + tempY->getAlbum()->getName()+"\"" + "->" + "\"" +tempY->getAnterior()->getAlbum()->getName()+"\"" + "; \n";
							}

						}
						if (tempY->getSiguiente() != 0) // apuntador a la derecha a un album
						{
							graf = graf +"\"" +tempY->getAlbum()->getName()+"\"" + "->" + "\"" + tempY->getSiguiente()->getAlbum()->getName() +"\"" +"; \n";
						}
						if (tempY->getAbajo() != 0)//apuntador hacia abajo a un album
						{
							graf = graf +"\"" +tempY->getAlbum()->getName()+"\"" + "->" +"\"" +tempY->getAbajo()->getAlbum()->getName()+ "\"" + "; \n";
						}
						if (tempY->getAdelante() != 0) // Verificar Si Tiene Nodos Adelante
						{

							graf = graf +"\"" +tempY->getAlbum()->getName() + "\"" + "->" + "\"" + tempY->getAdelante()->getAlbum()->getName() + "\"" + "; \n";

							Nodo* tempZ = tempY->getAdelante();
							while (tempZ != 0) // Recorrer Cada Nodo Del Eje Z Si Existe
							{

								// GRAFICAR EL TEMP.ADELANTE
								stringstream ss2;
								ss2 << contX;
								string str2 = ss2.str();

								stringstream ss3;
								ss3 << ordenaMes(tempZ->getMes());
								string str3 = ss3.str();

								//graf = graf + tempZ->getAlbum()->getName() + "[fillcolor=\"#d62728\" pos=\" " + str2 + ",-" + str3 + "!\"];" + "\n";

								// Apuntadores
								if (tempZ->getAdelante() != 0) // Adelante
								{
									graf = graf +"\"" +tempZ->getAlbum()->getName()+"\"" + "->" + "\"" + tempZ->getAdelante()->getAlbum()->getName() + "\"" + "; \n";
								}
								if (tempZ->getAtras() != 0) { // Atras

									graf = graf + "\"" + tempZ->getAlbum()->getName() + "\"" + "->" + "\"" + tempZ->getAtras()->getAlbum()->getName()+"\"" + "; \n";
								}

								tempZ = tempZ->getAdelante();
							}

						}


					}
				}

				tempY = tempY->getAbajo();
			}
			contX++;
			tempX = tempX->getSiguiente();
		}

		graf = graf + "\n";
		graf = graf + "}";

		ofstream g("graficaMatriz.dot");

		g << graf;
		g.close();
		system("neato -Tsvg graficaMatriz.dot -o grafMat.svg");
		system("grafMat.svg");

	}

	Nodo *obtenerNodo(string mes,int año, string nameAlbum)
	{

		// Recorrer CabeceraX
		Nodo* temp = cabecera;
		while (temp != 0)
		{

			if (año == temp->getAño()) // Encontrar Año De Nodo A Insertar
			{

		
					// Recorremos Mes
					Nodo* temp2 = temp;
					while (temp2 != 0)
					{
						if (ordenaMes(mes) == ordenaMes(temp2->getMes()))//insertar en z
						{
						
							Nodo* tempo = temp2;
							if (tempo->getAdelante() == 0)
							{
								return temp2;

							}
							else { // ARREGLAR AQUI
								tempo = tempo->getAdelante();
								while (tempo != 0)
								{
									if (tempo->getAlbum()->getName() == nameAlbum)
									{
										return tempo;
									}

									tempo = tempo->getAdelante();
								}
							}
							break;
						}
			
						temp2 = temp2->getAbajo();
					}

			}

			temp = temp->getSiguiente();
		}

	} //fin obtenerNodo

	ListaDoble<Album> *obtenerTop5()
	{
		ListaDoble<Album> *ls = new ListaDoble<Album>();
		try
		{



			Nodo* aux = this->cabecera->getSiguiente(); //empieza apuntando al primero par recorrer

			while (aux != 0) { // recorre cabeceras en x


				Nodo* aux2 = aux->getAbajo();
				while (aux2 != 0) // recorrer en y 
				{
					int cast = aux2->getAño();
					stringstream power;
					power << cast;
					string pepe = power.str(); //tendra el ano

					/*cout << "Name: " << aux2->getAlbum()->getName() << endl;
					cout << "Year: " << aux2->getAlbum()->getAno() << endl;
					cout << "Month: " << aux2->getAlbum()->getMonth() << endl;
					cout << "-------------------------------------------" << endl; */
					if (ls->getsize() == 0)
					{
						ls->add_at(aux2->getAlbum(),aux2->getAlbum()->getName(),0);
						//cout << ls->get_element_at(0)->getName()<<"ls"<<endl;
					}
					else{ 
	
						int cont = 0;
						while (cont <= ls->getsize())
						{

							if (cont == ls->getsize()) { ls->add_at(aux2->getAlbum(), aux2->getAlbum()->getName(),cont); break; }//final
							else {
								if (aux2->getAlbum()->getRating() < ls->get_element_at(cont)->getRating())
								{
									ls->add_at(aux2->getAlbum(), aux2->getAlbum()->getName(), cont);
									break;
								}
								else if (aux2->getAlbum()->getRating() == ls->get_element_at(cont)->getRating())
								{
									ls->add_at(aux2->getAlbum(), aux2->getAlbum()->getName(), cont);
									break;
								}
							}
							cont++;
						}
					}
					
					if (aux2->getAdelante() != 0) // recorre en z
					{
						Nodo* aux3 = aux2->getAdelante();
						while (aux3 != 0)
						{
						/*	cout << "Name: " << aux3->getAlbum()->getName() << endl;
							cout << "Year: " << aux3->getAlbum()->getAno() << endl;
							cout << "Month: " << aux3->getAlbum()->getMonth() << endl;
							cout << "-------------------------------------------" << endl; */
							if (ls->getsize() == 0)
							{
								ls->add_at(aux3->getAlbum(), aux3->getAlbum()->getName(), 0);
							}
							else {
								int cont = 0;
								while (cont <= ls->getsize())
								{

									if (cont == ls->getsize()) { ls->add_at(aux3->getAlbum(), aux3->getAlbum()->getName(), cont); break; }
									else {
										if (aux3->getAlbum()->getRating() < ls->get_element_at(cont)->getRating())
										{
											ls->add_at(aux3->getAlbum(), aux3->getAlbum()->getName(), cont);
											break;
										}
										else if (aux3->getAlbum()->getRating() == ls->get_element_at(cont)->getRating())
										{
											ls->add_at(aux3->getAlbum(), aux2->getAlbum()->getName(), cont);
											break;

										}
									}
									cont++;
								}
							}
							aux3 = aux3->getAdelante();
						}

					} //fin if en z

					aux2 = aux2->getAbajo();
				}//fin while y

				aux = aux->getSiguiente(); // apunta al siguiente para recorrer

			}//fin while x

			return ls;
		}
		catch (const std::exception&)
		{
		}

	}

};





#endif // MATRIZ_H_INCLUDED
