#pragma once
#include "Item.h"

class BoxOfDonuts : public Item
{
public:
	BoxOfDonuts();

public:
	// Inherited via Item
	const void Description() override;
	void Use() override;

private:
	int m_count;
};

