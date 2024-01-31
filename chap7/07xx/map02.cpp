#include <map>
#include <iostream>
#include <string>

using namespace std;
class Compare {
public:
	bool operator()(int a, int b) {
		return a > b;
	}
};
int main()
{
	map<int, string, Compare> coll; // 影响插入顺序
	//map<int, string> coll;
	map<int, string>::iterator iter;

	// map的插入方式
	coll.insert(pair<int, string>(9, "Nine")); // 插入 pair 数据
	coll.insert(map<int, string>::value_type(1, "One")); // 插入value_type

	coll.insert(make_pair(2, "Two"));
	coll[0] = "Zero";


	// 遍历方案
	//// C++20 方案
	//for (const auto&[key, value] : m)
	//	std::cout << '[' << key << "] = " << value << "; ";

	// C++11 方案：
	  for (const auto& n : coll)
	      std::cout << n.first << " = " << n.second << "; ";
	  cout << endl;
	// C++98 方案：
	  for (std::map<int, string>::const_iterator it = coll.begin(); it != coll.end(); it++)
	      std::cout << it->first << " = " << it->second << "; ";
	
	  cout << endl<<"-------" << endl;
	  cout << coll.size() << endl;
	  for (std::map<int, string>::reverse_iterator it = coll.rbegin(); it != coll.rend(); it++)
		  std::cout << it->first << " = " << it->second << "; ";

	  // unordered_map / 
	  // unordered
	return 0;
}