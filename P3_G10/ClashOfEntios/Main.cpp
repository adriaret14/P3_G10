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
	std::vector<std::string> jug1;
	std::vector<std::string> jug2;



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
						p1.getNPC(activo).setFatiga(p1.getNPC(activo).getFatiga() + 1);
					}					
					break;
				case enti::InputKey::A:
					if (p1.getMovimientos() > 0)
					{
						interacc.movimientoNPC(p1.getNPC(activo), DIRECCION::A);
						p1.setMovimientos(p1.getMovimientos() - 1);
						system("cls");
						m.print(turno);
						p1.getNPC(activo).setFatiga(p1.getNPC(activo).getFatiga() + 1);
					}					
					break;
				case enti::InputKey::S:
					if (p1.getMovimientos() > 0)
					{
						interacc.movimientoNPC(p1.getNPC(activo), DIRECCION::S);
						p1.setMovimientos(p1.getMovimientos() - 1);
						system("cls");
						m.print(turno);
						p1.getNPC(activo).setFatiga(p1.getNPC(activo).getFatiga() + 1);
					}
					break;
				case enti::InputKey::W:
					if (p1.getMovimientos() > 0)
					{
						interacc.movimientoNPC(p1.getNPC(activo), DIRECCION::W);
						p1.setMovimientos(p1.getMovimientos() - 1);
						system("cls");
						m.print(turno);
						p1.getNPC(activo).setFatiga(p1.getNPC(activo).getFatiga() + 1);
					}
					break;
				case enti::InputKey::Z:
					//Deshacer movimiento
					interacc.deshacerMovimiento(p1.getNPC(activo));
					m.print(turno);
					p1.getNPC(activo).setFatiga(p1.getNPC(activo).getFatiga() - 1);
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
						jug1.push_back(p1.getNPC(activo).getIcon());
						p1.getNPC(activo).setFatiga(0 + 1);
						activo = interacc.cambioNPC(activo, 1);
						m.print(turno);
					}
					else
					{
						//Fin del turno
						for (int i = 0; i < jug1.size(); i++)
						{
							p1.getNPC(jug1[i]).setFatiga(p1.getNPC(jug1[i]).getFatiga() + 1);
						}
						p2.setMovimientos(10);
						turno = 2;
						jug1.clear();
						activo = interacc.cambioNPC("1", 2);
						m.print(turno);
						//FALTA CAMBIAR EL NPC AL DEL PLAYER2
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
						p2.getNPC(activo).setFatiga(p2.getNPC(activo).getFatiga() + 1);
					}
					break;
				case enti::InputKey::A:
					if (p2.getMovimientos() > 0)
					{
						interacc.movimientoNPC(p2.getNPC(activo), DIRECCION::A);
						p2.setMovimientos(p2.getMovimientos() - 1);
						system("cls");
						m.print(turno);
						p2.getNPC(activo).setFatiga(p2.getNPC(activo).getFatiga() + 1);
					}
					break;
				case enti::InputKey::S:
					if (p2.getMovimientos() > 0)
					{
						interacc.movimientoNPC(p2.getNPC(activo), DIRECCION::S);
						p2.setMovimientos(p2.getMovimientos() - 1);
						system("cls");
						m.print(turno);
						p2.getNPC(activo).setFatiga(p2.getNPC(activo).getFatiga() + 1);
					}
					break;
				case enti::InputKey::W:
					if (p2.getMovimientos() > 0)
					{
						interacc.movimientoNPC(p2.getNPC(activo), DIRECCION::W);
						p2.setMovimientos(p2.getMovimientos() - 1);
						system("cls");
						m.print(turno);
						p2.getNPC(activo).setFatiga(p2.getNPC(activo).getFatiga() + 1);
					}
					break;
				case enti::InputKey::Z:
					//Deshacer movimiento
					interacc.deshacerMovimiento(p2.getNPC(activo));
					m.print(turno);
					p2.getNPC(activo).setFatiga(p2.getNPC(activo).getFatiga() - 1);
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
						jug2.push_back(p2.getNPC(activo).getIcon());
						p2.getNPC(activo).setFatiga(0 + 1);
						activo = interacc.cambioNPC(activo, 2);
						m.print(turno);
					}
					else
					{
						//Fin del turno
						for (int t = 0; t < jug2.size(); t++)
						{
							p2.getNPC(jug2[t]).setFatiga(p2.getNPC(jug2[t]).getFatiga() + 1);
						}
						p1.setMovimientos(10);
						turno = 1;
						jug2.clear();
						activo = interacc.cambioNPC("A", 1);
						m.print(turno);
						//FALTA CAMBIAR EL NPC AL DEL PLAYER2
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