#include <iostream>

#include "Game.h"

int main()
{
	Game* game = new Game();

	int state = game->Run();

	delete game;

	return state;
}