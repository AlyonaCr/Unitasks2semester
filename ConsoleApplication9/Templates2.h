#pragma once
#include <iostream>
#include <string>

using namespace std;


template <typename T> const typename T::value_type& MyTop(const T& a)
{
	return a.top();
}
template <typename T, typename C> const typename T::value_type& MyTop(const queue <T,C> & q) {
	return q.front();
}

// print stack and priority queue
template <typename T> void print(T cont) {

	while (!cont.empty()) {
		cout << /*cont.top()*/ MyTop(cont)<< " ";
		cont.pop();
	}
	cout << '\n';
}


 //print queue
template <typename T> void print(std::queue<T> que) {

	while (!que.empty()) {
		cout << que.front()<< " ";
		que.pop();
	}
	cout << '\n';
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

//print map with set as value
void print_map_set(const map <char, set<string>> & voc) {
	map <char, set<string>>::const_iterator itb = voc.cbegin(), ite = voc.cend();
	while (itb != ite) {
		cout << itb->first<< ": ";
		print_basic_cont(itb->second);
		++itb;
	}
	cout << '\n';

}

// print map with multiset as value
void print_map_set(const map <unsigned int, multiset<string>> & voc) {
	map <unsigned int, multiset<string>>::const_iterator itb = voc.cbegin(), ite = voc.cend();
	while (itb != ite) {
		cout << itb->first << ": ";
		print_basic_cont(itb->second);
		++itb;
	}
	cout << '\n';
}

void insert_in_voc(const string & str, map <char, set<string>> & voc) {
	map<char, set<string>>::const_iterator ite = voc.cend();
	if (voc.find(str[0]) == ite) {
		voc.insert(pair <char, set<string >>(str[0], set<string> ()));
	}
	voc[str[0]].set::insert(str);
}

void insert_in_group(const string & lastname, unsigned int group,  map <unsigned int, multiset<string>> & stud) {
	map<unsigned int, multiset<string>>::const_iterator ite = stud.cend();
	if (stud.find(group) == ite) {
		stud.insert(pair <unsigned int, multiset<string>>(group, multiset<string>()));
	}
	stud[group].multiset::insert(lastname);
}

struct Compr {
	bool operator () (const char* l, const char* r) const {
		return (strcmp(l, r)>0);
	}
};