#include "Lamp.h"

Lamp::Lamp()
    : m_turnedOn{ false }
{
}

const void Lamp::Description()
{
    std::cout << "The room is pitch black but you can faintly see the outline of a lamp\n";
    return void();
}

void Lamp::Use()
{
    m_turnedOn = true;
    if (m_turnedOn)
    {
        std::cout << "The lamp has turned on. You can now see the empty room around you.\n";
    }

}
