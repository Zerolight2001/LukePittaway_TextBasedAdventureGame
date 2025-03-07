#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

using std::string;

class Item
{

public:
	virtual const void Description() = 0;
	virtual void Use() = 0;
	
protected:
	const char* M_RED = "\x1b[91m";
	const char* M_BLUE = "\x1b[94m";
	const char* M_RESET_COLOR = "\x1b[0m";
};

