#include "Circle.h"
#include <cstring>
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

using namespace std;

Circle::Circle(COLOR color, const char* author, double radius, double x, double y) :
	Shape(color, author)
{
	m_radius = radius;
	m_x = x;
	m_y = y;
}
//
//Circle::Circle() 
//: Shape(){
//	m_radius = 2.7;
//}

//описывает прямоугольник
Circle::Circle(Rect&rect) 
	:Shape(rect)
{
	//m_color = rect.GetColor();
	//m_author = new char[strlen(rect.GetAuthor()) + 1];
	strcpy_s(m_author, (strlen(rect.GetAuthor()) + 1) * sizeof(char), rect.GetAuthor());

	m_x = static_cast<double>(rect.GetXSide()) / 2;
	m_y = static_cast<double>(rect.GetYSide()) / 2;
	m_radius = rect.GetXSide() > rect.GetYSide() ? rect.GetXSide() : rect.GetYSide();

}

Circle::~Circle() {
	cout << "Now I am in Circle's destructor!" << '\n';
}

void Circle::SetAll(COLOR color, const char* author, double radius, double x, double y) {
	SetColor(color);
	SetAuthor(author);
	m_radius = radius;
	m_x = x;
	m_y = y;
}
void Circle::GetAll(COLOR& color, char* author, double& radius, double& x, double& y) const {
	color = GetColor();
	author = new char[strlen(GetAuthor()) + 1];
	strcpy_s(author,(strlen(GetAuthor())+1)*sizeof(char), GetAuthor());
	x = m_x;
	y = m_y;
}
void Circle::SetRadius(const double& radius) {
	m_radius = radius;
}
void Circle::GetRadius(double& radius) const {
	radius = m_radius;
}
void Circle::SetCenter(const double& x, const double& y) {
	m_x = x;
	m_y = y;
}

void Circle::GetCenter(double& x, double& y) {
	x = m_x;
	y = m_y;
}

void Circle::GetSquare(double & dest) const {
	dest = (pow(m_radius, 2.0)* M_PI);
}

void Circle::WhereAmI() {
	cout << "Now I am in class Circle" << '\n';
}
void Circle::Inflate(int x) {
	m_radius += x;
}