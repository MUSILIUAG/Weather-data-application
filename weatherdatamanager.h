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
    struct Variables{
        std::vector<std::pair<std::string, std::string>> hourlyVariables {
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
            {"Soil Moisture (27-81 cm)","soil_moisture_27_to_81cm"},

            ///special Variables with extra selections
            {"Solar Radiaton Variables","Special Variable with Extra selection"},
            {"Pressure Variables","Special Variable with Extra selection"},
            {"Weather Models","Special Variable with Extra selection"}
        };

        std::vector<std::pair<std::string, std::string>> dailyVariables {
            {"Weather Code", "weather_code"},
            {"Temperature 2m Max", "temperature_2m_max"},
            {"Temperature 2m Min", "temperature_2m_min"},
            {"Apparent Temperature Max", "apparent_temperature_max"},
            {"Apparent Temperature Min", "apparent_temperature_min"},
            {"Sunrise", "sunrise"},
            {"Sunset", "sunset"},
            {"Daylight Duration", "daylight_duration"},
            {"Sunshine Duration", "sunshine_duration"},
            {"UV Index Max", "uv_index_max"},
            {"UV Index Clear Sky Max", "uv_index_clear_sky_max"},
            {"Precipitation Sum", "precipitation_sum"},
            {"Rain Sum", "rain_sum"},
            {"Showers Sum", "showers_sum"},
            {"Snowfall Sum", "snowfall_sum"},
            {"Precipitation Hours", "precipitation_hours"},
            {"Precipitation Probability Max", "precipitation_probability_max"},
            {"Wind Speed 10m Max", "wind_speed_10m_max"},
            {"Wind Gusts 10m Max", "wind_gusts_10m_max"},
            {"Wind Direction 10m Dominant", "wind_direction_10m_dominant"},
            {"Shortwave Radiation Sum", "shortwave_radiation_sum"},
            {"ET0 FAO Evapotranspiration", "et0_fao_evapotranspiration"}
        };
    };

}; // Add a closing brace to close the class declaration

#endif // WEATHERDATAMANAGER_H
