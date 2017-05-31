#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Player.h"
#include "Renderer.hh"



class Map
{
public:
	Map(std::string, Player &, Player &);					//Consturctor de mapa, pasando como parametro el nombre del archivo a abrir
	~Map();													//Destructor de mapa

	std::string getCell(int, int);
	void updCell(std::string, int, int);
	void print(int, std::string);


	std::vector<std::vector<std::string>> mapa;				//Vector de vectores de chars donde esta almacenado el mapa, usamos vectores por la agilidad de acceso por índice
	Player &player1;
	Player &player2;
};

