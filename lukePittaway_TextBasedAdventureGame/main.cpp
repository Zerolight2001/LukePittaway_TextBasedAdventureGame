#include <iostream>

#include "Game.h"

#if _DEBUG
// Define the macro that will enable the memory leak detection tools
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

int main()
{
#if _DEBUG
	// thse flags turn on the memory leak traking tools 
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// This function will enable a breakpoint when the program
	// reaches a piece of memory with the matching ID
	//_CrtSetBreakAlloc(230);
#endif

	Game* game = new Game();

	game->Run();

	delete game;

	return EXIT_SUCCESS;
}