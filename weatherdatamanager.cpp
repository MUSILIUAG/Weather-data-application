#include "weatherdatamanager.h"
#include "apicontroller.h"
#include "locationmanager.h"

APIController api;
extern LocationManager location;

WeatherDataManager::WeatherDataManager(){}

void WeatherDataManager::loadWeatherDataMenu()
{
    std::cout <<"\n"<< "<<<DISPLAY WEATHER FORECAST>>>" << std::endl;

    if(location.Location.size() != 0) std::cout <<"\n"<< "SAVED LOCATIONS" << std::endl;
    for (const auto& loc : location.Location) // prints out all saved locations
    {
        std::cout << "Locaton name: "<<loc.first << std::endl;
    }

    std::cout << "Type location name: ";
    std::string locationName;
    std::cin >> locationName;

    setWeatherData(location.Location[locationName][0]);
    displayWeatherData();
}


void WeatherDataManager::setWeatherData(std::pair<double, double> credentials)
{
weatherDataJson = api.fetchWeatherData(credentials);
}

void WeatherDataManager::displayWeatherData()
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

        const auto& hourlyKey = weatherDataJson["hourly"];
        const auto& timeKeyValue = weatherDataJson["hourly"]["time"];
        for(unsigned int i = 0; i < timeKeyValue.size(); i++)
        {
            std::cout<< "\n" << "Time: "<<timeKeyValue[i].asString()<<std::endl; // prints the time first
            for (const auto& key : keyList)
            {
                std::string keyToWeatherVariable = weatherVariables[std::stoi(key)-1]; //converts the keys to an index so access the indexed weather variable
                const auto& hourlyData = hourlyKey[keyToWeatherVariable];
                const auto& hourlDataUnits = weatherDataJson["hourly_units"][keyToWeatherVariable];
                    if (hourlyKey.isMember(keyToWeatherVariable))
                    {
                        std::cout << keyToWeatherVariable << ": " << std::to_string(hourlyData[i].asInt()) + hourlDataUnits.asString() << std::endl;
                    }
                    else
                    {
                        std::cerr << "Key not found: " << keyToWeatherVariable << std::endl;
                    }

            }
        }

}



