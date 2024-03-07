#ifndef UICONTROLLER_H
#define UICONTROLLER_H
#include <iostream>
#include <vector>


class UIcontroller
{
public:
    std::vector<std::string>weatherVariables{"temperature_2m","relative_humidity_2m","precipitation_probability"};

    UIcontroller();
    void loadMainMenu();
    void displayWeatherData();
};

#endif // UICONTROLLER_H
