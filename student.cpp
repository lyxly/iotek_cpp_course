
#include <iostream>

class Student {
public:
	// Student(int ssID = 0) :id(ssID), score(100) { // ok, 冒号表示后面要对类的数据成员进行初始化
	Student(int ssID = 0):score(100), id(ssID) { // 编译该文件会告警
		std::cout << "Constructing student: " << ssID << std::endl;
	}
private:
	int id;
	int score;
};

int main(void) {
	Student a(11);
	return 0;
}
