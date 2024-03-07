#ifndef WEATHERDATAMANAGER_H
#define WEATHERDATAMANAGER_H
#include "apicontroller.h"

#include <jsoncpp/json/json.h>


class WeatherDataManager
{  
public:
    Json::Value weatherDataJson;
    std::vector<std::string>weatherVariables{"temperature_2m","relative_humidity_2m","precipitation_probability"};

    WeatherDataManager();
    void loadWeatherDataMenu();
    void setWeatherData(std::pair<double, double> credentials);
    void displayWeatherData();

};

#endif // WEATHERDATAMANAGER_H
