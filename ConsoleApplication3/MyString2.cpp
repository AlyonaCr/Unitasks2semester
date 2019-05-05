#include "myString2.h"
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

const char* MyString::GetString() const
{
	if (m_pStr == nullptr) {
		return "The string is empty!";
	}
	else {
		return m_pStr;
	}
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

void MyString::SetNewString(const char* p_nStr) 
{
		delete[] this->m_pStr;
		this->m_pStr = new char[strlen(p_nStr)+1];
		strcpy_s(m_pStr, (strlen(p_nStr) + 1) * sizeof(char), p_nStr);
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

MyString& MyString::operator+= (const MyString& other)
{
	if (this != nullptr) {
		*this = MyStrConcat(this->m_pStr, other.m_pStr, nullptr);
	}
	else {
		*this = other;
	}
	return *this;
}


MyString MyString::operator+ (const MyString& other) const 
{
	size_t new_str = strlen(this->m_pStr)+ strlen(other.m_pStr)+1;
	char* tmp =new char[new_str];
	strcpy_s(tmp, new_str * sizeof(char), this->m_pStr);
	for (size_t i = strlen(this->m_pStr)-1 , j = 0; i < new_str; i++, j++) {
		tmp[i] = other.m_pStr[j];
	}

	MyString str(tmp);
	delete[] tmp;
	return str;
}

MyString MyString::operator+ (const char* str) const 
{

	size_t new_str = strlen(this->m_pStr) + strlen(str) + 1;
	char* tmp = new char[new_str];
	strcpy_s(tmp, new_str * sizeof(char), this->m_pStr);
	for (size_t i = strlen(this->m_pStr)-1, j = 0; i < new_str; i++, j++) {
		tmp[i] = str[j];
	}

	MyString pstr(tmp);
	delete[] tmp;
	return pstr;
}

MyString& MyString::operator= (const char* str)
{
	delete [] this->m_pStr;
	this->m_pStr = new char[strlen(str) + 1];
	strcpy_s(this->m_pStr, (strlen(str)+1)*sizeof(char), str);
	return *this;

}


MyString MyStrConcat(const char* first, ...) {
	const char *p_i = first;
	int elem = 0;

	va_list p;
	va_start(p, first);


	while (p_i != nullptr) {
		elem += strlen(p_i);
		p_i = va_arg(p, char*);
	}

	p_i = first;
	va_start(p, first);
	char * p_concat = new char[elem + 1];
	int copied = 0;
	for (int i = 0; p_i != nullptr; i++) {
		int cap = strlen(p_i);
		for (int j = 0; j < cap; j++) {
			p_concat[copied] = p_i[j];
			copied++;
		}
		p_i = va_arg(p, char*);

	}

	p_concat[copied] = '\0';

	va_end(p);
	MyString str(p_concat);
	return str;
}