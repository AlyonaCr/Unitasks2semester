#pragma once
#include"Shape.h"
#include <iostream>
using namespace std;
class Rect : public Shape {
	double m_left, m_right, m_top, m_bottom;

	public:

		Rect(COLOR color, const char* author, double left, double right, double top, double bottom);
		Rect();
		Rect(const Rect& other) = default;
		Rect(Rect&& other) = default;
		~Rect() = default;

		virtual double GetXSide() const;
		virtual double GetYSide() const;
		double GetRight() const;
		double GetLeft() const; 
		double GetTop() const;
		double GetBottom() const;

		void NormalizeRect();
		void Swap(double& first, double& second);
		virtual double GetSquare() const;
		virtual Shape& operator= (const Shape& other);
		Rect& operator=(const Rect &) = default;
		virtual bool operator== (const Shape& other) const;

		friend ostream& operator<<(ostream& os, const Rect& rect);

		Shape* Clone() const;
}; 

