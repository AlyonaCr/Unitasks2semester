#include "pch.h"
#include "Point1.h"


Point::Point(int x, int y)
{
	m_x = x;
	m_y = y;
}

bool Point::operator==(const Point& point) {
	return ((m_x == point.m_x) && (m_y == point.m_y) ? 1 : 0);
}

ostream& operator<<(ostream& os, const Point & point)
{
	os << "Center: (" << point.m_x << ", " << point.m_y << ")";
	return os;
}
ostream& operator<<(ostream& os, const Point * point)
{
	os << "Center: (" << point->m_x << ", " << point->m_y << ")";
	return os;
}

Point& Point::operator= (Point&& other) {
	m_x = other.m_x;
	m_y = other.m_y;
	other.m_x = 0;
	other.m_y = 0;
	return *this;
}
bool Point::operator<(const Point& point) {
	return (m_x + m_y < point.m_x + point.m_y);
}


