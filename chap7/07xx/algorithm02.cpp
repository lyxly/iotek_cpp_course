#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>

#include "common.h"
using namespace std;
class ID {
public:
	ID() :name(""), score(0) {}
	ID(string name, int score) :name(name), score(score) {}

	string name;
	int score;
};

// 对于类的比较，属于复合型数据结构，必须默认重载==, <才能成功调用sort
bool operator==(const ID& x, const ID& y) {
	return (x.name == y.name) && (x.score == y.score);
}

bool operator<(const ID& x, const ID& y) {
	return x.score < y.score;
}

bool compare(const ID& x, const ID& y) {
	return x.score > y.score;
}

ostream& operator<<(ostream& os, const ID& id) {
	os << setw(10) << std::left << id.name << std::setw(10) << id.score<<std::endl;
	return os;
}

int main(void) {
	vector<ID> ids;
	vector<ID>::iterator iter;

	ids.push_back(ID("Tom", 5));
	ids.push_back(ID("John", 1));
	ids.push_back(ID("Alex", 2));
	
	show_array(ids);
	cout << "-----" << endl;
	sort(ids.begin(), ids.end());
	show_array(ids);
	cout << "*****" << endl;
	sort(ids.begin(), ids.end(), compare);
	show_array(ids);
	return 0;
}