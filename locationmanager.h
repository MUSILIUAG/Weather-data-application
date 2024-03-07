#ifndef LOCATIONMANAGER_H
#define LOCATIONMANAGER_H
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>


class locationManager
{
public:
    std::unordered_map<std::string, std::vector<std::pair<double, double>>>Location{
        {"Lagos",{{6.4541,3.3947}}}
    }; // format name {latitude, longitude}


    locationManager();
    void loadLocationMenu();
    void addLocation();
    void removeLocation();
};

#endif // LOCATIONMANAGER_H
