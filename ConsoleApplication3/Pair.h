#pragma once
#include "myString2.h"
#include "MyData.h"
class Pair
{
	MyString key;
	MyData data;
public:
	Pair() = default;
	Pair(const char *k, const MyData& d);
	~Pair() = default;
	Pair(const Pair& other) = default;
	Pair& operator=(const Pair& other);
	Pair(Pair&& other) = default;
	Pair& operator=(Pair&& other) = default;
	bool operator == (const Pair& other) const;
	friend class Base;
	friend ostream& operator<<(ostream& os, const Pair& pair);
};

