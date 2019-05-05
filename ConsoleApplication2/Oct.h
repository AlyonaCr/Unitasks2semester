#pragma once
enum NUMBER { JR, MID, SIN };
class Oct
{
	unsigned char  b0 : 3;
	unsigned char  b1 : 3;
	unsigned char  b2 : 2;
	

public:

	void ShowOct() const;
	void ShowOct(NUMBER num) const;
	void SetNum(NUMBER num, int & value);
};

