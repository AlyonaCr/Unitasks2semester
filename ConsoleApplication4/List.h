#pragma once
#include "Circle.h"
#include <iostream>
#include <fstream>

using namespace std;
class List
{
	
	class Node {
	public:
		Circle m_circle;
		Node *pPrev, *pNext;
		Node() {
			pPrev = pNext = nullptr;
		}
		Node(Node*, Node*, const Circle &);
		~Node();
		void SwapNodes(Node& right);
		friend class List;
	};

	Node Head, Tail;
	size_t m_size;

public:
	List();
	void AddToHead(const Circle&circle);
	void AddToTail(const Circle&circle);

	bool RemoveFirst(const Circle & circle);
	int RemoveAll(const Circle & circle);

	void MakeEmpty();

	~List();
	List(const List& list);
	List(List&& list);
	List& operator=(const List&list);

	void QuickSort(Node* left, Node* right, size_t size);
	friend ostream& operator<<(ostream& os, const List&list);

	// для сортировки
	size_t GetSize(const Node* first, const Node* last) const;
	// геттер 
	size_t GetSize() const;
	Node* GetHead();
	Node* GetTail();

	void SaveInFile(const char* fileName);
	void ReadFromFile(const char* fileName);



};
