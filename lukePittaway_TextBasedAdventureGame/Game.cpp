#include "Game.h"

#include <iostream>
#include <cstdlib>

Game::Game()
	: m_isRunning{ true }, m_player{ new Player }, m_cat{new Cat}, m_boxOfDonuts{new BoxOfDonuts},
	m_lamp{ new Lamp }
{
	// Create rooms 
	m_rEntry = new Room("This is the entry of the dungeon.\nLooks like its blocked of so you will have to find another way out\n", nullptr);
	m_rEmpty1 = new Room("Empty room, nothing but dusty floorboards\n", nullptr);
	m_rLamp = new Room("Lamp", m_lamp);
	m_rEmpty2 = new Room("Empty room, nothing but dusty floorboards\n", nullptr);
	m_rCat = new Room("Cat", m_cat);
	m_rDonut = new Room("Donut", m_boxOfDonuts);
	m_rEmpty3 = new Room("Empty room, nothing but dusty floorboards\n", nullptr);
	m_rExit = new Room("You found the exit! Seems to blocked with a highly famable wooden door\n", nullptr);


	// Put rooms in an array 
	m_rooms[0][0] = m_rEntry;
	m_rooms[0][1] = m_rEmpty1;
	m_rooms[0][2] = m_rLamp;
	m_rooms[0][3] = m_rEmpty2;
	m_rooms[1][0] = m_rCat;
	m_rooms[1][1] = m_rDonut;
	m_rooms[1][2] = m_rEmpty3;
	m_rooms[1][3] = m_rExit;

}

Game::~Game()
{
	delete m_rExit;
	m_rExit = nullptr;
	delete m_rEmpty3;
	m_rEmpty3 = nullptr;
	delete m_rDonut;
	m_rDonut = nullptr;
	delete m_cat;
	m_cat = nullptr;
	delete m_rEmpty2;
	m_rEmpty2 = nullptr;
	delete m_rLamp;
	m_rLamp = nullptr;
	delete m_rEmpty1;
	m_rEmpty1 = nullptr;
	delete m_rEntry;
	m_rEntry = nullptr;
	delete m_lamp;
	m_lamp = nullptr;
	delete m_boxOfDonuts;
	m_boxOfDonuts = nullptr;
	delete m_cat;
	m_cat = nullptr;
	delete m_player;
	m_player = nullptr;
}

 void Game::Run()
{
	// Welcome text
	std::cout << "Welcome!\n";
	std::cout << "Move through the dungeon by typing North, South, East, or West\n\n";
		


	// Game loop
	while (m_isRunning)
	{
			
		PrintDescription();

		std::cout << PossibleActions();	
		
		std::cout << "What Action would you like to take?\n\n";
		std::cin >> m_command;

		HandleCommand(m_command);
		
		
		
		//std::system("cls");
		
	}

	std::cout << "Game over, you may leave now...\n";
}

// check to see if command is valid depending on what room it is in
// take input and move player to next room or use an item
void Game::HandleCommand(string command)
{
	int playerX = m_player->Getposition().x;
	int playerY = m_player->Getposition().y;

	std::cout << "\n";

	if (m_rooms[playerX][playerY] == m_rEntry)
	{
		if (command == "south" || command == "South")
		{
			m_player->Setposisiton(Vector2(0, 1));
		}
		else if (command == "spells" || command == "Spells")
		{
			DoMagic();			
		}
		else
		{
			std::cout << "Invalid input!\n\n";
		}
	}

	else if (m_rooms[playerX][playerY] == m_rEmpty1)
	{
		if (command == "east" || command == "East")
		{
			m_player->Setposisiton(Vector2(1, 0));
		}
		else if (command == "west" || command == " West")
		{
			m_player->Setposisiton(Vector2(0, 2));
		}
		else if (command == "spells" || command == "Spells")
		{
			DoMagic();
		}
		else
		{
			std::cout << "Invalid input!\n\n";
		}
	}

	else if (m_rooms[playerX][playerY] == m_rLamp)
	{
		if (command == "east" || command == "East")
		{
			m_player->Setposisiton(Vector2(0, 1));
		}
		else if (command == "south" || command == "South")
		{
			m_player->Setposisiton(Vector2(0, 3));
		}
		else if (command == "use" || command == "Use")
		{
			m_lamp->Use();
		}
		else if (command == "spells" || command == "Spells")
		{
			DoMagic();
		}
		else
		{
			std::cout << "Invalid input!\n\n";
		}
	}

	else if (m_rooms[playerX][playerY] == m_rEmpty2)
	{
		if (command == "north" || command == "North")
		{
			m_player->Setposisiton(Vector2(0, 2));
		}
		else if (command == "spells" || command == "Spells")
		{
			DoMagic();
		}
		else
		{
			std::cout << "Invalid input!\n\n";
		}
	}

	else if (m_rooms[playerX][playerY] == m_rCat)
	{
		if (command == "east" || command == "East")
		{
			m_player->Setposisiton(Vector2(1, 2));
		}
		else if (command == "west" || command == " West")
		{
			m_player->Setposisiton(Vector2(0, 1));
		}
		else if (command == "south" || command == "South")
		{
			m_player->Setposisiton(Vector2(1, 1));
		}
		else if (command == "use" || command == "Use")
		{
			m_cat->Use();
		}
		else if (command == "spells" || command == "Spells")
		{
			DoMagic();
		}
		else
		{
			std::cout << "Invalid input!\n\n";
		}
	}

	else if (m_rooms[playerX][playerY] == m_rDonut)
	{
		if (command == "north" || command == "North")
		{
			m_player->Setposisiton(Vector2(1, 0));
		}
		else if (command == "use" || command == "Use")
		{
			m_boxOfDonuts->Use();
		}
		else if (command == "spells" || command == "Spells")
		{
			DoMagic();
		}
		else
		{
			std::cout << "Invalid input!\n\n";
		}
	}

	else if (m_rooms[playerX][playerY] == m_rEmpty3)
	{
		if (command == "north" || command == "North")
		{
			m_player->Setposisiton(Vector2(1, 3));
		}
		else if (command == "west" || command == "West")
		{
			m_player->Setposisiton(Vector2(1, 0));
		}
		else if (command == "spells" || command == "Spells")
		{
			DoMagic();
		}
		else
		{
			std::cout << "Invalid input!\n\n";
		}
	}

	else if (m_rooms[playerX][playerY] == m_rExit)
	{
		if (command == "south" || command == "South")
		{
			m_player->Setposisiton(Vector2(1, 2));
		}
		else if (command == "spells" || command == "Spells")
		{
		
		
			DoMagic();
			if (m_player->usedFireball == true)
			{
				std::cout << "The Door is now on fire\n";
				std::cout << "Turns out that thick solid wood burn pretty slowly...\n";
				std::cout << "With a closer look you do notice the door is actually cracked open a little\n\n";
				std::cout << "you look around to make sure no one saw and exit the dungeon\n\n";

				m_isRunning = false;
				
			}
		}
		else
		{
			std::cout << "Invalid input!\n\n";
		}
	}	

}


