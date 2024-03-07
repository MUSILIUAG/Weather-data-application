#include "locationmanager.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>
#include "debugaid.h"
locationManager::locationManager(){

}

void locationManager::loadLocationMenu()
{
    std::cout<<"<<<LOCATION MENU>>>"<<std::endl;
    std::cout<<"1 - ADD LOCATION"<<std::endl;
    std::cout<<"2 - MODIFY LOCATION"<<std::endl;
    std::cout<<"3 - REMOVE LOCATION \n"<<std::endl;

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
    }

}


void locationManager::addLocation()
{
   std::cout<<"Location name: ";
   std::string name;
   std::cin>>name;

   std::cout<<"Latitude: ";
   double Latitude;
   std::cin>>Latitude;

   std::cout<<"Longitude: ";
   double Longitude;
   std::cin>>Longitude;

   Location[name].push_back({Latitude,Longitude});
}


void locationManager::removeLocation()
{
    for (const auto& loc : Location) // prints out all saved locations
    {
        std::cout << "Locaton name: "<<loc.first << std::endl;
    }


   std::cout<<"Location name: ";
   std::string name;
   std::cin>>name;

   Location.erase(name);
}

