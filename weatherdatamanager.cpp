#include "weatherdatamanager.h"
#include "usersettings.h"

extern UserSettings userSettings;
WeatherDataManager::WeatherDataManager(){}

std::string WeatherDataManager::getUrl() const {
        return "https://api.open-meteo.com/v1/forecast?latitude=" + userSettings.latitudeAsString + "&longitude=" + userSettings.longitudeAsString +
                "&hourly="+userSettings.userSelections +
                "&daily=&temperature_unit="+ userSettings.currentTemperatureUnit +"&wind_speed_unit="+ userSettings.currentWindSpeedUnit +
                "&precipitation_unit="+userSettings.currentPercipitationUnit+"&forecast_days="+userSettings.dayRange;
}

std::vector<std::string> WeatherDataManager::getVariables() const{
Variables weatherVaribles;
return weatherVaribles.varibles;
}

