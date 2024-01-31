#include <vector>
#include <iostream>
#include <algorithm>
#include "common.h"
using namespace std;

bool compare(int a, int b) {
	return a > b;
}
#if 0
void show_array(const vector<int>& array)
{
	vector<int>::const_iterator iter;
	cout << "array[";
	for (iter = array.begin(); iter != array.end(); iter++)
	{
		cout << *iter << ",";
	}
	cout << "]" << endl;
}
#endif
int main()
{
	vector<int> array;
	array.push_back(42);
	array.push_back(1);
	array.push_back(100);
	show_array(array);
	sort(array.begin(), array.end()); // default ascending sequence
	show_array(array);
	sort(array.begin(), array.end(), compare);
	show_array(array); // descending sequence
	return 0;
}