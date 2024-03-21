#include "weatherdatamanager.h"
#include "usersettings.h"

extern UserSettings userSettings;
WeatherDataManager::WeatherDataManager()
{
    // uses the users settings to make to specify if to use days to specify or if to use range for historical data
    if(userSettings.startDate == "")//checks if the user has any saved range settings
    {
        url = "https://api.open-meteo.com/v1/forecast?latitude=" + userSettings.latitudeAsString + "&longitude=" + userSettings.longitudeAsString +
                "&hourly="+userSettings.userSelections +
                "&daily=&temperature_unit="+ userSettings.currentTemperatureUnit +"&wind_speed_unit="+ userSettings.currentWindSpeedUnit +
                "&precipitation_unit="+userSettings.currentPercipitationUnit+"&forecast_days="+userSettings.dayRange;
    }
    else{
        url = "https://archive-api.open-meteo.com/v1/archive?latitude=" + userSettings.latitudeAsString + "&longitude=" + userSettings.longitudeAsString +
                "&start_date="+userSettings.startDate+"&end_date="+userSettings.endDate +
                "&hourly="+ userSettings.userSelections + ",is_day" +
                "&temperature_unit="+ userSettings.currentTemperatureUnit +"&wind_speed_unit="+ userSettings.currentWindSpeedUnit +
                "&precipitation_unit="+userSettings.currentPercipitationUnit;
    }
}
