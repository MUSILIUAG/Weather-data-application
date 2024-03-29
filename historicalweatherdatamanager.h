#ifndef HISTORICALWEATHERDATAMANAGER_H
#define HISTORICALWEATHERDATAMANAGER_H
#include "datamanager.h"
#include "usersettings.h"

extern UserSettings userSettings;

class HistoricalWeatherDataManager:public DataManager
{
public:


    std::string getUrl() const override;
    std::vector<std::pair<std::string, std::string>> getVariables() const override;

    void setVariables();



    HistoricalWeatherDataManager();

private:
    struct hourlyVariables
    {
        std::vector<std::pair<std::string, std::string>> variables {
            {"Temperature","temperature_2m"},
            {"Relative Humidity","relative_humidity_2m"},
            {"Dew Point","dew_point_2m"},
            {"Apparent Temperature","apparent_temperature"},
            {"Precipitation","precipitation"},
            {"Rain","rain"},
            {"Snowfall","snowfall"},
            {"Snow Depth","snow_depth"},
            {"Weather Code","weather_code"},
            {"Pressure MSL","pressure_msl"},
            {"Surface Pressure","surface_pressure"},
            {"Cloud Cover","cloud_cover"},
            {"Low Cloud Cover","cloud_cover_low"},
            {"Mid Cloud Cover","cloud_cover_mid"},
            {"High Cloud Cover","cloud_cover_high"},
            {"ET0 FAO Evapotranspiration","et0_fao_evapotranspiration"},
            {"Vapour Pressure Deficit","vapour_pressure_deficit"},
            {"Wind Speed (10 m)","wind_speed_10m"},
            {"Wind Speed (100 m)","wind_speed_100m"},
            {"Wind Direction (10 m)","wind_direction_10m"},
            {"Wind Direction (100 m)","wind_direction_100m"},
            {"Wind Gusts (10 m)","wind_gusts_10m"},
            {"Soil Temperature (0-7 cm)","soil_temperature_0_to_7cm"},
            {"Soil Temperature (7-28 cm)","soil_temperature_7_to_28cm"},
            {"Soil Temperature (28-100 cm)","soil_temperature_28_to_100cm"},
            {"Soil Temperature (100-255 cm)","soil_temperature_100_to_255cm"},
            {"Soil Moisture (0-7 cm)","soil_moisture_0_to_7cm"},
            {"Soil Moisture (7-28 cm)","soil_moisture_7_to_28cm"},
            {"Soil Moisture (28-100 cm)","soil_moisture_28_to_100cm"},
            {"Soil Moisture (100-255 cm)","soil_moisture_100_to_255cm"}
        };
    };
};

#endif // HISTORICALWEATHERDATAMANAGER_H
