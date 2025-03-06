#pragma once
#include <string>

using std::string;

class Spell
{
public:
	string name;
	int damage;
	string description;

public:
	Spell();
	Spell(string name, int damage);
	~Spell();
	void cast();
	static bool compare(string spell1, string spell2);
	void PrintDescription(string spell, string comaprison);

};

