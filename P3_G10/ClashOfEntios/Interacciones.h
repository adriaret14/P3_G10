#pragma once
#include "Player.h"
#include "Map.h"


class Interacciones
{
public:
	Interacciones(Player &, Player &, Map &);				//Constructor de la clase interacciones, pasando como referencia ambos Players y el Mapa
	~Interacciones();										//Destructor de la clase interacciones

	void movimientoNPC(NPC &, int);							//Metodo para realizar un movimiento en los NPC, pasando como referencia el NPC y como parametro la direccion
	void deshacerMovimiento(NPC &);							//Metodo para deshacer un solo movimiento en los NPC, pasando como referencia el NPC
	void rehacerMovimiento(NPC &);							//Metodo para rehacer un solo movimiento en los NPC, pasando como referencia el NPC
	void ataque(NPC &, int);								//Metodo para realizar un ataque, pasando como refernecia el NPC que ataca y como parametro la direccion a la que ataca
	void cambioNPC();										//MEtodo para cambiar de NPC, procesando la fatiga del NPC anteriormente usado
	



private:
	Player &p1;
	Player &p2;
	Map &m;

	int lastMoveX;
	int lastMoveY;
};

