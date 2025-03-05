#pragma once
#include <string>

#include "Player.h"
#include "Room.h"

const int MAP_HEIGHT = 2;
const int MAP_WIDTH = 4;

using std::string
;
class Game
{
public:
	Game();
	~Game();

public:
	void Run();
	void HandleCommand(string direction);
	string PossibleActions();
	void PrintDescription();



private:
	bool m_isRunning;
	string m_command;

	Player* m_player;	

	// Item vairables
	Cat* m_cat;
	BoxOfDonuts* m_boxOfDonuts;
	Lamp* m_lamp;


	// Map
	Room* m_rooms[MAP_HEIGHT][MAP_WIDTH];
	

	// Room vaiables
	Room* m_rEntry;
	Room* m_rEmpty1;
	Room* m_rLamp;
	Room* m_rEmpty2;
	Room* m_rCat;
	Room* m_rDonut;
	Room* m_rEmpty3;
	Room* m_rExit;


};

