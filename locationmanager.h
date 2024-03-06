#ifndef LOCATIONMANAGER_H
#define LOCATIONMANAGER_H
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>


class locationManager
{
private:
    std::unordered_map<std::string, std::vector<std::pair<double, double>>>Location; // format name {longitude , latitude}

public:
    locationManager();
    void start();
    void addLocation();
};

#endif // LOCATIONMANAGER_H
