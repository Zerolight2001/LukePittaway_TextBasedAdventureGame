#include "Cat.h"

Cat::Cat()
    : m_purring{ false },m_patCount{ 2 }, isCatDead{ false }
{
    m_description = "A chubby cat aproches you as you enter the room. it sits at you feet and looks up at you with big eyes.\n";
}

const void Cat::Description()
{ 
    if (!isCatDead)
    {
       std::cout << M_BLUE << m_description << M_RESET_COLOR; 
    }
    else if (isCatDead)
    {
        std::cout << M_BLUE << "All he watnted was a pat...\n" << M_RESET_COLOR;
    }
}

void Cat::Use()
{    
    if ( m_patCount > 0)
    {
        m_purring = true;
        m_patCount--;
        m_description = "You pat the cat. It rolls over and starts agressivly purring.\n";
    }
    else
    {
        m_purring = false;
        m_patCount = 2;
        m_description = "You've pat the cat to much and he scatches your arm\n";
    }
}
