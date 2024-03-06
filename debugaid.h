#ifndef DEBUG_AID_H
#define DEBUG_AID_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

void print(const std::string& str);
void print(int num);
void print(const std::vector<int>& vec);
void print(const std::vector<std::string>& vec);
void print(const std::map<std::string, int>& map);
void print(const std::set<int>& set);

#endif // DEBUG_AID_H
