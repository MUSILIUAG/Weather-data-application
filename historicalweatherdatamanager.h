#ifndef HISTORICALWEATHERDATAMANAGER_H
#define HISTORICALWEATHERDATAMANAGER_H
#include "datamanager.h"
#include "usersettings.h"

extern UserSettings userSettings;

class HistoricalWeatherDataManager:public DataManager
{
public:


    std::string getUrl() const override;
    std::vector<std::string> getVariables() const override;

    void setVariables();



    HistoricalWeatherDataManager();

private:
    struct Variables
    {
        std::vector<std::string> variables; //Populates from Weather Data variables

    };
    Variables historicalWeather;
};

#endif // HISTORICALWEATHERDATAMANAGER_H
