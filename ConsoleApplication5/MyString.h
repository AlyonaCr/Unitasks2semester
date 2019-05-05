#pragma once
#include <iostream>
#include <fstream>
#include "Counter.h"

	class MyString {
		Counter* m_pMyCounter;

	public:
		MyString(const char* s);
		MyString();
		MyString(const MyString & other);
		MyString(MyString && other);
		MyString& operator= (const MyString & other);
		MyString& operator= (MyString && other);
		~MyString();
		static void PrintAll();
		static void ToUpper();
		static void ToLower();
		static void SortByAlph();

	};

