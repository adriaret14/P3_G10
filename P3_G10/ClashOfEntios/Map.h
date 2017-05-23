#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


class Map
{
public:
	Map(std::string);									//Consturctor de mapa, pasando como parametro el nombre del archivo a abrir
	~Map();												//Destructor de mapa

	char getCell(int, int);
	void updCell(char, int, int);
	void print();

	std::vector<std::vector<char>> mapa;				//Vector de vectores de chars donde esta almacenado el mapa, usamos vectores por la agilidad de acceso por índice
};

