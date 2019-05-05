#include "pch.h"
#include "MyString.h"


MyString::MyString(const char* s) {
	m_pMyCounter = Counter::Search(s);
}

MyString::MyString()
{
	m_pMyCounter = nullptr;
}

MyString::MyString(const MyString & other)
{
	m_pMyCounter = other.m_pMyCounter;
	if(other.m_pMyCounter) m_pMyCounter->AddUser();
	
}

MyString::MyString(MyString && other) {

	m_pMyCounter = other.m_pMyCounter;
	other.m_pMyCounter = nullptr;
}

MyString& MyString::operator= (const MyString & other)
{
	if (m_pMyCounter != other.m_pMyCounter) {
		if (this->m_pMyCounter) this->m_pMyCounter->RemoveUser();
		if (other.m_pMyCounter) other.m_pMyCounter->AddUser();
		m_pMyCounter = other.m_pMyCounter;
	}
	return *this;
}

MyString& MyString::operator= (MyString && other)
{
	if (m_pMyCounter != other.m_pMyCounter) {
		if (this->m_pMyCounter) this->m_pMyCounter->RemoveUser();
		if (other.m_pMyCounter) other.m_pMyCounter = nullptr;
		m_pMyCounter = other.m_pMyCounter;

	}
	return *this;
}

MyString::~MyString()
{
	if (this->m_pMyCounter) m_pMyCounter->RemoveUser();
}

void MyString::PrintAll()
{
	Counter::PrintAll();
}

void MyString::ToUpper()
{
	Counter::ToUpper();
}

void MyString::ToLower()
{
	Counter::ToLower();
}

void MyString::SortByAlph()
{
	Counter::SortByAlph();
}