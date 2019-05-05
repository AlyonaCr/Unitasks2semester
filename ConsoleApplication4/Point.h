#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Point
{
	int m_x, m_y;
public:
	Point(int x = 0, int y = 0);
	~Point() = default;
	bool operator==(const Point& point);
	friend ostream& operator<<(ostream& os, const Point & point);

};

