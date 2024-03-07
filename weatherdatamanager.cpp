#include "weatherdatamanager.h"
#include "apicontroller.h"

APIController api;

weatherDataManager::weatherDataManager(){}

void weatherDataManager::setWeatherData(std::pair<double, double> credentials)
{
weatherDataJson = api.fetchWeatherData(credentials);
}

