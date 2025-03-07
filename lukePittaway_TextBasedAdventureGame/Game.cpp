#include "Game.h"

#include <iostream>
#include <cstdlib>
#include <algorithm>


Game::Game()
	: m_isRunning{ true },m_isCombat{ false }, m_player{ new Player }, m_enemy{ new Enemy("George", 50, 10 ) }
{
	// Create rooms 
	m_rEntry = new Room("This is the entry of the dungeon.\nLooks like its blocked of so you will have to find another way out\n", nullptr);
	m_rEmpty1 = new Room("Empty room, nothing but dusty floorboards\n", nullptr);
	m_rLamp = new Room("Lamp", m_lamp = new Lamp);
	m_rEmpty2 = new Room("Empty room, nothing but dusty floorboards\n", nullptr);
	m_rCat = new Room("Cat", m_cat = new Cat);
	m_rDonut = new Room("Donut", m_boxOfDonuts = new BoxOfDonuts);
	m_rEmpty3 = new Room("Empty room, nothing but dusty floorboards, and geoges corpse...\n", nullptr);
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
	delete m_rCat;
	m_rCat = nullptr;
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
	delete m_enemy;
	m_enemy = nullptr;
	delete m_player;
	m_player = nullptr;
}

 void Game::Run()
{
	// Welcome text
	std::cout << MAGENTA <<  "Welcome!\n";
	std::cout << MAGENTA << "Move through the dungeon by typing North, South, East, or West\n\n" << RESET_COLOR;	

	// Game loop
	while (m_isRunning)
	{

		if (m_rooms[m_player->Getposition().x][m_player->Getposition().y] == m_rooms[1][2])
		{
			Combat(*m_enemy);
		}

		// Print room description	
		PrintDescription();
		// Give possible actions
		std::cout << PossibleActions();	
		// Get input
		std::cout << YELLOW << "What Action would you like to take?\n\n" << RESET_COLOR;
		std::cin >> m_command;
		// Turns input to lowercase
		std::transform(m_command.begin(), m_command.end(), m_command.begin(), ::tolower);
		// Use input or move character
		HandleCommand(m_command);

		if (
			m_command == "north"  ||
			m_command == "south" || 
			m_command == "east" || 
			m_command == "west" || 
			m_command == "use" 
			)
		{
			// Clear page
			std::system("cls");
		}			
	}

	std::cout << YELLOW << "Game over, you may leave now...\n" << RESET_COLOR;
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
		if (command == "south")
		{
			m_player->Setposisiton(Vector2(0, 1));			
		}
		else if (command == "spells")
		{
			DoMagic();			
		}
		else
		{
			std::cout << RED << "Invalid input!\n\n" << RESET_COLOR;
		}
	}

	else if (m_rooms[playerX][playerY] == m_rEmpty1)
	{
		if (command == "east")
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
			std::cout << RED << "Invalid input!\n\n" << RESET_COLOR;
		}
	}

	else if (m_rooms[playerX][playerY] == m_rLamp)
	{
		if (command == "east")
		{
			m_player->Setposisiton(Vector2(0, 1));
		}
		else if (command == "south")
		{
			m_player->Setposisiton(Vector2(0, 3));
		}
		else if (command == "use")
		{
			m_lamp->Use();
		}
		else if (command == "spells")
		{
			DoMagic();
		}
		else
		{
			std::cout << RED << "Invalid input!\n\n" << RESET_COLOR;
		}
	}

	else if (m_rooms[playerX][playerY] == m_rEmpty2)
	{
		if (command == "north")
		{
			m_player->Setposisiton(Vector2(0, 2));
		}
		else if (command == "spells")
		{
			DoMagic();
		}
		else
		{
			std::cout << RED << "Invalid input!\n\n" << RESET_COLOR;
		}
	}

	else if (m_rooms[playerX][playerY] == m_rCat)
	{
		if (command == "east")
		{
			m_player->Setposisiton(Vector2(1, 2));
		}
		else if (command == "west")
		{
			m_player->Setposisiton(Vector2(0, 1));
		}
		else if (command == "south")
		{
			m_player->Setposisiton(Vector2(1, 1));
		}
		else if (command == "use")
		{
			m_cat->Use();
		}
		else if (command == "spells")
		{
			m_player->usedFireball = false;
			DoMagic();
			if (m_cat->isCatDead == false && m_player->usedFireball == true)
			{			
					std::cout << RED << "The cat was ammused by the light and stayed still for to long\n";
					std::cout << "His fur bursts into flames and he is now bouncing of the walls chaotically\n";
					std::cout << "You watch as he the boucing becomes slower until you see him thud against the wall\n" << RESET_COLOR;

					m_cat->isCatDead = true;				
			}

		}
		else
		{
			std::cout << RED << "Invalid input!\n\n" << RESET_COLOR;
		}
	}

	else if (m_rooms[playerX][playerY] == m_rDonut)
	{
		if (command == "north")
		{
			m_player->Setposisiton(Vector2(1, 0));
		}
		else if (command == "use")
		{
			m_boxOfDonuts->Use();
		}
		else if (command == "spells")
		{
			DoMagic();
		}
		else
		{
			std::cout << RED << "Invalid input!\n\n" << RESET_COLOR;
		}
	}

	else if (m_rooms[playerX][playerY] == m_rEmpty3)
	{
		if (command == "north")
		{
			m_player->Setposisiton(Vector2(1, 3));
		}
		else if (command == "west")
		{
			m_player->Setposisiton(Vector2(1, 0));
		}
		else if (command == "spells")
		{
			DoMagic();
		}
		else
		{
			std::cout << RED << "Invalid input!\n\n" << RESET_COLOR;
		}
	}

	else if (m_rooms[playerX][playerY] == m_rExit)
	{
		if (command == "south")
		{
			m_player->Setposisiton(Vector2(1, 2));
		}
		else if (command == "spells")
		{
			m_player->usedFireball = false;
		
			DoMagic();
			if (m_player->usedFireball == true)
			{
				std::cout << BLUE << "The Door is now on fire\n";
				std::cout << "Turns out that thick solid wood burn pretty slowly...\n";
				std::cout << "With a closer look you do notice the door is actually cracked open a little\n\n";
				std::cout << "you look around to make sure no one saw and exit the dungeon\n\n" << RESET_COLOR;

				m_isRunning = false;
				
			}
		}
		else
		{
			std::cout << RED << "Invalid input!\n\n" << RESET_COLOR;
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
	std::cout << YELLOW << "what spell would you like to look for?\n" << RESET_COLOR;
	std::cout << "possible spell:\n-Fireball\n-Spark\n";
	std::cin >> m_spell;		

	if (m_player->FindSpell(m_spell) == true)
	{
		std::cout << GREEN << "Spell found!\nWould you like to use it?  Yes/No\n" << RESET_COLOR;
		std::cin >> m_spellCommand;
		std::transform(m_spellCommand.begin(), m_spellCommand.end(), m_spellCommand.begin(), ::tolower);

		std::cout << "\n";
		if (m_spellCommand == "yes")
		{
			m_player->UseSpell(m_spell);
		}
		else if (m_spellCommand == "no")
		{
			// Clear page
			std::system("cls");
			std::cout << "probably for the best\n\n";
		}
		else
		{
			std::cout << RED << "Invalid Input" << RESET_COLOR;
		}
	}
	else
	{
		std::cout << RED << "SPELL NOT FOUND! Magic has to be very precise\n\n" << RESET_COLOR;		
	}
}

void Game::Combat(Enemy enemy)
{
	m_isCombat = true;

	srand(time(nullptr));
	
	// Encounter text
	std::cout << BLUE << "You walk into the room and feel something tug at your feet\n";
	std::cout << "You look down to see that an ethernet cable has just been ripped from the wall\n";
	std::cout << "Its at this moment you hear raging footsteps stampeeding down the corridor\n\n";
	std::cout << "A guy comes bursting out from depths of the dungeon still wearing his headset and holding a controller\n";
	std::cout << "He sees you standing over the chord\n\n" << RESET_COLOR;
	std::cout << RED << "You are now in combat!\n\n" << RESET_COLOR;

	// Fight loop
	while (m_isCombat)
	{		
		// Show health
		std::cout << "Player health: " << m_player->GetHealth() << "\n";
		std::cout << "Enemy health: " << m_enemy->GetHealth() << "\n\n";
		
		// if player is alive let them do something 
		if (m_player->GetHealth() > 0)
		{
			std::cout << YELLOW << "What action would you like to take\n" << RESET_COLOR;
			std::cout << "Possible actions:\n-Attack\n-spells\n-Roll\n-Run\n";
			std::cin >> m_fCommand;
			// Change command to lowercase
			std::transform(m_fCommand.begin(), m_fCommand.end(), m_fCommand.begin(), ::tolower);
			std::cout << "\n\n";

			if (m_fCommand == "attack")
			{
				// Clear page
				std::system("cls");
				std::cout << GREEN <<"You punch him\n\n" << RESET_COLOR;
				m_enemy->TakeDamage(m_player->GetDamage());
			}
			else if (m_fCommand == "spells")
			{
				DoMagic();
			}
			else if (m_fCommand == "roll")
			{
				// Clear page
				std::system("cls");				
			}
			else if (m_fCommand == "run")
			{
				// Clear page
				std::system("cls");
				std::cout << RED << "There is no running!! you must stay and face what you have done\n\n" << RESET_COLOR;
			}
			else
			{
				// Clear page
				std::system("cls");
				std::cout << RED << "Invalid input\n" << RESET_COLOR;
			}
		}
		else 
		{

			m_isRunning = false;
			break;
		}
		
		// pick random number between 1 and 3
		int eAttack = (rand() % 3) + 1;

		// If the enemy still has health, make an action 
		if (m_enemy->GetHealth() > 0)
		{
			switch (eAttack)
			{
			case 1:
			{
				// Attack
				if (m_fCommand == "roll")
				{		
					std::cout << GREEN << "George tried to attacked you but due to your sick roll it was a swing and a miss\n\n" << RESET_COLOR;
					break;
				}
				else
				{					
					std::cout << RED << m_enemy->name << " has attacked you\n\n" << RESET_COLOR;
					m_player->TakeDamage(m_enemy->Getdamage());
					break;
				}				
			}
			case 2:
			{
				// Block
				if (m_fCommand == "attack")
				{
					std::cout << RED << "you got blocked\n\n" << RESET_COLOR;
					m_enemy->GainHealth(m_player->GetDamage());
				}
				else
				{
					std::cout << GREEN << "He thows his arms up like a fool trying to block your roll\n\n" << RESET_COLOR;
				}
				break;
			}
			case 3:
			{
				// freezes
				std::cout << RED << "He is to angry to move\n\n" << RESET_COLOR;
				break;
			}
			}
		}
		else
		{
			m_isCombat = false;
		}
	

	}

	// Clear page
	std::system("cls");
	std::cout << GREEN << enemy.name << " Has Been Defeated\n\n" << RESET_COLOR;


}

