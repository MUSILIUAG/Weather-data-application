#include "datamanager.h"
#include "apicontroller.h"
#include "locationmanager.h"
#include "userpreferences.h"
#include "airqualitydatamanager.h"
#include "weatherdatamanager.h"
#include "historicalweatherdatamanager.h"
#include "dataexporter.h"
#include "utility.h"
#include <set>
#include <algorithm>

APIController api;

extern LocationManager location;
extern UserPreferences userSettings;

extern WeatherDataManager weatherdata;
extern AirQualityDataManager airQualityData;
extern HistoricalWeatherDataManager historicalWeatherData;





DataManager::DataManager(){}

void DataManager::loadDataMenu()
{

    std::cout <<"\n"<< "<<<DISPLAY FORECAST>>>" << std::endl;

    std::cout <<"\n"<<"DISCLAIMER:  All day ranges and start to end dates for historical data are Default values go to settings to change them"<<std::endl;

    selectDerivedClassAddress();
    locationSelectionHandler();

}

void DataManager::selectDerivedClassAddress()
{
    switch(userSettings.option)
    {
        case 2:
        ptr = &weatherdata;
        break;
        case 3:
        ptr = &historicalWeatherData;
        break;
        case 4:
        ptr = &airQualityData;
        break;
    }
}





void DataManager::locationSelectionHandler(){
    std::cout <<"\n"<< "SEARCH LOCATIONS" << std::endl;

    location.displayFavoriteLocation();
    std::cout << "Type location name or id: ";
    std::string locationName;
    std::cin >> locationName;


    std::string searchResults = location.searchForLocation(locationName);

    if (searchResults == "Too many Results" || searchResults == "No Results" || searchResults == "Invalid Character")
    {
        locationSelectionHandler();
        return;
    }




    std::pair<double, double>geocoordinates = location.Location[searchResults][0];
    userSettings.latitudeAsString = std::to_string(geocoordinates.first);
    userSettings.longitudeAsString = std::to_string(geocoordinates.second);
    getWeatherVariables();
}




void DataManager::getWeatherVariables()
{
    std::vector<std::pair<std::string, std::string>> Variables;
    Variables = ptr->getVariables();
    ptr->handleVariableSelections(Variables);

    getData();

    if(DataJson.isMember("error"))
    {
        std::cout <<DataJson["reason"].asString() << std::endl;
        userSettings.userVariablesVec.clear();
        userSettings.userVariablesStr.clear();
        userSettings.modelVec.clear();
        userSettings.modelStr.clear();
        return;
    }

    displayData();

}








std::vector<std::string> DataManager::handleKeySelection(std::vector<std::pair<std::string, std::string>> allVariables) const
{
    for (unsigned long i = 0; i < allVariables.size(); ++i)
    {
        std::cout << i + 1 << " - " << allVariables[i].first << std::endl;
    }

    std::cout << "Choose weather variables you want displayed (comma-separated): ";
    std::string choice;
    std::cin.ignore(); // Clear the input buffer
    std::getline(std::cin, choice);

    std::vector<std::string> choices = Utility::stringArrayToVec(choice);

    // Validate each choice
    for (const auto& c : choices) {
       unsigned int index = std::stoi(c);
        if (index < 1 || index > allVariables.size()) {
            std::cerr << "Invalid choice: " << index << ". Please enter a number between 1 and " << allVariables.size() << std::endl;
            return {}; // Return an empty vector to indicate failure
        }
    }

    return choices;
}





void DataManager::getData()
{
    std::string url;
    url = ptr->getUrl();
    DataJson = api.fetchJsonData(url);
}




void DataManager::displayData()
{
    std::string hourlyOrDaily = "hourly";

    if(DataJson.isMember("daily"))
    {
        hourlyOrDaily = "daily";
    }

    const auto& hourlyOrDailyKey = DataJson[hourlyOrDaily];
    const auto& timeKeyValue = hourlyOrDailyKey["time"];
    int forecastDays = 1;
        std::string dielCycle;

        for(unsigned int i = 0; i < timeKeyValue.size(); i++)
        {
            if((i == 0 || i%24 == 0) && hourlyOrDaily == "hourly" )

            {
                std::cout<<"\n"<<"<<<<<<<<<<<<< DAY "<<forecastDays<<" >>>>>>>>>>>>>"<<std::endl; // Prints out what days forecast is being displayed
                forecastDays++; //changes the day to the next day
            }

            std::cout<< "\n" << "Time: "<<timeKeyValue[i].asString()<<std::endl; // prints the time

            const auto& dataUnits = DataJson[hourlyOrDaily + "_units"];

                // Process each key-value pair in the nested JSON object
                for (const auto& item : hourlyOrDailyKey.getMemberNames()) {
                    if (item != "time" && item.find("is_day")==std::string::npos) {
                        std::cout << item << ": " << hourlyOrDailyKey[item][i].asDouble() << dataUnits[item].asString() << std::endl;
                    } else if (item.find("is_day")!=std::string::npos) {
                        std::string dielCycle = (hourlyOrDailyKey[item][i].asString() == "1") ? "Day" : "Night";
                        std::cout << item << ": " <<dielCycle << std::endl;
                    }
                }
            }

                DataExporter dataExporter(ptr->getUrl());
                dataExporter.loadDataExporterMenu();


                userSettings.userVariablesVec.clear();
                userSettings.userVariablesStr.clear();
                userSettings.modelVec.clear();
                userSettings.modelStr.clear();
}




std::string DataManager::setHourlyOrDaily() const
{
    std::cout<<"\n"<<"1 - HOURLY WEATHER VARIBLES"<<std::endl;
    std::cout<<"2 - DAILY WEATHER VARIABLES"<<std::endl;


    int userchoice = Utility::getIntegerInput();

    switch(userchoice){
    case 1:
        userSettings.hourlyOrDaily ="hourly";
        return userSettings.hourlyOrDaily ;
        break;
    case 2:
        userSettings.hourlyOrDaily ="daily";
        return userSettings.hourlyOrDaily ;

        break;
    default:
        std::cout << "Invalid command. Please Try again \n" << std::endl;
        setHourlyOrDaily();
        break;
    }
    return "";
}

