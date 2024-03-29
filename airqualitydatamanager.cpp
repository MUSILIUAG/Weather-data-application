#include "airqualitydatamanager.h"
#include <iostream>

AirQualityDataManager::AirQualityDataManager()
{}

std::string AirQualityDataManager::getUrl() const {

    return "https://air-quality-api.open-meteo.com/v1/air-quality?latitude=" +
                userSettings.latitudeAsString + "&longitude=" + userSettings.longitudeAsString +
                "&hourly="+userSettings.userSelections + "&forecast_days="+userSettings.dayRange;
}

std::vector<std::pair<std::string, std::string>> AirQualityDataManager::getVariables() const{
 hourlyVariables airQualityVariables;
 return airQualityVariables.variables;
}




