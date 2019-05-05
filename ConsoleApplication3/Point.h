#pragma once
class Point
{
	int m_x,m_y;
public:
	explicit Point(int x = 0, int y = 0);

	~Point() = default;
	Point(const Point&) = default;
	Point(Point&&) = default;
	Point& operator=(const Point&) = default;

	int Get_x() const;
	int Get_y() const;
	void Set_x(int x);
	void Set_y(int y);

	Point& operator+= (const Point& other_p);
	Point operator+ (const Point& other) const;
	Point operator+ (int x) const;
	Point operator- () const;
	Point operator+ () const;
};

Point& operator+= (Point& point, int x);
Point operator- (const Point& point, int x);
Point operator- (const Point& one, const Point& another);
Point operator+ (int x, const Point& point);
