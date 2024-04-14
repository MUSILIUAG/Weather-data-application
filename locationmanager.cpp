#include "locationmanager.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>
LocationManager::LocationManager(){

}

void LocationManager::loadLocationMenu()
{
    std::cout<< "\n" << "<<<LOCATION MENU>>>" <<std::endl;
    std::cout<<"1 - ADD LOCATION"<<std::endl;
    std::cout<<"2 - MODIFY LOCATION"<<std::endl;
    std::cout<<"3 - REMOVE LOCATION \n"<<std::endl;
    navToSelectedMenu();

}

void LocationManager::navToSelectedMenu()
{
    std::cout<<"choose option between 1 - 3: ";
    int choice;
    std::cin>>choice;

    switch(choice)
    {
    case 1:
        addLocation();
        break;
    case 2:
        break;
    case 3:
        removeLocation();
        break;
    default:
        std::cout << "Invalid command. Please Try again \n" << std::endl;
        loadLocationMenu();
        break;
    }

}


void LocationManager::addLocation()
{
   std::cout<<"Location id: ";
   int id;
   std::cin>>id;

   std::cout<<"Location name: ";
   std::string name;
   std::cin>>name;

   std::cout<<"Latitude: ";
   double Latitude;
   std::cin>>Latitude;

   std::cout<<"Longitude: ";
   double Longitude;
   std::cin>>Longitude;

   std::string locationKey = "{" + std::to_string(id) + "}" + " " + name;

   Location[locationKey].push_back({Latitude,Longitude});
}


void LocationManager::removeLocation()
{
    for (const auto& loc : Location) // prints out all saved locations
    {
        std::cout << "Locaton name: "<<loc.first << std::endl;
    }


   std::cout<<"Location ame: ";
   std::string name;
   std::cin>>name;

   Location.erase(name);
}


std::string LocationManager::searchForLocation(std::string locationNameOrId)
{
    std::vector<std::string> searchResults;
    // Iterate through the map using range-based for loop
    for (const auto& loc : Location) {
        if (loc.first.find(locationNameOrId) != std::string::npos) {
            std::cout<<"Location: "<<loc.first<<std::endl;;
            searchResults.push_back(loc.first);
        }
    }
    if (searchResults.size() == 1) return searchResults[0];
    else if(searchResults.size() == 0)
    {
        std::cout<<"No Results"<<std::endl;
        return "No Results";
    }
    else
    {
        std::cout<<"Too many Results"<<std::endl;
        return "Too many Results";
    }
}
