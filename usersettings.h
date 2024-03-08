#ifndef USERSETTINGS_H
#define USERSETTINGS_H
#include <string>
#include <vector>


class UserSettings
{
public:
    std::vector<std::string> temperatureUnits {"celsius","fahrenheit"};
    std::vector<std::string> windSpeedUnits {"kmh","ms","mph","knots"};
    std::vector<std::string> percipitationUnits {"mm","inch"};



    std::string currentTemperatureUnit = "celsius";
    std::string currentWindSpeedUnit = "kmh";
    std::string currentPercipitationUnit = "mm";
    std::string dayRange = "1";



    UserSettings();
    void loadUserSettingsMenu();
    void changeDisplayUnits();
};

#endif // USERSETTINGS_H
