#include "Spell.h"
#include <iostream>
#include <cstdlib>

Spell::Spell()
{
    name = "";
    damage = 0;
}

Spell::Spell(string name, int damage)
    :name{ name }, damage{ damage }
{
}

Spell::~Spell()
{
    name = "";
    damage = 0;
}

void Spell::cast()
{
    std::cout << "You cast " << name << "\n\n";
}

bool Spell::compare(string spell1, string spell2)
{
    return spell1 == spell2;
}

void Spell::PrintDescription(string spell1, string comaprison)
{    
    if (compare(spell1, comaprison) == true)
    {
        // Clear page
        std::system("cls");
        // Print descrpition
        std::cout << description;
    }
    else
    {
        std::cout << "Spell did nothing\n";
    }
}
