#include "Shape.h"
#include <cstring>
#include <iostream>

using namespace std;

Shape::Shape(COLOR color, const char* author) {
	m_color = color;
	m_author = new char[strlen(author) + 1];
	strcpy_s(m_author, (strlen(author) + 1)* sizeof(char), author);
}

Shape::Shape() {

	m_color = RED;
	m_author = new char[strlen("USER") + 1];
	strcpy_s(m_author, (strlen("USER") + 1) * sizeof(char), "USER");

}

Shape::Shape(const Shape& other) {
	m_color = other.m_color;
	m_author = new char[strlen(other.m_author) + 1];
	strcpy_s(m_author, (strlen(other.GetAuthor()) + 1) * sizeof(char), other.m_author);
}

// move конструктор копировани€
//Shape::Shape(Shape&& other) {
//	m_color = other.m_color;
//	delete[] m_author;
//	m_author = other.m_author;
//	other.m_author = nullptr;
//}

Shape::~Shape() {
	delete[]m_author;
	cout << "Now I am in Shape's destructor!" << '\n';
}

void Shape::SetColor(COLOR color) {

	m_color = color;
}

void Shape::SetAuthor(const char* author) {

	m_author = new char[strlen(author) + 1];
	strcpy_s(m_author, (strlen(author) + 1) * sizeof(char), author);

	//m_author = author;
	// при move по€вл€ютс€ проблемы с удалением

}

COLOR Shape::GetColor() const {
	return m_color;
}

const char * Shape::GetAuthor() const {
	return m_author;
}

/* ак только этот метод стал чисто виртуальным, класс Shape стал абстрактным и компил€тор не позволит создавать его экземпл€ры,
поэтому определение этого метода не нужно*/

void Shape::WhereAmI() {
	cout << "Now I am in class Shape" << '\n';
}
