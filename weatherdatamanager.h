#ifndef WEATHERDATAMANAGER_H
#define WEATHERDATAMANAGER_H

#include <jsoncpp/json/json.h>




class weatherDataManager
{

public:
    Json::Value weatherDataJson;
    weatherDataManager();
    void setWeatherData(std::pair<double, double> credentials);
};

#endif // WEATHERDATAMANAGER_H
