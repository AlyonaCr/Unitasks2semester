#include "List.h"


List::Node::Node(Node* p, Node* n, Shape * shape)
{
	this->m_shape = shape;
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

	delete this->m_shape;
}

List::List() : m_size(0)
{
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
}

void List::AddToHead(const Shape & shape)
{ 
	new Node(&Head, Head.pNext, shape.Clone());
	m_size++;
}

void List::AddToTail (const Shape & shape)
{
		new Node(Tail.pPrev, &Tail, shape.Clone());
		m_size++;
}

bool List::RemoveFirst (const Shape & shape)
{
	Node* current = Head.pNext;

	while (current != &Tail) {

		if (current->m_shape->operator==(shape)) {
			delete current;
			m_size--;
			return true;
		}

		current = current->pNext;
	}

		return false;
}

int List::RemoveAll (const Shape & shape)
{
	Node* current = Head.pNext;
	int counter = 0;
	while (current != &Tail) {

			Node* n = current->pNext;

			if (current->m_shape->operator==(shape)) {
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
		AddToTail(*current->m_shape);
		current = current->pNext;
	}
}

List::List(List&& list)
{
	
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
	while (current!= &Tail) {
		delete current;
		current = Head.pNext;
		m_size--;
	}

}

List& List::operator=(const List&list)
{
	if (this != &list) {

		const Node* sourse = list.Head.pNext;
		Node* dest = this->Head.pNext;
		size_t n = m_size < list.m_size ? m_size : list.m_size;

		for (size_t i = 0; i < n; i++) {
		
			try {
				*dest->m_shape = *sourse->m_shape;
			}
			catch (std::bad_cast) {

				delete dest->m_shape;
				dest->m_shape = sourse->m_shape->Clone();
			}

			dest = dest->pNext;
			sourse = sourse->pNext;
		}

		while (Tail.pPrev!= dest) {
			delete Tail.pPrev;
		}

		while (m_size <list.m_size){
			AddToTail(*sourse->m_shape);
			sourse = sourse->pNext;
			}
		}
	
	return *this;
}


void List::Sort(SORTMENU option)
{
	Node* tmp = nullptr;
	Node* current = Head.pNext;
	Node* max = current;
	size_t n = m_size;

	while (n) {

		max = current = Head.pNext;
		for (size_t i = 0; i < n; i++) {
			
				if ((option == MCOLOR)&&(current->m_shape->GetColor() > max->m_shape->GetColor())) {
					max = current;
				}
				else if ((option == SQUARE) && (current->m_shape->GetSquare() > max->m_shape->GetSquare())) {
					max = current;
				}
			
			current = current->pNext;

		}

		if (max->pNext) {
			max->pNext->pPrev = max->pPrev;
		}
		if (max->pPrev) {
			max->pPrev->pNext = max->pNext;
		}

		
		max->pNext = tmp;
		max->pPrev = nullptr;
		if(tmp) tmp->pPrev = max;
		tmp = max;
		n--;
	}

	Head.pNext = max;
	max->pPrev = &Head;
	
	current = Head.pNext;
	while (current->pNext != nullptr)
	{
		current = current->pNext;
	}
	current->pNext = &Tail;
	Tail.pPrev = current;

}



ostream& operator<<(ostream& os, const List&list)
{
	size_t counter = 1;
	const List::Node* current = list.Head.pNext;
	while (current->pNext != nullptr) {

		if (Rect * tmp = dynamic_cast<Rect*>(current->m_shape)) {
			
			os << counter << ") " << *tmp;
		}
		else if (Circle* tmp = dynamic_cast<Circle*>(current->m_shape)){

			os << counter << ") " << *tmp;
		}
		current = current->pNext;
		counter++;
	}
	return os;
}



size_t List::GetSize() const
{
	return this->m_size;
}

void List::SaveInFile(const char* fileName)
{
	if (strlen(fileName) <= 30) {
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
	char shape[10] = { 0 };
	char color[10] = { 0 };
	char author[10] = { 0 };

	while (!os.eof()) {

		os.ignore(20, ')');

		os.ignore(8, ':');
		os >> shape;
	
		os.ignore(9, ':');
		os >> author;
		
		os.ignore(8, ':');
		os >> color;
		size_t col = 0;
		if (strcmp(color, "Red")==0){
			col = 0;
		}
		else if ((strcmp(color, "Green") == 0)) {
			col = 1;
		}
		else {
			col = 2;
		}
		if (strcmp(shape, "circle") == 0) {
			os.ignore(4, ':');
			double x, y, r;
			os >> x;
			os.ignore(4, ':');
			os >> y;
			os.ignore(9, ':');
			os >> r;
			AddToTail(Circle(static_cast<COLOR>(col), author,r,x,y));
	
		}
		else {
			os.ignore(7, ':');
			double l, r, t, b;
			os >> l;
			os.ignore(8, ':');
			os >> r;
			os.ignore(6, ':');
			os >> t;
			os.ignore(10, ':');
			os >> b;
			AddToTail(Rect(static_cast<COLOR>(col), author, l,r,t,b));

		
		}
		//os.get();
		os.ignore(20, '\n');
	
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