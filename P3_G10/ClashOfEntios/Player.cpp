#include "Player.h"



Player::Player(int tipoIconos):
	movimientos(0)
{
	if (tipoIconos == 1)
	{
		NPCs.push_back(new NPC("A"));
		NPCs.push_back(new NPC("B"));
		NPCs.push_back(new NPC("C"));
		NPCs.push_back(new NPC("D"));
		NPCs.push_back(new NPC("E"));
		NPCs.push_back(new NPC("F"));
	}
	else
	{
		NPCs.push_back(new NPC("1"));
		NPCs.push_back(new NPC("2"));
		NPCs.push_back(new NPC("3"));
		NPCs.push_back(new NPC("4"));
		NPCs.push_back(new NPC("5"));
		NPCs.push_back(new NPC("6"));
	}
	
}


Player::~Player()
{
}

NPC & Player::getNPC(std::string c)
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

void Player::setMovimientos(int n)
{
	movimientos = n;
}

int Player::getMovimientos()
{
	return movimientos;
}

void Player::modifyNPCList(std::string icono)
{
	std::list<NPC*>::iterator it = NPCs.begin();

	while (it != NPCs.end())
	{
		if ((*it)->getIcon == icono)
		{
			NPCs.erase(it);
			break;
		}
		else
		{
			it++;
		}
	}
}

int Player::getSizeNPCList()
{
	return NPCs.size();
}
