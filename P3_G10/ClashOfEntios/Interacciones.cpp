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
	int dx;
	int dy;
	switch (dir)
	{
	case DIRECCION::W:
		dx = 0;
		dy = -1;
		break;
	case DIRECCION::A:
		dx = -1;
		dy = 0;
		break;
	case DIRECCION::S:
		dx = 0;
		dy = 1;
		break;
	case DIRECCION::D:
		dx = 1;
		dy = 0;
		break;
	}
	if (npc.getX() + dx >= 0 && npc.getX() + dx <= 72 && npc.getY() + dy >= 0 && npc.getY() + dy <= 35)
	{
		if (walkable.find(m.getCell(npc.getX() + dx, npc.getY() + dy)) != std::string::npos) {
			lastMoveX = npc.getX();
			lastMoveY = npc.getY();
			npc.setX(npc.getX() + dx);
			npc.setY(npc.getY() + dy);
			m.updCell(npc.getTile(), lastMoveX, lastMoveY);
			npc.setTile(m.getCell(npc.getX(), npc.getY()));
			m.updCell(npc.getIcon(), npc.getX(), npc.getY());
			flagDeshacer = 0;
		}
	}
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
				npc.setFlechas(npc.getFlechas() - 1);
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
				npc.setFlechas(npc.getFlechas() - 1);
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
	std::list<NPC*>::iterator it1 = p1.getList().begin();
	std::list<NPC*>::iterator it2 = p2.getList().begin();

	switch (jugador) {
	case 1:
		npcs = "";
		
		while (it1 != p1.getList().end())
		{
			npcs = npcs + (*it1)->getIcon();
			it1++;
		}
		for (int i = 0; i < p1.getList().size(); i++) 
		{
			npc = npcs[i];
			if (p1.getNPC(npc).getFatiga() < p1.getNPC(nextNPCicon).getFatiga())
			{
				nextNPCicon = npc;
			}
		}
		return nextNPCicon;
	case 2:
		npcs = "";

		while (it2 != p2.getList().end())
		{
			npcs = npcs + (*it2)->getIcon();
			it2++;
		}
		for (int i = 0; i < p2.getList().size(); i++)
		{
			npc = npcs[i];
			if (p2.getNPC(npc).getFatiga() < p2.getNPC(nextNPCicon).getFatiga())
			{
				nextNPCicon = npc;
			}
		}
		return nextNPCicon;
	}
}
