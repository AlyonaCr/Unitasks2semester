// Контейнеры STL: 
//stack, queue, priority_queue
//set, multiset, map, multimap
//
//#include "stdafx.h"

#include <tchar.h>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <clocale>
#include <iostream>
#include "Templates2.h"
#include "Point2.h"


using namespace std;


#define stop __asm nop

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");

	//Напишите шаблон функции для вывода значений stack, queue, priority_queue
	//обратите внимание на то, что контейнеры предоставляют РАЗНЫЕ методы для 
	//получения значений

	stack <string> st;
	st.push("ABC");
	st.push("DEF");
	st.push("GHI");

	queue <int, list<int>> que;
	que.push(1);
	que.push(2);
	que.push(3);
	
	
	priority_queue <char> p_que;
	p_que.push('a');
	p_que.push('b');
	p_que.push('c');

	cout << "Stack: ";
	print(st);
	cout << "Priority queue: ";
	print(p_que);
	cout << "Queue: ";
	//print_queue(que);

	////////////////////////////////////////////////////////////////////////////////////
	//stack

	//Создайте стек таким образом, чтобы
	//а) элементы стека стали копиями элементов вектора
	//б) при выводе значений как вектора, так и стека порядок значений был одинаковым 
	vector <int> v = { 1,2,3,4,5,6 };
	vector <int>::reverse_iterator itb = v.rbegin(), ite = v.rend();
	stack<int, vector<int>> sst(vector<int>(itb, ite));
	while (itb != ite) {
		sst.push(*itb);
		++itb;
	}
	cout << "Vector: ";
	print_basic_cont(v);
	cout << "Set: ";
	print(sst);

	////////////////////////////////////////////////////////////////////////////////////
	//queue

	//Создайте очередь, которая содержит указатели на объекты типа Point,
	//при этом явно задайте базовый контейнер.
	//Измените значения первого и последнего элементов посредством front() и back()
	//Подумайте, что требуется сделать при уничтожении такой очереди? -- цикл с освобождением захваченной памяти

	queue<Point*, deque<Point*>> m_que;
	m_que.push(new Point(1, 1));
	m_que.push(new Point(2, 2));
	m_que.push(new Point(3, 3));
	m_que.push(new Point(4, 4));
	print(m_que);
	//delete m_que.front();
	//m_que.front() = new Point(7, 7);
	*m_que.front() =  Point(7, 7);
	//delete m_que.back();
	//m_que.back() = new Point(11, 11);
	print(m_que);

	while (!m_que.empty()) {
		delete m_que.front();
		m_que.pop();
	}

	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//а) создайте очередь с приоритетами, которая будет хранить адреса строковых литералов - const char*
	//б) проинициализируйте очередь при создании с помощью вспомогательного массива с элементами const char*
	//в) проверьте "упорядоченность" значений (с помощью pop() ) - если они оказываются не упорядоченными, подумайте:
	//		что сравнивается при вставке? ---- адреса ??? на верх всплывает самый большой (последний)

	const char * pMas[6];
	pMas[4] = { "EEE" };
	pMas[0] = { "AAAA" };
	pMas[1] = { "BBB" };
	pMas[5] = { "FFFF" };
	pMas[2] = { "CCC" };
	pMas[3] = { "DDD" };
	
	

	priority_queue <const char*, vector<const char*>, Compr> p_q(pMas, pMas + 6);

	print(p_q);

	//while (!p_q.empty()) {
	//	cout << p_q.top() << " ";
	//	p_q.pop();
	//}
	//cout << '\n';


	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) создайте множество с элементами типа Point - подумайте, что необходимо определить
	//		в классе Point (и каким образом)
	//б) распечатайте значения элементов с помощью шаблона, реализованного в предыдущей лаб. работе
	//в) попробуйте изменить любое значение...
	//г) Создайте два множества, которые будут содержать одинаковые значения
	//		типа int, но занесенные в разном порядке
	//д) Вставьте в любое множество диапазон элементов из любого другого
	//	контейнера, например, элементов массива	(что происходит, если в массиве имеются дубли?) -- не добавляются
	{
		//a)
		set <Point> s1;
		s1.insert(Point(1, 1));
		s1.insert(Point(12, 5));
		s1.insert(Point(6, 7));
		s1.insert(Point(0, 1));
		s1.insert(Point(0, 1));
		s1.insert(Point(12, 5));

		//б)
		print_basic_cont(s1);

		//в
		set <Point>::iterator itb = s1.begin();
		/**itb = new Point(0, 2);
		в set объекты константны, изменить их нельзя, можно только удалить элемент. итератор только на чтение*/

		//г
		set<int> s_i1 = { 1,2,3,4,5 };
		set<int> s_i2 = { 3,1,4,2,5 };
		cout << " s_i1: " << endl;
		print_basic_cont(s_i1);
		cout << " s_i2: " << endl;
		print_basic_cont(s_i2);
		// добавление в разных порядках одинаковых элементов дает одну картину при выводе на экран, т.к. set частично упорядоченная структура

		//д
		int iMas[] = { 2,8,3,4,8,2,1 };
		cout << " s_i1 before insert: " << endl;
		print_basic_cont(s_i1);
		s_i1.insert(iMas, iMas + std::size(iMas));
		// дубли не добавляются
		cout << " s_i1 after insert: " << endl;
		print_basic_cont(s_i1);

	}
	////////////////////////////////////////////////////////////////////////////////////
	//map, multiset
	//а) создайте map, который хранит пары "фамилия, зарплата" - pair<const char*, int>,
	//	при этом строки задаются строковыми литералами
	//б) заполните контейнер значениями посредством operator[] и insert()
	//в) распечатайте содержимое

	//г) замените один из КЛЮЧЕЙ на новый (была "Иванова", вышла замуж => стала "Петрова")
	{

	//a
	map < const char*, int, Compr> m1;
	//б
	m1["Иванова"] = 2222222;
	m1.insert(pair<const char*, int>("Петров", 7777777));
	m1["Сидорова"] = 6666666;
	//в
	print_map(m1);
	//г
	m1.erase("Иванова");
	m1.insert(pair<const char*, int>("Петрова", 2222222));
	print_map(m1);
	}

	stop




		//д) Сформируйте любым способом вектор с элементами типа string.
		//Создайте (и распечатайте для проверки) map<string, int>, который будет
		//содержать упорядоченные по алфавиту строки и
		//количество повторений каждой строки в векторе
	{
		vector <string> v = { string("rectangle"), string("square"),string("circle"), string("rectangle"),
		string("triangle"),string("square") };

		vector <string>::const_iterator itb = v.cbegin(), ite = v.cend();

		map<string, int> m2;


		while (itb != ite) {
	
			m2[*itb] ++;
			
			itb++;
		}

		cout << " Vector: " << '\n';
		print_basic_cont(v);
		cout << " Map: " << '\n';
		print_map(m2);

	}


		//е) 
		//задан массив:
		//const char* words[] = {"Abba", "Alfa", "Beta", "Beauty" ,...};
		//создайте map, в котором каждой букве будет соответствовать совокупность 
		//лексиграфически упорядоченных слов, начинающихся с этой буквы.
		//Подсказка: не стоит хранить дубли одной и той же строки

		//'A' -  "Abba" "Alfa"
		//'B' -  "Beauty" "Beta"  ...
		//...
	{
		map <char, set<string>> voc;
		insert_in_voc("Cucumber", voc);
		insert_in_voc("Carrot", voc);
		insert_in_voc("Abba", voc);
		insert_in_voc("Alfa", voc);
		insert_in_voc("Cucumber", voc);
		insert_in_voc("Beta", voc);
		insert_in_voc("Beauty", voc);
		insert_in_voc("Zeta", voc);
		insert_in_voc("Zebra", voc);
		cout << " My vocabulary" << endl;
		print_map_set(voc);


	}

		//ж)
		//создайте структуру данных, которая будет хранить информацию о студенческих группах.
		//Для каждой группы должны хранится фамилии студентов (по алфавиту). При этом 
		//фамилии могут дублироваться
		//Сами группы тоже должны быть упорядочены по номеру
		//
		//номера 
	{
		map <unsigned int, multiset<string>> groups;
		insert_in_group("Иванов", 2, groups);
		insert_in_group("Петров", 2, groups);
		insert_in_group("Кетов", 1, groups);
		insert_in_group("Путов", 3, groups);
		insert_in_group("Савельева", 2, groups);
		insert_in_group("Седова", 1, groups);
		print_map_set(groups);

	}



	////////////////////////////////////////////////////////////////////////////////////
	//multimap
	//а) создайте "англо-русский" словарь, где одному и тому же ключу будут соответствовать
	//		несколько русских значений - pair<string,string>, например: strange: чужой, странный...
	//б) Заполните словарь парами с помощью метода insert или проинициализируйте с помощью 
	//		вспомогательного массива пара (пары можно конструировать или создавать с помощью шаблона make_pair)
	//в) Выведите все содержимое словаря на экран
	//г) Выведите на экран только варианты "переводов" для заданного ключа. Подсказка: для нахождения диапазона
	//		итераторов можно использовать методы lower_bound() и upper_bound()
	{
		multimap <string, string> voc;
		voc.insert(pair<string, string>(string("fear"), string ("страх")));
		voc.insert(pair<string, string>(string("fear"), string("боязнь")));
		voc.insert(pair<string, string>(string("wobble"), string("трястись")));
		voc.insert(pair<string, string>(string("wobble"), string("шататься (стул)")));
		voc.insert(pair<string, string>(string("strange"), string("чужой")));
		voc.insert(pair<string, string>(string("strange"), string("странный")));
		voc.insert(make_pair("deal", "сделка"));
		voc.insert(make_pair("deal", "решать"));

		print_map(voc);

		cout << "wobble: ";
		multimap <string, string>::const_iterator itb = voc.lower_bound("wobble"), ite = voc.upper_bound("wobble");
		while (itb != ite) {
			cout << itb->second<< ", ";
			++itb;
		}

		cout << '\n';
	}

		stop

		return 0;
}

