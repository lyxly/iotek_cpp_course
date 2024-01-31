#include <iostream>
#include <list>
#include "common.h"
using namespace std;

int main()
{
	list<int> coll;
	coll.push_back(10);
	coll.push_back(11);
	coll.push_front(12);
	coll.push_front(9);

	show_list(coll);

	list<int>::iterator iter = coll.begin();
	cout << *iter << endl;
#if 1
    coll.erase(iter++); // 先删除了iter所指，iter所指已非法，然后iter移到下一个位置
	cout << *iter << endl;
#else
	//coll.erase(++iter); // 先iter移到下一位置，再删除iter所指，iter已非法
#endif

	show_list(coll);
	return 0;
}