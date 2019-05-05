

#include "pch.h"
#include <iostream>
#include "MyString.h"
#include "Counter.h"

int main()
{
	MyString str1("FFF");
	MyString str2("AAA");
	MyString str3("LLL");
	MyString str4("CCC");
	MyString::PrintAll();
	MyString::SortByAlph();
	MyString::PrintAll();
	//MyString::ToLower();
	//MyString::PrintAll();

	MyString s1 = str4;
	MyString s2 = str2;
	MyString::PrintAll();
	s2 = str1;
	MyString s3 = std::move(s2);
	MyString::PrintAll();
	MyString str5("CCC");

}


