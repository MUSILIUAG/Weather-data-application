#include "historicalweatherdatamanager.h"
#include "weatherdatamanager.h"
#include <iostream>
#include "utility.h"

extern WeatherDataManager weatherdata;



HistoricalWeatherDataManager::HistoricalWeatherDataManager(){}

std::string HistoricalWeatherDataManager::getUrl() const {
    return  "https://archive-api.open-meteo.com/v1/archive?latitude=" + userSettings.latitudeAsString + "&longitude=" + userSettings.longitudeAsString +
            "&start_date="+userSettings.startDate+"&end_date="+userSettings.endDate +
            userSettings.userVariablesStr + userSettings.modelStr +
            "&temperature_unit="+ userSettings.currentTemperatureUnit +"&wind_speed_unit="+ userSettings.currentWindSpeedUnit +
            "&precipitation_unit="+userSettings.currentPercipitationUnit +
            userSettings.solarTiltAndAzimuth + "&timezone=" + userSettings.currentTimeZone;
}



void HistoricalWeatherDataManager::handleVariableSelections(std::vector<std::pair<std::string, std::string>> allVariables) const
{

        std::vector<std::string>KeyVector;
        KeyVector = handleKeySelection(allVariables);

        std::pair<std::string, std::string> keyToPair;

        for(auto& keyVect : KeyVector)
        {

            keyToPair = allVariables[std::stoi(keyVect)-1];

                if(keyToPair.first == "Reanalysis Models" )
                {
                    handleReanalysisModels();
                    continue;
                }

            if (keyToPair.second != "Special Variable with Extra selection")
            {
                userSettings.userVariablesVec.push_back(keyToPair.second);
            }
            else if(keyToPair.first == "Solar Radiaton Variables" )
            {
                weatherdata.handleSolar();
                continue;
            }

        }



        std::string temp = Utility::vectorToString(userSettings.userVariablesVec);
        if(!temp.empty()) userSettings.userVariablesStr = "&" + userSettings.hourlyOrDaily + "=" + temp;


}




void HistoricalWeatherDataManager::handleReanalysisModels() const
{
    std::cout<<"Reanalysis Models"<<std::endl;

    std::vector<std::string>KeyVector;
    KeyVector = handleKeySelection(historicalWeather.reanalysisModels);

    std::pair<std::string, std::string> keyToPair;

    for(auto& keyVect : KeyVector)
    {
        keyToPair = historicalWeather.reanalysisModels[std::stoi(keyVect)-1];
        userSettings.modelVec.push_back(keyToPair.second);
    }

    std::string temp = Utility::vectorToString(userSettings.modelVec);
    if(!temp.empty()) userSettings.modelStr = "&models=" + temp;
}



std::vector<std::pair<std::string, std::string>> HistoricalWeatherDataManager::getVariables() const
{
    if (setHourlyOrDaily() == "hourly")return historicalWeather.hourlyVariables;
    else return historicalWeather.dailyVariables;
}
