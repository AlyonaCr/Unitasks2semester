// ConsoleApplication8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//Стандартная библиотека шаблонов - STL 
	//Контейнеры стандартной библиотеки - vector
	//Итераторы

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "Templates.h"
#include "myString4.h"
#include "Point1.h"



#pragma warning(disable: 4786)


using namespace std;

#define	  stop __asm nop


int main()
{
	// Контейнер стандартной библиотеки vector 

//////////////////////////////////////////////////////////////////////
	//Создание векторов. 

	//Создайте следующие вектора:
	//---------------------------
	//пустой вектор целых чисел - vInt и проверьте с помощью функции size(),
	//что его размер нулевой. 


	vector <int> vInt;
	size_t size = vInt.size();
	//Раскомментируйте следующий фрагмент, подумайте - все ли корректно
	//Если есть некорректности, - исправьте
	// поведение на пустом векторе не определено

	vInt.resize(1);
	vInt.front() = 1;


	//С помощью функции push_back() в цикле заполните вектор какими-либо значениями.
	//На каждой итерации цикла следите за размером вектора с помощью методов
	//size(), capacity(), max_size() и выводите значения элементов. 
	//
	//Подсказка: так как такая проверка понадобится Вам и в следующих заданиях,
	//напишите шаблон функции, которая для вектора, содержащего элементы любого типа
	//выводит его "реквизиты" и значения элементов на консоль.
	const size_t N = 10;
	for (size_t i = 0; i < N; i++) {
		vInt.push_back(rand() % 100);
	/*	vector <int>::iterator itb = vInt.begin(), ite = vInt.end();*/
	/*	print_any_seq(itb, ite); */
		print_basic_cont(vInt);
		cout <<" size: " << vInt.size() << " capacity: " << vInt.capacity() << endl;
	}
	cout<< " max size: " << vInt.max_size() << endl;

	//вектор вещественных - vDouble1 с заданным Вами начальным размером  и
	//проверьте результат с помощью созданного Вами шаблона. Как будут
	//проинициализированы элементы вектора? --- нулями
	vector <double> vDouble1(10);
	vector <double>::iterator itb = vDouble1.begin(), ite = vDouble1.end();
	print_any_seq(itb, ite);

	//вектор объектов типа MyString с начальным размером - 5 элементов
	//и инициализацией каждого элемента строкой "A"
	//C помощью функции at() а также с помощью оператора
	//индексирования []  измените значения каких-либо элементов.
	//Попробуйте "выйти" за границы вектора с помощью at() и
	//с помощью []. 

	vector<MyString> vString(5, "A");
	//size_t nn = vString.size();
	//for (size_t i = 0; i < nn; i++) {
	//	vString[i] = "A";
	//}

	try {

		vString.at(2) = "B";
		vString.at(12) = "C";

	}
	catch (out_of_range& er) {
		cout << er.what() << endl;
	}

	//вектор вещественных - vDouble3, который является копией элементов
	// [0,5) массива вещественных чисел dMas. Предворительно массив dMas 
	//нужно создать и проинициализировать!

	double dMas[5];
	size_t nD = sizeof(dMas) / sizeof(double);
	for (size_t i = 0; i < nD; i++) {
		dMas[i] = rand() % 5;
	}

	


	//вектор вещественных - vDouble4, который является копией элементов
	// [2,5) вектора vDouble3. 
	{
		vector <double> vDouble3(dMas, dMas + std::size(dMas));
		vector<double>::iterator itb = vDouble3.begin(), ite = vDouble3.end();
		vector <double> vDouble4;

		while (itb != ite) {
			if ((*itb >= 2) && (*itb < 5)) {
				vDouble4.push_back(*itb);
			}
			++itb;
		}
		cout << "vDouble3: " << endl;
		print_container(vDouble3);
		cout << "vDouble4: " << endl;
		print_container(vDouble4);
	}


	//вектор элементов типа Point - vPoint1 а) с начальным размером 3. Какой конструктор
	//будет вызван для каждого элемента?  --- дефолтовый
	//b) vPoint2 с начальным размером 5 и проинициализируйте каждый элемент координатами (1,1).

	vector <Point> vPoint1(3);
	Point point (1, 1);
	vector <Point> vPoint2(5, point);


	//вектор указателей на Point - vpPoint с начальным размером 5
	//Подумайте: как корректно заставить эти указатели "указывать" на объекты Point
	{

		//Подсказка: для вывода на печать значений скорее всего Вам понадобится
			//а) специализация Вашей шаблонной функции
			//б) или перегрузка operator<< для Point*

	}//Какие дополнительные действия нужно предпринять для такого вектора?

	vector <Point*> vpPoint(5);

	size_t n = vpPoint.size();
	for (size_t i = 0; i <n; i++) {
		vpPoint[i] = new Point(i, i);
	}
	vector <Point*>::iterator itb2 = vpPoint.begin(), ite2 = vpPoint.end();
	print_any_seq(itb2, ite2);
	for (size_t i = 0; i < n; i++) {
		delete vpPoint[i];
	}
	stop
		///////////////////////////////////////////////////////////////////////
		//Резервирование памяти.
		//Подумайте, всегда ли верны приведенные ниже проверки?
			/*
			{
			size_t n=...
			vector<int> v(n);
			v.resize(n/2);
			if(v.capacity() == n) //true?				----------- true
			}
			*/

			/*
			{
			int n=...
			size_t m=...
			vector<int> v(n);
			v.reserve(m);
			if(v.capacity() == m) //true?      ----------- false только если m>n, иначе true
			}
			*/

			/*
			{
			vector<int> v(3,5);
			v.resize(4,10); //значения? 5 5 5 10 10 10 10 10 10 10 10
			v.resize(5); //значения?  5 5 5 10 10

			}
			*/

			//Создайте два "пустых" вектора с элементами
			//любого (но одного и того же типа) типа. 
			//В первом векторе зарезервируйте память под 5 элементов, а потом заполните
			//его значениями с помощью push_back.
			//Второй вектор просто заполните значениями посредством push_back.
			//
			//Сравните размер, емкость векторов и значения элементов

		vector <int> e_v1;
		vector <int> e_v2;
		e_v1.reserve(5);
		e_v1.push_back(1);
		e_v1.push_back(2);
		e_v1.push_back(3);
		e_v1.push_back(4);
		e_v1.push_back(5);


		e_v2.push_back(1);
		e_v2.push_back(2);
		e_v2.push_back(3);
		e_v2.push_back(4);
		e_v2.push_back(5);

		//push_back() в пустой вектор дает резерв для еще одного элемента????

		{
			vector<int>::iterator itb = e_v1.begin(), ite = e_v1.end();
			cout << "vector <int> e_v1 size: " << e_v1.size() << " capacity: " << e_v1.capacity() << endl;
			print_any_seq(itb, ite);
		}

		{
			vector<int>::iterator itb = e_v2.begin(), ite = e_v2.end();
			cout << "vector <int> e_v2 size: " << e_v2.size() << " capacity: " << e_v2.capacity() << endl;
			print_any_seq(itb, ite);
		}

		//!!! shrink_to_fit - Уменьшение емкости вектора.
		//Для любого вектора из предыдущего задания требуется уменьшить емкость
		//до size.
		{
			e_v2.shrink_to_fit();
			vector<int>::iterator itb = e_v2.begin(), ite = e_v2.end();
			cout << "vector <int> e_v2 size: " << e_v2.size() << " capacity: " << e_v2.capacity() << endl;
			print_any_seq(itb, ite);
		}


		//Создание "двухмерного вектора" - вектора векторов
		//Задан одномерный массив int ar[] = {11,2,4,3,5};
		//Создайте вектор векторов следующим образом:
		//вектор vv[0] - содержит 11 элементов со значением 11
		//vv[1] - содержит 2,2
		//vv[2] - содержит 4,4,4,4
		//...
		//Распечатайте содержимое такого двухмерного вектора по строкам
		{
			int ar[] = { 11,2,4,3,5 };
			vector <vector<int>> vv;

			for (size_t i = 0; i < n; i++) {
				vv.emplace_back(ar[i], ar[i]);
			}

			for (size_t i = 0; i < n; i++) {
				vector<int>::iterator itb = vv[i].begin(), ite = vv[i].end();
				print_any_seq(itb, ite);
			}

			std::cout<<vv;

		}


		stop

			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

				//Вставка элемента последовательности insert().

				//В вектор vChar2 вставьте в начало вектора символ только при
				//условии, что в векторе такого еще нет.
		{
		vector<char> vChar2 = { 'a','b','c','d' };
		size_t n = std::size(vChar2);
		const char s = 's';

		insert_as_set(vChar2, s);
		vector<char>::iterator itb = vChar2.begin(), ite = vChar2.end();
		print_any_seq(itb, ite);

		//Вставьте перед каждым элементом вектора vChar2 букву 'W'

	for (size_t i = 0; i < n; i++) {
		itb = vChar2.insert(itb, 'W');
		++itb;
		++itb;
		}
	
		itb = vChar2.begin();
		ite = vChar2.end();
		cout << " After 'W' adding: " << endl;
		print_any_seq(itb, ite);
	

		}

		///////////////////////////////////////////////////////////////////
			//Напишите функцию, которая должна удалять только повторяющиеся последовательности.
			//Например: было - "qwerrrrty12222r3", стало - "qwety1r3"
		{
			vector <char> v = { 'q','w','e','r','r','r','r','t','y','1','2','2','2','2','r','3' };
			delete_same_seq(v);
			print_container(v);
		}


		stop

		///////////////////////////////////////////////////////////////////

			//Удаление элемента последовательности erase()
			//Напишите функцию удаления из любого вектора всех дублей 
		{
			vector<MyString> v_m = {"AAA","BBB","CCC","FFF","BBB", "AAA", "MMM"};
			make_as_set(v_m);
			print_container(v_m);



			///////////////////////////////////////////////////////////////////
				//Создайте новый вектор таким образом, чтобы его элементы стали
				//копиями элементов любого из созданных ранее векторов, но расположены
				//были бы в обратном порядке

			
			vector<MyString>::reverse_iterator r_itb = v_m.rbegin(), r_ite = v_m.rend();
			vector <MyString> v_m2(r_itb, r_ite);

			//while (r_itb != r_ite) {
			//	v_m2.emplace_back(*r_itb);
			//	++r_itb;
			//}

			cout << "v_m: ";
			print_container(v_m);

			cout << "v_m2: ";
			print_container(v_m2);


		}

		///////////////////////////////////////////////////////////////////

			//Задание 1. Списки. Операции, характерные для списков.
			//Создайте пустой список из элементов Point - ptList1 и наполните
			//его значениями с помощью методов push_back(),
			//push_front, insert()
		{
			list <Point> ptList1;
	
			ptList1.push_back(Point(1,1));
			list<Point>::iterator itb = ptList1.begin();
			ptList1.insert(itb, Point(2, 2));
			ptList1.push_back(Point(3,3));
		}

		{
			//Напишите шаблон функции, которая будет выводить элементы
				//ЛЮБОГО КОНТЕЙНЕРА на печать. Проверьте работу шаблона на контейнерах
				//vector и list. Подсказка - хотелось бы увидеть тип контейнера.
			vector<MyString> v_m = { "AAA","BBB","CCC","FFF","BBB", "AAA", "MMM" };
			list <Point> ptList1 = { Point(1,2), Point(1,3), Point(4,7) };
			print_container(v_m);
			print_container(ptList1);

			//Сделайте любой из списков "реверсивным" - reverse()
			ptList1.reverse();
			print_container(ptList1);


			//Создайте список ptList2 из элементов Point таким образом, чтобы он стал 
			//копией вектора элементов типа Point, но значения элементов списка располагались
			//бы в обратном порядке 

			vector <Point> vp = { Point(3,6), Point(1,1), Point(6,7), Point(4,5) };
			list <Point> ptList2(vp.rbegin(), vp.rend());
			print_container(vp);
			print_container(ptList2);





			//Отсортируйте списки  ptList1 и ptList2 - методом класса list - sort()
			//по возрастанию.
			//Подумайте: что должно быть перегружено в классе Point для того, чтобы
			//работала сортировка

			cout << " Before sort ptList1: ";
			print_container(ptList1);
			ptList1.sort();
			cout << " After sort ptList1: ";
			print_container(ptList1);

			cout << " Before sort ptList2: ";
			print_container(ptList2);
			ptList2.sort();
			cout << " After sort ptList2: ";
			print_container(ptList2);



			stop

				//Объедините отсортированные списки - merge(). Посмотрите: что
				//при этом происходит с каждым списком.  -- слияние с сортировкой
				ptList1.merge(ptList2);
			cout << " After merge: ";
			print_container(ptList1);


			stop

				//Исключение элемента из списка - remove()
				//Исключите из списка элемент с определенным значением.
				//Подумайте: что должно быть перегружено в классе Point? - operator==
				ptList1.remove(Point(1, 2));
			print_container(ptList1);


			//Исключение элемента из списка, удовлетворяющего заданному условию:
			//любая из координат отрицательна - remove_if(). 
			ptList1.push_back(Point(-1, 4));
			ptList1.push_front(Point(-1, -7));
			print_container(ptList1);
			ptList1.remove_if(IfNeg);
			print_container(ptList1);
		}
		//Исключение из списка подряд расположенных дублей - unique(). 
		{
			list <Point> ptList3 = { Point(1,1), Point(1,1), Point(7,7), Point(1,1) };
			cout << "Before unique(): " << endl;
			print_container(ptList3);
			ptList3.unique();
			cout << "After unique(): " << endl;
			print_container(ptList3);

		}

		stop

			///////////////////////////////////////////////////////////////////
				//Задание 2.Очередь с двумя концами - контейнер deque

				//Создайте пустой deque с элементами типа Point. С помощью
				//assign заполните deque копиями элементов вектора. С помощью
				//разработанного Вами в предыдущем задании универсального шаблона
				//выведите значения элементов на печать
		{
			vector <Point> vp = { Point(3,6), Point(1,1), Point(6,7), Point(4,5) };
			vector<Point>::iterator itb = vp.begin(), ite = vp.end();
			deque <Point>my_deq;
			my_deq.assign(itb, ite);
			print_container(my_deq);




			//Создайте deque с элементами типа MyString. Заполните его значениями
			//с помощью push_back(), push_front(), insert()
			//С помощью erase удалите из deque все элементы, в которых строчки
			//начинаются с 'A' или 'a'
			{
				deque< MyString> my_deq2;
				my_deq2.push_back("Apple");
				my_deq2.push_back("Cabbage");
				my_deq2.push_front("Banana");
				deque<MyString>::const_iterator it = my_deq2.begin(); ++it;
				my_deq2.insert(it, "ananas");
				print_container(my_deq2);
				deque<MyString>::const_iterator itb = my_deq2.begin(), ite = my_deq2.end();
				while (itb != ite) {
					if (*itb == 'a' || *itb == 'A') {
						itb = my_deq2.erase(itb);
						ite = my_deq2.end();
					}
					else {
						++itb;
					}
				}
				itb = my_deq2.begin(); ite = my_deq2.end();
				print_container(my_deq2);
			}


		}

		return 0;
}
