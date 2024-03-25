#include "datamanager.h"
#include "apicontroller.h"
#include "locationmanager.h"
#include "usersettings.h"
#include <algorithm>

APIController api;
extern LocationManager location;
extern UserSettings userSettings;


DataManager::DataManager(){}

void DataManager::loadDataMenu()
{

    std::cout <<"\n"<< "<<<DISPLAY FORECAST>>>" << std::endl;

    std::cout <<"\n"<<"DISCLAIMER:  All day ranges and start to end dates for historical data are Default values go to settings to change them"<<std::endl;

    if(!location.Location.empty()) std::cout <<"\n"<< "SAVED LOCATIONS" << std::endl;
    for (const auto& loc : location.Location) // prints out all saved locations
    {
        std::cout << "Locaton name: "<<loc.first << std::endl;
    }
    idkk();
}

void DataManager::idkk()
{
    std::cout << "Type location name: ";
    std::string locationName;
    std::cin >> locationName;

    std::pair<double, double>geocoordinates = location.Location[locationName][0];
    userSettings.latitudeAsString = std::to_string(geocoordinates.first);
    userSettings.longitudeAsString = std::to_string(geocoordinates.second);

    idk();
}


void DataManager::idk()
{

    std::vector<std::string> Variables = getVariables();
    handleVariableSelections(Variables);

    getData();
    displayData();

}





void DataManager::handleVariableSelections(std::vector<std::string> allVariables)
{
    for (unsigned long i=1; i <= allVariables.size(); i++)
    {
        std::cout<<i<<" - "<<allVariables[i-1]<<std::endl;
    }
        std::cout<< "choose weather variables you want displayed: ";
        std::string choice;
        std::cin>>choice;



        std::istringstream iss(choice); //Gets the string array from the user

        std::string key;
        std::vector<std::string> keyToWeatherVar;
        // adds the values to a vector
        while (std::getline(iss, key, ',')) {
            keyToWeatherVar.push_back(allVariables[std::stoi(key)-1]);
        }

        std::sort(keyToWeatherVar.begin(), keyToWeatherVar.end());
        userSettings.userSelcetionVec = keyToWeatherVar;


        std::ostringstream oss;
            for (size_t i = 0; i < userSettings.userSelcetionVec.size(); ++i) {
                if (i > 0) {
                    oss << ",";
                }
                oss << userSettings.userSelcetionVec[i];
            }
            userSettings.userSelections = oss.str(); //saves user preferences as comma seprated list
}




void DataManager::getData()
{
    std::string url = getUrl();
    DataJson = api.fetchJsonData(url);
}




void DataManager::displayData()
{
        const auto& hourlyKey = DataJson["hourly"];
        const auto& timeKeyValue = hourlyKey["time"];
        const auto& dayKeyValue = hourlyKey["is_day"];
        int forecastDays = 1;
        std::string dielCycle;
        for(unsigned int i = 0; i < timeKeyValue.size(); i++)
        {
            if(i == 0 || i%24 == 0)
            {
                std::cout<<"\n"<<"<<<<<<<<<<<<< DAY "<<forecastDays<<" >>>>>>>>>>>>>"<<std::endl; // Prints out what days forecast is being displayed
                forecastDays++; //changes the day to the next day
            }

            std::cout<< "\n" << "Time: "<<timeKeyValue[i].asString()<<std::endl; // prints the time

            if(hourlyKey.isMember("is_day")) //displays the diel cycle only if a user but in a date for historical data
            {
                if (dayKeyValue[i].asString() == "1") dielCycle = "Day";
                else dielCycle = "Night";

                 std::cout<<"Diel Cycle: "<<dielCycle<<std::endl;
            }

            for (auto& selection : userSettings.userSelcetionVec)
            {
                const auto& hourlyData = hourlyKey[selection];
                const auto& hourlDataUnits = DataJson["hourly_units"][selection];
                    if (hourlyKey.isMember(selection))
                    {
                        std::cout << selection << ": " << std::to_string(hourlyData[i].asInt()) + hourlDataUnits.asString() << std::endl;
                    }
                    else
                    {
                        std::cerr << "Key not found: " << selection << std::endl;
                    }

            } 

        }
        std::cout<<"Do you want to export y/n: "<<std::endl;
        char thing;
        std::cin>>thing;


        if (thing =='y')
        {
           std::cout<<"Formats csv, xlsx "<<std::endl;
           std::string thinge;
           std::cin>>thinge;

           std::string url = getUrl();

           api.test(url + "&format=" + thinge);
        }
}



