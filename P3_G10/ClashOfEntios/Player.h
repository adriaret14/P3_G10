#pragma once
#include <list>
#include "NPC.h"
class Player
{
public:
	Player(int);									//Constructor por defecto de Player, pasando como parametro un entero con el que decidiremos si los iconos son numeros o letras
	~Player();										//Destructor de Player

	NPC getNPC(char);								//Metodo para consultar un NPC, pasando como parametro el icono del NPC

private:
	std::list<NPC*> NPCs;							//Lista de NPCs de cada personaje, usamos lista por su facilidad de eliminar el objeto cuando lo eliminas de la lista, entre otros
};

