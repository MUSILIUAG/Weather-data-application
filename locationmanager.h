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
        {"{1} lagos",{{6.4541,3.3947}}}
    }; // location id location name {latitude, longitude}


    LocationManager();
    void loadLocationMenu();
    void addLocation();
    void navToSelectedMenu();
    void removeLocation();
    void modifyLocation();
    void setFavouriteLocaton();
    std::string searchForLocation(std::string locationNameOrId);

};

#endif // LOCATIONMANAGER_H
