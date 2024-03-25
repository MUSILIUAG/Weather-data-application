#ifndef AIRQUALITYDATAMANAGER_H
#define AIRQUALITYDATAMANAGER_H
#include "datamanager.h"
#include "usersettings.h"

extern UserSettings userSettings;

class AirQualityDataManager:public DataManager
{
public:
    std::string getUrl() const override;
    std::vector<std::string> getVariables() const override;


    AirQualityDataManager();


private:
    struct Variables
    {
      std::vector<std::string> variables {"pm10", "pm2_5", "carbon_monoxide", "nitrogen_dioxide", "european_aqi"
                                             , "european_aqi_pm2_5", "european_aqi_pm10", "european_aqi_nitrogen_dioxide",
                                             "european_aqi_ozone", "european_aqi_sulphur_dioxide"};
    };


};

#endif // AIRQUALITYDATAMANAGER_H
