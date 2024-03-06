#include "locationmanager.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>
#include "debugaid.h"
locationManager::locationManager(){

}

void locationManager::start()
{
    std::cout<<"<<<LOCATION MENU>>>";
    std::cout<<"1 - ADD LOCATION";
    std::cout<<"2 - MODIFY LOCATION";
    std::cout<<"3 - REMOVE LOCATION";

    int choice;
    std::cin>>choice;

    switch(choice)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
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

