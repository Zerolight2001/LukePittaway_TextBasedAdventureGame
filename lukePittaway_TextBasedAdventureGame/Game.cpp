#include "Game.h"

#include <iostream>



Game::Game()
	: m_isRunning{ true }, m_player{ new Player },
	m_entry{ new Room("Entry", nullptr)}, m_room1{ new Room("Empty", nullptr) }, m_room2{ new Room("Empty", nullptr) },
	m_room3{ new Room("Empty", nullptr) }, m_catRoom{ new Room("Cat", &cat) }, m_donutRoom{ new Room("Donuts", &boxOfDonuts) },
	m_lampRoom{ new Room("Lamp", &lamp)}, m_exit{new Room("Exit", nullptr)}		
{
	// Fill array with all the rooms
	m_rooms[0][0] = m_entry;
	m_rooms[0][1] = m_room1;
	m_rooms[0][2] = m_room2;
	m_rooms[0][3] = m_room3;
	m_rooms[1][0] = m_catRoom;
	m_rooms[1][1] = m_lampRoom;
	m_rooms[1][2] = m_donutRoom;
	m_rooms[1][3] = m_exit;

};


Game::~Game()
{

	delete m_exit;
	delete m_lampRoom;
	delete m_donutRoom;
	delete m_catRoom;
	delete m_room3;
	delete m_room2;
	delete m_room1;
	delete m_entry;
	delete m_player;
	m_player = nullptr;
}

int Game::Run()
{
		
	

	// Welcome text
	std::cout << "Welcome!\n";
	std::cout << "Move through the dungeon by saying North, South, East, or West\n";
	

	// Game loop
	while (m_isRunning)
	{
	

		PossibleActions(m_playerX, m_playerY);

	


		// Movement		
		std::cout << "What direction would you like to move?\n";
		std::cin >> direction;
		switch (HandleDirection(direction))
			{
		case 1:
		{
			std::cout << "You have moved north\n\n";
			m_rooms[m_playerX][m_playerY]->Description(0);
			break;
		}
		case 2:
		{
			std::cout << "You have moved south\n\n";
			m_rooms[m_playerX][m_playerY]->Description(0);
			break;
		}
		case 3:
		{
			std::cout << "You have moved east\n\n";
			break;
		}
		case 4:
		{
			std::cout << "You have moved west\n\n";
			break;
		}
		default:
		{
			std::cout << "Invalid input\n\n";
			continue;
		}
		}
		

		

	}

	return EXIT_SUCCESS;
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

string Game::PossibleActions(int posX, int posY)
{
	if (m_rooms[posX][posY] == m_entry)
	{
		std::cout << "possible actions:\n-South.\n\n";
		if (HandleDirection(direction) == 2)
		{
			m_playerX = 0;
			m_playerY = 1;
		}
	}
	if (m_rooms[posX][posY] == m_room1)
	{
		std::cout << "possible actions:\n-East\n-West\n\n";
		if (HandleDirection(direction) == 3)
		{
			m_playerX = 1;
			m_playerY = 0;

		}
	}
	if (m_rooms[posX][posY] == m_lampRoom)
	{
		std::cout << "possible actions:\n-East\n-South\n-Use\n\n";
	}
	if (m_rooms[posX][posY] == m_room2)
	{
		std::cout << "possible actions\n-North\n\n";
	}
	if (m_rooms[posX][posY] == m_catRoom)
	{
		std::cout << "possible actions\n-East\n-South\n\n";
	}
	if (m_rooms[posX][posY] == m_donutRoom)
	{
		std::cout << "possible actions\n-North\n-use\n\n";
	}
	if (m_rooms[posX][posY] == m_room3)
	{
		std::cout << "possible actions\n-North\n-West\n\n";
	}
	if (m_rooms[posX][posY] == m_exit)
	{
		std::cout << "possible actions\n-South\n-Exit\n\n";
	}



	return string();
}
