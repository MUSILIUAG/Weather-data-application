#ifndef MAINMENU_H
#define MAINMENU_H
#include "locationmanager.h"
#include "usersettings.h"
#include "weatherdatamanager.h"
#include "airqualitydatamanager.h"



extern LocationManager location;
extern UserSettings userSettings;
extern WeatherDataManager data;
extern AirQualityDataManager airQualityData;

class mainMenu
{
public:

    mainMenu();
    void loadMainMenu();
    void displayWeatherData();
};

#endif // MAINMENU_H
