// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "List.h"
#include "Circle.h"
#include "Point.h"

int main()
{
	List list;
	//list.AddToHead(Circle(4, 5, 13));
	//list.AddToHead(Circle(4, 5, .7));
	//list.AddToHead(Circle(4, 5, 2));
	//list.AddToHead(Circle(4, 5, 3)); 
	//list.AddToHead(Circle(4, 5, 6));
	//list.AddToHead(Circle(4, 5, 2.5));
	//list.AddToHead(Circle(4, 5, .5));
	////list.RemoveAll(Circle(4, 5, 13));
	//cout << list << std::endl;
	//list.QuickSort(list.GetHead()->pNext, list.GetTail()->pPrev, list.GetSize());
	//cout << list << std::endl;
	//list.SaveInFile("Myfile.txt");
	list.ReadFromFile("Myfile.txt");
	cout << list << std::endl;
}

