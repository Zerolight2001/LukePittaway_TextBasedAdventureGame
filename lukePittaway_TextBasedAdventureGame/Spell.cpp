#include "Spell.h"

Spell::Spell(string name, int damage)
    :name{ name }, damage{ damage }
{
}

void Spell::cast()
{

}

bool Spell::compare(string spell1, string spell2)
{
    return spell1 == spell2;
}
