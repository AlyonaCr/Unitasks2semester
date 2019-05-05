#include "List.h"


List::Node::Node(Node* p, Node* n, const Circle & circle): m_circle(circle)
{
	this->pPrev = p;
	this->pNext = n;
	if (n != 0) n->pPrev = this;
	if (p != 0) p->pNext = this;

}

List::Node::~Node() 
{
	if (pNext) {
		pNext->pPrev = this->pPrev;
	}
	if (pPrev) {
		pPrev->pNext = pNext;
	}
}

List::List() : m_size(0) 
{
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
}

void List::AddToHead(const Circle&circle) 
{
	new Node(&Head, Head.pNext, circle);
	m_size++;
}

void List::AddToTail(const Circle&circle)
{
	new Node(Tail.pPrev, &Tail, circle);
	m_size++;
}

bool List::RemoveFirst(const Circle & circle) 
{
	Node* current = Head.pNext;

	while (current!= &Tail) {
		if (current->m_circle == circle) {
			delete current;
			m_size--;
			return true;
		}
		current = current->pNext;
	}
	return false;
}

//int List::RemoveAll(const Circle & circle)
//{
//	Node* current = Head.pNext;
//	int counter = 0;
//	while (current != &Tail) {
//		current = current->pNext;
//		if (current->pPrev->m_circle == circle) {
//			delete current->pPrev;
//			m_size--;
//			counter++;
//		}
//		
//	}
//
//	return counter;
//}
int List::RemoveAll(const Circle & circle)
{
	Node* current = Head.pNext;
	int counter = 0;
	while (current != &Tail) {
		Node* n = current->pNext;
		
		if (current->m_circle == circle) {
			delete current;
			m_size--;
			counter++;
		}
		current = n;

	}

	return counter;
}
List::~List()
{
	while (Head.pNext != &Tail) {
		delete Head.pNext;
	}
}

List::List(const List& list) 
{
	const Node* current = list.Head.pNext;
	for (size_t i = 0; i < list.m_size; i++) {
		AddToTail(current->m_circle);
		current = current->pNext;
	}
}

List::List(List&& list)
{
	//если пустой и nullptr
	Head.pNext = list.Head.pNext;
	Tail.pPrev = list.Tail.pPrev;

	Head.pNext->pPrev = &this->Head;
	Tail.pPrev->pNext = &this->Tail;

	list.Head.pNext = &list.Tail;
	list.Tail.pPrev = &list.Head;

	m_size = list.m_size;
	list.m_size = 0;
}

void List::MakeEmpty()
{
	const Node* current = Head.pNext;
	while (current->pNext != &Tail) {
		delete current;
	}

}

List& List::operator=(const List&list)
{
	if (this != &list) {
		const Node* sourse = list.Head.pNext;
		Node* dest = this->Head.pNext;

		for (size_t i = 0; i < this->m_size; i++) {
			dest->m_circle.operator=(sourse->m_circle);
			dest = dest->pNext;
			sourse = sourse->pNext;
		}

		if ((m_size < list.m_size) || (m_size > list.m_size)) {
			for (size_t i = 0; i < list.m_size; i++) {
				if (this->m_size < list.m_size) {
					AddToTail(sourse->m_circle);
				}
				else if (this->m_size > list.m_size) {
					delete dest;
				}

				dest = dest->pNext;
				sourse = sourse->pNext;
			}
		}
	}
	return *this;
}

size_t List::GetSize(const Node* first, const Node* last) const 
{
	size_t size = 1;
	const Node* pFirst = first;
	while(pFirst!= last) {
		size++;
		pFirst = pFirst->pNext;
	}
	return size;
}


void List::QuickSort(Node* left, Node* right, size_t size)
{
	if (size < 2) return;

	Node* middle = left;
	Node*pLeft = left;
	Node*pRight = right;

	size_t mid = (size % 2 == 0) ? size / 2 : (size / 2) + 1;

	for (size_t i = 1; i < mid; i++) {
		middle = middle->pNext;
	}

	do {
		while ((pLeft->m_circle.GetSquare() < middle->m_circle.GetSquare()) && (pLeft != middle)) { pLeft = pLeft->pNext; }
		while ((middle->m_circle.GetSquare() < pRight->m_circle.GetSquare()) && (pRight != middle)) { pRight = pRight->pPrev; }
		if (pLeft != pRight) {

				Node* tmpL = pLeft; 
				Node* tmpR = pRight;
				pLeft->SwapNodes(*pRight);
				if (pRight == middle) {
					pLeft = pRight->pNext;
					pRight = middle = tmpL;
			
				}
				else if (pLeft == middle) {
					pRight = pLeft->pPrev;
					pLeft = middle = tmpR;
				}
				else {
					pLeft = pRight->pNext;
					pRight = tmpL->pPrev;
				}
			}

		} while (pLeft!= pRight);

		if (pLeft->pNext!= right) { this->QuickSort(pLeft, right, this->GetSize(pLeft, right)); }
		if (pRight->pPrev!= left) { this->QuickSort(left, pRight, this->GetSize(left, pRight)); }

	}



ostream& operator<<(ostream& os, const List&list)
{
	const List::Node* current = list.Head.pNext;
	while (current->pNext != nullptr) {
		os << current->m_circle << '\n';
		current = current->pNext;
	}
	return os;
}

void List::Node::SwapNodes(Node& node)
{
	Node* this_prev = this->pPrev;
	Node* node_next = node.pNext;


	if (this->pNext == &node) {
	this->pPrev = &node;
	node.pNext = this;
	}
	else if (this->pPrev == &node) {
	node.pPrev = this;
	this->pNext = &node;

	}
	else {
	node.pNext = this->pNext;
	node.pNext->pPrev = &node;
	this->pPrev = node.pPrev;
	this->pPrev->pNext = this;
	}

	node.pPrev = this_prev;
	node.pPrev->pNext = &node;
	this->pNext = node_next;
	this->pNext->pPrev = this;


}

size_t List::GetSize() const 
{
	return this->m_size;
}

void List::SaveInFile(const char* fileName)
{
	if (strlen(fileName)<= 30) {
		ofstream fout(fileName);
		fout << *this;
		fout.close();
	}
	else {
		cout << "Name of file is too big. It can't be more than 30 symbols" << endl;
	}

}

void List::ReadFromFile(const char* fileName)
{
	ifstream os(fileName);
	if (!os) { cout << "Failed!" << endl; }

	while (!os.eof()) {
			os.ignore(9, '(');
			int x, y; double r;
			os >> x;
			os.ignore(2, ' ');
			os >> y;
			os.ignore(11, ':');
			os >> r;
			AddToTail(Circle(x, y, r));
			os.ignore(1, '\n');
			if (os.eof()) break;
	}
	os.close();
	
}

List::Node* List::GetHead()
{
	return &this->Head;
}

List::Node* List::GetTail()
{
	return &this->Tail;
}