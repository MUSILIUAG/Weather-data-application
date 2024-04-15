#include "airqualitydatamanager.h"
#include <iostream>
#include "utility.h"


AirQualityDataManager::AirQualityDataManager()
{}


std::string AirQualityDataManager::getUrl() const
{

    return "https://air-quality-api.open-meteo.com/v1/air-quality?latitude=" +
                userSettings.latitudeAsString + "&longitude=" + userSettings.longitudeAsString +
                userSettings.userVariablesStr + "&forecast_days="+userSettings.dayRange +
                "&domains="+userSettings.currentDomain;
}

void AirQualityDataManager::handleEuropeanAirqualityVariables() const
{
    std::cout<<"European Air Quality"<<std::endl;
    handleVariableSelections(airQualityVariables.europeanAirQualityVariables);
}


std::vector<std::pair<std::string, std::string>> AirQualityDataManager::getVariables() const{
 return airQualityVariables.hourlyVariables;
}


void AirQualityDataManager::handleVariableSelections(std::vector<std::pair<std::string, std::string>> allVariables) const
{

        std::vector<std::string>KeyVector;
        KeyVector = handleKeySelection(allVariables);

        std::pair<std::string, std::string> keyToPair;

        for(auto& keyVect : KeyVector)
        {

            keyToPair = allVariables[std::stoi(keyVect)-1];

                if(keyToPair.first == "European AirQuality Index" )
                {
                    handleEuropeanAirqualityVariables();
                }

            if (keyToPair.second != "Special Variable with Extra selection")
            {
                userSettings.userVariablesVec.push_back(keyToPair.second);
            }

        }

        std::string temp = Utility::vectorToString(userSettings.userVariablesVec);
        if(!temp.empty()) userSettings.userVariablesStr = "&hourly=" + temp;

}



