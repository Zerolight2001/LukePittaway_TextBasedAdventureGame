#pragma once
#include <iostream>

class Item
{
public:
	Item();
	~Item();

public:
	virtual const void Description() = 0;
	virtual void Use() = 0;

};

