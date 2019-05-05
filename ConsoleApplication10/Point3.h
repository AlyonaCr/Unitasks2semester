#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Point
{
private:
	double m_x, m_y;
public:
	Point(int x = 0, int y = 0);
	~Point() = default;

	Point(const Point& other) = default;
	Point(Point&& other) = default;

	Point& operator= (const Point& other) = default;
	Point& operator= (Point&& other);

	bool operator==(const Point& point) const;
	bool operator<(const Point& point)const ;

	Point& operator+= (const Point& other);

	void setX(double x);
	void setY(double y);

	double getX() const;
	double getY() const;

	friend ostream& operator<<(ostream& os, const Point & point);
	friend ostream& operator<<(ostream& os, const Point * point);

};

