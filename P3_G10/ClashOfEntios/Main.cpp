#include <iostream>
#include "NPC.h"
#include "Player.h"
#include <list>


void main()
{
	//Creación de la lista de NPC's del jugador 1
	/*std::list<NPC*> NPC_Player_A;

	NPC_Player_A.push_back(new NPC('A'));
	NPC_Player_A.push_back(new NPC('B'));
	NPC_Player_A.push_back(new NPC('C'));
	NPC_Player_A.push_back(new NPC('D'));
	NPC_Player_A.push_back(new NPC('E'));
	NPC_Player_A.push_back(new NPC('F'));

	//Creación de la lista de NPC's del jugador 2
	std::list<NPC*> NPC_Player_B;

	NPC_Player_B.push_back(new NPC('1'));
	NPC_Player_B.push_back(new NPC('2'));
	NPC_Player_B.push_back(new NPC('3'));
	NPC_Player_B.push_back(new NPC('4'));
	NPC_Player_B.push_back(new NPC('5'));
	NPC_Player_B.push_back(new NPC('6'));

	//Creación de sus iteradores correspondientes
	std::list<NPC*>::iterator ita = NPC_Player_A.begin();
	std::list<NPC*>::iterator itb = NPC_Player_B.begin();
	

	//Bucles para recorrer dicha lista
	while (ita != NPC_Player_A.end())
	{
		std::cout << (*ita)->getIcon() << std::endl;
		ita++;
	}

	std::cout << std::endl;

	while (itb != NPC_Player_B.end())
	{
		std::cout << (*itb)->getIcon() << std::endl;
		itb++;
	}*/

	Player p1(1);
	Player p2();

	std::cout << p1.
}