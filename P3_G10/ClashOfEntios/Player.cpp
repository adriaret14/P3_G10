#include "Player.h"



Player::Player(int tipoIconos):
	movimientos(0)
{
	if (tipoIconos == 1)
	{
		NPCs.push_back(new NPC('A'));
		NPCs.push_back(new NPC('B'));
		NPCs.push_back(new NPC('C'));
		NPCs.push_back(new NPC('D'));
		NPCs.push_back(new NPC('E'));
		NPCs.push_back(new NPC('F'));
	}
	else
	{
		NPCs.push_back(new NPC('1'));
		NPCs.push_back(new NPC('2'));
		NPCs.push_back(new NPC('3'));
		NPCs.push_back(new NPC('4'));
		NPCs.push_back(new NPC('5'));
		NPCs.push_back(new NPC('6'));
	}
	
}


Player::~Player()
{
}

NPC Player::getNPC(char c)
{
	std::list<NPC*>::iterator it= NPCs.begin();

	while (it != NPCs.end())
	{
		if ((*it)->getIcon() == c)
		{
			return *(*it);
			break;
		}
		else
		{
			it++;
		}

	}
}
