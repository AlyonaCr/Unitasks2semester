#include "myString.h"
#include <cstring>
#include <cstdarg>




MyString::MyString(const char* m_pStr) {
	this->m_pStr = new char[strlen(m_pStr) + 1];
	memcpy(this->m_pStr, m_pStr, (strlen(m_pStr) + 1) * sizeof(char));
}

MyString::~MyString() {
	delete[] m_pStr;
}

const char* MyString::GetString() const{
	if (m_pStr == nullptr) {
		return "The string is empty!";
	}
	else {
		return m_pStr;
	}
}

MyString::MyString(const MyString & other) {
	if (other.m_pStr != nullptr) {
		this->m_pStr = new char[strlen(other.m_pStr) + 1];
		memcpy(this->m_pStr, other.m_pStr, (strlen(other.m_pStr) + 1) * sizeof(char));
	}
}

void MyString::SetNewString(const char* p_nStr) {
	int old_cap = strlen(m_pStr) + 1;
	int new_cap = strlen(p_nStr) + 1;
	if (old_cap <new_cap) 
	
	{
		delete[] this->m_pStr;
		this->m_pStr = new char[new_cap];
		
	}
	memcpy(m_pStr, p_nStr, new_cap * sizeof(char));
}


// "ручной" конкатенатор
MyString MyStrConcat2(const char* first, ...) {
	const char ** p = &first;
	// счетчик элементов для итоговой строки
	int elem = 0;
	int count = 0;
	while (*p != nullptr) {
		elem += strlen(*p);
		count++;
		p++;
	}
	//возращаем указатель на первый параметр
	p = &first;
	char * p_concat = new char[elem + 1];
	// счетчик для итогового массива
	int copied = 0;
	
	for (int i = 0; i < count; i++) {
		int cap = strlen(p[i]);
		for (int j = 0; j < cap; j++) {
			p_concat[copied] = p[i][j];
			copied++;
		}
	}
	//терминирующий ноль
	p_concat[copied] = '\0';
	MyString str (p_concat);
	return str;
}

MyString MyStrConcat(const char* first, ...) {
	const char *p_i = first;
	// количество символов
	int elem = 0;

	va_list p;
	va_start(p, first);

	// считаем количество символов
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
