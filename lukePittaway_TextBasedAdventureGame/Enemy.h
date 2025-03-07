#pragma once
#include <string>

using std::string;

class Enemy
{
public:
	string name;

public:
	Enemy(string name, int health, int damage);

	void TakeDamage(int damage);
	void GainHealth(int health);
	int GetHealth();
	int Getdamage();
	
private:
	int m_damage;
	int m_health;
	
};

