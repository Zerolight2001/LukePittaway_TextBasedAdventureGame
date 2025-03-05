#pragma once
#include <iostream>
#include <string>

using std::string;

class Item
{

public:
	virtual const void Description() = 0;
	virtual void Use() = 0;
	string ToString(string description);

};

