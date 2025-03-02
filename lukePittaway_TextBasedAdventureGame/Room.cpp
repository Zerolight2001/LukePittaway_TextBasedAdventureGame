#include "Room.h"



const int EMPTY = 0;
const int LAMP = 1;
const int BOX_OF_DONUTS = 2;
const int CAT = 3;
const int ENTRY = 4;
const int EXIT = 5;
const int MAX_RAND_TYPE = CAT + 1;

Room::Room(string description, Item* item)
	:m_description{ description }, item{ item }
{
	
}

Room::~Room()
{
}



const void Room::Description(int roomType)
{
	switch (roomType)
	{
	case EMPTY:
	{
		std::cout << "Empty room, nothing but dusty floorboards\n";
		break;
	}
	case LAMP:
	{
		std::cout << &Lamp::Description;
		break;
	}
	case BOX_OF_DONUTS:
	{
		std::cout << &BoxOfDonuts::Description;
		break;
	}
	case CAT:
	{
		std::cout << &Cat::Description;
		break;
	}
	case ENTRY:
	{
		std::cout << "This is the entry of the dungeon.\nLooks like its collapsed as you entered of so you will have to find another way out\n";
		break;
	}
	case EXIT:
	{
		std::cout << "Congrats you found the exit!\nYou win!!\n";
		break;
	}
	default:
	{
		std::cout << "Dont know how you did it but you have fallen out of the map";
		break;
	}
	}
	return void();
}



