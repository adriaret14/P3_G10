#include <iostream>
#include "NPC.h"
#include "Player.h"
#include "Map.h"
#include <list>
#include "Input.inl.hh"
#include "Interacciones.h"


void main()
{
	//Iniciamos las variables y objetos necesarios para el juego
	Player p1(1);
	Player p2(0);
	Map m("default.cfg", p1, p2);
	Interacciones interacc(p1, p2, m);
	int endgame = 0;
	int turno = 1;
	std::string activo = "A";
	p1.getNPC(activo).setActive(true);
	m.print(turno);


	do {
	
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

				switch (enti::getInputKey())
				{
				case enti::InputKey::D:
					//std::cout << "D";
					interacc.movimientoNPC(p1.getNPC(activo), DIRECCION::D);
					system("cls");
					m.print(turno);
					break;
				case enti::InputKey::A:
					interacc.movimientoNPC(p1.getNPC(activo), DIRECCION::A);
					system("cls");
					m.print(turno);
					break;
				case enti::InputKey::S:
					interacc.movimientoNPC(p1.getNPC(activo), DIRECCION::S);
					system("cls");
					m.print(turno);
					break;
				case enti::InputKey::W:
					interacc.movimientoNPC(p1.getNPC(activo), DIRECCION::W);
					system("cls");
					m.print(turno);
					break;
				case enti::InputKey::Z:

					break;
				case enti::InputKey::SPACEBAR:

					break;
				case enti::InputKey::ENTER:

					break;
				}

				turno = 2;
			}
			else {
				//Juega el player 2

				turno = 1;
			}
		}
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