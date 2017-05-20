#pragma once
#include <list>
#include "NPC.h"
class Player
{
public:
	Player(std::list<NPC*> &);						//Constructor por defecto de Player, pasando como referencia la lista de puntero de NPC
	~Player();										//Destructor de Player

private:
	std::list<NPC*> &NPCs;
};

