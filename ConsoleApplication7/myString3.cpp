#include "myString3.h"
#include <cstring>
#include <cstdarg>



MyString::MyString(const char* m_pStr) 
{
	this->m_pStr = new char[strlen(m_pStr) + 1];
	strcpy_s(this->m_pStr,(strlen(m_pStr) + 1) * sizeof(char), m_pStr);
}

MyString::~MyString() 
{
	delete[] m_pStr;
}


MyString::MyString(const MyString & other) 
{
	if (other.m_pStr != nullptr) {
		this->m_pStr = new char[strlen(other.m_pStr) + 1];
		strcpy_s(this->m_pStr, (strlen(other.m_pStr) + 1) * sizeof(char), other.m_pStr);
	}
	else {
		this->m_pStr = nullptr;
	}
}

MyString::MyString(MyString && other)
{
	m_pStr = other.m_pStr;
	other.m_pStr = nullptr;
}


MyString& MyString::operator= (const MyString & other) 
{
	if (this != &other) {
			delete[] m_pStr;
			if (other.m_pStr!= nullptr) {
				m_pStr = new char[strlen(other.m_pStr) + 1];
				strcpy_s(m_pStr, (strlen(other.m_pStr) + 1) * sizeof(char), other.m_pStr);
			}
			else {
				this->m_pStr = nullptr;
			}
	}
	return *this;
}

MyString& MyString::operator= (MyString && other) 
{
	if (this != &other) {
		delete[] m_pStr;
		m_pStr = other.m_pStr;
		other.m_pStr = nullptr;
	}
	return *this;
}


bool MyString::operator== (const MyString & other) const 
{
	return (strcmp(m_pStr, other.m_pStr) == 0);
}
bool MyString::operator== (const char* other) const
{
	return (strcmp(m_pStr, other) == 0);
}


ostream & operator<<(ostream & os, const MyString& str) 
{
	os << str.m_pStr;
	return os;
}


MyString& MyString::operator= (const char* str)
{
	delete [] this->m_pStr;
	this->m_pStr = new char[strlen(str) + 1];
	strcpy_s(this->m_pStr, (strlen(str)+1)*sizeof(char), str);
	return *this;

}
