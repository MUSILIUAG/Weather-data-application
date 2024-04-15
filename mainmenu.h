#ifndef MAINMENU_H
#define MAINMENU_H
#include "locationmanager.h"
#include "userpreferences.h"
#include "weatherdatamanager.h"
#include "airqualitydatamanager.h"
#include "historicalweatherdatamanager.h"
#include "utility.h"




extern LocationManager location;
extern UserPreferences userSettings;
extern WeatherDataManager weatherdata;
extern AirQualityDataManager airQualityData;
extern HistoricalWeatherDataManager historicalWeatherData;
extern Utility utility;


class MainMenu
{
public:

    MainMenu();
    void loadMainMenu();

private:
    void navToSelectedMenu();

};

#endif // MAINMENU_H
