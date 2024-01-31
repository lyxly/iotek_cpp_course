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
    coll.erase(iter++); // ��ɾ����iter��ָ��iter��ָ�ѷǷ���Ȼ��iter�Ƶ���һ��λ��
	cout << *iter << endl;
#else
	//coll.erase(++iter); // ��iter�Ƶ���һλ�ã���ɾ��iter��ָ��iter�ѷǷ�
#endif

	show_list(coll);
	return 0;
}