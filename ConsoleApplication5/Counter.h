#pragma once
class Counter
{
	Counter* pNext;
	char* m_pStr;
	size_t m_nOwners;
	static Counter* Head;
	static size_t m_curCounters;

	Counter(const char*);
	~Counter();
	void AddUser();
	void RemoveUser();
	static void PrintAll();
	static void ToUpper();
	static void ToLower();
	static void SortByAlph();
	static Counter* Search(const char*);

	void Evoke(Counter* pPrev);
	void Insert(Counter* pPrev);
	friend class MyString;
};

