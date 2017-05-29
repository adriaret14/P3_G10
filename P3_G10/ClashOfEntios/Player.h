#pragma once
#include <list>
#include "NPC.h"
class Player
{
public:
	Player(int);									//Constructor por defecto de Player, pasando como parametro un entero con el que decidiremos si los iconos son numeros o letras
	~Player();										//Destructor de Player

	NPC & getNPC(std::string);						//Metodo para consultar un NPC, pasando como parametro el icono del NPC
	void setMovimientos(int);						//Metodo para establecer la cantidad de movimientos restantes de un jugador, pasando como parametros la cantidad de turnos
	int getMovimientos();							//Metodo para consultar el numero de movimientos restantes de un jugador
	void modifyNPCList(std::string);				//Metodo para modificar la lista de NPCs de un jugador(eliminar), pasando como parametro una cadena con el icono del NPC
	int getSizeNPCList();							//Metodo para consultar el tamaño de la lista de NPCs de un jugador
	std::list<NPC*> & getList();					//Metodo para obtener la lista por referencia

private:
	std::list<NPC*> NPCs;							//Lista de NPCs de cada personaje, usamos lista por su facilidad de eliminar el objeto cuando lo eliminas de la lista, entre otros
	int movimientos;
};

