#include "Map.h"



Map::Map(std::string url, Player & p1, Player & p2):
	player1(p1),
	player2(p2)
{
	std::ifstream archivo;
	std::string linea;
	mapa = std::vector<std::vector<std::string>>(36, std::vector<std::string>(74));
	std::string npcs1 = "ABCDEF";
	std::string npcs2 = "123456";
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
					if (npcs1.find(mapa[j][i]) != std::string::npos)
					{
						p1.getNPC(mapa[j][i]).setX(i);
						p1.getNPC(mapa[j][i]).setY(j);
					}
					if (npcs2.find(mapa[j][i]) != std::string::npos)
					{
						p2.getNPC(mapa[j][i]).setX(i);
						p2.getNPC(mapa[j][i]).setY(j);
					}
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

std::string Map::getCell(int x, int y)
{
	return mapa[y][x];
}

void Map::updCell(std::string c, int x, int y)
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