// gets the location of player and gives possible actions 
string Game::PossibleActions()
{	
	int playerX = m_player->Getposition().x;
	int playerY = m_player->Getposition().y;

	if (m_rooms[playerX][playerY] == m_rooms[0][0])
	{
		return "Possible Action:\n-south\n-Spells\n\n";
	}
	else if (m_rooms[playerX][playerY] == m_rooms[0][1])
	{
		return "Possible Action:\n-West\n-East\n-Spells\n\n";
	}
	else if (m_rooms[playerX][playerY] == m_rooms[0][2])
	{
		return "Possible Action:\n-South\n-East\n-Use\n-Spells\n\n";
	}
	else if (m_rooms[playerX][playerY] == m_rooms[0][3])
	{
		return "Possible Action:\n-North\n-Spells\n\n";
	}
	else if (m_rooms[playerX][playerY] == m_rooms[1][0])
	{
		return "Possible Action:\n-West\n-East\n-South\n-Use\n-Spells\n\n";
	}
	else if (m_rooms[playerX][playerY] == m_rooms[1][1])
	{
		return "Possible Action:\n-North\n-Use\n-Spells\n\n";
	}
	else if (m_rooms[playerX][playerY] == m_rooms[1][2])
	{
		return "Possible Action:\n-North\n-West\n-Spells\n\n";
	}
	else if (m_rooms[playerX][playerY] == m_rooms[1][3])
	{
		return "Possible Action:\n-South\n-Spells\n\n";
	}
	else
	{
		return "you have fallen of the map";
	}
}

// Prints string of room you are in
void Game::PrintDescription()
{
	int playerX = m_player->Getposition().x;
	int playerY = m_player->Getposition().y;

	if (m_rooms[playerX][playerY] == m_rCat)
	{
		m_cat->Description();
	}
	else if (m_rooms[playerX][playerY] == m_rLamp)
	{
		m_lamp->Description();
	}
	else if (m_rooms[playerX][playerY] == m_rDonut)
	{
		m_boxOfDonuts->Description();
	}
	else
	{
		m_rooms[playerX][playerY]->Description();
	}
}

// Take input for spell - Search for spell - Do the spell if chosen
void Game::DoMagic()
{
	std::cout << "what spell would you like to look for?\n";
	std::cout << "possible spell:\n-Fireball\n-Spark\n";
	std::cin >> m_spell;

	m_player->FindSpell(m_spell);

	if (m_player->FindSpell(m_spell) == true)
	{
		std::cout << "Spell found!\nWould you like to use it?  Yes/No\n";
		std::cin >> m_spellCommand;
		if (m_spellCommand == "yes" || m_spellCommand == "Yes")
		{
			m_player->UseSpell(m_spell);
		}
		else if (m_spellCommand == "no" || m_spellCommand == "No")
		{
			std::cout << "probably for the best\n\n";
		}
	}
	else
	{
		std::cout << "Spell NOT found! magic has to be very precise\n\n";		
	}
}

