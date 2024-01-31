#include <iostream>
#include <set>
#include "common.h"

using namespace std;

int main(){
	set<int> coll;
	set<int>::iterator iter;

	coll.insert(1);
	coll.insert(100);
	coll.insert(90);
	coll.insert(-1);
	coll.insert(80);
	
	show_set(coll);
	
	return 0;
}