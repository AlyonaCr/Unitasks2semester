// ConsoleApplication6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "Shape.h"
#include "Rect.h"
#include "Circle.h"
#include "List.h"
#include <iostream>

int main()
{
	List list;
	Circle c1 (BLUE, "Bob", 4, 5, 13);
	Circle c2 (RED, "Hank", 4, 5, .7);
	Circle c3(BLUE, "Mary", 2.7, 4, 5);
	Rect r1(GREEN, "Mary", 1, 5, 1, 4);
	Rect r2(GREEN, "Kate", 3, 7, 2, 8);

	list.AddToHead(c1);
	list.AddToHead(c2);
	list.AddToHead(r1);
	list.AddToHead(c3);
	list.AddToHead(r2);

	list.Sort(SQUARE);
	cout << "After sort by square: " << '\n'<< list << std::endl;
	list.SaveInFile("MFile.txt");

	list.RemoveFirst(c2);

	list.Sort(MCOLOR);
	cout << "After sort by color: " << '\n' << list << std::endl;

	Rect r3(GREEN, "Mark", 1, 5, 1, 4);
	Circle c4(BLUE, "Leo", 2.7, 4, 5);
	Rect r4(GREEN, "Mandy", 3, 7, 2, 8);
	List t_list;
	t_list.AddToHead(r3);
	t_list.AddToHead(c4);
	t_list.AddToHead(r4);

	list = t_list;

	cout << list << std::endl;
	list.Sort(MCOLOR);
	cout << "After sort by color: " << '\n' << list << std::endl;


	//list.MakeEmpty();
	//list.AddToHead(c1);
	List r_list;
	r_list.ReadFromFile("MFile.txt");
	cout << r_list << std::endl;
}

