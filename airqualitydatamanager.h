#ifndef AIRQUALITYDATAMANAGER_H
#define AIRQUALITYDATAMANAGER_H
#include "datamanager.h"
#include "usersettings.h"

extern UserSettings userSettings;

class AirQualityDataManager:public DataManager
{
public:

    std::string url;


    AirQualityDataManager();


};

#endif // AIRQUALITYDATAMANAGER_H
