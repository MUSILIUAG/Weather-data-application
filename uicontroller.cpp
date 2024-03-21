#include "uicontroller.h"
#include "weatherdatamanager.h"
#include "locationmanager.h"
#include "usersettings.h"
#include <iostream>

LocationManager location;
WeatherDataManager weatherData;
UserSettings userSettings;


UIcontroller::UIcontroller(){}

void UIcontroller::loadMainMenu()
{
    std::cout << "\n" << "<<<MAIN MENU>>>" << std::endl;
    std::cout << "1 - LOCATION QUERIES" << std::endl;
    std::cout << "2 - DISPLAY WEATHER FORECAST" << std::endl;
    std::cout << "3 - USER SETTINGS" << std::endl;
    std::cout << "4 - EXIT" << std::endl;

    int choice;
    std::cout <<"\n"<< "choose between 1 and 3: ";
    std::cin >> choice;

    switch(choice)
    {
        case 1:
            location.loadLocationMenu();
            loadMainMenu();
            break;

        case 2:
            weatherData.loadWeatherDataMenu();
            loadMainMenu();
            break;

        case 3:
            userSettings.loadUserSettingsMenu();
            loadMainMenu();
            break;
        case 4:

            break; //Exit the program

        default:
            std::cout << "Invalid command. Please Try again \n" << std::endl;
            loadMainMenu();
            break;
    }
}


