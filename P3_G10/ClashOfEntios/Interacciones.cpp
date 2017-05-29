#include "Interacciones.h"

Interacciones::Interacciones(Player & player1, Player & player2, Map & mapa) :
	p1(player1),
	p2(player2),
	m(mapa),
	walkable(".:"),
	flagDeshacer(-1)
{
}

void Interacciones::movimientoNPC(NPC & npc, DIRECCION dir)
{
	switch (dir)
	{
	case DIRECCION::A:
		if (npc.getX() > 0) {
			if (walkable.find(m.getCell(npc.getX() - 1, npc.getY()))!=std::string::npos) {
				lastMoveX = npc.getX();
				lastMoveY = npc.getY();
				npc.setX(npc.getX() - 1);
			}
		}
		break;
	case DIRECCION::D:
		if (npc.getX() < 73) {
			if (walkable.find(m.getCell(npc.getX() + 1, npc.getY())) != std::string::npos) {
				lastMoveX = npc.getX();
				lastMoveY = npc.getY();
				npc.setX(npc.getX() + 1);
			}
		}
		break;
	case DIRECCION::S:
		if (npc.getY() < 73) {
			if (walkable.find(m.getCell(npc.getX(), npc.getY() + 1)) != std::string::npos) {
				lastMoveX = npc.getX();
				lastMoveY = npc.getY();
				npc.setY(npc.getY() + 1);
			}
		}
		break;
	case DIRECCION::W:
		if (npc.getY() > 0) {
			if (walkable.find(m.getCell(npc.getX(), npc.getY() - 1)) != std::string::npos) {
				lastMoveX = npc.getX();
				lastMoveY = npc.getY();
				npc.setY(npc.getY() - 1);
			}
		}
		break;
	}
	m.updCell(npc.getTile(), lastMoveX, lastMoveY);
	npc.setTile(m.getCell(npc.getX(), npc.getY()));
	m.updCell(npc.getIcon(), npc.getX(), npc.getY());
	flagDeshacer = 0;
}

void Interacciones::deshacerMovimiento(NPC & npc)
{
	if (lastMoveX != -1 && lastMoveY != -1 && flagDeshacer == 0)
	{
		int auxX = npc.getX();
		int auxY = npc.getY();

		npc.setX(lastMoveX);
		npc.setY(lastMoveY);

		lastMoveX = auxX;
		lastMoveY = auxY;

		m.updCell(npc.getTile(), lastMoveX, lastMoveY);
		npc.setTile(m.getCell(npc.getX(), npc.getY()));
		m.updCell(npc.getIcon(), npc.getX(), npc.getY());
		flagDeshacer = 1;
	}
}

void Interacciones::rehacerMovimiento(NPC & npc)
{
	if (lastMoveX != -1 && lastMoveY != -1 && flagDeshacer == 1)
	{
		int auxX = npc.getX();
		int auxY = npc.getY();

		npc.setX(lastMoveX);
		npc.setY(lastMoveY);

		lastMoveX = auxX;
		lastMoveY = auxY;

		m.updCell(npc.getTile(), lastMoveX, lastMoveY);
		npc.setTile(m.getCell(npc.getX(), npc.getY()));
		m.updCell(npc.getIcon(), npc.getX(), npc.getY());
		flagDeshacer = 0;
	}
}

void Interacciones::ataque(NPC & npc, DIRECCION dir, ARMA arma)
{
	std::string p1npcs = "ABCDEF";
	std::string p2npcs = "123456";
	if (arma == ARMA::SWORD)
	{
		if (p1npcs.find(npc.getIcon()) != std::string::npos)
		{

		}
		else if (p2npcs.find(npc.getIcon()) != std::string::npos)
		{

		}
	}
}

std::string Interacciones::cambioNPC(std::string npcIcon, int jugador)
{
	std::string npcs;
	std::string npc;
	std::string nextNPCicon = npcIcon;

	switch (jugador) {
	case 1:
		p1.getNPC(npcIcon).setActive(false);
		npcs = "ABCDEF";
		for (int i = 0; i < 6; i++) 
		{
			npc = npcs[i];
			if (p1.getNPC(npc).getFatiga() < p1.getNPC(nextNPCicon).getFatiga())
			{
				nextNPCicon = npc;
			}
		}
		p1.getNPC(nextNPCicon).setActive(true);
		return nextNPCicon;
	case 2:
		p2.getNPC(npcIcon).setActive(false);
		npcs = "123456";
		for (int i = 0; i < 6; i++)
		{
			npc = npcs[i];
			if (p2.getNPC(npc).getFatiga() < p2.getNPC(nextNPCicon).getFatiga())
			{
				nextNPCicon = npc;
			}
		}
		p2.getNPC(nextNPCicon).setActive(true);
		return nextNPCicon;
	}
}
