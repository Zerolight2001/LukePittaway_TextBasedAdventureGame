#include "Cat.h"

Cat::Cat()
    : m_purring{ false }
{
}

const void Cat::Description()
{
    std::cout << "A chubby cat aproches you as you enter the room. it sits at you feet and looks up at you with big eyes.\n";
    return void();
}

void Cat::Use()
{
    m_purring = true;
    if (m_purring)
    {
        std::cout << "You pat the cat and they start agressivly purring.\n";
    }

}
