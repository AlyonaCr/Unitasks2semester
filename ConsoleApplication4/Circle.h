#pragma once
#include "Point.h"
#include <iostream>

using namespace std;
class Circle
{
	Point center;
	double m_radius;


public:
	Circle() = default;
	Circle(int x, int y, double radius = 0);
	Circle(const Point&, double radius = 0);
	~Circle() = default;
	double GetSquare() const;
	bool operator==(const Circle& circle);
	friend ostream& operator<<(ostream& os, const Circle&circle);

};

