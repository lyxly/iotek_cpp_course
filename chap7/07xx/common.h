#pragma once
#include <vector>
#include <list>
#include <set>
using namespace std;

template <typename T>
void show_array(const vector<T>& array){
	vector<T>::const_iterator iter;
	for (iter = array.begin(); iter != array.end(); iter++)
	{
		//cout << *iter << ",";
		cout << *iter;
	}
}

template <typename T>
void show_list(const list<T>& li) {
	list<T>::const_iterator iter;
	for (iter = li.begin(); iter != li.end(); iter++)
	{
		cout << *iter << ",";
		//cout << *iter;
	}
	cout << endl;
}

template <typename T>
void show_set(const set<T>& se){
	set<T>::const_iterator iter;
	for (iter = se.begin(); iter != se.end(); iter++)
	{
		cout << *iter << ",";
		//cout << *iter;
	}
	cout << endl;
}