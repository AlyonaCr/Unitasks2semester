#pragma once
class MyString
{
    char* m_pStr;	//строка-член класса
public:
	MyString() {
		m_pStr = nullptr;
	}
	
	MyString(const char* m_pStr);
	~MyString();
	// геттер
	const char* GetString() const;
	// копирование
	MyString(const MyString & other);
	// сеттер
	void SetNewString(const char* p_nStr);

};

MyString MyStrConcat(const char* first, ...);
MyString MyStrConcat2(const char* first, ...);