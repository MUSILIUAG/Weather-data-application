#include "userpreferences.h"
#include <iostream>
#include <vector>
#include "utility.h"



UserPreferences::UserPreferences(){}












void UserPreferences::loadUserSettingsMenu()
{
    std::cout<<" <<CURRENT SETTINGS>>" <<std::endl;
    std::cout<<"1 - Temperature Unit: "<<currentTemperatureUnit<<std::endl;
    std::cout<<"2 - Wind Speed Unit: "<<currentWindSpeedUnit<<std::endl;
    std::cout<<"3 - Percipitation Units: "<<currentPercipitationUnit<<std::endl;
    std::cout<<"4 - Time Zone: "<<currentTimeZone<<std::endl;
    std::cout<<"5 - Day Range: "<<dayRange<<std::endl;
    std::cout<<"6 - Historical data:  Start Date: "<<startDate<<", End date: " <<endDate<<std::endl;
    std::cout<<"7 - Air Quality Domain: "<<currentDomain<<std::endl;
    std::cout<<"8 - NONE (exit menu)"<<std::endl;

    changeCurrentSettings();
}



void UserPreferences::changeCurrentSettings()
{
    std::cout<<"What unit do you want to change: ";

    int userChoice = Utility::getIntegerInput();
    switch(userChoice)
    {
        case 1:
            changedisplayUnit(allUnits.temperatureUnits,currentTemperatureUnit);
            loadUserSettingsMenu();
            break;
        case 2:
            changedisplayUnit(allUnits.windSpeedUnits,currentWindSpeedUnit);
            loadUserSettingsMenu();
            break;
        case 3:
            changedisplayUnit(allUnits.percipitationUnits,currentPercipitationUnit);
            loadUserSettingsMenu();
            break;
        case 4:
            changedisplayUnit(allUnits.timeZones,currentTimeZone);
            loadUserSettingsMenu();
            break;
        case 5:
            setDayRange();
            loadUserSettingsMenu();
            break;
        case 6:
            setHistoricalDataRange();
            loadUserSettingsMenu();
            break;
        case 7:
            changedisplayUnit(allUnits.domains,currentDomain);
            loadUserSettingsMenu();
            break;
        case 8:
            //Exit menu
            break;
        default:
            std::cout << "Invalid command. Please Try again \n" << std::endl;
            changeCurrentSettings();
            break;

    }
}





void UserPreferences::changedisplayUnit(std::vector<std::string>& units, std::string& unit)
{
    std::cout<<" <<AVAILABLE UNIT>>" <<std::endl;
    for(unsigned int i = 1; i <= units.size(); i++)
    {
        std::cout<< i << " - " << units[i-1]<<std::endl; //print out available units
    }




    unsigned int userChoice = Utility::getIntegerInput();

    // Check if the choice is within the valid range
    if (userChoice >= 1 && userChoice <= units.size()) {
           unit = units[userChoice - 1];
    }
    else {
        std::cout << "Invalid choice!" << std::endl;
        changedisplayUnit(units,unit);
    }




}


void UserPreferences::setDayRange()
{
    std::cout<<"choose day range"<<std::endl;
    int userChoice;

    do
    {
        std::cout<<"Make Sure Day is within 0 - 16"<<"\n"<<std::endl;
        std::cout<<"Day"<<std::endl;
        userChoice = Utility::getIntegerInput();
    } while (!Utility::isWithinRange(userChoice,0,16));


    dayRange = std::to_string(userChoice); //changes day range to what the user types in
}

void UserPreferences::setHistoricalDataRange() {
    std::string userStartDateInput, userEndDateInput;

    do {
        std::cout << "Date format: yyyy-mm-dd" << std::endl;
        std::cout << "Choose start date: ";
        std::cin >> userStartDateInput;
    } while (!Utility::isValidDateFormat(userStartDateInput));

    do {
        std::cout << "Choose end date: ";
        std::cin >> userEndDateInput;
    } while (!Utility::isValidDateFormat(userEndDateInput));

    startDate = userStartDateInput;
    endDate = userEndDateInput;
}

