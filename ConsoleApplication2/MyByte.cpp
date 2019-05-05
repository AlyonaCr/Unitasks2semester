#include "MyByte.h"
#include <iostream>

void f(MyByte* p, WHAT what)
{
	switch (what)
	{
	case HEX:
		p->h.ShowHex();
		break;
	case BIN:
		p->b.ShowBin();
		break;
	case OCT:
		p->o.ShowOct();
		break;
	case CHAR:
		std::cout << p->c << '\n';
	}
}

