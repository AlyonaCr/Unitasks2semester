#include "Rect.h"
#include <iostream>

using namespace std;

Rect::Rect(COLOR color, const char* author,int left, int right, int top, int bottom)
					: Shape (color, author) // вызов конструктора базового класса
{
	m_left = left;
	m_right = right;
	m_top = top;
	m_bottom = bottom;
	this->NormalizeRect();
}

Rect::Rect()
:Shape (){
	m_left = 1;
	m_right = 6;
	m_top = 1;
	m_bottom = 4;
	this->NormalizeRect();
}

Rect::~Rect() {
	cout << "Now I am in Shape's destructor!" << '\n';
}

// можно и не переопределять
Rect::Rect(const Rect& other) :
	Shape(other)
{
	m_left = other.m_left;
	m_right = other.m_right;
	m_top = other.m_top;
	m_bottom = other.m_bottom;
	this->NormalizeRect();

}

// функция расширения прямоугольника
void Rect::InflateRect(int left, int right, int top, int bottom)
{
	m_left -= left;
	m_right += right;
	m_top -= top;
	m_bottom += bottom;

	this->NormalizeRect();

}

void Rect::InflateRect(int x, int y) {

	m_left -= x;
	m_right += x;
	m_top -= y;
	m_bottom += y;

	this->NormalizeRect();
}


void Rect::SetAll(COLOR color, char* author, int left, int right, int top, int bottom)
{
	SetColor(color);
	SetAuthor(author);
	m_left = left;
	m_right = right;
	m_top = top;
	m_bottom = bottom;

	this->NormalizeRect();

}

void Rect::GetAll(COLOR& color, char* author, int& x1, int& x2, int& y1, int& y2) const {
	color = GetColor();
	strcpy_s(author, (strlen(GetAuthor())+1)*sizeof(char), GetAuthor());
	x1 = m_left;
	x2 = m_right;
	y1 = m_top;
	y2 = m_bottom;
}

int Rect::GetXSide() const {
	return (m_right - m_left);
}
int Rect::GetYSide() const {
	return (m_bottom - m_top);
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

void Rect::GetSquare(int & dest) const{

	dest = ((m_right - m_left)*(m_bottom - m_top));
}

void Rect::WhereAmI() {
	cout << "Now I am in class Rect" << '\n';
}


void Rect::Inflate(int x) {
	m_left -= x;
	m_right += x;
	m_top -= x;
	m_bottom += x;

	this->NormalizeRect();
}