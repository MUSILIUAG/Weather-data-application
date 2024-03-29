#ifndef WEATHERDATAMANAGER_H
#define WEATHERDATAMANAGER_H

#include "datamanager.h"

class WeatherDataManager : public DataManager
{
public:



    WeatherDataManager();
    std::string getUrl() const override;
    std::vector<std::pair<std::string, std::string>> getVariables() const override;


private:
    struct hourlyVariables{
        std::vector<std::pair<std::string, std::string>> variables {
            {"Temperature","temperature_2m"},
            {"Relative Humidity","relative_humidity_2m"},
            {"Dew Point","dew_point_2m"},
            {"Apparent Temperature","apparent_temperature"},
            {"Precipitation Probability","precipitation_probability"},
            {"Precipitation","precipitation"},
            {"Rain","rain"},
            {"Showers","showers"},
            {"Snowfall","snowfall"},
            {"Snow Depth","snow_depth"},
            {"Weather Code","weather_code"},
            {"Pressure MSL","pressure_msl"},
            {"Surface Pressure","surface_pressure"},
            {"Cloud Cover","cloud_cover"},
            {"Low Cloud Cover","cloud_cover_low"},
            {"Mid Cloud Cover","cloud_cover_mid"},
            {"High Cloud Cover","cloud_cover_high"},
            {"Visibility","visibility"},
            {"Evapotranspiration","evapotranspiration"},
            {"ET0 FAO Evapotranspiration","et0_fao_evapotranspiration"},
            {"Vapour Pressure Deficit","vapour_pressure_deficit"},
            {"Wind Speed (10 m)","wind_speed_10m"},
            {"Wind Speed (80 m)","wind_speed_80m"},
            {"Wind Speed (120 m)","wind_speed_120m"},
            {"Wind Speed (180 m)","wind_speed_180m"},
            {"Wind Direction (10 m)","wind_direction_10m"},
            {"Wind Direction (80 m)","wind_direction_80m"},
            {"Wind Direction (120 m)","wind_direction_120m"},
            {"Wind Direction (180 m)","wind_direction_180m"},
            {"Wind Gusts (10 m)","wind_gusts_10m"},
            {"Temperature (80 m)","temperature_80m"},
            {"Temperature (120 m)","temperature_120m"},
            {"Temperature (180 m)","temperature_180m"},
            {"Soil Temperature (0 cm)","soil_temperature_0cm"},
            {"Soil Temperature (6 cm)","soil_temperature_6cm"},
            {"Soil Temperature (18 cm)","soil_temperature_18cm"},
            {"Soil Temperature (54 cm)","soil_temperature_54cm"},
            {"Soil Moisture (0-1 cm)","soil_moisture_0_to_1cm"},
            {"Soil Moisture (1-3 cm)","soil_moisture_1_to_3cm"},
            {"Soil Moisture (3-9 cm)","soil_moisture_3_to_9cm"},
            {"Soil Moisture (9-27 cm)","soil_moisture_9_to_27cm"},
            {"Soil Moisture (27-81 cm)","soil_moisture_27_to_81cm"}
        };
    };

}; // Add a closing brace to close the class declaration

#endif // WEATHERDATAMANAGER_H
