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
	Room(string description, Item *item);
	~Room();

public:
	const void Description();

public:
	Item* item;
	string description;

};

