#include "Shape.h"
#include <cstring>
#include <iostream>

static const char* colors[] = { "Red", "Green", "Blue" };

using namespace std;

Shape::Shape(COLOR color, const char* author) 
{
	m_color = color;
	m_author = author;
}

Shape::Shape() 
{
	m_color = RED;
	m_author = "USER";

}

Shape::Shape(const Shape& other) 
{
	m_color = other.m_color;
	m_author =  other.m_author;
}


Shape::Shape(Shape&& other) 
{
	m_color = other.m_color;
	m_author = std::move(other.m_author);
	
}

void Shape::SetColor(COLOR color)
{
	m_color = color;
}

void Shape::SetAuthor(const char* author) 
{
	m_author = author;
}

COLOR Shape::GetColor() const 
{
	return m_color;
}

const char * Shape::GetAuthor() const 
{
	return m_author.GetString();
}

bool Shape::operator== (const Shape& other) const
{
	return ((m_author == other.m_author) && (this->m_color == other.m_color));
}

Shape& Shape::operator= (const Shape& other)
{
	if (this != &other) {
		m_author = other.m_author;
		m_color = other.m_color;
	}
	return *this;
}

Shape& Shape::operator= (Shape&& other)
{
	this->m_author = std::move(other.m_author);
	m_color = other.m_color;
	return *this;
}



ostream& operator<<(ostream& os, const Shape& shape)
{
	os <<" Author: " << shape.GetAuthor() << " Color: " << colors[shape.GetColor()];
	return os;
}
