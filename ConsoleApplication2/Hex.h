#pragma once


enum NIBBLE{FN, SN};

class Hex
{
	unsigned char  b0 : 4;
	unsigned char  b1 : 4;


public:

	void ShowHex() const;
	void ShowNum(NIBBLE nib)const;
	void SetNum(NIBBLE nib, int & value);

};

