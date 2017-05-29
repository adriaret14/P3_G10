#include <iostream>
#include "NPC.h"
#include "Player.h"
#include "Map.h"
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
	Player p2(0);
	Map m("default.cfg", p1, p2);
	int endgame = 0;
	int turno = 1;
	std::string activo = "A";
	//std::cout << p1.getNPC('A').getHp();
	
	do {
		m.print(turno);
		
		
		//Comprobacion de si un jugador es el ganador de la partida
		if (p1.getSizeNPCList() < 1)
		{
			endgame = 2;
		}
		else if (p2.getSizeNPCList() < 1)
		{
			endgame = 1;
		}
		else
		{
			//Forma de asignar los turnos en Clash of Entios
			if (turno == 1)
			{
				//Juega el player1

				turno = 2;
			}
			else {
				//Juega el player 2

				turno = 1;
			}
		}
		system("cls");
	} while (endgame == 0);

	system("cls");

	if (endgame == 1)
	{
		std::cout << "Ganador el PLAYER 1";
	}
	else {
		std::cout << "Ganador el PLAYER 2";
	}
}