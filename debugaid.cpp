#include <iostream>
#include <vector>
#include <set>
#include "debugaid.h"

template<typename T>
void print(const std::vector<T>& vec) {
    std::cout << "Vector: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
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
    std::cout << str << std::endl;
}

void print(int num) {
    std::cout <<  num << std::endl;
}

