#include "Game.h"

#include <iostream>

const int DUNGEON_HEIGHT = 6;
const int DUNGEON_WIDTH = 10;

const int EMPTY = 0;
const int LAMP = 1;
const int BOX_OF_DONUTS = 2;
const int CAT = 3;
const int ENTRY = 4;
const int EXIT = 5;
const int MAX_RAND_TYPE = CAT + 1;

Game::Game()
	: m_isRunning{ true }
{
}

Game::~Game()
{
}

void Game::Run()
{
	// Create player
	Player player;

	// Create dungeon map
	int rooms[DUNGEON_HEIGHT][DUNGEON_WIDTH];
	
	srand(time(nullptr));

	// Assigning values to the rooms randomly 
	for (int i = 0; i < DUNGEON_HEIGHT; ++i)
	{
		int roomType = rand() % (MAX_RAND_TYPE * 2);
		for (int j = 0; j < DUNGEON_WIDTH; i++)
		{
			if (roomType < MAX_RAND_TYPE)
			{
				rooms[i][j] = roomType;
			}
			else
			{
				rooms[i][j] = EMPTY;
			}
		}
	}
	// Setting the entry and exit of the map
	rooms[0][0] = ENTRY;
	rooms[DUNGEON_HEIGHT - 1][DUNGEON_WIDTH - 1] = EXIT;
	

	// Welcome text
	std::cout << "Welcome!\n";
	std::cout << "Move through the dungeon by saying North, South, East, or West\n";
	

	// Game loop
	while (m_isRunning)
	{
		// Get description for the rooms 
		rooms[player.playerX][player.playerY];
		

		



		// Movement
		
		std::cout << "What direction would you like to move?\n";
		std::cin >> direction;
		switch (HandleDirection(direction))
			{
		case 1:
		{
			std::cout << "You have moved north\n";
			break;
		}
		case 2:
		{
			std::cout << "You have moved south\n";
			break;
		}
		case 3:
		{
			std::cout << "You have moved east\n";
			break;
		}
		case 4:
		{
			std::cout << "You have moved west\n";
			break;
		}
		default:
		{
			std::cout << "Invalid input\n";
			continue;
		}
		}
		



	}
}

int Game::HandleDirection(string direction)
{
	if (direction == "north" || direction == "North")
	{
		return 1;
	}
	else if (direction == "south" || direction == "South")
	{
		return 2;
	}
	else if (direction == "east" || direction == "East")
	{
		return 3;
	}
	else if (direction == "west" || direction == "West")
	{
		return 4;
	}
	else
	{
		return -1;
	}

}
