#ifndef MAINMENU_H
#define MAINMENU_H
#include "locationmanager.h"
#include "usersettings.h"
#include "weatherdatamanager.h"
#include "airqualitydatamanager.h"



extern LocationManager location;
extern UserSettings userSettings;
extern WeatherDataManager weatherdata;
extern AirQualityDataManager airQualityData;

class MainMenu
{
public:

    MainMenu();
    void loadMainMenu();
    void navToSelectedMenu();
    void displayWeatherData();
};

#endif // MAINMENU_H
