#pragma once
class Rect{

private:
	int m_left, m_right, m_top, m_bottom;

public:

	Rect(int left = 1, int right = 2, int top = 1, int bottom = 3);
	// переопределенный метод копирования
	Rect(const Rect& other);


	// функция расширения прямоугольника
	void InflateRect(int left, int right, int top, int bottom);
	void InflateRect(int x = 1, int y = 1);
	void SetAll(int left, int right, int top, int bottom);
	void GetAll(int& x1, int& x2, int& y1, int& y2);
	void NormalizeRect();
	void Swap(int& first, int& second);

	void BoundingRect(Rect rect1, Rect rect2);
	void BoundingRect2(const Rect& rect1, const  Rect& rect2);

	void is_rectangle();

	
};


Rect GlobalBoundingRect(Rect rect1, Rect rect2);
