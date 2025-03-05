#include "Room.h"


Room::Room(string description, Item* item)
	:m_description{ description }, item{ item }
{
	
}

Room::~Room()
{
}

const void Room::Description()
{	
	std::cout << m_description;
}

