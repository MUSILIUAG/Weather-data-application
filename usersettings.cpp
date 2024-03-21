#include "usersettings.h"
#include <iostream>
#include <vector>

UserSettings::UserSettings(){}

void UserSettings::loadUserSettingsMenu()
{

    std::cout << "\n" << "<<<USER SETTINGS>>>" << std::endl;
    std::cout << "1 - CHANGE DISPLAY UNITS" << std::endl;
    std::cout << "2 - SET WEATHER FORECAST DISPLAY RANGE" << std::endl;
    std::cout << "3 - SET HISTORICAL FORECAST DISPLAY RANGE" << std::endl;
    std::cout << "4 - EXIT" << std::endl;

    std::cout<<"choose: ";
    int choice;
    std::cin>>choice;
    switch(choice)
    {
        case 1:
            changeDisplayUnits();
            break;
        case 2:
<<<<<<< HEAD
            setDayRange();
            break;
=======
            std::cout<<"choose day range: ";
            std::cin>>choice;
            dayRange = std::to_string(choice); //changes day range to what the user types in
            startDate="";
            endDate="";
>>>>>>> b9ef956ed2f28bf2688b9187f845c0c48dc1ae7b
        case 3:
            setHistoricalDataRange();
            break;
        case 4:
            //Exit menu
            break;
        default:
            std::cout << "Invalid command. Please Try again \n" << std::endl;
            loadUserSettingsMenu();
            break;


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
    std::cout<<"4 - NONE (exit menu)"<<std::endl;



    std::cout<<"What unit do you want to change: ";

    int choice;
    std::cin>>choice;

    switch(choice)
    {
        case 1:
            changeUnitHelperFuction(temperatureUnits,currentTemperatureUnit);
            changeDisplayUnits();
            break;
        case 2:
            changeUnitHelperFuction(windSpeedUnits,currentWindSpeedUnit);
            changeDisplayUnits();
            break;
        case 3:
            changeUnitHelperFuction(percipitationUnits,currentPercipitationUnit);
            changeDisplayUnits();
            break;
        case 4:
            //Exit menu
            break;
        default:
            std::cout << "Invalid command. Please Try again \n" << std::endl;
            changeDisplayUnits();
            break;

    }
}

void UserSettings::setDayRange()
{
    std::cout<<"choose day range: ";
    std::string userDayRangeInput;
    std::cin>>userDayRangeInput;

    dayRange = userDayRangeInput; //changes day range to what the user types in

    startDate=""; // reset the start and end dates to the default to make sure only one weather period setting can be set
    endDate="";
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
    dayRange = "1"; //reset the day range back to the default


}

