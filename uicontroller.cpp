#include "uicontroller.h"
#include "debugaid.h"
#include "apicontroller.h"
#include <iostream>

APIController api;

UIcontroller::UIcontroller(){}

void UIcontroller::start()
{
    std::cout<<"<<<MAIN MENU>>>"<<std::endl;
    std::cout<<"1 - LOCATION QUERIES"<<std::endl;
    std::cout<<"2 - EXIT"<<std::endl;

    int choice;
    std::cout<<"choose between 1 and 3: ";
    std::cin>>choice;

    switch(choice)
    {
    case 1:
        api.fetchWeatherData();
        break;
    case 2:

        break;
    default:
        std::cout<<"Invalid command. Please Try again \n"<<std::endl;
        start();
        break;

    }

}

void UIcontroller::addLocation()
{

}




