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
	bool FindSpell(string spell);
	void UseSpell(string spell);
	void Setposisiton(Vector2 position);
	Vector2 Getposition();

private:
	vector<string> m_spells;

	
};

