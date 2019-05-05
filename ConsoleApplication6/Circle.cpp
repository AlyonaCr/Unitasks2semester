#define _USE_MATH_DEFINES
#include "Circle.h"
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

Circle::Circle(COLOR color, const char* author, double radius, double x, double y) :
	Shape(color, author)
{
	m_radius = radius;
	m_x = x;
	m_y = y;
}


double Circle::GetSquare() const {
	return (pow(m_radius, 2.0)* M_PI);
}

bool Circle::operator== (const Shape& other)const
{
	const Circle* tmp = dynamic_cast<const Circle*>(&other);
	return (Shape::operator==(other)&&(m_radius == tmp->m_radius) && (m_x == tmp->m_x) && (m_y == tmp->m_y));
}

double Circle::GetXSide() const
{
	return this->m_x;
}

double Circle::GetYSide() const
{
	return this->m_y;
}

ostream& operator<<(ostream& os, const Circle& circle) 
{
	os << "Shape: circle" << static_cast<const Shape&>(circle) << " x: " << circle.GetXSide() << " y: " << circle.GetYSide() << " Radius: "<<circle.m_radius << " Square: " << circle.GetSquare() << '\n';
	return os;
}

Shape* Circle::Clone() const
{
	return new Circle(*this);
}


Shape& Circle::operator= (const Shape& other)
{
	const Circle& tmp = dynamic_cast<const Circle&>(other);
	*this = tmp;
	return *this;
}