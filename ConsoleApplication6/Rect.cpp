#include "Rect.h"
#include <iostream>

using namespace std;

Rect::Rect(COLOR color, const char* author, double left, double right, double top, double bottom)
					: Shape (color, author)
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

void Rect::NormalizeRect() {
	if (m_right < m_left) {
		Swap(m_right, m_left);
	}
	else if (m_top > m_bottom) {
		Swap(m_top, m_bottom);
	}
}

void Rect::Swap(double& first, double& second) {
	double tmp = first;
	first = second;
	second = tmp;
}

double Rect::GetSquare() const {

	return ((m_right - m_left)*(m_bottom - m_top));
}

double Rect::GetXSide() const {
	return (m_right - m_left);
}
double Rect::GetYSide() const {
	return (m_bottom - m_top);
}

bool Rect::operator== (const Shape& other) const
{
	const Rect* tmp = dynamic_cast<const Rect*>(&other);
	return (Shape::operator==(other)&&(m_left == tmp->m_left) && (m_right == tmp->m_right) && (m_top == tmp->m_top) && (m_bottom == tmp->m_bottom));
	
}

double  Rect::GetRight() const
{
	return m_right;
}

double  Rect::GetLeft() const
{
	return m_left;
}

double  Rect::GetTop() const
{
	return m_top;
}

double  Rect::GetBottom() const
{
	return m_bottom;
}

ostream& operator<<(ostream& os, const Rect& rect)
{
	os << "Shape: rectangle" <<static_cast<const Shape&>(rect) <<" Left: " << rect.GetLeft() << " Right: " << rect.GetRight() << " Top: " << rect.GetTop() << " Bottom: " << rect.GetBottom()<< " Square: "<<rect.GetSquare()<< '\n';
	return os;
}



Shape* Rect::Clone() const
{
	return new Rect(*this);
}


Shape& Rect::operator= (const Shape& other)
{
	const Rect& tmp = dynamic_cast<const Rect&>(other);
	*this = tmp;
	return *this;
}