#pragma once
#include "Shape.h"
#include <iostream>

using namespace std;
class Circle : public Shape {
	double m_radius;
	double m_x;
	double m_y;

public:

	Circle(COLOR color = BLUE, const char* author = "I", double radius = 2.7, double x = 0, double y = 0);
	~Circle() = default;

	Circle(const Circle & circle) = default;
	Circle(Circle && circle) = default;
	virtual Shape* Clone() const;

	virtual bool operator== (const Shape& other) const;
	virtual Shape& operator= (const Shape& other);
	Circle& operator=(const Circle & ) = default;
	
	virtual double GetXSide() const;
	virtual double GetYSide() const;
	double GetSquare() const;
	
	friend ostream& operator<<(ostream& os, const Circle& circle);
}; 