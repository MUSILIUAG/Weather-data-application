#include "airqualitydatamanager.h"
#include <iostream>

AirQualityDataManager::AirQualityDataManager()
{
    url = "https://api.open-meteo.com/v1/forecast?latitude=" + userSettings.latitudeAsString + "&longitude=" + userSettings.longitudeAsString +
          "&hourly="+userSettings.userSelections +
          "&daily=&temperature_unit="+ userSettings.currentTemperatureUnit +"&wind_speed_unit="+ userSettings.currentWindSpeedUnit +
          "&precipitation_unit="+userSettings.currentPercipitationUnit+"&forecast_days=2";
}




