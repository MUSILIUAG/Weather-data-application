#include "mainmenu.h"
#include "weatherdatamanager.h"
#include "locationmanager.h"
#include "userpreferences.h"
#include "airqualitydatamanager.h"
#include "datamanager.h"
#include "historicalweatherdatamanager.h"
#include "apicontroller.h"
#include <iostream>

LocationManager location;
UserPreferences userSettings;
WeatherDataManager weatherdata;
AirQualityDataManager airQualityData;
HistoricalWeatherDataManager historicalWeatherData;




MainMenu::MainMenu(){}

void MainMenu::loadMainMenu()
{
    std::cout << "\n" << "<<<MAIN MENU>>>" << std::endl;
    std::cout << "1 - LOCATION QUERIES" << std::endl;
    std::cout << "2 - DISPLAY WEATHER FORECAST" << std::endl;
    std::cout << "3 - DISPLAY HISTORICAL WEATHER FORECAST" << std::endl;
    std::cout << "4 - DISPLAY AIR QUALITY DATA" << std::endl;
    std::cout << "5 - USER SETTINGS" << std::endl;
    std::cout << "6 - EXIT" << std::endl;
    navToSelectedMenu();
}


void MainMenu::navToSelectedMenu()
{
    std::cout <<"\n"<< "choose between 1 and 6: ";
    int choice;
    if (!(std::cin >> choice)) {
            std::cin.clear(); // clear the failbit
            std::cin.ignore(256, '\n'); // discard invalid input
            std::cerr << "Invalid input. Please enter an integer." << std::endl;
            loadMainMenu();
            return;
        }

    if (location.Location.empty() && (choice > 1 && choice < 4))
    {
        std::cout <<"\n"<<" << You have Saved locations (Click 1 for Location Queries) >>";
        loadMainMenu();
        return;

    }

    userSettings.option = choice;
    switch(choice)
    {
        case 1:
            location.loadLocationMenu();
            loadMainMenu();
            break;
        case 2:
            weatherdata.loadDataMenu();
            loadMainMenu();
            break;
        case 3:
            historicalWeatherData.loadDataMenu();
            loadMainMenu();
            break;
        case 4:
            airQualityData.loadDataMenu();
            loadMainMenu();
            break;
        case 5:
            userSettings.loadUserSettingsMenu();
            loadMainMenu();
            break;
        case 6:
            //Exit the program
            break;
        default:
            std::cout << "Invalid command. Please Try again \n" << std::endl;
            loadMainMenu();
            break;
    }
}


