#ifndef HISTORICALWEATHERDATAMANAGER_H
#define HISTORICALWEATHERDATAMANAGER_H
#include "datamanager.h"
#include "userpreferences.h"

extern UserPreferences userSettings;

class HistoricalWeatherDataManager:public DataManager
{
public:
    HistoricalWeatherDataManager();

    std::string getUrl() const override;
    std::vector<std::pair<std::string, std::string>> getVariables() const override;
    void handleVariableSelections(std::vector<std::pair<std::string, std::string>> allVariables) const override;



private:
    void handleReanalysisModels() const;


    struct variables
    {
        std::vector<std::pair<std::string, std::string>> hourlyVariables {
            {"Temperature","temperature_2m"},
            {"Relative Humidity","relative_humidity_2m"},
            {"Is Day","is_day"},
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
            {"Soil Moisture (100-255 cm)","soil_moisture_100_to_255cm"},


            ///special Varibles with extra selections
            {"Solar Radiaton Variables","Special Variable with Extra selection"},
            {"Reanalysis Models","Special Variable with Extra selection"}
        };


        std::vector<std::pair<std::string, std::string>> dailyVariables {
            {"Weather Code", "weather_code"},
            {"Temperature 2m Max", "temperature_2m_max"},
            {"Temperature 2m Min", "temperature_2m_min"},
            {"Temperature 2m Mean", "temperature_2m_mean"},
            {"Apparent Temperature Max", "apparent_temperature_max"},
            {"Apparent Temperature Min", "apparent_temperature_min"},
            {"Apparent Temperature Mean", "apparent_temperature_mean"},
            {"Sunrise", "sunrise"},
            {"Sunset", "sunset"},
            {"Daylight Duration", "daylight_duration"},
            {"Sunshine Duration", "sunshine_duration"},
            {"Precipitation Sum", "precipitation_sum"},
            {"Rain Sum", "rain_sum"},
            {"Snowfall Sum", "snowfall_sum"},
            {"Precipitation Hours", "precipitation_hours"},
            {"Wind Speed 10m Max", "wind_speed_10m_max"},
            {"Wind Gusts 10m Max", "wind_gusts_10m_max"},
            {"Wind Direction 10m Dominant", "wind_direction_10m_dominant"},
            {"Shortwave Radiation Sum", "shortwave_radiation_sum"},
            {"ET0 FAO Evapotranspiration", "et0_fao_evapotranspiration"}
        };

        std::vector<std::pair<std::string, std::string>> reanalysisModels {
            {"ECMWF IFS (9 km, Global, 2017 onwards)", "ecmwf_ifs"},
            {"ERA5-Seamless (ERA5 & ERA5-Land combined)", "era5_seamless"},
            {"ERA5 (25 km, Global)", "era5"},
            {"ERA5-Land (10 km, Global)", "era5_land"},
            {"CERRA (5 km, Europe, 1985 to June 2021)", "cerra"}
        };
    };
    variables historicalWeather;

};

#endif // HISTORICALWEATHERDATAMANAGER_H
