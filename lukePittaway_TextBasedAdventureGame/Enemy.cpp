#include "Enemy.h"
#include "player.h"

class Player;

Enemy::Enemy(string name, int health, int damage)
	:name{ name }, m_health{ health }, m_damage{ damage }
{

}

void Enemy::TakeDamage(int damage)
{
	m_health -= damage;
}

void Enemy::GainHealth(int health)
{
	m_health += health;
}

int Enemy::GetHealth()
{
	return m_health;
}

int Enemy::Getdamage()
{
	return m_damage;
}
