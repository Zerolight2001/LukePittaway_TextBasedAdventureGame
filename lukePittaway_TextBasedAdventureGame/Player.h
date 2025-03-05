#pragma once
#include <string>
#include <vector>

using std::vector;

#include "Spell.h"
#include "Vector2.h"


using std::string;

class Player
{
public:
	Vector2* m_position;

public:
	Player();
	~Player();

	
public:
	bool FindSpell(string spell);
	void Setposisiton(Vector2 position);
	Vector2 Getposition();

private:
	vector<string> m_spells;
	

};

