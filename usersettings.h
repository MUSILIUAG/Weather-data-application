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
<<<<<<< HEAD
    std::string startDate = "";
    std::string endDate = "";


    std::string userSelections;//comma separated list of weather variables
    std::vector<std::string> userSelcetionVec; //vector list of weather variables
=======
    std::string startDate = "2024-03-17";
    std::string endDate = "2024-03-19";
>>>>>>> b9ef956ed2f28bf2688b9187f845c0c48dc1ae7b



    UserSettings();
    void loadUserSettingsMenu();
    void changeDisplayUnits();
    void setDayRange();
    void setHistoricalDataRange();
};

#endif // USERSETTINGS_H
