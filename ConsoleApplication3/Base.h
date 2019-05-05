#pragma once
#include "Pair.h"
class Base
{
	Pair* pBase;
	size_t count;
	size_t capacity;
public:
	Base();
	Base(size_t p_capacity);
	~Base();
	Base(const Base& bd);
	Base& operator=(const Base& bd); //оптимизированный!!!
	Base(Base&& bd);
	Base& operator=(Base&& bd);
	MyData& operator[](const char * key);
	int deletePair(const char* key);
	friend ostream& operator<<(ostream& os, const Base &bd);
	bool operator== (const Base & other) const;
	
};

