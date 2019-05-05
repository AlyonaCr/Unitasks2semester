#pragma once
#include <iostream>
#include <fstream>
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"

enum SORTMENU {MCOLOR, SQUARE, CENTER};
using namespace std;
class List
{

	class Node {
	public:
		Shape* m_shape;
		Node *pPrev, *pNext;
		Node() {
			pPrev = pNext = nullptr;
		}
		Node(Node*, Node*, Shape *);
		~Node();
		friend class List;
	};

	Node Head, Tail;
	size_t m_size;

public:
	List();
	void AddToHead(const Shape & shape);
	void AddToTail(const Shape & shape);

	bool RemoveFirst(const Shape & shape);
	int RemoveAll(const Shape & shape);

	void MakeEmpty();

	~List();
	List(const List& list);
	List(List&& list);
	List& operator=(const List&list);

	void Sort(SORTMENU option);
	friend ostream& operator<<(ostream& os, const List&list);

	size_t GetSize() const;
	Node* GetHead();
	Node* GetTail();

	void SaveInFile(const char* fileName);
	void ReadFromFile(const char* fileName);



};
