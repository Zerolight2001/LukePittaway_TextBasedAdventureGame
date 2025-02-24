#include "BoxOfDonuts.h"

BoxOfDonuts::BoxOfDonuts()
	: m_count{ 5 }
{
}

const void BoxOfDonuts::Description()
{
	std::cout << "A box of semi questionable donuts sit on a bench infront of you.\n";
	std::cout << "There are " << m_count << "donuts left\n";
	return void();
}

void BoxOfDonuts::Use()
{
	--m_count;
	std::cout << "You eat a donut. You feel as tho the walls are sightly judging you.\n";
	BoxOfDonuts::Description();
}
