#pragma once

#include <string>
#include <Windows.h>


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
	Room(string description, Item* item);
	~Room();

public:
	const void Description();
	
private:
	string m_description;	
	
	const char* M_BLUE = "\x1b[94m";
	const char* M_RESET_COLOR = "\x1b[0m";

};

