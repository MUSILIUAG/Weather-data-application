#include "uicontroller.h"
#include "debugaid.h"
#include "apicontroller.h"
#include "locationmanager.h"
#include <iostream>

APIController api;
locationManager location;

UIcontroller::UIcontroller(){}

void UIcontroller::start()
{
    std::cout << "<<<MAIN MENU>>>" << std::endl;
    std::cout << "1 - LOCATION QUERIES" << std::endl;
    std::cout << "2 - DISPLAY WEATHER FORECAST" << std::endl;
    std::cout << "3 - EXIT" << std::endl;

    int choice;
    std::cout << "choose between 1 and 3: ";
    std::cin >> choice;

    if (choice == 1) {
        location.addLocation();
        start();
    } else if (choice == 2) {
        for (const auto& loc : location.Location) {
            std::cout << loc.first << std::endl;
        }

        std::string locationName;
        std::cin >> locationName;

        api.fetchWeatherData(location.Location[locationName][0]);
    } else if (choice == 3) {
        // Do nothing or exit the program
    } else {
        std::cout << "Invalid command. Please Try again \n" << std::endl;
        start();
    }
}
