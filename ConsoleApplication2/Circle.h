#pragma once
#include "Shape.h"
#include "Rect.h"

class Circle : public Shape {
	double m_radius;
	double m_x;
	double m_y;

public:

	Circle(COLOR color = BLUE, const char* author = "I", double radius = 2.7, double x = 0, double y = 0);
	//Circle();
	~Circle();
	Circle(Rect&rect);
	void SetAll(COLOR color, const char* author, double radius, double x, double y);
	void GetAll(COLOR& color, char* author, double& radius, double& x, double& y) const;
	void SetRadius(const double& radius);
	void GetRadius(double& radius) const;
	void SetCenter(const double& x, const double& y);
	void GetCenter(double& x, double& y);
	void GetSquare(double & dest) const;
	void WhereAmI();
	void Inflate(int x);
};