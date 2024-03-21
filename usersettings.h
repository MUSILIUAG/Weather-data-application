#ifndef USERSETTINGS_H
#define USERSETTINGS_H
#include <string>
#include <vector>


class UserSettings
{
public:
    std::vector<std::string> temperatureUnits {"celsius","fahrenheit"};
    std::vector<std::string> windSpeedUnits {"kmh","ms","mph","kn"};
    std::vector<std::string> percipitationUnits {"mm","inch"};



    std::string currentTemperatureUnit = "celsius";
    std::string currentWindSpeedUnit = "kmh";
    std::string currentPercipitationUnit = "mm";
    std::string dayRange = "1";
    std::string startDate = "";
    std::string endDate = "";


    std::string userSelections;//comma separated list of weather variables
    std::vector<std::string> userSelcetionVec; //vector list of weather variables



    UserSettings();
    void loadUserSettingsMenu();
    void changeDisplayUnits();
    void setDayRange();
    void setHistoricalDataRange();
};

#endif // USERSETTINGS_H
