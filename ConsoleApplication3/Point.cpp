#include "Point.h"


Point::Point(int x, int y) 
{
	m_x = x;
	m_y = y;
}

int Point::Get_x() const 
{
	return m_x;
}

int Point::Get_y() const 
{
	return m_y;
}

void Point::Set_x(int x) 
{
	m_x = x;
}

void Point::Set_y(int y) 
{
	m_y = y;
}

Point& Point::operator+= (const Point& other_p)
{
	m_x += other_p.m_x;
	m_y += other_p.m_y;
	return *this;
}

Point Point::operator+ (const Point& other_p) const
{
	Point tmp((m_x + other_p.m_x), (m_y + other_p.m_y));
	return tmp;
}
Point Point::operator+ (int x) const 
{
	Point tmp(this->m_x + x, this->m_y + x);
	return tmp;

}

Point Point::operator- () const
{
	Point tmp(- m_x, - m_y);
	return tmp;
}

Point Point::operator+ () const
{
	return *this;
}

Point& operator+= (Point& point, int x)
{
	point.Set_x(point.Get_x() + x);
	point.Set_y(point.Get_y() + x);
	return point;
}

Point operator+ (int x, const Point& point) 
{
	Point tmp((point.Get_x() + x), (point.Get_y() + x));
	return tmp;
}


Point operator- (const Point& point, int x) 
{
	Point tmp((point.Get_x() - x), (point.Get_y() - x));
	return tmp;
}

Point operator- (const Point& one, const Point& another) 
{
	Point tmp((one.Get_x() - another.Get_x()), (one.Get_y() - another.Get_y()));
	return tmp;
}
