#pragma once
class NPC
{
public:
	NPC(char);							//Constructor por defecto del NPC, pasando como parametro el icono
	~NPC();							//Destructor de NPC
						
	void setIcon(char);				//Metodo para establecer el icono de un NPC, pasando como parametro el icono
	char getIcon();					//Metodo para consultar el icono de un NPC
	void setFatiga(float);			//Metodo para establecer la fatiga de un NPC, pasando como parametro la fatiga a sumar
	float getFatiga();				//Metodo para consultar la fatiga de un NPC
	void setFlechas(int);			//Metodo para establecer el numero de flechas que posee un NPC, pasando como parametro las flechas
	int getFlechas();				//Metodo para consultar las flechas disponibles de un NPC
	void setHp(int);				//Metodo para establecer la vida de un NPC, pasando como parametro la vida a sumar
	int getHp();					//Metodo para consultar la vida de un NPC
	void setX(int);					//Metodo para establecer la coordenada x de un NPC
	int getX();						//Metodo para consultar la coordenada x de un NPC
	void setY(int);					//Metodo para establecer la coordenada y de un NPC
	int getY();						//Metodo para consultar la coordenada y de un NPC
	void setLastX(int);				//Metodo para establecer la coordenada LastX de un NPC
	int getLastX();					//Metodo para consultar la coordenada LastX de un NPC
	void setLastY(int);				//Metodo para establecer la coordenada LastY de un NPC
	int getLastY();					//Metodo para consultar la coordenada LastY de un NPC

private: 
	char icon;					
	float fatiga;
	int nFlechas;
	int hp;
	int x;
	int y;
	int lastX;
	int lastY;
};

