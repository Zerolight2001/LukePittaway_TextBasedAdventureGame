#pragma once
#include <string>

#include "Player.h"
#include "Room.h"
#include "Enemy.h"

class Enemy;
class Player;
class Room;

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
	void DoMagic();
	void Combat(Enemy enemy);



private:
	bool m_isRunning;
	bool m_isCombat;
	string m_fCommand;
	string m_command;
	string m_spellCommand;
	string m_spell;

	Player* m_player;
	Enemy* m_enemy;

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

