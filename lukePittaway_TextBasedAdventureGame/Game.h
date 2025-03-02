#pragma once
#include <string>

#include "Player.h"
#include "Room.h"



const int MAP_WIDTH = 4;
const int MAP_HEIGHT = 2;

using std::string
;
class Game
{
public:
	Game();
	~Game();

public:
	int Run();
	int HandleDirection(string direction);
	string PossibleActions(int posX, int posY);


private:
	bool m_isRunning;
	string direction;
	
	Player* m_player;
	int m_playerX = m_player->playerX;
	int m_playerY = m_player->playerY;

	Cat cat;
	BoxOfDonuts boxOfDonuts;
	Lamp lamp;

	Room* m_rooms[MAP_WIDTH][MAP_HEIGHT];
	 
	Room* m_entry;
	Room* m_room1;
	Room* m_room2;
	Room* m_room3;
	Room* m_catRoom;
	Room* m_donutRoom;
	Room* m_lampRoom;
	Room* m_exit;
};

