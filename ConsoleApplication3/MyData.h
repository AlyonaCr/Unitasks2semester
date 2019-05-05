#pragma once
#include "myString2.h"

class MyData
{
public:
	enum Sex{UNDEF, MALE, FMALE};
private:
	Sex sex;
	size_t m_age;
	MyString m_job;
	float m_salary;
public:
	MyData() = default;
	MyData(const char* job, Sex s, size_t age, float sal);
	~MyData() = default;
	MyData(const MyData& d) = default;
	MyData& operator=(const MyData& d) = default;
	MyData(MyData&& d) = default;
	MyData& operator=(MyData&& d) = default;
	friend ostream& operator<<(ostream& os, const MyData& d);
};

