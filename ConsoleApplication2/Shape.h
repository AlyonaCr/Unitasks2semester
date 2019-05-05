#pragma once

enum COLOR {RED, GREEN, BLUE};

class Shape {
protected:
	COLOR m_color;
	char * m_author;

public:
	Shape(COLOR color, const char* author);
	Shape();
	virtual ~Shape();
	virtual void Inflate(int x) = 0;
	Shape(const Shape& other);
	// move конструктор копировани€
	Shape(Shape&& other);
	// дл€ того, чтобы класс был абстрактный и нельз€ было создать его объект, должен быть хот€ бы один чистый виртуальный метод
	void SetColor(COLOR color);
	void SetAuthor(const char* author);
	COLOR GetColor() const;
	const char * GetAuthor() const;
	virtual void WhereAmI();
	
};


