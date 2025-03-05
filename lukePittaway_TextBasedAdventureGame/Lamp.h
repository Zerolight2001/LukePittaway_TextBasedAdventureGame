#pragma once
#include "Item.h"

class Lamp : public Item
{
public:
	Lamp();	

public:
	// Inherited via Item
	const void Description() override;
	void Use() override;

private:
	bool m_turnedOn;
	string m_description;
};

