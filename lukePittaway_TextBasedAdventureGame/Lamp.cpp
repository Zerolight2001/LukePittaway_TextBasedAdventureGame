#include "Lamp.h"

Lamp::Lamp()
    : m_turnedOn{ false }
{
}

const void Lamp::Description()
{
    std::cout << m_description;
    
}

void Lamp::Use()
{
    if (m_turnedOn == false) 
    {
        m_turnedOn = true;
        if (m_turnedOn)
        {
            m_description = "The lamp has turned on. You can now see the empty room around you.\n";
        }
    }
    else if (m_turnedOn == true)
    {
        m_turnedOn = false;
        if (m_turnedOn)
        {
            m_description = "The room is dark. You can't see sh**.\n";
        }
    }

}
