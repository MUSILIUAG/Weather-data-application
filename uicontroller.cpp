#include "uicontroller.h"
#include "debugaid.h"
#include "weatherdatamanager.h"
#include "locationmanager.h"
#include <iostream>

weatherDataManager weatherData;
locationManager location;

UIcontroller::UIcontroller(){}

void UIcontroller::loadMainMenu()
{
    std::cout << "<<<MAIN MENU>>>" << std::endl;
    std::cout << "1 - LOCATION QUERIES" << std::endl;
    std::cout << "2 - DISPLAY WEATHER FORECAST" << std::endl;
    std::cout << "3 - EXIT" << std::endl;

    int choice;
    std::cout <<"\n"<< "choose between 1 and 3: ";
    std::cin >> choice;

    if (choice == 1)
    {
        location.loadLocationMenu();
        loadMainMenu();
    }

    else if (choice == 2)
    {
        std::cout << "<<<DISPLAY WEATHER FORECAST>>>" << std::endl;
        for (const auto& loc : location.Location) // prints out all saved locations
        {
            std::cout << "Locaton name: "<<loc.first << std::endl;
        }

        std::cout << "Type location name: ";
        std::string locationName;
        std::cin >> locationName;

        weatherData.setWeatherData(location.Location[locationName][0]);
        displayWeatherData();

    }

    else if (choice == 3)
    {
        // Do nothing or exit the program
    }
    else
    {
        std::cout << "Invalid command. Please Try again \n" << std::endl;
        loadMainMenu();
    }
}


void UIcontroller::displayWeatherData()
{
    for (unsigned long i=1; i <= weatherVariables.size(); i++)
    {
        std::cout<<i<<" - "<<weatherVariables[i-1]<<std::endl;
    }
    std::cout<< "choose weather variables you want displayed: ";
    std::string choice;
    std::cin>>choice;



    std::istringstream iss(choice); //Gets the string array from the user
        std::vector<std::string> keyList;
        std::string key; // adds the values to a vector
        while (std::getline(iss, key, ',')) {
            keyList.push_back(key);
        }
    Json::Value timeData = weatherData.weatherDataJson["hourly"]["time"];
    for(unsigned int i = 0; i < timeData.size(); i++)
    {
        std::cout<< "\n" << "Time: "<<timeData[i]<<std::endl; // prints the time first
        for (const auto& key : keyList)
        {
            std::string keyToWeatherVariable = weatherVariables[std::stoi(key)-1]; //converts the keys to an index so access the indexed weather variable
            const auto& hourlyData = weatherData.weatherDataJson["hourly"][keyToWeatherVariable];
                if (weatherData.weatherDataJson["hourly"].isMember(keyToWeatherVariable))
                {
                    std::cout << keyToWeatherVariable << ": " << hourlyData[i] << std::endl;
                }
                else
                {
                    std::cerr << "Key not found: " << keyToWeatherVariable << std::endl;
                }

        }
    }

}
