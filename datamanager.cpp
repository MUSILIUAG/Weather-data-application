#include "datamanager.h"
#include "apicontroller.h"
#include "locationmanager.h"
#include "userpreferences.h"
#include "airqualitydatamanager.h"
#include "weatherdatamanager.h"
#include "historicalweatherdatamanager.h"
#include <set>
#include <algorithm>

APIController api;
extern LocationManager location;
extern UserPreferences userSettings;


extern WeatherDataManager weatherdata;
extern AirQualityDataManager airQualityData;
extern HistoricalWeatherDataManager historicalWeatherData;


DataManager* ptr;



DataManager::DataManager(){}

void DataManager::loadDataMenu()
{

    std::cout <<"\n"<< "<<<DISPLAY FORECAST>>>" << std::endl;

    std::cout <<"\n"<<"DISCLAIMER:  All day ranges and start to end dates for historical data are Default values go to settings to change them"<<std::endl;

    std::cout<<"1 - HOURLY WEATHER VARIBLES"<<std::endl;
    std::cout<<"2 - DAILY WEATHER VARIABLES"<<std::endl;

    setHourlyOrDaily();
}

void DataManager::setHourlyOrDaily(){
    std::cout<<"1 or 2: ";
    int choice;
    std::cin>>choice;

    switch(choice){
    case 1:
        userSettings.hourlyOrDaily = "hourly";
        break;
    case 2:
        userSettings.hourlyOrDaily = "daily";
        break;
    default:
        std::cout << "Invalid command. Please Try again \n" << std::endl;
        setHourlyOrDaily();
        break;
    }
    printSavedLocation();
}

void DataManager::printSavedLocation(){
    if(!location.Location.empty()) std::cout <<"\n"<< "SAVED LOCATIONS" << std::endl;
    for (const auto& loc : location.Location) // prints out all saved locations
    {
        std::cout << "Locaton name: "<<loc.first << std::endl;
    }
    idkk();
}

void DataManager::idkk()
{
    std::cout << "Type location name: ";
    std::string locationName;
    std::cin >> locationName;

    std::pair<double, double>geocoordinates = location.Location[locationName][0];
    userSettings.latitudeAsString = std::to_string(geocoordinates.first);
    userSettings.longitudeAsString = std::to_string(geocoordinates.second);



    std::vector<std::pair<std::string, std::string>> Variables;

    switch(userSettings.option)
    {
        case 2:
        ptr = &weatherdata;
        break;
        case 3:
        ptr = &historicalWeatherData;
        break;
        case 4:
        ptr = &airQualityData;
        break;
    }


    Variables = ptr->getVariables();
    handleVariableSelections(Variables);

    getData();
    displayData(userSettings.hourlyOrDaily);
}






std::string vectorToString(std::vector<std::string> vector)
{
    std::ostringstream oss;

    for (size_t i = 0; i < vector.size(); ++i) {
        if (i > 0) {
            oss << ",";
        }
        oss << vector[i]; // Adds only the  code
    }
    return oss.str(); // Returns the comma-separated string
}


std::vector<std::string> stringArrayToVec(std::string choice){
    std::istringstream iss(choice); //Gets the string array from the user

    std::string key;
    std::vector<std::string> keyToKeyVector;

    // adds the values to a vector
    while (std::getline(iss, key, ',')) {
        keyToKeyVector.push_back(key);
    }

    std::sort(keyToKeyVector.begin(), keyToKeyVector.end());
    return keyToKeyVector;

}



std::vector<std::string> handleKeySelection(std::vector<std::pair<std::string, std::string>> allVariables)
{
    for (unsigned long i=1; i <= allVariables.size(); i++)
    {
        std::cout<<i<<" - "<<allVariables[i-1].first<<std::endl;
    }
        std::cout<< "choose weather variables you want displayed: ";
        std::string choice;
        std::cin>>choice;

        return stringArrayToVec(choice);
}





void DataManager::handleVariableSelections(std::vector<std::pair<std::string, std::string>> allVariables)
{

        std::vector<std::string>KeyVector;
        KeyVector = handleKeySelection(allVariables);

        std::pair<std::string, std::string> keyToPair;

        Variables variables;
        for(auto& keyVect : KeyVector)
        {

            keyToPair = allVariables[std::stoi(keyVect)-1];

                if(keyToPair.first == "Solar Radiaton Variables" )
                {
                handleSolar(variables.solarVariables);
                continue;
                }
                else if(keyToPair.first == "Pressure Variables" )
                {
                 handlePressure();
                 continue;
                }
                else if(keyToPair.first == "Weather Models" )
                {
                    handleWeatherModels(variables.WeatherModels);
                }
                else if(keyToPair.first == "Reanalysis Models" )
                {
                    handleWeatherModels(variables.reanalysisModels);
                }


            if (keyToPair.second != "Special Variable with Extra selection" &&
                    std::find(variables.WeatherModels.begin(),variables.WeatherModels.end(),keyToPair) == variables.WeatherModels.end()&&
                    std::find(variables.reanalysisModels.begin(),variables.reanalysisModels.end(),keyToPair) == variables.reanalysisModels.end()
               )
            {
                userSettings.userVariablesVec.push_back(keyToPair.second);
            }
            else if(keyToPair.second != "Special Variable with Extra selection")
            {
                userSettings.modelVec.push_back(keyToPair.second);
            }

        }


        userSettings.userVariablesStr = vectorToString(userSettings.userVariablesVec);
        std::string temp = vectorToString(userSettings.modelVec);

        if(!temp.empty()) userSettings.modelStr = "&models=" + temp;

}















