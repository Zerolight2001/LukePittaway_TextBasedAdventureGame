#pragma once
#include <string>

#include "Player.h"
#include "Room.h"

using std::string
;
class Game
{
public:
	Game();
	~Game();

public:
	void Run();
	int HandleDirection(string direction);


private:
	bool m_isRunning;
	string direction;
};

