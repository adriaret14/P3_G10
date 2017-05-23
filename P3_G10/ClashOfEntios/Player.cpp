#include "Player.h"



Player::Player(int tipoIconos)
{
	if (tipoIconos == 0)
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