void DataManager::handleSolar(std::vector<std::pair<std::string, std::string>>solarVariables)
{
std::cout<<"Solar Radiation Variables"<<std::endl;

handleVariableSelections(solarVariables);

std::string tilt;
std::string azimuth;

std::cout<<"Tilt: ";
std::cin >> tilt;
std::cout<<"Azimuth: ";

std::cin>>azimuth;
userSettings.solarTiltAndAzimuth = "&tilt=" + tilt +"&azimuth=" + azimuth;
}


void DataManager::handleWeatherModels(std::vector<std::pair<std::string, std::string>> weatherModels)
{
    std::cout<<"Weather Models"<<std::endl;
    handleVariableSelections(weatherModels);
}


void DataManager::handleReanalysisModels(std::vector<std::pair<std::string, std::string>> reanalysisModels)
{
    std::cout<<"Reanalysis Models"<<std::endl;
    handleVariableSelections(reanalysisModels);
}

void DataManager::handlePressure()
{
    std::vector<std::pair<std::string, std::string>> Domain {
        {"Temperature", "temperature_"},
        {"Relative Humidity", "relative_humidity_"},
        {"Cloud cover","cloud_cover_"},
        {"Wind speed","wind_speed_"},
        {"Wind Direction", "wind_direction_"},
        {"Geopontential Height","geopotential_height_"}
    };

    std::vector<std::pair<std::string, std::string>> PressureLevel {
    {"1000 hPa (110 m)", "1000hPa"},
    {"975 hPa (320 m)", "975hPa"},
    {"950 hPa (500 m)", "950hPa"},
    {"925 hPa (800 m)", "925hPa"},
    {"900 hPa (1000 m)", "900hPa"},
    {"850 hPa (1500 m)", "850hPa"},
    {"800 hPa (1900 m)", "800hPa"},
    {"700 hPa (3 km)", "700hPa"},
    {"600 hPa (4.2 km)", "600hPa"},
    {"500 hPa (5.6 km)", "500hPa"},
    {"400 hPa (7.2 km)", "400hPa"},
    {"300 hPa (9.2 km)", "300hPa"},
    {"250 hPa (10.4 km)", "250hPa"},
    {"200 hPa (11.8 km)", "200hPa"},
    {"150 hPa (13.5 km)", "150hPa"},
    {"100 hPa (15.8 km)", "100hPa"},
    {"70 hPa (17.7 km)", "70hPa"},
    {"50 hPa (19.3 km)", "50hPa"},
    {"30 hPa (22 km)", "30hPa"}
    };

    std::vector<std::string> doma = handleKeySelection(Domain);
    std::vector<std::string> prejure = handleKeySelection(PressureLevel);

    for(auto& i : doma){
        for(auto& j:prejure){
            userSettings.userVariablesVec.push_back(Domain[std::stoi(i)-1].second + PressureLevel[std::stoi(j)-1].second);
        }
    }



}


void DataManager::getData()
{

    std::string url;

    switch(userSettings.option)
    {
        case 2:
        ptr = &weatherdata;
        break;
        case 3:
        ptr = &historicalWeatherData;
        break;
        case 4:
        ptr = &airQualityData;
        break;
    }

    url = ptr->getUrl();
    DataJson = api.fetchJsonData(url);
    std::cout<<url<<std::endl;
}




void DataManager::displayData(std::string hourlyOrDaily)
{
    const auto& hourlyOrDailyKey = DataJson[hourlyOrDaily];
    const auto& timeKeyValue = hourlyOrDailyKey["time"];
    int forecastDays = 1;
        std::string dielCycle;

        for(unsigned int i = 0; i < timeKeyValue.size(); i++)
        {
            if((i == 0 || i%24 == 0) && hourlyOrDaily == "hourly" )
            {
                std::cout<<"\n"<<"<<<<<<<<<<<<< DAY "<<forecastDays<<" >>>>>>>>>>>>>"<<std::endl; // Prints out what days forecast is being displayed
                forecastDays++; //changes the day to the next day
            }

            std::cout<< "\n" << "Time: "<<timeKeyValue[i].asString()<<std::endl; // prints the time

            const auto& dataUnits = DataJson[hourlyOrDaily + "_units"];

                // Process each key-value pair in the nested JSON object
                for (const auto& item : hourlyOrDailyKey.getMemberNames()) {
                    if (item != "time" && item.find("is_day")==std::string::npos) {
                        std::cout << item << ": " << hourlyOrDailyKey[item][i].asDouble() << dataUnits[item].asString() << std::endl;
                    } else if (item.find("is_day")!=std::string::npos) {
                        std::string dielCycle = (hourlyOrDailyKey[item][i].asString() == "1") ? "Day" : "Night";
                        std::cout << item << ": " <<dielCycle << std::endl;
                    }
                }
            }
                userSettings.userVariablesVec.clear();
                userSettings.userVariablesStr.clear();
                userSettings.modelVec.clear();
}


