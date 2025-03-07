#pragma once
#include <string>
#include <vector>
#include "Spell.h"
using std::vector;


#include "Vector2.h"

class Spell;

using std::string;

class Player
{
public:
	Vector2* position;
	Spell* fireball;
	Spell* spark;
	bool usedFireball;

public:
	Player();
	~Player();

	
public:
	// Spell related function
	bool FindSpell(string spell);
	void UseSpell(string spell);
	// Position related functions
	void Setposisiton(Vector2 position);
	Vector2 Getposition();

	// Combat related functions
	void TakeDamage(int damage);
	int GetHealth();
	int GetDamage();
		
private:
	vector<string> m_spells;
	int m_health;
	int m_damage;
	
};

