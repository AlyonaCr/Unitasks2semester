#pragma once
#include <iostream>

using namespace std;
class MyString
{
    char* m_pStr;	//строка-член класса
public:
	MyString() {
		m_pStr = nullptr;
	}
	
	explicit MyString(const char* m_pStr);
	~MyString();
	const char* GetString() const;
	MyString(const MyString & other);
	MyString(MyString && other);
	void SetNewString(const char* p_nStr);

	
	MyString& operator= (const MyString & other);
	MyString& operator= (const char* str);
	MyString& operator= (MyString && other);

	bool operator== (const MyString & other) const;
	bool operator== (const char* other) const;
	friend ostream & operator<<(ostream & os, const MyString& str);
	MyString& operator+= (const MyString& other);
	MyString operator+ (const MyString& other) const ;
	MyString operator+ (const char* str) const;
 
};

MyString MyStrConcat(const char* first, ...);

ostream & operator<<(ostream & os, const MyString& str);