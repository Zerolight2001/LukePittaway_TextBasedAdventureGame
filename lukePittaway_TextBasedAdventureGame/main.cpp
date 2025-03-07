#include <iostream>

#include "Game.h"
// Combat branch
int main()
{
	Game* game = new Game();

	game->Run();

	delete game;

	return EXIT_SUCCESS;
}