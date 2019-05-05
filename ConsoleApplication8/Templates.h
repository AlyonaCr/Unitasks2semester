#pragma once
#include <vector>
#include "Point1.h"
using namespace std;

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

template  <typename IT> void print_any_seq(IT first, IT last) 
{

	while (first != last) {
		std::cout << *first << " ";
		++first;
	}
	std::cout << '\n';
}

template <typename T> void print_container(const T& cont)
{

	typename T::const_iterator first = cont.begin();
	typename T::const_iterator last = cont.end();

	cout <<" Type of container: "<< typeid(cont).name() << endl;
	while (first != last) {
		std::cout << *first << " ";
		++first;
	}
	std::cout << '\n';
}

template  <typename T> void insert_as_set (std::vector<T>& v, const T & val) {

	typename vector<T>::iterator first = v.begin();
	typename vector<T>::iterator last = v.end();

	if (first != last) {
		while (first != last) {
			if (*first == val) {
				return;
			}
			++first;
		}
	}

	first = v.begin();
	v.insert(first, val);
}

template  <typename T> void delete_same_seq(T& cont) {

	typename T::iterator first = cont.begin();
	typename T::iterator last = cont.end();
	typename T::iterator it_cur = first;
	typename T::iterator it_last = it_cur;
	++it_cur;

	while (it_cur!=last) {
		while (*first == *it_cur) {
			it_last = it_cur;
			++it_cur;
			if (*first != *it_cur) {
				first = cont.erase(first, it_last);
				last = cont.end();
				break;

			}
		}

		++first;
		it_cur = first;
		++it_cur;
	}
}

template  <typename T> void make_as_set(std::vector<T>& v) {

	typename vector<T>::iterator first = v.begin();
	typename vector<T>::iterator last = v.end();
	typename vector<T>::iterator current  = first;

	while (first != last) {
		current = first;
		++current;
		while (current != last) {
			if (*first == *current) {
				current= v.erase(current);
				last = v.end();
			}
			else {
				++current;
			}
		}

		++first;
	}
}


//Predicate global function
bool IfNeg(Point&point) {
	return (point.GetX() < 0 || point.GetY() < 0);
}



template <typename T> ostream& operator<<(ostream &os, const vector <T>& v) {

	typename vector<T>::const_iterator itb = v.begin(), ite = v.end();
	while (itb != ite) {
		os << *itb << ' ';
		++itb;
	}

	return os;
}