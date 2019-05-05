#pragma once

enum DIGITS{ FIRST,SECOND, THIRD, FOURTH, FIFTH, SIXTH, SEVENTH,EIGHTH };

class Bin
{
	bool b0 : 1;
	bool b1 : 1;
	bool b2 : 1;
	bool b3 : 1;
	bool b4 : 1;
	bool b5 : 1;
	bool b6 : 1;
	bool b7 : 1;

public:

	void ShowBin() const;
	void ShowDigit(DIGITS digit) const;
	void SetDigit(DIGITS digit, bool dig);
};

