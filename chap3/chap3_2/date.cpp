#include "date.h"

int main(int argc, char *argv[])
{
	TDate a; // 定义一个TDate对象
	a.set(2,14,2014); // 调用public成员函数给对象成员赋值

	a.print();
	
	return 0;
}
