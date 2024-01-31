
#include "RefCount.h"
#include "SmartPtr.h"
#include <iostream>
using namespace std;
// chap7/smartptr/valgrind.sh ÓÃÀ´¼ì²âÄÚ´æĞ¹Â¶
int main(int argc, char* argv[])
{
	//new Sample;
	//cout << "****" << endl;
	SmartPtr<Sample> p = new Sample; //(Sample *)
	//cout << p << endl;
	//SmartPtr<Sample> p2 = new Sample;
	//cout << "--------" << endl;
	//p2 = p;
	
	cout << "--------" << endl;
//	p->doSomething();
//	(*p).doSomething();


	return 0;
}
