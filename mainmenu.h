#ifndef MAINMENU_H
#define MAINMENU_H
#include "locationmanager.h"
#include "userpreferences.h"
#include "weatherdatamanager.h"
#include "airqualitydatamanager.h"
#include "historicalweatherdatamanager.h"



extern LocationManager location;
extern UserPreferences userSettings;
extern WeatherDataManager weatherdata;
extern AirQualityDataManager airQualityData;
extern HistoricalWeatherDataManager historicalWeatherData;


class MainMenu
{
public:

    MainMenu();
    void loadMainMenu();
    void navToSelectedMenu();
    void displayWeatherData();
};

#endif // MAINMENU_H
