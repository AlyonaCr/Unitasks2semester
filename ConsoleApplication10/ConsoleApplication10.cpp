// Iter_Alg.cpp : Defines the entry point for the console application.
//
//Итераторы. Стандартные алгоритмы. Предикаты.
#include <tchar.h>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include "Point3.h"
#include "Templates3.h"
#include"Shape.h"
#include "Rect.h"


using namespace std;
#define	  stop __asm nop


int _tmain(int argc, _TCHAR* argv[])
{

	///////////////////////////////////////////////////////////////////

	set <Point> s = { Point(1,2), Point(6,2), Point(8,3), Point(6,8), Point(14,10) };
	set <Point>::reverse_iterator r_itb = s.rbegin(), r_ite = s.rend();
	vector <Point> rv (r_itb, r_ite);

	
	cout << "set: " << endl;
	copy(s.begin(), s.end(), ostream_iterator<Point>(cout));
	cout << '\n';
	cout << "vector with reversed set values: " << endl;
	copy(rv.begin(), rv.end(), ostream_iterator<Point>(cout));
	cout << '\n';


	

	back_insert_iterator<vector<Point>> it = back_inserter(rv);
	*it = Point(0, 0);
	cout << "vector after using of back_insert_iterator " << endl;
	print_basic_cont(rv);

	list <Point> l(rv.begin(), rv.end());
	cout << "list: " << endl;
	print_basic_cont(l);
	front_insert_iterator<list<Point>> it_l = front_inserter(l);
	*it_l = Point(7, 7);
	cout << "list after using of front_insert_iterator " << endl;
	print_basic_cont(l);

	list<Point>::iterator itr = l.begin();
	insert_iterator<list<Point>> it_l2 = inserter(l, ++itr);
	*it_l2 = Point(99, 99);
	cout << "list after using of insert_iterator " << endl;
	print_basic_cont(l);



	for_each(l.begin(), l.end(), print_for_each<Point>);
	cout << '\n';
	int Mas[] = { 1,2,3,4,5,6,7,8,9 };
	for_each(Mas, Mas + std::size(Mas), print_for_each<int>);
	cout << '\n';

	set <string> sstr = { "AAA", "BBB", "CCC" };
	for_each(sstr.begin(), sstr.end(), print_for_each<string>);
	for_each(sstr.begin(), sstr.end(), [](const string & str) {cout << str << ' '; });
	for_each(sstr.begin(), sstr.end(), [](const auto & str) {cout << str << ' '; });
	cout << '\n';

	stop

		//С помощью алгоритма for_each в любой последовательности с элементами типа Point
		//измените "координаты" на указанное значение (такой предикат тоже стоит реализовать 
		//как шаблон) и выведите результат с помощью предыдущего предиката

	{
	vector <Point> vp = {Point(1,3), Point(1,7), Point(8,3), Point(1,3), Point(8,6)};
	/*for_each(vp.begin(), vp.end(), change_coordinates<Point>);*/
	for_each(vp.begin(), vp.end(), change<Point, int>(2));
	print_basic_cont(vp);

	}

	

	{
		vector <Point> vp = {Point(1,3), Point(1,7), Point(8,3), Point(1,3), Point(8,6)};
		list<vector<Point>::const_iterator> lp;
		vector <Point>::const_iterator itb = vp.begin(), ite = vp.end();
		while (itb != ite) {
		itb = find_if(itb, vp.cend(), PointPr(1, 3));
		if (itb == vp.end()) break;
		lp.push_back(itb);
		++itb;
		}

		list<vector<Point>::const_iterator>::const_iterator itbl = lp.cbegin(), itel = lp.cend();
		while (itbl != itel) {
			cout << *(*itbl) << " ";
			++itbl;
		}
		cout << '\n';
	}



	{

		vector <Point> vp = { Point(1,3), Point(1,7), Point(8,3), Point(1,3), Point(8,6) };
		list <Point> l = { Point(1,9), Point(3,4), Point(7,17), Point(10,3), Point(0,0) };

		cout << "vector before sort: " << endl;
		print_basic_cont(vp);
		sort(vp.begin(), vp.end());
		cout << "vector after sort: " << endl;
		print_basic_cont(vp);

		cout << "list before sort: " << endl;
		print_basic_cont(l);
		l.sort();
		cout << "list after sort: " << endl;
		print_basic_cont(l);


	}

	
		//С помощью алгоритма find_if() найдите в любой последовательности элементов Point
		//итератор на элемент Point, удовлетворяющий условию: координаты x и y лежат в промежутке
		//[-n, +m].
	{
		list <Point> l = { Point(1,9), Point(3,4), Point(7,17), Point(10,3), Point(0,0) };
		cout << " initial values: " << endl;
		print_basic_cont(l);
		list<Point>::const_iterator itb = l.begin(), ite = l.end();
		cout << "points in range [0, 7]: " << endl;
		while (itb != ite) {
			/*itb = find_if(itb, l.cend(), PointPr2(0, 7));*/
			itb = find_if(itb, l.cend(), [](const Point& pt) {return ((0 <= pt.getX()) && (7 >= pt.getX()) && (0 <= pt.getY()) && (7 >= pt.getY())); });
			if (itb == l.end()) break;
			cout << *itb << " ";
			++itb;
		}
	}

		
	vector <Rect> vrect = { Rect(RED, "Bob",1,5,2,7), Rect(GREEN,"Hank", 1, 5, 1, 4), Rect(BLUE,"Katy", 3,7,6,12) , Rect(RED,"Mandy",2,7,0,4) };
	cout << "vector before sort:" << endl;
	print_basic_cont(vrect);
	sort(vrect.begin(), vrect.end(), CMP_IF(0, 0));
	cout << "vector after sort:" << endl;
	print_basic_cont(vrect);


	{//transform
	

		string str("AAABBBCCDD");
		transform(str.begin(), str.end(),str.begin(),tolower);
		cout << str << '\n';




		{list <string> strl = { "Apple", "Banana", "KIWI" };
		set<string> strs;
		set<string>::iterator ite = strs.begin();
		insert_iterator<set<string>> itr = inserter(strs, ite);
		transform(strl.begin(), strl.end(), itr, [](string str) {string::iterator it = str.begin(); while (it != str.end()) {*it = tolower(*it); ++it; }return str; });
		print_basic_cont(strs);

		}
		stop
	}
	{// map


		vector <string> v = { "apple", "banana", "ananas", "cabbage", "kiwi", "potato", "ananas", "ananas" };
		map <string, int> mp;
	



	}




	return 0;
}

