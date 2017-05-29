#include "NPC.h"



NPC::NPC(std::string c) :
	hp(10),
	nFlechas(10),
	fatiga(0),
	icon(c),
	tile("."),
	isActive(false)
{
}


NPC::~NPC()
{
}

void NPC::setIcon(std::string c)
{
	icon = c;
}

std::string NPC::getIcon()
{
	return icon;
}

void NPC::setFatiga(float f)
{
	fatiga = f;
}

float NPC::getFatiga()
{
	return fatiga;
}

void NPC::setFlechas(int nf)
{
	nFlechas = nf;
}

int NPC::getFlechas()
{
	return nFlechas;
}

void NPC::setHp(int life)
{
	hp = life;
}

int NPC::getHp()
{
	return hp;
}

void NPC::setX(int n)
{
	x = n;
}

int NPC::getX()
{
	return x;
}

void NPC::setY(int n)
{
	y = n;
}

int NPC::getY()
{
	return y;
}

void NPC::setLastX(int n)
{
	lastX = n;
}

int NPC::getLastX()
{
	return lastX;
}

void NPC::setLastY(int n)
{
	lastY = n;
}

int NPC::getLastY()
{
	return lastY;
}

void NPC::setTile(std::string t)
{
	tile = t;
}

std::string NPC::getTile()
{
	return tile;
}

void NPC::setActive(bool b)
{
	isActive = b;
}

bool NPC::getActive()
{
	return isActive;
}
