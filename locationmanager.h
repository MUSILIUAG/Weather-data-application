#ifndef LOCATIONMANAGER_H
#define LOCATIONMANAGER_H
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>


class LocationManager
{
public:
    std::unordered_map<std::string, std::vector<std::pair<double, double>>>Location{
        {"lagos",{{6.4541,3.3947}}}
    }; // format name {latitude, longitude}


    LocationManager();
    void loadLocationMenu();
    void addLocation();
    void navToSelectedMenu();
    void removeLocation();
};

#endif // LOCATIONMANAGER_H
