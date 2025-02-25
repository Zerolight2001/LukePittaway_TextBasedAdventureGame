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
	
public:
	Room(string description, Item *item);
	~Room();

public:
	const void Description(int roomType);
	

private:
	string m_description;
	
};

