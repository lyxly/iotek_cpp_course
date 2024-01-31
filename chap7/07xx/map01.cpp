#include <iostream>
#include <map>
#include <string>
#include <string_view>
 
void print_map(std::string_view comment, const std::map<std::string, int>& m)
{
    std::cout << comment;
    // 使用 C++17 设施进行遍历
    for (const auto& [key, value] : m)
        std::cout << '[' << key << "] = " << value << "; ";
 
// C++11 方案：
//  for (const auto& n : m)
//      std::cout << n.first << " = " << n.second << "; ";
//
// C++98 方案：
//  for (std::map<std::string, int>::const_iterator it = m.begin(); it != m.end(); it++)
//      std::cout << it->first << " = " << it->second << "; ";
 
    std::cout << '\n';
}
 
int main()
{
    // 创建包含三对 (string, int) 的 map
    std::map<std::string, int> m{{"CPU", 10}, {"GPU", 15}, {"RAM", 20}};
 
    print_map("1) 初始 map：", m);
 
    m["CPU"] = 25; // 更新已经存在的值
    m["SSD"] = 30; // 插入新值
    print_map("2) 更新后的 map：", m);
 
    // 以不存在的键使用 operator[] 总是会执行插入操作
    std::cout << "3) m[UPS] = " << m["UPS"] << '\n';
    print_map("4) 更新后的 map：", m);
 
    m.erase("GPU");
    print_map("5) 移除后：", m);
 
    std::erase_if(m, [](const auto& pair){ return pair.second > 25; });
    print_map("6) 移除后：", m);
    std::cout << "7) m.size() = " << m.size() << '\n';
 
    m.clear();
    std::cout << std::boolalpha << "8) map 为空：" << m.empty() << '\n';
}