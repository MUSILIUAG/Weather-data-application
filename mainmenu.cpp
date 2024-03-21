#include "mainmenu.h"
#include "weatherdatamanager.h"
#include "locationmanager.h"
#include "usersettings.h"
#include "airqualitydatamanager.h"
#include <iostream>

LocationManager location;
UserSettings userSettings;
WeatherDataManager data;
AirQualityDataManager airQualityData;



mainMenu::mainMenu(){}

void mainMenu::loadMainMenu()
{
    std::cout << "\n" << "<<<MAIN MENU>>>" << std::endl;
    std::cout << "1 - LOCATION QUERIES" << std::endl;
    std::cout << "2 - DISPLAY WEATHER FORECAST" << std::endl;
<<<<<<< HEAD:mainmenu.cpp
    std::cout << "3 - DISPLAY AIR QUALITY DATA" << std::endl;
    std::cout << "4 - USER SETTINGS" << std::endl;
    std::cout << "5 - EXIT" << std::endl;
=======
    std::cout << "3 - USER SETTINGS" << std::endl;
    std::cout << "4 - EXIT" << std::endl;
>>>>>>> b9ef956ed2f28bf2688b9187f845c0c48dc1ae7b:uicontroller.cpp

    int choice;
    std::cout <<"\n"<< "choose between 1 and 5: ";
    std::cin >> choice;

    switch(choice)
    {
        case 1:
            location.loadLocationMenu();
            loadMainMenu();
            break;

        case 2:
            data.loadDataMenu();
            loadMainMenu();
            break;
        case 3:
            airQualityData.loadDataMenu();
            loadMainMenu();
            break;
        case 4:
            userSettings.loadUserSettingsMenu();
            loadMainMenu();
            break;
        case 5:

            break; //Exit the program

        default:
            std::cout << "Invalid command. Please Try again \n" << std::endl;
            loadMainMenu();
            break;
    }
}


