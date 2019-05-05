#pragma once
#include <iostream>
#include <string>
#include "Rect.h"
#include <cctype>  

using namespace std;

// print stack and queue
template <typename T> void print(T cont) {

	while (!cont.empty()) {
		cout << MyTop(cont)<< " ";
		cont.pop();
	}
	cout << '\n';
}
template <typename T> const typename T::value_type& MyTop(const T& a)
{
	return a.top();
}
template <typename T, typename C> const typename T::value_type & MyTop(const queue <T, C> & q) {
	return q.front();
}


// print basic containers: vector, list and deque plus set
template <typename T> void print_basic_cont(const T& cont)
{
	typename T::const_iterator first = cont.begin();
	typename T::const_iterator last = cont.end();

	while (first != last) {
	cout << *first << " ";
		++first;
	}
	cout << '\n';
}
// print map
template <typename T> void print_map(const T & cont) {

	typename T::const_iterator  itb = cont.cbegin();
	typename T::const_iterator  ite = cont.cend();

	while (itb != ite) {
		cout << itb->first << ": " << itb->second << endl;
		++itb;
	}

}


template <typename T> void print_for_each(const T& t) {
	cout << t << ", ";
}
template <typename T> void change_coordinates(Point & pt) {
	pt += 2;
}

class PointPr {
	double x, y;
public:
	PointPr(double xx, double yy): x(xx), y(yy){}

	bool operator () (const Point & pt) {
		return ((x == pt.getX()) && (y == pt.getY()));
	}
};

class PointPr2 {
	double n, m;
public:
	PointPr2(double m_n, double m_m) : n(m_n), m(m_m) {}

	bool operator () (const Point & pt) {
		return ((n <= pt.getX()) && (m >= pt.getX())&& (n <= pt.getY()) && (m >= pt.getY()));
	}
};
template <typename T, typename A> class change{
	A m_b;
public:
	change(const A& b) : m_b(b) {}

	void operator () (T& t) {
		t += m_b;
	}
};
class CMP_IF {
	double m_x, m_y;
public:
	CMP_IF(double x, double y) : m_x(x), m_y(y) {};
	bool operator()(const Rect& r1, const Rect& r2)const {
		return ((r1.GetXSide() + r1.GetYSide() - (m_x + m_y)) < (r2.GetXSide() + r2.GetYSide() - (m_x + m_y)));
	}
};

