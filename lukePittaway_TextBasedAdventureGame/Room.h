#pragma once

#include <string>

#include "Item.h"
#include "Lamp.h"
#include "Cat.h"
#include "BoxOfDonuts.h"

using std::string;

class Room
{
public:
	Item* item;
	
	Room* northPtr = nullptr;
	Room* southPtr = nullptr;
	Room* eastPtr = nullptr;
	Room* westPtr = nullptr;

public:
	Room(string description, Item* item);
	~Room();

public:
	const void Description();
	
private:
	string m_description;
	


};

