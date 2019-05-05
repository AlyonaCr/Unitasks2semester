#include "myRect.h"
#include <iostream>

Rect::Rect(int left, int right, int top, int bottom) {
	// Проверка на корректность вводимых значений
	
		m_left = left;
		m_right = right;
		m_top = top;
		m_bottom = bottom;
		this->is_rectangle();
		this->NormalizeRect();
	
	
}
	

// функция расширения прямоугольника
void Rect::InflateRect(int left, int right, int top, int bottom)
{
		m_left -= left;
		m_right += right;
		m_top -= top;
		m_bottom += bottom;
		this->is_rectangle();
		this->NormalizeRect();
	
}

void Rect::InflateRect(int x, int y) {

	m_left -= x;
	m_right += x;
	m_top -= y;
	m_bottom += y;
	this->is_rectangle();
	this->NormalizeRect();
}

Rect::Rect(const Rect& other) {
	m_right = other.m_right;
	m_left = other.m_left;
	m_top = other.m_top;
	m_bottom = other.m_bottom;
}

void Rect::SetAll(int left, int right, int top, int bottom) {

		m_left = left;
		m_right = right;
		m_top = top;
		m_bottom = bottom;
		this->is_rectangle();
		this->NormalizeRect();

}

void Rect::GetAll(int& x1, int& x2, int& y1, int& y2) {
	x1 = m_left;
	x2 = m_right;
	y1 = m_top;
	y2 = m_bottom;
}

void Rect::NormalizeRect() {
	if (m_right < m_left) {
		Swap(m_right, m_left);
	}
	else if (m_top > m_bottom) {
		Swap(m_top, m_bottom);
	}
}

void Rect::Swap(int& first, int& second) {
	int tmp = first;
	first = second;
	second = tmp;
}


void Rect::BoundingRect(Rect rect1, Rect rect2) {

	this->m_left = rect1.m_left > rect2.m_left ? rect2.m_left : rect1.m_left;
	this->m_top = rect1.m_top > rect2.m_top ? rect2.m_top : rect1.m_top;
	this->m_right = rect1.m_right < rect2.m_right ? rect2.m_right : rect1.m_right;
	this->m_bottom = rect1.m_bottom < rect2.m_bottom ? rect2.m_bottom : rect1.m_bottom;
}

void Rect::BoundingRect2(const Rect& rect1, const  Rect& rect2) {

	this->m_left = rect1.m_left > rect2.m_left ? rect2.m_left : rect1.m_left;
	this->m_top = rect1.m_top > rect2.m_top ? rect2.m_top : rect1.m_top;
	this->m_right = rect1.m_right < rect2.m_right ? rect2.m_right : rect1.m_right;
	this->m_bottom = rect1.m_bottom < rect2.m_bottom ? rect2.m_bottom : rect1.m_bottom;
}
// добраться до членов класса только через методы?
Rect GlobalBoundingRect(Rect rect1, Rect rect2) {

	int r1_x1, r1_x2, r1_y1, r1_y2;
	rect1.GetAll(r1_x1, r1_x2, r1_y1, r1_y2);

	int r2_x1, r2_x2, r2_y1, r2_y2;
	rect2.GetAll(r2_x1, r2_x2, r2_y1, r2_y2);

	int left = r1_x1 > r2_x1? r2_x1 : r1_x1;
	int right = r1_x2 < r2_x2 ? r2_x2 : r1_x2;
	int top = r1_y1 > r2_y1? r2_y1 : r1_y1;
	int bottom = r1_y2 < r2_y2 ? r2_y2 : r1_y2;
	Rect rect(left, right, top, bottom);
	return rect;
}


void Rect::is_rectangle() {
	if ((this->m_right - this->m_left) == (this->m_bottom - this->m_top)) {
		printf("Caution! This is not rectangle!\n");
	}
}
