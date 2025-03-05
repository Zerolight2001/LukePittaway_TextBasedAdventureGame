#include "Player.h"

Player::Player()
	: m_position{ new Vector2( 0, 0 )}
{
}

Player::~Player()
{
}

bool Player::FindSpell(string spell)
{
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
