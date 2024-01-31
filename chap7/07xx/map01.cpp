#include <iostream>
#include <map>
#include <string>
#include <string_view>
 
void print_map(std::string_view comment, const std::map<std::string, int>& m)
{
    std::cout << comment;
    // ʹ�� C++17 ��ʩ���б���
    for (const auto& [key, value] : m)
        std::cout << '[' << key << "] = " << value << "; ";
 
// C++11 ������
//  for (const auto& n : m)
//      std::cout << n.first << " = " << n.second << "; ";
//
// C++98 ������
//  for (std::map<std::string, int>::const_iterator it = m.begin(); it != m.end(); it++)
//      std::cout << it->first << " = " << it->second << "; ";
 
    std::cout << '\n';
}
 
int main()
{
    // ������������ (string, int) �� map
    std::map<std::string, int> m{{"CPU", 10}, {"GPU", 15}, {"RAM", 20}};
 
    print_map("1) ��ʼ map��", m);
 
    m["CPU"] = 25; // �����Ѿ����ڵ�ֵ
    m["SSD"] = 30; // ������ֵ
    print_map("2) ���º�� map��", m);
 
    // �Բ����ڵļ�ʹ�� operator[] ���ǻ�ִ�в������
    std::cout << "3) m[UPS] = " << m["UPS"] << '\n';
    print_map("4) ���º�� map��", m);
 
    m.erase("GPU");
    print_map("5) �Ƴ���", m);
 
    std::erase_if(m, [](const auto& pair){ return pair.second > 25; });
    print_map("6) �Ƴ���", m);
    std::cout << "7) m.size() = " << m.size() << '\n';
 
    m.clear();
    std::cout << std::boolalpha << "8) map Ϊ�գ�" << m.empty() << '\n';
}