#include "historicalweatherdatamanager.h"
#include "weatherdatamanager.h"
#include <iostream>


HistoricalWeatherDataManager::HistoricalWeatherDataManager(){}

std::string HistoricalWeatherDataManager::getUrl() const {
    return  "https://archive-api.open-meteo.com/v1/archive?latitude=" + userSettings.latitudeAsString + "&longitude=" + userSettings.longitudeAsString +
            "&start_date="+userSettings.startDate+"&end_date="+userSettings.endDate +
            "&"+ userSettings.hourlyOrDaily +"="+ userSettings.userVariablesStr + userSettings.modelStr +
            "&temperature_unit="+ userSettings.currentTemperatureUnit +"&wind_speed_unit="+ userSettings.currentWindSpeedUnit +
            "&precipitation_unit="+userSettings.currentPercipitationUnit +
            userSettings.solarTiltAndAzimuth;
}



std::vector<std::pair<std::string, std::string>> HistoricalWeatherDataManager::getVariables() const{
    Variables historicalWeather;

    if (userSettings.hourlyOrDaily == "hourly")return historicalWeather.hourlyVariables;
    else return historicalWeather.dailyVariables;
}
