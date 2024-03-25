#include "usersettings.h"
#include <iostream>
#include <vector>

UserSettings::UserSettings(){}












void UserSettings::loadUserSettingsMenu()
{
    std::cout<<" <<CURRENT SETTINGS>>" <<std::endl;
    std::cout<<"1 - Temperature Unit: "<<currentTemperatureUnit<<std::endl;
    std::cout<<"2 - Wind Speed Unit: "<<currentWindSpeedUnit<<std::endl;
    std::cout<<"3 - Percipitation Units: "<<currentPercipitationUnit<<std::endl;
    std::cout<<"4 - Day Range: "<<dayRange<<std::endl;
    std::cout<<"5 - Historical data:  Start Date: "<<startDate<<", End date: " <<endDate<<std::endl;
    std::cout<<"6 - NONE (exit menu)"<<std::endl;

    changeCurrentSettings();
}



void UserSettings::changeCurrentSettings()
{
    std::cout<<"What unit do you want to change: ";

    int choice;
    std::cin>>choice;

    switch(choice)
    {
        case 1:
            changedisplayUnit(temperatureUnits,currentTemperatureUnit);
            loadUserSettingsMenu();
            break;
        case 2:
            changedisplayUnit(windSpeedUnits,currentWindSpeedUnit);
            loadUserSettingsMenu();
            break;
        case 3:
            changedisplayUnit(percipitationUnits,currentPercipitationUnit);
            loadUserSettingsMenu();
            break;
        case 4:
            setDayRange();
            loadUserSettingsMenu();
            break;
        case 5:
            setHistoricalDataRange();
            loadUserSettingsMenu();
        case 6:
            //Exit menu
            break;
        default:
            std::cout << "Invalid command. Please Try again \n" << std::endl;
            changeCurrentSettings();
            break;

    }
}





void UserSettings::changedisplayUnit(std::vector<std::string>& units, std::string& unit)
{
    std::cout<<" <<AVAILABLE UNIT>>" <<std::endl;
    for(unsigned int i = 1; i <= units.size(); i++)
    {
        std::cout<< i << " - " << units[i-1]<<std::endl; //print out available units
    }


    std::cout<<"choose: ";
    int choice;
    std::cin>>choice;

    unit = units[choice - 1];
}


void UserSettings::setDayRange()
{
    std::cout<<"choose day range: ";
    std::string userDayRangeInput;
    std::cin>>userDayRangeInput;

    dayRange = userDayRangeInput; //changes day range to what the user types in
}

void UserSettings::setHistoricalDataRange()
{


    std::cout<<"date format - yyyy-mm-dd"<<std::endl;
    std::cout<<"choose start date: ";
    std::string userStartDateInput;
    std::cin>>userStartDateInput;

    std::cout<<"choose end date: ";
    std::string userEndDateInput;
    std::cin>>userEndDateInput;

    startDate = userStartDateInput;
    endDate= userEndDateInput;
}

