#pragma once
#include <iostream>

using namespace std;
class MyString
{
    char* m_pStr;	
public:
	MyString() {
		m_pStr = nullptr;
	}
	
	MyString(const char* m_pStr);
	~MyString();
	
	MyString(const MyString & other);
	MyString(MyString && other);

	
	MyString& operator= (const MyString & other);
	MyString& operator= (const char* str);
	MyString& operator= (MyString && other);

	bool operator== (const MyString & other) const;
	bool operator== (const char* other) const;
	friend ostream & operator<<(ostream & os, const MyString& str);

};

