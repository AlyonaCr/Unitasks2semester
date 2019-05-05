#include "Oct.h"
#include <iostream>

void Oct::ShowOct() const 
{
	std::cout << static_cast<int> (b2) << static_cast<int> (b1) << static_cast<int> (b0) << std::endl;
}

void Oct::ShowOct(NUMBER num) const
{
	switch (num)
	{
	case SIN:
		std::cout << static_cast<int> (b2) << std::endl;
		break;
	case MID:
		std::cout << static_cast<int> (b1) << std::endl;
		break;
	case JR:
		std::cout << static_cast<int> (b0) << std::endl;
		break;
	}
}
void Oct::SetNum(NUMBER num, int & value) {
	switch (num)
	{
	case SIN:
		b2 = value;
		break;
	case MID:
		b1 = value;
		break;
	case JR:
		b0 = value;
		break;
	}
}