#include "locationmanager.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>
#include <utility.h>




std::string selectedLocation;


LocationManager::LocationManager(){

}

void LocationManager::loadLocationMenu()
{
    std::cout<< "\n" << "<<<LOCATION MENU>>>" <<std::endl;
    std::cout<<"1 - ADD LOCATION"<<std::endl;
    std::cout<<"2 - MODIFY LOCATION"<<std::endl;
    std::cout<<"3 - REMOVE LOCATION"<<std::endl;
    std::cout<<"4 - SET FAVORITE LOCATION"<<std::endl;
    std::cout<<"5 - REMOVE FAVORITE LOCATION"<<std::endl;
    std::cout<<"6 - EXIT"<<std::endl;

    navToSelectedMenu();

}

void LocationManager::navToSelectedMenu()
{
    int userChoice = Utility::getIntegerInput();


    switch(userChoice)
    {
    case 1:
        addLocation();
        break;
    case 2:
        modifyLocationMenu();
        break;
    case 3:
        removeLocation();
        break;
    case 4:
        setFavoriteLocaton();
        break;
    case 5:
        removeFavoriteLocation();
        break;
    case 6:
        break;
    default:
        std::cout << "Invalid command. Please Try again \n" << std::endl;
        loadLocationMenu();
        break;
    }

}


void LocationManager::addLocation()
{
   std::cout<<"Location id"<<std::endl;
   int id = Utility::getIntegerInput();

   // Check if ID already exists
   std::string formattedId = "{" + std::to_string(id) + "}";
   bool idExists = false;
   for (const auto& pair : Location) {
       // Check if the key starts with the formatted ID
       if (pair.first.find(formattedId) == 0) {
           idExists = true;
           break;
       }
   }


   if (idExists) {
       std::cout << "ID already exists." << std::endl;
       addLocation();
       return;
   }


   std::cout<<"Location name: ";
   std::string name;
   std::cin>>name;

   double latitude;
   do
   {
       std::cout<<"Make Sure its within -90 - 90"<<"\n"<<std::endl;
       std::cout<<"Latitude"<<std::endl;
        latitude = Utility::getDoubleInput();
   } while (!Utility::isWithinRange(latitude,-90.0,90.0));


   double longitude;
   do
   {
       std::cout<<"Make Sure its within -180 - 180"<<"\n"<<std::endl;
       std::cout<<"Longitude"<<std::endl;
       longitude = Utility::getDoubleInput();
   } while (!Utility::isWithinRange(longitude,-180.0,180.0));



   std::string locationKey = "{" + std::to_string(id) + "}" + " " + name;

   Location[locationKey].push_back({latitude,longitude});
}


void LocationManager::removeLocation()
{
    for (const auto& loc : Location) // prints out all saved locations
    {
        std::cout << "Locaton: "<<loc.first << std::endl;
    }


    std::cout << "Location name: ";
    std::string name;
    std::cin >> name;

    auto it = Location.find(name);
    if (it != Location.end()) {
        Location.erase(it);
        std::cout << "Location removed successfully!" << std::endl;
    } else {
        std::cout << "Location not found!" << std::endl;
        removeLocation();
    }

}



void LocationManager::modifyLocationMenu()
{
    selectLocationToModify();

   std::cout<<"1 - LOCATION NAME" << std::endl;
   std::cout<<"2 - LATITUDE" << std::endl;
   std::cout<<"3 - LONGITUDE" << std::endl;

   int userChoice = Utility::getIntegerInput();

   switch(userChoice)
   {
    case 1:
       modifyLocationName();
       break;
    case 2:
       modifyLatitude();
       break;
    case 3:
      modifyLongitude();
      break;
   default:
       std::cout << "Invalid command. Please Try again \n" << std::endl;
       modifyLocationMenu();
       break;
   }

}




