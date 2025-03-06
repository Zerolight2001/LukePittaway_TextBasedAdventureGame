#include "BoxOfDonuts.h"

BoxOfDonuts::BoxOfDonuts()
	: m_count{ 3 }, m_isThereDonuts{ true }
{
	m_description = "A box of semi questionable donuts sit on a bench infront of you.\n";
}

const void BoxOfDonuts::Description()
{
	std::cout << m_description;
	std::cout << "There are " << m_count << " donuts left\n";	
}

void BoxOfDonuts::Use()
{
	if (m_count <= 0)
	{
		std::cout << "you ate them all... the walls are harshly judging you\n\n";
	}
	else
	{
		--m_count;
		std::cout << "You eat a donut. You feel the walls are sightly judging you.\n\n";
	}
	
	
}
