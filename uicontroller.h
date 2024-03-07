#ifndef UICONTROLLER_H
#define UICONTROLLER_H
#include "locationmanager.h"


extern LocationManager location;

class UIcontroller
{
public:

    UIcontroller();
    void loadMainMenu();
    void displayWeatherData();
};

#endif // UICONTROLLER_H
