#include "pch.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include "Circle.h"


Circle::Circle(int x, int y, double radius): center(x, y) {
	m_radius = radius;
}
Circle::Circle(const Point& p, double radius): center (p), m_radius(radius){}
bool Circle::operator==(const Circle& circle) {
	return ((this->center == circle.center) && (this->m_radius == circle.m_radius) );
}

double Circle::GetSquare() const {
	double square = (pow(m_radius, 2.0)* M_PI);
	return square;
}

ostream& operator<<(ostream& os, const Circle&circle)
{
	os << circle.center<< ", radius:" << circle.m_radius;
	return os;
}

