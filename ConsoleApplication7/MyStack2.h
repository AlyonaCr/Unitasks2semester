#pragma once
template <typename T> class MyStack2
{

	class Node {
		T m_element;
		Node *pNext;

	public:
		
		Node() {
			pNext = nullptr;
		}
		Node(const T& element, Node* Next);
		~Node() = default;

		friend class MyStack2;
	};

	Node* Head;
	size_t m_size;

public:
	MyStack2();
	~MyStack2() = default;

	MyStack2(const MyStack2 & other);
	MyStack2(MyStack2 && other);

	MyStack2& operator= (const MyStack2 & other);
	MyStack2& operator= (MyStack2 && other);

	void push(const T& value);
	void pop();
	T& top();
	void Print();

};

template <typename T> MyStack2 < T>  ::Node::Node(const T& element, Node* Next) {
	this->m_element = element;
	this->pNext = Next;
}

//template <typename T> MyStack2 < T>  ::Node::~Node() {
//	Head = this->pNext;
//	delete this->element;
//}


template <typename T> MyStack2 < T> ::MyStack2() : m_size(0)
{
	this->Head = nullptr;
}


template <typename T> void MyStack2 < T> :: push(const T& element)
{
	Head = new Node (element, this->Head);
	m_size++;

}

template <typename T> void  MyStack2 < T> ::pop()
{
	if (m_size == 0) throw "Stack is empty";
	Node* tmp = Head->pNext;
	delete Head;
	Head = tmp;
	m_size--;
	
}

template <typename T> T& MyStack2 < T> :: top() {
	return Head->m_element;
}

template <typename T> void MyStack2 < T> ::Print()
{
	const Node* current = Head;
	while (current!= nullptr) {
		cout << current->m_element << endl;
		current = current->pNext;
	}
}

template <typename T> MyStack2<T>& MyStack2 < T> :: operator= (const MyStack2 & other)
{
	if (this!= &other) {
	
		Node* sourse = other.Head;
		Node* dest = this->Head;
		size_t n = dest->m_size < sourse->m_size ? dest->m_size : sourse->m_size;
		for (size_t i = 0; i < n; i++) {
			try {
				*dest->m_element = *sourse->m_element;
			}
			catch (std::bad_cast) {

				delete dest->m_element;
				*dest->m_element = *sourse->m_element;
			}

			dest = dest->pNext;
			sourse = sourse->pNext;
		}
		
		while (dest!= nullptr) {
			delete dest->pNext;
			dest = dest->pNext;
		}

		while (m_size < other.m_size) {
			this->push(*sourse->m_element);
			sourse = sourse->pNext;
		}
	
	}
	
	return *this;
}

template <typename T> MyStack2<T>&MyStack2 < T> :: operator= (MyStack2 && other)
{
	Head.pNext = other.Head.pNext;
	other.Head = nullptr;
	m_size = other.m_size;
	other.m_size = 0;
}

template <typename T> MyStack2 < T> ::MyStack2(const MyStack2 & other)
{
	Node* m_sourse = other.Head->pNext;
	Head = new Node(other.Head->m_element, nullptr);
	Node* tmp = Head;
	m_size = 1;
	while (m_size < other.m_size) {
		tmp->pNext = new Node(m_sourse->Node::m_element, nullptr);
		m_size++;
		m_sourse = m_sourse->pNext;
	}
}

template <typename T> MyStack2 < T> ::MyStack2(MyStack2 && other)
{
	Head = other.Head;
	other.Head = nullptr;
	m_size = other.m_size;
	other.m_size = 0;
}