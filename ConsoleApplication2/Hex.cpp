#include "Hex.h"
#include <iostream>


void Hex::ShowHex() const
{
	static const char* s = "0123456789abcdef";
	std::cout << s[b1] << ' ' << s[b0] << std::endl;
}

void Hex::ShowNum(NIBBLE nib)const {
	static const char* s = "0123456789abcdef";

	if (nib == FN) {
		std::cout << s[b0] << ' ';
	}
	else {
		std::cout << s[b1] << std::endl;
	}
}

void Hex::SetNum(NIBBLE nib, int &value){
	if (value > 'F') {
		std::cout << "Wrong data" << std::endl;
		return;
	}
	if (nib == FN) {
		b0 = value;

	}
	else {
		b1 = value;
	}
}
