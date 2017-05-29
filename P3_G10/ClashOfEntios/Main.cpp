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
	p1.setMovimientos(10);
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
					if (p1.getMovimientos() > 0)
					{
						interacc.movimientoNPC(p1.getNPC(activo), DIRECCION::D);
						p1.setMovimientos(p1.getMovimientos() - 1);
						system("cls");
						m.print(turno);
					}					
					break;
				case enti::InputKey::A:
					if (p1.getMovimientos() > 0)
					{
						interacc.movimientoNPC(p1.getNPC(activo), DIRECCION::A);
						p1.setMovimientos(p1.getMovimientos() - 1);
						system("cls");
						m.print(turno);
					}					
					break;
				case enti::InputKey::S:
					if (p1.getMovimientos() > 0)
					{
						interacc.movimientoNPC(p1.getNPC(activo), DIRECCION::S);
						p1.setMovimientos(p1.getMovimientos() - 1);
						system("cls");
						m.print(turno);
					}
					break;
				case enti::InputKey::W:
					if (p1.getMovimientos() > 0)
					{
						interacc.movimientoNPC(p1.getNPC(activo), DIRECCION::W);
						p1.setMovimientos(p1.getMovimientos() - 1);
						system("cls");
						m.print(turno);
					}
					break;
				case enti::InputKey::Z:
					//Deshacer movimiento

					break;
				case enti::InputKey::SPACEBAR:
					if (p1.getMovimientos() > 0)
					{
						//Atacar
					}
					break;
				case enti::InputKey::ENTER:
					if (p1.getMovimientos() > 0)
					{
						//Cambiar NPC
					}
					else
					{
						//Fin del turno
						p1.getNPC(activo).setActive(false);
						for (std::list<NPC*>::iterator it = p2.getList().begin(); it != p2.getList().end(); it++)
						{
							//Buscar el npc con menos fatiga

						}
						p2.setMovimientos(10);
						turno = 2;
					}
					break;
				}

				
			}
			else {
				//Juega el player 2

				switch (enti::getInputKey())
				{
				case enti::InputKey::D:
					if (p2.getMovimientos() > 0)
					{
						interacc.movimientoNPC(p2.getNPC(activo), DIRECCION::D);
						p2.setMovimientos(p2.getMovimientos() - 1);
						system("cls");
						m.print(turno);
					}
					break;
				case enti::InputKey::A:
					if (p2.getMovimientos() > 0)
					{
						interacc.movimientoNPC(p2.getNPC(activo), DIRECCION::A);
						p2.setMovimientos(p2.getMovimientos() - 1);
						system("cls");
						m.print(turno);
					}
					break;
				case enti::InputKey::S:
					if (p2.getMovimientos() > 0)
					{
						interacc.movimientoNPC(p2.getNPC(activo), DIRECCION::S);
						p2.setMovimientos(p2.getMovimientos() - 1);
						system("cls");
						m.print(turno);
					}
					break;
				case enti::InputKey::W:
					if (p2.getMovimientos() > 0)
					{
						interacc.movimientoNPC(p2.getNPC(activo), DIRECCION::W);
						p2.setMovimientos(p2.getMovimientos() - 1);
						system("cls");
						m.print(turno);
					}
					break;
				case enti::InputKey::Z:
					//Deshacer movimiento
					break;
				case enti::InputKey::SPACEBAR:
					if (p2.getMovimientos() > 0)
					{
						//Atacar
					}
					break;
				case enti::InputKey::ENTER:
					if (p2.getMovimientos() > 0)
					{
						//Cambiar NPC
					}
					else
					{
						//Fin del turno
						p2.getNPC(activo).setActive(false);
						for (std::list<NPC*>::iterator it = p1.getList().begin(); it != p1.getList().end(); it++)
						{
							//Buscar el npc con menos fatiga
						}
						p1.setMovimientos(10);
						turno = 1;
					}
					break;
				}

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