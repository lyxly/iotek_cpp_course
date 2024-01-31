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
	map<int, string, Compare> coll; // Ӱ�����˳��
	//map<int, string> coll;
	map<int, string>::iterator iter;

	// map�Ĳ��뷽ʽ
	coll.insert(pair<int, string>(9, "Nine")); // ���� pair ����
	coll.insert(map<int, string>::value_type(1, "One")); // ����value_type

	coll.insert(make_pair(2, "Two"));
	coll[0] = "Zero";


	// ��������
	//// C++20 ����
	//for (const auto&[key, value] : m)
	//	std::cout << '[' << key << "] = " << value << "; ";

	// C++11 ������
	  for (const auto& n : coll)
	      std::cout << n.first << " = " << n.second << "; ";
	  cout << endl;
	// C++98 ������
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