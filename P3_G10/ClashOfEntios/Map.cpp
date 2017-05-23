#include "Map.h"



Map::Map(std::string url)
{
	std::ifstream archivo;
	std::string linea;
	mapa = std::vector<std::vector<char>>(36, std::vector<char>(74));

	archivo.open(url);

	if (archivo.fail())
	{
		system("pause");
	}
	else
	{
		while (!archivo.eof())
		{
			for (int j = 0; j < 36; j++) 
			{
				std::getline(archivo, linea);
				for (int i = 0; i < linea.size(); i++)
				{
					mapa[j][i] = linea[i];
				}
			}
		}
		archivo.close();
	}	
}

Map::~Map()
{
	for (int i = 0; i < 36; i++)
	{
		mapa[i].~vector();
	}
	mapa.~vector();
}

char Map::getCell(int x, int y)
{
	return mapa[y][x];
}

void Map::updCell(char c, int x, int y)
{
	mapa[y][x] = c;
}

void Map::print()
{
	for (int j = 0; j < 36; j++) 
	{
		for (int i = 0; i < 74; i++)
		{
			std::cout << mapa[j][i] << " ";
		}
		std::cout << std::endl;
	}
}


