#include <iostream>
using namespace::std;

void foo(int i, int j=5, int k=10);
//void foo(int , int = 5, int = 10);

void func(int){ int a = 0;};
//void func(int,int=4){int a = 5;};
void func(int=3,int=4){int a = 6;};  // 前两个函数都已经算重复定义了吧!



int main(int argc, char *argv[])
{
	foo(20);
	foo(20,30);
	foo(20,30,40);
	
	// func (7); // error：到底调用2个重载函数中的哪个？
    func (20, 30); // ok

	return 0;
}

void foo(int i, int j, int k)
{
	cout << i << "  " << j << "  " << k << endl;
}
