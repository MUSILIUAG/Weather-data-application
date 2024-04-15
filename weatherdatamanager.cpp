#include "weatherdatamanager.h"
#include "userpreferences.h"
#include "iostream"
#include "utility.h"


extern UserPreferences userSettings;

WeatherDataManager::WeatherDataManager(){}

std::string WeatherDataManager::getUrl() const {
        return "https://api.open-meteo.com/v1/forecast?latitude=" + userSettings.latitudeAsString + "&longitude=" + userSettings.longitudeAsString +
                userSettings.userVariablesStr + userSettings.modelStr +
                "&temperature_unit="+ userSettings.currentTemperatureUnit +"&wind_speed_unit="+ userSettings.currentWindSpeedUnit +
                "&precipitation_unit="+userSettings.currentPercipitationUnit+"&forecast_days="+userSettings.dayRange +
                userSettings.solarTiltAndAzimuth + "&timezone=" + userSettings.currentTimeZone;
}

std::vector<std::pair<std::string, std::string>> WeatherDataManager::getVariables() const{

if (setHourlyOrDaily() == "hourly")return weatherVariables.hourlyVariables;
else return weatherVariables.dailyVariables;
}



void WeatherDataManager::handleVariableSelections(std::vector<std::pair<std::string, std::string>> allVariables) const
{

        std::vector<std::string>KeyVector;
        KeyVector = handleKeySelection(allVariables);

        std::pair<std::string, std::string> keyToPair;

        for(auto& keyVect : KeyVector)
        {

            keyToPair = allVariables[std::stoi(keyVect)-1];

                if(keyToPair.first == "Additional Variables" )
                {
                    handleAdditionalVariables();
                }
                else if(keyToPair.first == "Solar Radiaton Variables" )
                {
                    handleSolar();
                    continue;
                }
                else if(keyToPair.first == "Pressure Variables" )
                {
                    handlePressure();
                    continue;
                }
                else if(keyToPair.first == "Weather Models" )
                {
                    handleWeatherModels();
                    continue;
                }


            if (keyToPair.second != "Special Variable with Extra selection")
            {
                userSettings.userVariablesVec.push_back(keyToPair.second);
            }

        }

        std::string temp = Utility::vectorToString(userSettings.userVariablesVec);
        if(!temp.empty()) userSettings.userVariablesStr = "&" + userSettings.hourlyOrDaily + "=" + temp;
}


void WeatherDataManager::handlePressure() const
{

    std::vector<std::string> selectedDomains = handleKeySelection(weatherVariables.pressureLevelDomain);
    std::vector<std::string> selectedPressureLevels = handleKeySelection(weatherVariables.pressureLevel);

    for(auto& dom : selectedDomains){
        for(auto& press : selectedPressureLevels){
            userSettings.userVariablesVec.push_back(weatherVariables.pressureLevelDomain[std::stoi(dom)-1].second +
                              weatherVariables.pressureLevel[std::stoi(press)-1].second);
        }
    }



}

void WeatherDataManager::handleAdditionalVariables() const
{
    std::cout<<"Weather Models"<<std::endl;
    handleVariableSelections(weatherVariables.additionalVariables);
}



void WeatherDataManager::handleWeatherModels() const
{
    std::cout<<"Weather Models"<<std::endl;

    std::vector<std::string>KeyVector;
    KeyVector = handleKeySelection(weatherVariables.weatherModels);

    std::pair<std::string, std::string> keyToPair;

    for(auto& keyVect : KeyVector)
    {
        keyToPair = weatherVariables.weatherModels[std::stoi(keyVect)-1];
        userSettings.modelVec.push_back(keyToPair.second);
    }

    std::string temp = Utility::vectorToString(userSettings.modelVec);
    if(!temp.empty()) userSettings.modelStr = "&models=" + temp;
}


void WeatherDataManager::handleSolar() const
{
std::cout<<"Solar Radiation Variables"<<std::endl;

handleVariableSelections(weatherVariables.solarVariables);


double tilt;
do
{
    std::cout<<"Make Sure its within 0 - 90"<<"\n"<<std::endl;
    std::cout<<"Tilt"<<std::endl;
    tilt = Utility::getDoubleInput();
} while (!Utility::isWithinRange(tilt,0.0,90.0));



std::cout<<"Azimuth"<<std::endl;
double azimuth;
do
{
    std::cout<<"Make Sure its within -90 - 90"<<"\n"<<std::endl;
    std::cout<<"Azimuth"<<std::endl;
    azimuth = Utility::getDoubleInput();
} while (!Utility::isWithinRange(azimuth,-90.0,90.0));



userSettings.solarTiltAndAzimuth = "&tilt=" + std::to_string(tilt) +"&azimuth=" + std::to_string(azimuth);
}





