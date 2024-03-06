#include <iostream>
#include <vector>
#include <map>
#include <set>

template<typename T>
void print(const std::vector<T>& vec) {
    std::cout << "Vector: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

template<typename Key, typename Value>
void print(const std::map<Key, Value>& mp) {
    std::cout << "Map: ";
    for (const auto& pair : mp) {
        std::cout << "{" << pair.first << ": " << pair.second << "} ";
    }
    std::cout << std::endl;
}

template<typename T>
void print(const std::set<T>& st) {
    std::cout << "Set: ";
    for (const auto& elem : st) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void print(const std::string& str) {
    std::cout << "String: " << str << std::endl;
}

void print(int num) {
    std::cout << "Int: " << num << std::endl;
}

int main() {
    std::vector<int> intVec = {1, 2, 3, 4, 5};
    print(intVec);

    std::vector<std::string> strVec = {"apple", "banana", "orange"};
    print(strVec);

    std::map<int, std::string> intStrMap = {{1, "one"}, {2, "two"}, {3, "three"}};
    print(intStrMap);

    std::set<int> intSet = {1, 2, 3, 4, 5};
    print(intSet);

    std::set<std::string> strSet = {"apple", "banana", "orange"};
    print(strSet);

    print("Hello, world!");

    print(123);

    return 0;
}
