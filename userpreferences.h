#ifndef USERPREFERENCES_H
#define USERPREFERENCES_H
#include <string>
#include <vector>


class UserPreferences
{
public:
    std::vector<std::string> temperatureUnits {"celsius","fahrenheit"};
    std::vector<std::string> windSpeedUnits {"kmh","ms","mph","kn"};
    std::vector<std::string> percipitationUnits {"mm","inch"};



    std::string currentTemperatureUnit = "celsius";
    std::string currentWindSpeedUnit = "kmh";
    std::string currentPercipitationUnit = "mm";
    std::string dayRange = "1";

    std::string startDate = "2022-11-12";
    std::string endDate = "2022-11-14";




    std::pair<double, double>geocoordinates;
    std::string latitudeAsString;
    std::string longitudeAsString;

    std::string userVariablesStr;//comma separated list of weather variables
    std::vector<std::string> userVariablesVec; //vector list of weather variables

    std::string hourlyOrDaily = "";
    std::string solarTiltAndAzimuth = "";

    std::vector<std::string> modelVec;
    std::string modelStr;
    int option;




    UserPreferences();
    void loadUserSettingsMenu();
    void changedisplayUnit(std::vector<std::string>& units, std::string& unit);
    void setDayRange();
    void setHistoricalDataRange();
    void changeCurrentSettings();
};

#endif // USERPREFERENCES_H
