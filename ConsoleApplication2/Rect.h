#pragma once
#include"Shape.h"

class Rect : public Shape {
	int m_left, m_right, m_top, m_bottom;

	public:

		Rect(COLOR color, const char* author, int left, int right, int top, int bottom);
		Rect();
		Rect(const Rect& other);
		~Rect();
		void InflateRect(int left, int right, int top, int bottom);
		void InflateRect(int x = 1, int y = 1);
		void SetAll(COLOR color, char* author, int left, int right, int top, int bottom);
		void GetAll(COLOR& color, char* author,int& x1, int& x2, int& y1, int& y2) const;

		int GetXSide() const;
		int GetYSide() const;


		void NormalizeRect();
		void Swap(int& first, int& second);
		void BoundingRect(Rect rect1, Rect rect2);
		void BoundingRect2(const Rect& rect1, const  Rect& rect2);
		void GetSquare(int & dest) const;
		void WhereAmI();
		void Inflate(int x);
		
}; 

