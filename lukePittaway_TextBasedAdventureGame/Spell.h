#pragma once
#include <string>

using std::string;

class Spell
{
public:
	string name;
	int damage;

public:
	Spell(string name, int damage);
	void cast();
	static bool compare(string spell1, string spell2);

};

