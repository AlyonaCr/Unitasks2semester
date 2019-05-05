#pragma once
#include <iostream>
#include "myString4.h"

enum COLOR {RED, GREEN, BLUE};
using namespace std;

class Shape {
protected:
	COLOR m_color;
	MyString m_author;

public:
	Shape(COLOR color, const char* author);
	Shape();
	virtual ~Shape() = default;

	Shape(const Shape& other);
	Shape(Shape&& other);

	void SetColor(COLOR color);
	void SetAuthor(const char* author);
	COLOR GetColor() const;
	const char * GetAuthor() const;

	virtual double GetSquare() const = 0;
	virtual double GetXSide() const = 0;
	virtual double GetYSide() const = 0;
	virtual Shape* Clone() const = 0;

	virtual bool operator== (const Shape& other) const;

	virtual Shape& operator= (const Shape& other);
	virtual Shape& operator= (Shape&& other);

	friend ostream& operator<<(ostream& os, const Shape& shape);
};


