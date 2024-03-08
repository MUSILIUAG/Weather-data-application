#ifndef UICONTROLLER_H
#define UICONTROLLER_H
#include "locationmanager.h"
#include "usersettings.h"


extern LocationManager location;
extern UserSettings userSettings;

class UIcontroller
{
public:

    UIcontroller();
    void loadMainMenu();
    void displayWeatherData();
};

#endif // UICONTROLLER_H
