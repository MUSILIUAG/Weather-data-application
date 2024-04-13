#include "weatherdatamanager.h"
#include "userpreferences.h"

extern UserPreferences userSettings;
WeatherDataManager::WeatherDataManager(){}

std::string WeatherDataManager::getUrl() const {
        return "https://api.open-meteo.com/v1/forecast?latitude=" + userSettings.latitudeAsString + "&longitude=" + userSettings.longitudeAsString +
                "&" + userSettings.hourlyOrDaily +"="+userSettings.userVariablesStr + userSettings.modelStr +
                "&temperature_unit="+ userSettings.currentTemperatureUnit +"&wind_speed_unit="+ userSettings.currentWindSpeedUnit +
                "&precipitation_unit="+userSettings.currentPercipitationUnit+"&forecast_days="+userSettings.dayRange +
                userSettings.solarTiltAndAzimuth;
}

std::vector<std::pair<std::string, std::string>> WeatherDataManager::getVariables() const{
Variables weatherVaribles;

if (userSettings.hourlyOrDaily == "hourly")return weatherVaribles.hourlyVariables;
else return weatherVaribles.dailyVariables;
}

