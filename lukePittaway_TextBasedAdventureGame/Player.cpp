#include "Player.h"

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;


Player::Player()
	: m_position{ new Vector2( 0, 0 )}
{
	
}

Player::~Player()
{
	delete m_position;
	m_position = nullptr;
}

bool Player::FindSpell(string spell)
{
	std::sort(m_spells.begin(), m_spells.end());

	int lowIndex = 0;
	int highIndex = static_cast<int>(m_spells.size() - 1);

	int midpoint = (lowIndex + highIndex) / 2;
	
	

	while (lowIndex <= highIndex)
	{
		if (m_spells[midpoint] == spell)
		{
			return true;
		}

		if (m_spells[midpoint] < spell)
		{
			lowIndex = midpoint + 1;
		}

		if (m_spells[midpoint] > spell)
		{
			highIndex = midpoint - 1;
		}

		midpoint = (lowIndex + highIndex) / 2;
	}

	return false;
}

void Player::Setposisiton(Vector2 position)
{
	if (m_position != nullptr)
	{
		*m_position = position;
	}
}

Vector2 Player::Getposition()
{
	if (m_position != nullptr)
	{
		return *m_position;
	}
	return { 0, 0 };
}
