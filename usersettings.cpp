#include "usersettings.h"
#include <iostream>
#include <vector>

UserSettings::UserSettings(){}

void UserSettings::loadUserSettingsMenu()
{

    std::cout << "\n" << "<<<USER SETTINGS>>>" << std::endl;
    std::cout << "1 - CHANGE DISPLAY UNITS" << std::endl;
    std::cout << "2 - SET WEATHER FORECAST DISPLAY RANGE" << std::endl;

    std::cout<<"choose: ";
    int choice;
    std::cin>>choice;
    switch(choice)
    {
        case 1:
            changeDisplayUnits();
            break;
        case 2:
            std::cout<<"choose day range: ";
            std::cin>>choice;
            dayRange = std::to_string(choice);


    }
}





void changeUnitHelperFuction(std::vector<std::string>& units, std::string& unit)
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


void UserSettings::changeDisplayUnits()
{
    std::cout<<" <<CURRENT SETTINGS>>" <<std::endl;
    std::cout<<"1 - Temperature Unit: "<<currentTemperatureUnit<<std::endl;
    std::cout<<"2 - Wind Speed Unit: "<<currentWindSpeedUnit<<std::endl;
    std::cout<<"3 - Percipitation Units: "<<currentPercipitationUnit<<std::endl;


    std::cout<<"What unit do you want to change: ";

    int choice;
    std::cin>>choice;

    switch(choice)
    {
        case 1:
            changeUnitHelperFuction(temperatureUnits,currentTemperatureUnit);
            break;
        case 2:
            changeUnitHelperFuction(windSpeedUnits,currentWindSpeedUnit);
            break;
        case 3:
            changeUnitHelperFuction(percipitationUnits,currentPercipitationUnit);
            break;

    }




}