void LocationManager::modifyLocationName()
{
        auto it = Location.find(selectedLocation);

        // Extract the mapped values associated with the old name
        std::vector<std::pair<double, double>> mappedValues = it->second;

        // Remove the old entry from the map
        Location.erase(it);

        // Read the new location name
        std::cout << "New Location name: ";
        std::string newName;
        std::cin >> newName;

        // Generate the new location key
        std::string id = getId(selectedLocation);
        std::string locationKey = "{" + id + "}" + " " + newName;

        // Insert the updated entry into the map
        Location[locationKey] = mappedValues;

        std::cout << "Location name updated successfully!" << std::endl;
}



void LocationManager::modifyLongitude()
{
       double newLongitude;
       do
       {
           std::cout<<"Make Sure its within -180 - 180"<<"\n"<<std::endl;
           std::cout<<"Longitude"<<std::endl;
           newLongitude = Utility::getDoubleInput();
       } while (!Utility::isWithinRange(newLongitude,-180.0,180.0));


       Location[selectedLocation][0].second = newLongitude;

       std::cout << "Location Longitude updated successfully!" << std::endl;

}


void LocationManager::modifyLatitude()
{
       double newLatitude;
       do
       {
           std::cout<<"Make Sure its within -90 - 90"<<"\n"<<std::endl;
           std::cout<<"Latitude"<<std::endl;
           newLatitude = Utility::getDoubleInput();
       } while (!Utility::isWithinRange(newLatitude,-90.0,90.0));

       Location[selectedLocation][0].first = newLatitude;

       std::cout << "Location Latitude updated successfully!" << std::endl;

}




void LocationManager::setFavoriteLocaton()
{
    selectLocationToModify();
    favoriteLocations.push_back(selectedLocation);
    std::cout << "Sucessfully Added to Favorite Locations!" << std::endl;

}



void LocationManager::removeFavoriteLocation()
{
    if (!favoriteLocations.empty())
    {
        for(unsigned int i = 0 ; i < favoriteLocations.size(); i++)
        {
            std::cout << i + 1 << " - " << favoriteLocations[i] << std::endl;
        }

        std::cout << "Select Location To Remove"<<std::endl;
        unsigned int userChoice = Utility::getIntegerInput();


        // Check if the choice is within the valid range
        if (userChoice >= 1 && userChoice <= favoriteLocations.size()) {
            favoriteLocations.erase(favoriteLocations.begin() + userChoice - 1);
            std::cout << "Location removed successfully!" << std::endl;
        } else {
            std::cout << "Invalid choice!" << std::endl;
            removeFavoriteLocation();
        }
    }
}







std::string LocationManager::searchForLocation(std::string locationNameOrId)
{
    if(locationNameOrId.find("{") != std::string::npos || locationNameOrId.find("}") != std::string::npos)
    {
        std::cout<<"Invalid Character"<<std::endl;
        return "Invalid Character";
    }



    std::vector<std::string> searchResults;
    // Iterate through the map using range-based for loop
    for (const auto& loc : Location) {
        if (loc.first.find(locationNameOrId) != std::string::npos) {
            std::cout<<"Location Search Result: "<<loc.first<<std::endl;;
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







void LocationManager::selectLocationToModify()
{
    std::cout << "Type location name or id: ";
    std::string locationName;
    std::cin >> locationName;


    std::string searchResults = searchForLocation(locationName);

    if (searchResults == "Too many Results" || searchResults == "No Results" || searchResults == "Invalid Character")
    {
        selectLocationToModify();
        return;
    }
    selectedLocation = searchResults;
}



void LocationManager::displayFavoriteLocation()
{
    if(!favoriteLocations.empty())
    {
        std::cout<<"<<<<< FAVORITE LOCATIONS >>>>"<<std::endl;
    }

    for(auto& loc : favoriteLocations)
    {
        std::cout<<"Location: "<<loc<<std::endl;
    }

    if(!favoriteLocations.empty())
    {
        std::cout<<"<<<<<<<<<<>>>>>>>>>>"<<"\n"<<std::endl;
    }

}


std::string LocationManager::getId(std::string key)
{
    std::string id;
    for (unsigned int i = 1; i < key.size(); i++)
    {
        if (key[i] == '}') break;
        id+= key[i];
    }
    return id;
}

