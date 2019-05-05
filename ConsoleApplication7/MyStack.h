#pragma once
template <typename T, size_t size = 50> class MyStack
{
	T st[size];
	size_t count = 0;
public:
	MyStack() = default;
	~MyStack() = default;

	T& operator[] (size_t i);
	const T& operator[] (size_t i) const;

	MyStack(const MyStack & other) = default;
	MyStack(MyStack && other) = default;

	MyStack& operator= (const MyStack & other) = default;
	//?
	MyStack& operator= (MyStack && other) = default;

	void push(const T& value);
	void pop();
	size_t GetCount() { return count; }
};


//template <typename T, size_t size> MyStack < T, size > ::MyStack() 
//{
//	for (size_t i = 0; i < size; i++) 
//	{
//		st[i] = T();
//	}
//	count = 0;
//}

template <typename T, size_t size> T& MyStack < T, size > :: operator[] (size_t i) {
	if (i >= 0 && i < count) {
		return st[i];
	}
	else {
		throw "Wrong index";
	}
}

template <typename T, size_t size> const T& MyStack < T, size > ::operator[] (size_t i) const {
	if (i >= 0 && i < count) {
		return st[i];
	}
	else {
		throw "Wrong index";
	}
}

template <typename T, size_t size> void MyStack < T, size > ::push(const T& value)
{
	if (count == size) throw "Stack overflow";

	this->st[count] = value;
	count++;
	
}

template <typename T, size_t size> void MyStack < T, size > ::pop()
{
	if(count== 0) throw "Stack is empty";
	count--;
}