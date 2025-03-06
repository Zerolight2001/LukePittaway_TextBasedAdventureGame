#include "Player.h"

#include <iostream>
#include <vector>
#include <algorithm>

#include "Spell.h"


Player::Player()
	: position{ new Vector2( 0, 0 ) }, fireball{ new Spell("Fireball" , 5) }, spark{ new Spell( "Spark", 3 ) }, usedFireball{ false },
	m_damage{ 10 }, m_health{ 60 }
{
	m_spells.emplace_back(fireball->name);
	m_spells.emplace_back(spark->name);	

	fireball->description = "A ball of fire sad wobbley shuffles out of your hands and slowly makes its way outwards\n\n";
	spark->description = "A few little sparks shoot out from your fingers...\nYou definitly should have payed more attention in your \"how to be a wizard seminare\" \n\n";

}

Player::~Player()
{
	delete spark;
	spark = nullptr;
	delete fireball;
	fireball = nullptr;
	delete position;
	position = nullptr;
}

// Binary seach. returns true if spell was found 
bool Player::FindSpell(string spell)
{	
	std::sort(m_spells.begin(), m_spells.end(), &Spell::compare);

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
// prints what spell you used and then what spell description 
void Player::UseSpell(string spell)
{

	if (fireball->compare(fireball->name, spell))
	{
		fireball->cast();
		usedFireball = true;
		fireball->PrintDescription(fireball->name, spell);
	}
	else if (spark->compare(spark->name, spell))
	{
		spark->cast();
		spark->PrintDescription(spark->name, spell);
	}
}
// Set player postion
void Player::Setposisiton(Vector2 pos)
{
	if (position != nullptr)
	{
		*position = pos;
	}
}
// Gets player position
Vector2 Player::Getposition()
{
	if (position != nullptr)
	{
		return *position;
	}
	return { 0, 0 };
}
// hurts the player
void Player::TakeDamage(int damage)
{
	m_health -= damage;
}

int Player::GetHealth()
{
	return m_health;
}

int Player::GetDamage()
{
	return m_damage;
}

