#include "Bin.h"
#include <iostream>



void Bin::ShowBin() const {
	std::cout << b7 << b6 << b5 << b4 << b3 << b2 << b1 << b0 << std::endl;
}

void Bin::ShowDigit(DIGITS digit) const {
	if (digit <= EIGHTH)
	{
		bool tmp[] = { b7, b6, b5, b4, b3, b2, b1, b0 };
		std::cout << tmp[digit] << std::endl;
	}
	else {
		std::cout << "Wrong data" << std::endl;
	}
	
}
void Bin::SetDigit(DIGITS digit, bool dig) {
	switch (digit)
	{
	case FIRST:
		b7 = dig;
		break;
	case SECOND:
		b6 = dig;
		break;
	case THIRD:
		b5 = dig;
		break;
	case FOURTH:
		b4 = dig;
		break;
	case FIFTH:
		b3 = dig;
		break;
	case SIXTH:
		b2 = dig;
		break;
	case SEVENTH:
		b1 = dig;
		break;
	case EIGHTH:
		b0 = dig;
		break;
	}
}