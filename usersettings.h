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
    std::string startDate = "2024-03-17";
    std::string endDate = "2024-03-19";



    UserSettings();
    void loadUserSettingsMenu();
    void changeDisplayUnits();
};

#endif // USERSETTINGS_H
