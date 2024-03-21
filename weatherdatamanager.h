#ifndef WEATHERDATAMANAGER_H
#define WEATHERDATAMANAGER_H
#include "datamanager.h"

class WeatherDataManager:public DataManager
{
public:
    WeatherDataManager();
    std::string url;


#endif // WEATHERDATAMANAGER_H
