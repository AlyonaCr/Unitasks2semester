#include "pch.h"
#include "Counter.h"
#include <cstring>
#include <iostream>


Counter* Counter::Head = nullptr;
size_t Counter::m_curCounters = 0;


Counter::Counter(const char* str)
:m_nOwners(1) 
{
	m_pStr = new char[strlen(str) + 1];
	strcpy_s(m_pStr, (strlen(str) + 1) * sizeof(char), str);
	
	this->pNext = Head;
	Head = this;

	m_curCounters++;
}


Counter::~Counter()
{	
	if (this == Head) {
		Head = this->pNext;
	}
	else {
		Counter* pPrev = Head;
		while (pPrev->pNext != this) {
			pPrev = pPrev->pNext;
		}
		pPrev->pNext = this->pNext;
	}

	delete[] m_pStr;
}

void Counter::AddUser()
{
	m_nOwners++;
}
void Counter::RemoveUser()
{
	m_nOwners--;
	if (!m_nOwners) {
		delete this;
	}
}

void Counter::PrintAll()
{
	Counter* current = Head;
	for (size_t i = 0; i< m_curCounters; i++){
		std::cout << current->m_pStr <<" owners: "<< current->m_nOwners<< std::endl;
		current = current->pNext;
	}
	
	std::cout << "references: " << m_curCounters << std::endl;

}

void Counter::ToUpper()
{
	Counter* current = Head;
	for (size_t i = 0; i < m_curCounters; i++) {
		size_t n = strlen(current->m_pStr);
		for (size_t i = 0; i < n; i++) {
			current->m_pStr[i] = toupper(current->m_pStr[i]);
		}
		current = current->pNext;
	}
}

void Counter::ToLower()
{
	Counter* current = Head;
	for (size_t i = 0; i < m_curCounters; i++){
		size_t n = strlen(current->m_pStr);
		for (size_t i = 0; i < n; i++) {
			current->m_pStr[i] = tolower(current->m_pStr[i]);
		}
		current = current->pNext;
	}
}

void  Counter::SortByAlph()
{
	Counter* tmp = nullptr;
	Counter* current = Head;
	Counter* max = current;

	size_t tmp_size = m_curCounters;

	while(Head){

		max = current = Head;
		for( size_t i = 0; i < tmp_size; i++) {
			if (strcmp(current->m_pStr, max->m_pStr) > 0) {
				max = current;
			}
			current = current->pNext;
			
		}

		if (max == Head) {
			Head = max->pNext;
		}
		else {
			Counter* pPrev = Head;
			while (pPrev->pNext != max) {
				pPrev = pPrev->pNext;
			}
			pPrev->pNext = max->pNext;
		}
		
		max->pNext = tmp;
		tmp = max;
		tmp_size--;
	}

	Head = max;
	
}

Counter* Counter::Search(const char* s)
{
	if (Counter::m_curCounters != 0) {
		Counter* current = Head;
		while (current->pNext != nullptr) {
			if (strcmp(current->m_pStr, s) == 0) return current;
			current = current->pNext;
		}
	}
	return new Counter(s);
}

