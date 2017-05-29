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

bool Interacciones::ataque(NPC & npc, DIRECCION dir, ARMA arma)
{
	std::string p1npcs = "ABCDEF";
	std::string p2npcs = "123456";
	int x;
	int y;
	switch (dir)
	{
	case DIRECCION::A:
		x = -1;
		y = 0;
		break;
	case DIRECCION::W:
		x = 0;
		y = -1;
		break;
	case DIRECCION::D:
		x = 1;
		y = 0;
		break;
	case DIRECCION::S:
		x = 0;
		y = 1;
		break;
	}
	if (arma == ARMA::SWORD)
	{
		if (p1npcs.find(npc.getIcon()) != std::string::npos)
		{
			if (p2npcs.find(m.mapa[npc.getY() + y][npc.getX() + x]) != std::string::npos)
			{
				p2.getNPC(m.mapa[npc.getY() + y][npc.getX() + x]).setHp(p2.getNPC(m.mapa[npc.getY() + y][npc.getX() + x]).getHp()-10);
				if (p2.getNPC(m.mapa[npc.getY() + y][npc.getX() + x]).getHp() <= 0)
				{
					std::string aux = p2.getNPC(m.mapa[npc.getY() + y][npc.getX() + x]).getTile();
					p2.modifyNPCList(m.mapa[npc.getY() + y][npc.getX() + x]);
					m.mapa[npc.getY() + y][npc.getX() + x] = aux;
				}
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (p2npcs.find(npc.getIcon()) != std::string::npos)
		{
			if (p1npcs.find(m.mapa[npc.getY() + y][npc.getX() + x]) != std::string::npos)
			{
				p1.getNPC(m.mapa[npc.getY() + y][npc.getX() + x]).setHp(p1.getNPC(m.mapa[npc.getY() + y][npc.getX() + x]).getHp() - 10);
				if (p1.getNPC(m.mapa[npc.getY() + y][npc.getX() + x]).getHp() <= 0)
				{
					std::string aux = p1.getNPC(m.mapa[npc.getY() + y][npc.getX() + x]).getTile();
					p1.modifyNPCList(m.mapa[npc.getY() + y][npc.getX() + x]);
					m.mapa[npc.getY() + y][npc.getX() + x] = aux;
				}
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if (arma == ARMA::BOW)
	{
		int mult = 0;
		if (p1npcs.find(npc.getIcon()) != std::string::npos)
		{
			for (int i = 1; i <= 10; i++)
			{
				if (p2npcs.find(m.mapa[npc.getY() + i*y][npc.getX() + i*x]) != std::string::npos)
				{
					mult = i;
					i = 11;
				}
			}
			if (mult >= 3 && mult <= 10)
			{
				p2.getNPC(m.mapa[npc.getY() + mult*y][npc.getX() + mult*x]).setHp(p2.getNPC(m.mapa[npc.getY() + mult*y][npc.getX() + mult*x]).getHp() - (11 - mult));
				if (p2.getNPC(m.mapa[npc.getY() + mult*y][npc.getX() + mult*x]).getHp() <= 0)
				{
					std::string aux = p2.getNPC(m.mapa[npc.getY() + mult*y][npc.getX() + mult*x]).getTile();
					p2.modifyNPCList(m.mapa[npc.getY() + mult*y][npc.getX() + mult*x]);
					m.mapa[npc.getY() + mult*y][npc.getX() + mult*x] = aux;
				}
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (p2npcs.find(npc.getIcon()) != std::string::npos)
		{
			for (int i = 1; i <= 10; i++)
			{
				if (p1npcs.find(m.mapa[npc.getY() + i*y][npc.getX() + i*x]) != std::string::npos)
				{
					mult = i;
					i = 11;
				}
			}
			if (mult >= 3 && mult <= 10)
			{
				p1.getNPC(m.mapa[npc.getY() + mult*y][npc.getX() + mult*x]).setHp(p1.getNPC(m.mapa[npc.getY() + mult*y][npc.getX() + mult*x]).getHp() - (11 - mult));
				if (p1.getNPC(m.mapa[npc.getY() + mult*y][npc.getX() + mult*x]).getHp() <= 0)
				{
					std::string aux = p1.getNPC(m.mapa[npc.getY() + mult*y][npc.getX() + mult*x]).getTile();
					p1.modifyNPCList(m.mapa[npc.getY() + mult*y][npc.getX() + mult*x]);
					m.mapa[npc.getY() + mult*y][npc.getX() + mult*x] = aux;
				}
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
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
