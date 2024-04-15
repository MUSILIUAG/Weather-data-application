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

    std::vector<std::string> favoriteLocations;


    LocationManager();
    void loadLocationMenu();
    void addLocation();
    void navToSelectedMenu();
    void removeLocation();

    void selectLocationToModify();
    void modifyLocationMenu();
    void modifyLocationName();
    void modifyLongitude();
    void modifyLatitude();

    void displayFavoriteLocation();
    void setFavoriteLocaton();
    void removeFavoriteLocation();

    std::string searchForLocation(std::string locationNameOrId);

    std::string getId(std::string key);

};

#endif // LOCATIONMANAGER_H
