#include "historicalweatherdatamanager.h"
#include "weatherdatamanager.h"
#include <iostream>

WeatherDataManager weatherData;

HistoricalWeatherDataManager::HistoricalWeatherDataManager(){}

std::string HistoricalWeatherDataManager::getUrl() const {
    return  "https://archive-api.open-meteo.com/v1/archive?latitude=" + userSettings.latitudeAsString + "&longitude=" + userSettings.longitudeAsString +
            "&start_date="+userSettings.startDate+"&end_date="+userSettings.endDate +
            "&hourly="+ userSettings.userSelections + ",is_day" +
            "&temperature_unit="+ userSettings.currentTemperatureUnit +"&wind_speed_unit="+ userSettings.currentWindSpeedUnit +
            "&precipitation_unit="+userSettings.currentPercipitationUnit;
}



std::vector<std::pair<std::string, std::string>> HistoricalWeatherDataManager::getVariables() const{
    hourlyVariables historicalWeather;
    return historicalWeather.variables;
}
